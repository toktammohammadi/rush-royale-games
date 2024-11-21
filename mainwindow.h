#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>

#include "Board.h"



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onStartButtonClicked();

private:
    QStackedWidget *stackedWidget;
    QWidget *mainPage;
    QWidget *secondPage;
    QPushButton *startpushButton;
    QLabel *backgroundLabel;
    Board *board;
};

#endif // MAINWINDOW_H
