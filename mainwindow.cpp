#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "colors.h"
#include "dialogabout.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    for(int i=0; i<8; i++) {
        gob2bottles[i] = QPixmap("://bottles/gob2_" + QString::number(i+1) + ".png");
        gob3bottles[i] = QPixmap("://bottles/gob3_" + QString::number(i+1) + ".png");
    }
    ui->setupUi(this);
    dialogAbout = new DialogAbout(this);

    ui->game->setItemData(0, 0, Qt::UserRole - 1);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::calculateResult() {
    int rowIndex = ui->number->value() - 1;
    int gameIndex = ui->game->currentIndex();
    if(rowIndex < 0 || columnLetter == '0' || gameIndex < 1) {
        ui->bottleImage->clear();
        return;
    }
    int columnIndex;
    if(columnLetter == 'A')
        columnIndex = 0;
    else if(columnLetter == 'B')
        columnIndex = 1;
    else if(columnLetter == 'C')
        columnIndex = 2;
    else if(columnLetter == 'D')
        columnIndex = 3;

    if(gameIndex == 1) {
        Color color = gobliins2colors[rowIndex][columnIndex];
        ui->bottleImage->setPixmap(gob2bottles[color-1]);
    }
    if(gameIndex == 2) {
        Color color = goblins3colors[rowIndex][columnIndex];
        ui->bottleImage->setPixmap(gob3bottles[color-1]);
    }
    return;
}

void MainWindow::on_game_currentIndexChanged(int index)
{
    calculateResult();
}

void MainWindow::on_number_valueChanged(int index)
{
    if(ui->horizontalSlider->value() != index) {
        ui->horizontalSlider->setValue(index);
    }
    calculateResult();
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    if(ui->number->value() != value)
        ui->number->setValue(value);
}

void MainWindow::on_dial_valueChanged(int value)
{
    if(value == 0){
        ui->dial->setValue(previousDialValue);
        return;
    }
    switch (value) {
    case 0:
        columnLetter = '0';
        break;
    case 1:
        columnLetter = 'A';
        break;
    case 2:
        columnLetter = 'B';
        break;
    case 3:
        columnLetter = 'C';
        break;
    case 4:
        columnLetter = 'D';
        break;
    default:
        columnLetter = '0';
        break;
    }
    if(columnLetter == '0')
        ui->number->setPrefix("");
    else
        ui->number->setPrefix(QString(columnLetter));
    previousDialValue = value;
    calculateResult();
}

void MainWindow::on_aboutButton_clicked()
{
    dialogAbout->show();
}
