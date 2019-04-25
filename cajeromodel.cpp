#include "cajeromodel.h"
#include <QSqlTableModel>
#include <QSqlQuery>

cajeroModel::cajeroModel()
{


}

QSqlQuery cajeroModel::query(QString var)
{
    QSqlQuery q;
    QString cant;
    q.exec(QString("SELECT * FROM producto WHERE nombreproducto LIKE '%1'").arg(var));
    q.next();
    return q;
}

QString cajeroModel::consultaCant(QString var)
{
   return QString(query(var).value(5).toString());//Cant existente
}

int cajeroModel::consultaPrecio(QString var)
{
    return query(var).value(4).toInt();//Precio
}

void cajeroModel::actualizar(QString s, QString p)
{
  QSqlQuery q2;
  q2.exec("UPDATE producto SET cantidadExistente ='"+s+"' WHERE nombreproducto ='"+p+"'");

}

QSqlQuery cajeroModel::queryprod()
{
    QSqlQuery query;
    query.exec(QString("SELECT * FROM producto"));
    query.next();
    return query;
}
