#include "product.h"
#include "ui_product.h"
#include <QSqlTableModel>
product::product(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::product)
{
    ui->setupUi(this);
    mModel=new QSqlTableModel(this);
    mModel->setTable("Producto");
    mModel->select();

    mModel->setHeaderData(0,Qt::Horizontal,"ID");
    mModel->setHeaderData(1,Qt::Horizontal,"PRODUCTO");
    mModel->setHeaderData(2,Qt::Horizontal,"PROVEDOR");
    mModel->setHeaderData(3,Qt::Horizontal,"CATEGORIA");
    mModel->setHeaderData(4,Qt::Horizontal,"VALOR C/u");
    mModel->setHeaderData(5,Qt::Horizontal,"STOCK");
    ui->tableView->hideColumn(0);
    ui->tableView->setModel(mModel);
    ui->tableView->addActions({ui->actionAdd,ui->actionDelete});

}

product::~product()
{
    delete ui;
}

void product::on_actionAdd_triggered()
{
mModel->insertRow(mModel->rowCount());

}

void product::on_actionDelete_triggered()
{
mModel->removeRow(ui->tableView->currentIndex().row());
mModel->select();
}


