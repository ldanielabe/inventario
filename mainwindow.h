#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "database.h"
namespace Ui {
class MainWindow;
}
class MainWindow : public QMainWindow{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionQuitar_Aplicacion_triggered();

    void on_actionAgregar_triggered();


    void on_btnIngresar_clicked();

    void on_btnIngresar_clicked(bool checked);

    void on_btnIngresar_pressed();

    void on_btnIngresar_customContextMenuRequested(const QPoint &pos);

    void on_btnIngresar_toggled(bool checked);

    void on_checkBoxAdmin_stateChanged(int arg1);

    void on_AdminRadioButton_clicked();

    void on_CajeroRadioButton_clicked();

    void on_buttonBox_accepted();

private:
    Ui::MainWindow *ui;
    database dbase;

};

#endif // MAINWINDOW_H
