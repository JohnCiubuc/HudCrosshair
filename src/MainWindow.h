#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qt_windows.h>
#include <tlhelp32.h>
#include <QDebug>
#include <QCloseEvent>
#include <QTimer>

#include "Overlay.h"
#define db qDebug() << this <<

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void getRectFromName(QString name);
    QRect _windowRect;
    Ui::MainWindow *ui;
    Overlay * _Overlay;
protected:
    void closeEvent(QCloseEvent *event);
};
#endif // MAINWINDOW_H
