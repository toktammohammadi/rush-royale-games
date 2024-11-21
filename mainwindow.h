#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include <QPushButton>
#include <QLabel>

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
};

#endif // MAINWINDOW_H
