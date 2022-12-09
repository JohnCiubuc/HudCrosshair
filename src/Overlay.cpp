#include "Overlay.h"
#include "ui_Overlay.h"

Overlay::Overlay(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Overlay)
{
    ui->setupUi(this);
}

Overlay::~Overlay()
{
    delete ui;
}
