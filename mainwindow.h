#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QTableWidget>
#include <QTableView>
#include <QFileDialog>
#include <QMessageBox>
#include <QTimer>
#include <bits/stdc++.h>
using namespace std;
#include "pipe.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_MainWindow_destroyed();
    void timerGo();
    void timerPause();
    void stepNext();
    void stepOne();
    void showAll();
    void pipeReset();
    void on_bReset_clicked();

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    QAbstractItemView *mem, *ins;

};
#endif // MAINWINDOW_H
