#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "Win32Functions.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   _Overlay = new Overlay();
   getRectFromName("DummyApp.exe");
   _Overlay->show();
   _Overlay->setCrosshair(QPixmap(":/Circle/Crosshairs/circle/circle-01-whole.png"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::getRectFromName(QString name)
{
    auto dw = FindProcessId(name);
    g_HWND = 0;
    if(dw == 0) return;

    EnumWindows(EnumWindowsProcMy,dw);
    RECT rect;
    if (g_HWND == 0) return;

    GetWindowRect(g_HWND, &rect);
    _windowRect.setRect(rect.left, rect.top, rect.right, rect.bottom);
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    _Overlay->deleteLater();
    event->accept();
}

