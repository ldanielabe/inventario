#ifndef CAJEROMODEL_H
#define CAJEROMODEL_H

#include <iostream>
#include <QString>
#include <QSqlQuery>

using namespace std;

class cajeroModel
{
public:
    cajeroModel();
    QSqlQuery query(QString var);
    QString consultaCant(QString var);
    int consultaPrecio(QString var);
    void actualizar(QString s, QString p);
    QSqlQuery queryprod();
private:


};

#endif // CAJEROMODEL_H
