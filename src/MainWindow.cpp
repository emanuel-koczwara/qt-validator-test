#include "MainWindow.hpp"
#include "ui_MainWindow.h"
#include <QMessageBox>
#include <QCloseEvent>
#include <QRegExp>
#include <QRegExpValidator>
#include <QIntValidator>
#include <QStateMachine>
#include <QState>
#include <QHostAddress>


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

  machine = new QStateMachine(this);

  QState *ipToInt = new QState();
  QState *intToHex = new QState();
  QState *hexToBase64 = new QState();
  QState *base64ToHex = new QState();
  QState *hexToInt = new QState();
  QState *intToIp = new QState();

  ipToInt->addTransition(ui->pushButton, SIGNAL(clicked()), intToHex);
  intToHex->addTransition(ui->pushButton, SIGNAL(clicked()), hexToBase64);
  hexToBase64->addTransition(ui->pushButton, SIGNAL(clicked()), base64ToHex);
  base64ToHex->addTransition(ui->pushButton, SIGNAL(clicked()), hexToInt);
  hexToInt->addTransition(ui->pushButton, SIGNAL(clicked()), intToIp);
  intToIp->addTransition(ui->pushButton, SIGNAL(clicked()), ipToInt);

  machine->addState(ipToInt);
  machine->addState(intToHex);
  machine->addState(hexToBase64);
  machine->addState(base64ToHex);
  machine->addState(hexToInt);
  machine->addState(intToIp);

  machine->setInitialState(ipToInt);

  QObject::connect(ipToInt, SIGNAL(exited()), this, SLOT(convertIpToInt()));
  QObject::connect(intToHex, SIGNAL(exited()), this, SLOT(convertIntToHex()));
  QObject::connect(hexToBase64, SIGNAL(exited()), this, SLOT(convertHexToBase64()));
  QObject::connect(base64ToHex, SIGNAL(exited()), this, SLOT(convertBase64ToHex()));
  QObject::connect(hexToInt, SIGNAL(exited()), this, SLOT(convertHexToInt()));
  QObject::connect(intToIp, SIGNAL(exited()), this, SLOT(convertIntToIp()));

  machine->start();

}


MainWindow::~MainWindow()
{
  delete ui;
}


void MainWindow::convertIpToInt()
{
  ui->lineEdit->setText(QString::number(QHostAddress(ui->lineEdit->text()).toIPv4Address()));
}


void MainWindow::convertIntToHex()
{
  ui->lineEdit->setText(QString::number(ui->lineEdit->text().toUInt(), 16).toUpper());
}


void MainWindow::convertHexToBase64()
{
  ui->lineEdit->setText(QByteArray(ui->lineEdit->text().toAscii()).toBase64());
}


void MainWindow::convertBase64ToHex()
{
  ui->lineEdit->setText(QString(QByteArray::fromBase64(ui->lineEdit->text().toAscii())));
}


void MainWindow::convertHexToInt()
{
  bool ok;
  ui->lineEdit->setText(QString::number(ui->lineEdit->text().toUInt(&ok, 16)));
}


void MainWindow::convertIntToIp()
{
  ui->lineEdit->setText(QHostAddress(ui->lineEdit->text().toUInt()).toString());
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
