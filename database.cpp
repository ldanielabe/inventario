#include "database.h"
#include "QSqlDatabase"
#include <QSqlError>
#include <QtSql>
#include <QSqlDatabase>

database::database(const QString &nombreBD,
                   const QString &user,
                   const QString &contra,
                   const QString &direccionServer,
                   int puerto){
   db=QSqlDatabase::addDatabase("QMYSQL");
   db.setDatabaseName(nombreBD);
   db.setUserName(user);
   db.setPassword(contra);
   db.setHostName(direccionServer);
   db.setPort(puerto);

}

bool database::conectardb(QString &mensaje){
    if(!db.open()){
               mensaje= db.lastError().text();
               return false;
           }

           return true;
}
