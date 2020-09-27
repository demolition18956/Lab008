#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    strModel = new QStringListModel(this);

    ui->listView->setModel(strModel);
    ui->treeView->setModel(strModel);
    ui->tableView->setModel(strModel);

    connect(ui->addButton, &QPushButton::clicked, this, &MainWindow::addToViews);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addToViews()
{
    QString str = ui->lineEdit->text();
    ui->lineEdit->clear();
    QStringList strList = strModel->stringList();
    strList.append(str);
    strModel->setStringList(strList);
}
