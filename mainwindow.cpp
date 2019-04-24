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
    dbase("inventario","root","","localhost",3306)
{
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

/*void MainWindow::on_actionQuitar_Aplicacion_triggered()
{
    close();
}
*/

/*void MainWindow::on_actionAgregar_triggered()
{
    product d(this);
    d.exec();
}*/

void MainWindow::on_btnIngresar_clicked()
{


}



void MainWindow::on_btnIngresar_pressed()
{
    QMessageBox::warning(this,"Aviso","holiii.");
}

void MainWindow::on_buttonBox_accepted()
{
    QSqlQuery q;
    int cant;

    if(ui->CajeroRadioButton->isChecked()){
        q.exec(QString("SELECT count(*) FROM usuario WHERE idusuario LIKE '%1' AND contra LIKE '%2' AND rol LIKE '%3'")
               .arg(ui->txtUser->text())
               .arg(ui->txtContra->text())
               .arg("cajero"));

        q.next();
        cant=q.value(0).toInt();
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
        q.exec(QString("SELECT count(*) FROM usuario WHERE idusuario LIKE '%1' AND contra LIKE '%2' AND rol LIKE '%3'")
                   .arg(ui->txtUser->text())
                   .arg(ui->txtContra->text())
                   .arg("administrador"));

            q.next();
            cant=q.value(0).toInt();
            if(cant==0){
                QMessageBox::warning(this,"Aviso","Usuario o contraseña incorrectos.");
                return;
            }else{
                product d(this);
                d.exec();
            }
    }
}
