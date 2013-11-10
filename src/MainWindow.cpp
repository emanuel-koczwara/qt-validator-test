#include "MainWindow.hpp"
#include "ui_MainWindow.h"
#include <QMessageBox>
#include <QCloseEvent>
#include <QRegExp>
#include <QRegExpValidator>
#include <QIntValidator>


MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);

  // QRegExpValidator *validator = new QRegExpValidator(QRegExp("\\b\\d{1,3}\\.\\d{1,3}\\.\\d{1,3}\\.\\d{1,3}\\b"));

  // QIntValidator *validator = new QIntValidator(0, 4294967295);

  // QRegExpValidator *validator = new QRegExpValidator(QRegExp("[0-9a-fA-F]+"));

  // QRegExpValidator *validator = new QRegExpValidator(QRegExp("^(?:[A-Za-z0-9+/]{4})*(?:[A-Za-z0-9+/]{2}==|[A-Za-z0-9+/]{3}=)?$"));

  // ui->lineEdit->setValidator(validator);
}


MainWindow::~MainWindow()
{
  delete ui;
}


void MainWindow::closeEvent(QCloseEvent *event)
{
  if(QMessageBox::question(this, QString::fromUtf8("ipAddress"),
    QString::fromUtf8("Do you want to quit?"), QMessageBox::Yes, QMessageBox::No) == QMessageBox::Yes)
  {
    event->accept();
  }
  else
  {
    event->ignore();
  }
}
