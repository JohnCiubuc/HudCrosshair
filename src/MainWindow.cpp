#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "Win32Functions.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   _Overlay = new Overlay();
   _targetName = "DummyApp.exe";
   _Overlay->show();
   _crosshairFile = ":/Circle/Crosshairs/circle/circle-01-whole.png";
   setCrosshair(_crosshairFile, 1);

   QTimer * t = new QTimer(this);
   connect(t, &QTimer::timeout, this, &MainWindow::centerOverlayOnTarget);
   t->start(10);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setCrosshair(QString file, double scale=1.0)
{
        QPixmap p(file);
        auto w = p.width();
        auto h = p.height();
        p = p.scaled(w*scale, h*scale);
        _crossRect = p.rect();
        _Overlay->setCrosshair(p);
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


void MainWindow::on_doubleSpinBox_valueChanged(double arg1)
{
    setCrosshair(_crosshairFile, arg1);
}

void MainWindow::centerOverlayOnTarget()
{
    getRectFromName(_targetName);
    auto x = (_windowRect.width() - _windowRect.x())/2 +  _windowRect.x();
    x -= _crossRect.width()/2;
    auto y = (_windowRect.height() - _windowRect.y())/2 + _windowRect.top() ;
    y -= _crossRect.height()/2;
    _Overlay->setGeometry(x, y, _Overlay->width(), _Overlay->height());
}

