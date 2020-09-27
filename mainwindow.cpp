#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    strModel.setStringList(strList);
    ui->listView->setModel(&strModel);
    ui->treeView->setModel(&strModel);
    ui->tableView->setModel(&strModel);

    connect(ui->addButton, &QPushButton::clicked, this, &MainWindow::addToViews);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addToViews()
{
    strList.append(ui->lineEdit->text());
    ui->lineEdit->clear();
    strModel.setStringList(strList);
}
