#include "MainWindow.hpp"
#include "ui_MainWindow.h"
#include <QMessageBox>
#include <QCloseEvent>
#include <QRegExp>
#include <QRegExpValidator>
#include <QIntValidator>
#include <QStateMachine>
#include <QState>


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

  QStateMachine machine;

  QState *ipToInt = new QState();
  QState *intToHex = new QState();
  QState *hexToBase64 = new QState();
  QState *base64ToHex = new QState();
  QState *hexToInt = new QState();
  QState *intToIp = new QState();

  ipToInt->addTransition(ui->pushButton, SIGNAL(clicked()), intToHex);
  intToHex->addTransition(ui->pushButton, SIGNAL(clicked()), hexToBase64);
  hexToBase64->addTransition(ui->pushButton, SIGNAL(clicked()), hexToInt);
  hexToInt->addTransition(ui->pushButton, SIGNAL(clicked()), intToIp);

  machine.addState(ipToInt);
  machine.addState(intToHex);
  machine.addState(hexToBase64);
  machine.addState(base64ToHex);
  machine.addState(hexToInt);
  machine.addState(intToIp);

  machine.setInitialState(ipToInt);

  machine.start();

  QObject::connect(ipToInt, SIGNAL(exited()), this, SLOT(convertIpToInt()));
  QObject::connect(intToHex, SIGNAL(exited()), this, SLOT(convertIntToHex()));
  QObject::connect(hexToBase64, SIGNAL(exited()), this, SLOT(convertHexToBase64()));
  QObject::connect(base64ToHex, SIGNAL(exited()), this, SLOT(convertBase64ToHex()));
  QObject::connect(hexToInt, SIGNAL(exited()), this, SLOT(convertHexToInt()));
  QObject::connect(intToIp, SIGNAL(exited()), this, SLOT(convertIntToIp()));
}


MainWindow::~MainWindow()
{
  delete ui;
}


void MainWindow::convertIpToInt()
{

}


void MainWindow::convertIntToHex()
{

}


void MainWindow::convertHexToBase64()
{

}


void MainWindow::convertBase64ToHex()
{

}


void MainWindow::convertHexToInt()
{

}


void MainWindow::convertIntToIp()
{

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
