#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "database.h"
#include "mainwindowmodel.h"

namespace Ui {
class MainWindow;
}
class MainWindow : public QMainWindow{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_buttonBox_accepted();

    void on_btnIngresar_toggled(bool checked);

    void on_btnIngresar_clicked();

private:
    Ui::MainWindow *ui;
    database dbase;
    mainwindowmodel * mModelMainWindow;

};

#endif // MAINWINDOW_H
