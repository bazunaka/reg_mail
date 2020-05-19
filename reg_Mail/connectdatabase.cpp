#include "connectdatabase.h"

ConnectDatabase::ConnectDatabase()
{

}

QSqlDatabase ConnectDatabase::connectDB(QString drv, QString host, QString drv_str,  QString name, QString usr, QString psw)
{
    db = QSqlDatabase::addDatabase(drv);
    db.setHostName(host);
    db.setDatabaseName("DRIVER={" + drv_str + "};DATABASE=" + name + ";");
    db.setUserName(usr);
    db.setPassword(psw);
    return db;
}
