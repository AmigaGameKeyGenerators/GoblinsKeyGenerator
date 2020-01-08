#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dialogabout.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_number_valueChanged(int arg1);

    void on_game_currentIndexChanged(int index);

    void on_horizontalSlider_valueChanged(int value);

    void on_dial_valueChanged(int value);

    void on_aboutButton_clicked();

private:
    Ui::MainWindow *ui;
    DialogAbout *dialogAbout;
    void calculateResult();
    QPixmap gob2bottles[8];
    QPixmap gob3bottles[8];
    char columnLetter = '0';
    int previousDialValue = 0;
};

#endif // MAINWINDOW_H
