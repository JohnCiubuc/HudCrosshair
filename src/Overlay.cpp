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
}

Overlay::~Overlay()
{
    delete ui;
}
