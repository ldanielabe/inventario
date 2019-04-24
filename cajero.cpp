#include "cajero.h"
#include "ui_cajero.h"
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QMessageBox>

cajero::cajero(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cajero)
{
    ui->setupUi(this);
    mModel=new QSqlTableModel(this);

}

cajero::~cajero()
{
    delete ui;
}


void cajero::on_pushButton_clicked()
{
  if(!ui->txtprod->text().isEmpty()&&!ui->txtcant->text().isEmpty()){
   QSqlQuery q;
   QSqlQuery q2;
   QString cant;
   q.exec(QString("SELECT * FROM producto WHERE nombreproducto LIKE '%1'").arg(ui->txtprod->text()));
   q.next();
   cant=q.value(5).toString();//Esta es la cantidad

   int sum=0;
   if(cant.toInt()==0){
       QMessageBox::warning(this,"Aviso","No existe este producto.");
       return;
   }else{
    QString prod=ui->txtprod->text();
    QString c=ui->txtcant->text();

        if(c.toInt()>=cant.toInt()){
            QMessageBox::information(this,"Aviso","No existe la cantidad que solicita. Stock: "+ cant);
            return;
        }else{
            ui->listWidget->addItem(QString(prod + "-Cantidad-" + QString(c)));
            QStringList arrtot=ui->txttotal->text().split(" ");

            if(ui->txttotal->text()!=""){
                 sum=arrtot.value(arrtot.length()-2).toInt()+(q.value(4).toString().toInt()*c.toInt());
                }else {
                sum=q.value(4).toString().toInt()*c.toInt();
                }


            ui->txttotal->setText(QVariant(sum).toString()+" pesos");
            ui->txttotal->show();
            int res=cant.toInt()-c.toInt();

            q2.exec("UPDATE producto SET cantidadExistente ='"+QVariant(res).toString()+"' WHERE nombreproducto ='"+prod+"'");
        }
        }
   }else {
      QMessageBox::information(this,"Aviso","Faltan datos.");
      return;
  }
}

void cajero::on_pushButton_2_clicked()
{
    QSqlQuery q2;
    QSqlQuery q;
    QString cant;

    QList<QListWidgetItem*> items = ui->listWidget->selectedItems();

    foreach(QListWidgetItem* item, items){
        ui->listWidget->removeItemWidget(item);
        QStringList arr=item->text().split("-");

        int c=arr.value(arr.length()-1).toInt();

        QString prod=arr.value(arr.length()-3);

        q.exec(QString("SELECT * FROM producto WHERE nombreproducto LIKE '%1'").arg(prod));
        q.next();
        cant=q.value(5).toString();

        q2.exec("UPDATE producto SET cantidadExistente ='"+QVariant(cant.toInt()+c).toString()+"' WHERE nombreproducto ='"+prod+"'");
        QStringList arrtot=ui->txttotal->text().split(" ");
        if(ui->txttotal->text()!=""){
             sum=arrtot.value(arrtot.length()-2).toInt()-(q.value(4).toString().toInt()*c);
            }


        ui->txttotal->setText(QVariant(sum).toString()+" Pesos");

        delete item;
    }
    ui->listWidget->selectAll();
}


void cajero::on_buttonBox_2_accepted()
{
     if(!ui->txtced->text().isEmpty()&&!ui->txtnombre->text().isEmpty()){
    sum=0;
    QMessageBox::information(this,"Reporte","Se vendio al cliente "+ ui->txtnombre->text()+" el total de: "+ui->txttotal->text());
    ui->txttotal->setText("");
    ui->txtced->setText("");
    ui->txtnombre->setText("");
    ui->txtprod->setText("");
    ui->txtcant->setText("");
    ui->listWidget->clear();
     }else {
         QMessageBox::information(this,"Aviso","Faltan datos.");
         return;
     }
}

void cajero::on_buttonBox_2_rejected()
{
     close();
}