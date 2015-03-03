#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::reset_card(){
    int x,y;
    x = rand()%10;
    y = rand()%10;


    ui->label->setText(QString::number(x));
    ui->label_3->setText(QString::number(y));

}

void MainWindow::on_pushButton_pressed()
{
    int answer = ui->label->text().toInt() + ui->label_3->text().toInt();

    if(ui->label->text() == ""){
        ui->textEdit->setText("");
        reset_card();
        answer = ui->label->text().toInt() + ui->label_3->text().toInt();


    }

    else if(ui->label_5->text() == "Correct!"){
        reset_card();
        answer = ui->label->text().toInt() + ui->label_3->text().toInt();
        ui->label_5->setText("");
        ui->textEdit->setText("");
        ui->textEdit->setFocus();

    }

    else if(QString::number(answer) == ui->textEdit->toPlainText()){
        ui->label_5->setText("Correct!");
    }

    else if(ui->label->text() != ui->textEdit->toPlainText()){
        ui->label_5->setText("Incorrect!");

    }
    ui->textEdit->setFocus();
}
