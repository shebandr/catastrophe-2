#ifndef FILE_PROCESSOR_H
#define FILE_PROCESSOR_H
#include <vector>
#include <qfile.h>
#include <qdir.h>
#include <QString>
#include <QSql>
#include <QSqlDatabase>



#include <QObject>

#include <QSqlQuery>
#include <QSqlError>

#include <QFile>

#include <QDebug>



#define DATABASE_NAME "db_catastrophe.db"

#define TABLE "SAVES"

#define TABLE_SAVE_NAME "save_name"
#define TABLE_SAVE_PATH "save_path"

class file_processor
{
public:
    file_processor();
    void save_import(std::vector<QString> *save, QString save_name);
    void save_export(std::vector<QString> save, QString save_name);
    void db_saves_load();
    bool open_db(QSqlDatabase *db);
    bool restore_db(QSqlDatabase *db);
    void close_db(QSqlDatabase *db);
    bool create_table(QSqlDatabase *db);
    QSqlDatabase connect_to_db(QSqlDatabase *db);
    bool insert_into_table(QSqlDatabase *db, const QString &save_name, const QString &save_path);
    bool delete_from_db(QSqlDatabase *db, const QString &save_name);
    std::vector<QString> get_from_bd(QSqlDatabase *db);
private:

};

#endif // FILE_PROCESSOR_H
