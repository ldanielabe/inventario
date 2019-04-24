#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlDatabase>

class database
{
public:
    database(const QString &nombreBD,
             const QString &nombreUser,
             const QString &nombreContra,
             const QString &direccionServer,
             int puerto);
    bool conectardb(QString &mensaje);
private:
    QSqlDatabase db;
};

#endif // DATABASE_H
