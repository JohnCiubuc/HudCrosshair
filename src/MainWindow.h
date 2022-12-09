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

public slots:
    void setCrosshair(QString file, double scale);

private:
    void getRectFromName(QString name);
    QRect _windowRect;
    Ui::MainWindow *ui;
    Overlay * _Overlay;
    QString _crosshairFile;
protected:
    void closeEvent(QCloseEvent *event);
private slots:
    void on_doubleSpinBox_valueChanged(double arg1);
};
#endif // MAINWINDOW_H
