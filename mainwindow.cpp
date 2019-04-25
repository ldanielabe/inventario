#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "product.h"
#include "cajero.h"
#include "database.h"
#include <QMessageBox>
#include <QSqlQuery>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    dbase("inventario","root","","localhost",3306){
    ui->setupUi(this);

    QString msjErr;

    if(!dbase.conectardb(msjErr)){
     QMessageBox::critical(this,tr("Error"),msjErr);
     close();
    }

    ui->CajeroRadioButton->setChecked(true);

    }

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_buttonBox_accepted()
{


}

void MainWindow::on_btnIngresar_toggled(bool checked)
{
 QMessageBox::warning(this,"Aviso","Holiiiiii");
}

void MainWindow::on_btnIngresar_clicked()
{
    QSqlQuery q;
    int cant;
    QString user=ui->txtUser->text();
    QString pass=ui->txtContra->text();

    if(user.isEmpty()||pass.isEmpty()){
        QMessageBox::warning(this,"Aviso","Faltan datos.");
    }else {
        if(ui->CajeroRadioButton->isChecked()){

            mModelMainWindow=new mainwindowmodel();
            mModelMainWindow->query(user,pass,"cajero");
            cant=mModelMainWindow->consultaCant(user,pass,"cajero");
            if(cant==0){
                QMessageBox::warning(this,"Aviso","Usuario o contraseña incorrectos.");
                return;
            }else{
                cajero d(this);
                d.exec();
            }
        }else{
            QSqlQuery q;
            int cant;

                mModelMainWindow->query(user,pass,"administrador");
                cant=mModelMainWindow->consultaCant(user,pass,"administrador");
                if(cant==0){
                    QMessageBox::warning(this,"Aviso","Usuario o contraseña incorrectos.");
                    return;
                }else{
                    product d(this);
                    d.exec();
                }
        }
}
}
