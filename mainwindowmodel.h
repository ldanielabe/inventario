#ifndef MAINWINDOWMODEL_H
#define MAINWINDOWMODEL_H
#include <iostream>
#include <QString>
#include <QSqlQuery>

class mainwindowmodel
{
public:
    mainwindowmodel();

    QSqlQuery query(QString user, QString pass, QString rol);
    int consultaCant(QString user, QString pass, QString rol);

private:
};

#endif // MAINWINDOWMODEL_H
