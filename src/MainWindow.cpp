#include "MainWindow.h"
#include "ui_MainWindow.h"


HWND g_HWND=NULL;
BOOL CALLBACK EnumWindowsProcMy(HWND hwnd,LPARAM lParam)
{
    DWORD lpdwProcessId;
    GetWindowThreadProcessId(hwnd,&lpdwProcessId);
    if(lpdwProcessId==lParam)
    {
        g_HWND=hwnd;
        return FALSE;
    }
    return TRUE;
}

DWORD FindProcessId(QString processName)
{
    PROCESSENTRY32 processInfo;
    processInfo.dwSize = sizeof(processInfo);

    HANDLE processesSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);
    if (processesSnapshot == INVALID_HANDLE_VALUE) {
        return 0;
    }

    Process32First(processesSnapshot, &processInfo);
    if (processName.compare(processInfo.szExeFile) == 0)
    {
        CloseHandle(processesSnapshot);
        return processInfo.th32ProcessID;
    }

    while (Process32Next(processesSnapshot, &processInfo))
    {
        if (processName.compare(processInfo.szExeFile) == 0)
        {
            CloseHandle(processesSnapshot);
            return processInfo.th32ProcessID;
        }
    }

    CloseHandle(processesSnapshot);
    return 0;
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    auto dw = FindProcessId("DummyApp.exe");
    if(dw != 0)
        EnumWindows(EnumWindowsProcMy,dw);
    db g_HWND;
    RECT rect;
    GetWindowRect(g_HWND, &rect);
    db rect.bottom;
    db rect.right;
}

MainWindow::~MainWindow()
{
    delete ui;
}

