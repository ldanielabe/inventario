#include "cajero.h"
#include "ui_cajero.h"
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QMessageBox>
#include "cajeromodel.h"
#include<bits/stdc++.h>
cajero::cajero(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cajero)
{
    ui->setupUi(this);
   mModel=new QSqlTableModel(this);
// QObject::connect(this,SIGNAL(toggled()),this,SLOT(on_pushButton_toggled(bool val)));
// this->setObjectName(QString("MyWindowUFPS"));
   mModelCajero=new cajeroModel();

   QSqlQuery q=mModelCajero->queryprod();
ui->comboBox->addItem(QVariant(q.value(1).toString()).toString());
   while (q.next()) {
   ui->comboBox->addItem(QVariant(q.value(1).toString()).toString());
   }


}

cajero::~cajero()
{


    delete ui;
}


void cajero::on_buttonBox_accepted()
{

}
//AGG
void cajero::on_pushButton_toggled(bool checked)
{
if(checked){cout<<"HolaMundo:)"<<endl;}
}

//DELETE
void cajero::on_pushButton_2_toggled(bool checked)
{
if(checked){cout<<"HolaMundo:) 2"<<endl;}
}


void cajero::on_pushButton_3_toggled(bool checked)
{
    if(checked){
    if(checked){cout<<"HolaMundo:) 3"<<endl;}
    return;}
}


void cajero::on_pushButton_clicked()
{
    if(!ui->txtcant->text().isEmpty()){

     mModelCajero=new cajeroModel();
      QString cant;
     cant=mModelCajero->consultaCant(ui->comboBox->currentText());

     int sum=0;
     if(cant.toInt()==0){
         QMessageBox::warning(this,"Aviso","No existe este producto.");
         return;
     }else{
      QString prod=ui->comboBox->currentText();
      QString c=ui->txtcant->text();
     //Verificar
      int intcantidad; //declaro una variable tipo entero
      bool check;
      intcantidad=c.toInt(&check);
      if(!check){
      QMessageBox::warning(this, "Error tipo de dato", "Porfavor digite un numero");
      ui->txtcant->setText("");
      return;
      }


          if(c.toInt()>=cant.toInt()){
              QMessageBox::information(this,"Aviso","No existe la cantidad que solicita. Stock: "+ cant);
              return;
          }else if(c.toInt()<=0){
              QMessageBox::information(this,"Aviso","Valor invalido.");
              return;
          }else{
              ui->listWidget->addItem(QString(prod + "-Cantidad-" + QString(c)));
              QStringList arrtot=ui->txttotal->text().split(" ");

              if(ui->txttotal->text()!=""){
                   sum=arrtot.value(arrtot.length()-2).toInt()+(mModelCajero->consultaPrecio(prod)*c.toInt());
                  }else {
                  sum=mModelCajero->consultaPrecio(prod)*c.toInt();
                  }


              ui->txttotal->setText(QVariant(sum).toString()+" pesos");
              ui->txttotal->show();
              int res=cant.toInt()-c.toInt();

              mModelCajero->actualizar(QVariant(res).toString(),prod);
          }
          }
     }else {
        QMessageBox::information(this,"Aviso","Faltan datos.");
        return;
    }
}

void cajero::on_pushButton_2_clicked()
{

if(ui->txttotal->text().isEmpty()){
    QMessageBox::information(this,"ERROR","No ha agregado ningun producto.");

}else{
    QString cant;

    QList<QListWidgetItem*> items = ui->listWidget->selectedItems();

    foreach(QListWidgetItem* item, items){
        ui->listWidget->removeItemWidget(item);
        QStringList arr=item->text().split("-");

        int c=arr.value(arr.length()-1).toInt();

        QString prod=arr.value(arr.length()-3);

        cant=mModelCajero->consultaCant(prod);
        mModelCajero->actualizar(QVariant(cant.toInt()+c).toString(),prod);
        QStringList arrtot=ui->txttotal->text().split(" ");
        if(ui->txttotal->text()!=""){
             sum=arrtot.value(arrtot.length()-2).toInt()-(mModelCajero->consultaPrecio(prod)*c);
            }
        ui->txttotal->setText(QVariant(sum).toString()+" Pesos");

        delete item;
    }
    ui->listWidget->selectAll();
}
}

void cajero::on_pushButton_3_clicked()
{
    if(!ui->txtced->text().isEmpty()||!ui->txtnombre->text().isEmpty()){
   sum=0;
   QMessageBox::information(this,"Reporte","Se vendio al cliente "+ ui->txtnombre->text()+" el total de: "+ui->txttotal->text());
   ui->txttotal->setText("");
   ui->txtced->setText("");
   ui->txtnombre->setText("");
   ui->txtcant->setText("");
   ui->listWidget->clear();
}else{
        QMessageBox::information(this,"Aviso","Faltan datos.");
        return;
}
}


