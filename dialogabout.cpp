#include "dialogabout.h"
#include "ui_dialogabout.h"

DialogAbout::DialogAbout(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogAbout)
{
    ui->setupUi(this);
    ui->labelMail->setText("<a href=\"mailto:contactme@volkanorhan.com\">contactme@volkanorhan.com</a>");
    ui->labelMail->setTextFormat(Qt::RichText);
    ui->labelMail->setTextInteractionFlags(Qt::TextBrowserInteraction);
    ui->labelMail->setOpenExternalLinks(true);
    ui->labelWeb->setText("<a href=\"http://www.volkanorhan.com\">http://www.volkanorhan.com</a>");
    ui->labelWeb->setTextFormat(Qt::RichText);
    ui->labelWeb->setTextInteractionFlags(Qt::TextBrowserInteraction);
    ui->labelWeb->setOpenExternalLinks(true);
}

DialogAbout::~DialogAbout()
{
    delete ui;
}
