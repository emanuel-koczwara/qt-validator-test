#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP


#include <QMainWindow>


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

protected:
  virtual void closeEvent(QCloseEvent *event);

private:
  Ui::MainWindow *ui;

}; // class MainWindow


#endif // MAINWINDOW_HPP
