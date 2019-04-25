#ifndef PRODUCT_H
#define PRODUCT_H

#include <QDialog>

namespace Ui {
class product;
}

class QSqlTableModel;

class product : public QDialog
{
    Q_OBJECT

public:
    explicit product(QWidget *parent = nullptr);
    ~product();

private slots:
    void on_actionAdd_triggered();

    void on_actionDelete_triggered();




private:
    Ui::product *ui;
    QSqlTableModel * mModel;

};

#endif // PRODUCT_H
