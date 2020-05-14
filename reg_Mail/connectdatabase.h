#ifndef CONNECTDATABASE_H
#define CONNECTDATABASE_H
#include <QString>
#include <QSettings>
#include <QSqlDatabase>

class ConnectDatabase
{
    protected:

    public:
    ConnectDatabase();

    QSettings *settings;
    QSqlDatabase db;
    QString db_driver, db_driver_string, db_host, db_name, db_user, db_password;

    void connectDB(QString, QString, QString, QString, QString, QString);
};

#endif // CONNECTDATABASE_H
