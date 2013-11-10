#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP


#include <QMainWindow>
#include <QStateMachine>


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

protected:
  virtual void closeEvent(QCloseEvent *event);

private:
  Ui::MainWindow *ui;
  QStateMachine *machine;

}; // class MainWindow


#endif // MAINWINDOW_HPP
