#include "MainWindow.h"
#include "../../../cmake-build-debug/lib/src/StockBeansLib_autogen/include/ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
