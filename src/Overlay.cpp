#include "Overlay.h"
#include "ui_Overlay.h"

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
ui->label_image->setPixmap(p);
}
