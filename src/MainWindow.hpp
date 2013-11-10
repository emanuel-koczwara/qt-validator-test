#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP


#include <QMainWindow>
#include <QStateMachine>
#include <QRegExp>
#include <QRegExpValidator>
#include <QIntValidator>


namespace Ui
{
class MainWindow;
}


class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = 0);
  virtual ~MainWindow();

public slots:
  void convertIpToInt();
  void convertIntToHex();
  void convertHexToBase64();
  void convertBase64ToHex();
  void convertHexToInt();
  void convertIntToIp();
  void setIpValidator();
  void setIntValidator();
  void setHexValidator();
  void setBase64Validator();

protected:
  virtual void closeEvent(QCloseEvent *event);

private:
  Ui::MainWindow *ui;

  QStateMachine *machine;

  QRegExpValidator *ipValidator;
  QRegExpValidator *intValidator;
  QRegExpValidator *hexValidator;
  QRegExpValidator *base64Validator;

}; // class MainWindow


#endif // MAINWINDOW_HPP
