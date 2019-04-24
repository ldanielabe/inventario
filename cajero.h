#ifndef CAJERO_H
#define CAJERO_H

#include <QDialog>

namespace Ui {
class cajero;
}

class QSqlTableModel;

class cajero : public QDialog
{
    Q_OBJECT

public:
    explicit cajero(QWidget *parent = nullptr);
    ~cajero();

private slots:
    void on_buttonBox_accepted();

    void on_actionAgregar_Producto_triggered();

    void on_actionEliminar_Producto_triggered();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_btneliminar_clicked();

    void on_btnagg_clicked();

    void on_btnvender_clicked();

    void on_buttonBox_2_accepted();

    void on_buttonBox_2_rejected();

private:
    Ui::cajero *ui;
    QSqlTableModel * mModel;
    int sum=0;
};

#endif // CAJERO_H
