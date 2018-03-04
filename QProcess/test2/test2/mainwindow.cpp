#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "windows.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    appPath = QDir::currentPath() + "/debug/Hello.exe";

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(60000);

    pMinerProcess = new QProcess(this);

    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{



pMinerProcess->setCreateProcessArgumentsModifier(
            [this](QProcess::CreateProcessArguments *args) {

    ui->textEditQProcess->append("typedef struct _STARTUPINFO");
    ui->textEditQProcess->append("{");
    ui->textEditQProcess->append("DWORD     cb;                              // " + QString::number(args->startupInfo->cb));
    ui->textEditQProcess->append("LPTSTR      lpReserved;               // \"" + QString::fromWCharArray(args->startupInfo->lpReserved) + "\"");
    ui->textEditQProcess->append("LPTSTR      lpDesktop;                 // \"" + QString::fromWCharArray(args->startupInfo->lpDesktop) + "\"");
    ui->textEditQProcess->append("LPTSTR      lpTitle;                       // \"" + QString::fromWCharArray(args->startupInfo->lpTitle) + "\"");
    ui->textEditQProcess->append("DWORD     dwX;                          // " + QString::number(args->startupInfo->dwX));
    ui->textEditQProcess->append("DWORD     dwY;                          // " + QString::number(args->startupInfo->dwY));
    ui->textEditQProcess->append("DWORD     dwXSize;                    // " + QString::number(args->startupInfo->dwXSize));
    ui->textEditQProcess->append("DWORD     dwYSize;                    // " + QString::number(args->startupInfo->dwYSize));
    ui->textEditQProcess->append("DWORD     dwXCountChars;       // " + QString::number(args->startupInfo->dwXCountChars));
    ui->textEditQProcess->append("DWORD     dwYCountChars;        // " + QString::number(args->startupInfo->dwYCountChars));
    ui->textEditQProcess->append("DWORD     dwFillAttribute;           // " + QString::number(args->startupInfo->dwFillAttribute));
    ui->textEditQProcess->append("DWORD     dwFlags;                     // " + QString::number(args->startupInfo->dwFlags));
    ui->textEditQProcess->append("WORD       wShowWindow;          // " + QString::number(args->startupInfo->wShowWindow));
    ui->textEditQProcess->append("WORD       cbReserved2;             // " + QString::number(args->startupInfo->cbReserved2));
    ui->textEditQProcess->append("LPBYTE      lpReserved2;              // " + QString::number(reinterpret_cast<unsigned int>(args->startupInfo->lpReserved2)));
    ui->textEditQProcess->append("HANDLE     hStdInput;                  // " + QString::number(reinterpret_cast<unsigned int>(args->startupInfo->hStdInput)));
    ui->textEditQProcess->append("HANDLE     hStdOutput;               // " + QString::number(reinterpret_cast<unsigned int>(args->startupInfo->hStdOutput)));
    ui->textEditQProcess->append("HANDLE     hStdError;                  // " + QString::number(reinterpret_cast<unsigned int>(args->startupInfo->hStdError)));
    ui->textEditQProcess->append("} STARTUPINFO, *LPSTARTUPINFO");

    args->startupInfo->cb = 0;
    args->startupInfo->lpReserved = 0;
    args->startupInfo->lpDesktop = 0;
    args->startupInfo->lpTitle = 0;
    args->startupInfo->dwX = 0;
    args->startupInfo->dwY = 0;
    args->startupInfo->dwXSize = 0;
    args->startupInfo->dwYSize = 0;
    args->startupInfo->dwXCountChars = 0;
    args->startupInfo->dwYCountChars = 0;
    args->startupInfo->dwFillAttribute = 0;
    args->startupInfo->dwFlags = 0;
    args->startupInfo->wShowWindow = 0;
    args->startupInfo->cbReserved2 = 0;
    args->startupInfo->lpReserved2 = 0;
    args->startupInfo->hStdInput = 0;
    args->startupInfo->hStdOutput = 0;
    args->startupInfo->hStdError = 0;


    args->startupInfo->dwFlags |= STARTF_USESHOWWINDOW;
    args->startupInfo->wShowWindow |= SW_SHOW;


    ui->textEditQProcess->append("typedef struct _STARTUPINFO");
    ui->textEditQProcess->append("{");
    ui->textEditQProcess->append("DWORD     cb;                              // " + QString::number(args->startupInfo->cb));
    ui->textEditQProcess->append("LPTSTR      lpReserved;               // \"" + QString::fromWCharArray(args->startupInfo->lpReserved) + "\"");
    ui->textEditQProcess->append("LPTSTR      lpDesktop;                 // \"" + QString::fromWCharArray(args->startupInfo->lpDesktop) + "\"");
    ui->textEditQProcess->append("LPTSTR      lpTitle;                       // \"" + QString::fromWCharArray(args->startupInfo->lpTitle) + "\"");
    ui->textEditQProcess->append("DWORD     dwX;                          // " + QString::number(args->startupInfo->dwX));
    ui->textEditQProcess->append("DWORD     dwY;                          // " + QString::number(args->startupInfo->dwY));
    ui->textEditQProcess->append("DWORD     dwXSize;                    // " + QString::number(args->startupInfo->dwXSize));
    ui->textEditQProcess->append("DWORD     dwYSize;                    // " + QString::number(args->startupInfo->dwYSize));
    ui->textEditQProcess->append("DWORD     dwXCountChars;       // " + QString::number(args->startupInfo->dwXCountChars));
    ui->textEditQProcess->append("DWORD     dwYCountChars;        // " + QString::number(args->startupInfo->dwYCountChars));
    ui->textEditQProcess->append("DWORD     dwFillAttribute;           // " + QString::number(args->startupInfo->dwFillAttribute));
    ui->textEditQProcess->append("DWORD     dwFlags;                     // " + QString::number(args->startupInfo->dwFlags));
    ui->textEditQProcess->append("WORD       wShowWindow;          // " + QString::number(args->startupInfo->wShowWindow));
    ui->textEditQProcess->append("WORD       cbReserved2;             // " + QString::number(args->startupInfo->cbReserved2));
    ui->textEditQProcess->append("LPBYTE      lpReserved2;              // " + QString::number(reinterpret_cast<unsigned int>(args->startupInfo->lpReserved2)));
    ui->textEditQProcess->append("HANDLE     hStdInput;                  // " + QString::number(reinterpret_cast<unsigned int>(args->startupInfo->hStdInput)));
    ui->textEditQProcess->append("HANDLE     hStdOutput;               // " + QString::number(reinterpret_cast<unsigned int>(args->startupInfo->hStdOutput)));
    ui->textEditQProcess->append("HANDLE     hStdError;                  // " + QString::number(reinterpret_cast<unsigned int>(args->startupInfo->hStdError)));
    ui->textEditQProcess->append("} STARTUPINFO, *LPSTARTUPINFO");
    ui->textEditQProcess->append("");

    ui->textEditQProcess->append("LPCTSTR lpszModuleName;           // \"" + QString::fromWCharArray(args->applicationName) + "\"");


    ui->textEditQProcess->append("LPCTSTR lpszCommandLine;          //  \"" + QString::fromWCharArray(args->arguments) + "\"");

    args->inheritHandles = 0;
    ui->textEditQProcess->append("BOOL bInheritHandles;          //  " + QString::number(args->inheritHandles));
    ui->textEditQProcess->append("");

    ui->textEditQProcess->append("DWORD dwCreateFlags;          //  " + QString::number(args->flags));
    args->flags |= CREATE_NEW_CONSOLE;
    args->flags &= ~CREATE_NO_WINDOW;;
    ui->textEditQProcess->append("DWORD dwCreateFlags;          //  " + QString::number(args->flags));
    ui->textEditQProcess->append("");

    ui->textEditQProcess->append("LPVOID lpvEnvironment;          //  " + QString::number(reinterpret_cast<unsigned int>(args->environment)));

    ui->textEditQProcess->append("LPCTSTR lpszCurrentDir;           // \"" + QString::fromWCharArray(args->currentDirectory) + "\"");

});


//QString appPath = QDir::currentPath() + "/debug/Hello.exe";
//qInfo() << "Current path: " << appPath;

pMinerProcess->start(appPath);

qDebug() << "error = " << pMinerProcess->error();
qDebug() << "error = " << pMinerProcess->errorString();

}


void MainWindow::on_pushButton_2_clicked()
{
STARTUPINFO cif;
ZeroMemory(&cif,sizeof(STARTUPINFO));
PROCESS_INFORMATION pi;


if(CreateProcess((LPCTSTR)appPath.utf16(), 0, 0, 0, false, 0, 0, 0, &cif, &pi))
{
    qInfo() << "process started!";
}


ui->textEditCreateProcess->append("typedef struct _STARTUPINFO");
ui->textEditCreateProcess->append("{");
ui->textEditCreateProcess->append("DWORD     cb;                              // " + QString::number(cif.cb));
ui->textEditCreateProcess->append("LPTSTR      lpReserved;               // \"" + QString::fromWCharArray(cif.lpReserved) + "\"");
ui->textEditCreateProcess->append("LPTSTR      lpDesktop;                 // \"" + QString::fromWCharArray(cif.lpDesktop) + "\"");
ui->textEditCreateProcess->append("LPTSTR      lpTitle;                       // \"" + QString::fromWCharArray(cif.lpTitle) + "\"");
ui->textEditCreateProcess->append("DWORD     dwX;                          // " + QString::number(cif.dwX));
ui->textEditCreateProcess->append("DWORD     dwY;                          // " + QString::number(cif.dwY));
ui->textEditCreateProcess->append("DWORD     dwXSize;                    // " + QString::number(cif.dwXSize));
ui->textEditCreateProcess->append("DWORD     dwYSize;                    // " + QString::number(cif.dwYSize));
ui->textEditCreateProcess->append("DWORD     dwXCountChars;       // " + QString::number(cif.dwXCountChars));
ui->textEditCreateProcess->append("DWORD     dwYCountChars;        // " + QString::number(cif.dwYCountChars));
ui->textEditCreateProcess->append("DWORD     dwFillAttribute;           // " + QString::number(cif.dwFillAttribute));
ui->textEditCreateProcess->append("DWORD     dwFlags;                     // " + QString::number(cif.dwFlags));
ui->textEditCreateProcess->append("WORD       wShowWindow;          // " + QString::number(cif.wShowWindow));
ui->textEditCreateProcess->append("WORD       cbReserved2;             // " + QString::number(cif.cbReserved2));
ui->textEditCreateProcess->append("LPBYTE      lpReserved2;              // " + QString::number(reinterpret_cast<unsigned int>(cif.lpReserved2)));
ui->textEditCreateProcess->append("HANDLE     hStdInput;                  // " + QString::number(reinterpret_cast<unsigned int>(cif.hStdInput)));
ui->textEditCreateProcess->append("HANDLE     hStdOutput;               // " + QString::number(reinterpret_cast<unsigned int>(cif.hStdOutput)));
ui->textEditCreateProcess->append("HANDLE     hStdError;                  // " + QString::number(reinterpret_cast<unsigned int>(cif.hStdError)));
ui->textEditCreateProcess->append("} STARTUPINFO, *LPSTARTUPINFO");

}

void MainWindow::update()
{
    qInfo() << "KILL PROCESS!!!";

    pMinerProcess->close();
}


