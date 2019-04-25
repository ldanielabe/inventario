#include "mainwindowmodel.h"
#include <QSqlTableModel>
#include <QSqlQuery>

mainwindowmodel::mainwindowmodel()
{


}

QSqlQuery mainwindowmodel::query(QString user, QString pass, QString rol)
{
     QSqlQuery q;
     q.exec(QString("SELECT count(*) FROM usuario WHERE idusuario LIKE '%1' AND contra LIKE '%2' AND rol LIKE '%3'")
               .arg(user)
               .arg(pass)
               .arg(rol));

      q.next();
      return q;
}

int mainwindowmodel::consultaCant(QString user, QString pass, QString rol)
{
    return query(user,pass,rol).value(0).toInt();
}
