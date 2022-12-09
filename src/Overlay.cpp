#include "Overlay.h"
#include "qevent.h"
#include "ui_Overlay.h"
#include <QPainter>

Overlay::Overlay(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Overlay)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_TransparentForMouseEvents);
    this->setAttribute(Qt::WA_NoSystemBackground, true);
    this->setAttribute(Qt::WA_TranslucentBackground, true);
    this->setPalette ( Qt::transparent );
    this->setWindowFlag(Qt::WindowStaysOnTopHint, true);
    this->setWindowFlag(Qt::FramelessWindowHint, true);
    this->setWindowFlag(Qt::WindowTransparentForInput, true);
}

Overlay::~Overlay()
{
    delete ui;
}

void Overlay::setCrosshair(QPixmap p)
{
    _p = p;
}

void Overlay::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    painter.drawPixmap(0,0,_p.width(),_p.height(),_p);
    e->accept();
}

