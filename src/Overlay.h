#ifndef OVERLAY_H
#define OVERLAY_H

#include <QWidget>
#include <QPaintEvent>

namespace Ui {
class Overlay;
}

class Overlay : public QWidget
{
    Q_OBJECT

public:
    explicit Overlay(QWidget *parent = nullptr);
    ~Overlay();
public slots:
    void setCrosshair(QPixmap);
private:
    Ui::Overlay *ui;
    QPixmap _p;
protected:
    void paintEvent(QPaintEvent*);
};

#endif // OVERLAY_H
