#ifndef CAJERO_H
#define CAJERO_H

#include <QDialog>
#include "cajeromodel.h"
#include "ui_cajero.h"
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

    void on_pushButton_2_toggled(bool checked);

    void on_pushButton_toggled(bool checked);

    void on_pushButton_3_toggled(bool checked);

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::cajero *ui;
    QSqlTableModel * mModel;
    cajeroModel* mModelCajero;
    int sum=0;
};

#endif // CAJERO_H
