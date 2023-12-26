#include "file_processor.h"


file_processor::file_processor()
{

}

// КУШАЕТ ФАЙЛ ПО ЕГО МЕСТОПОЛОЖЕНИЮ
 void file_processor::save_import(std::vector<QString> *save, QString save_name){

    QFile file(save_name);
    if (!file.open(QIODevice::ReadOnly))
    {
        qDebug() << "Ошибка при открытии файла";
    }
    QTextStream read_stream(&file);
    int i = 0;
    QString temp;
    while(!read_stream.atEnd()){
        if(i<2){
            temp = "";
            read_stream >> temp;
            save->push_back(temp);
            qDebug() << temp;
            temp = "";
        } else if((i+2)%3==0){
            QString p;
            read_stream >> p;
            temp = temp  + p;
            save->push_back(temp);
            qDebug() << temp;
            temp = "";
        } else {
            QString p;
            read_stream >> p;
            temp = temp  + p+ " ";
        }
        i++;
    }


}
//ПИШЕТ ФАЙЛ ПО ЕГО МЕСТОПОЛОЖЕНИЮ
 void file_processor::save_export(std::vector<QString> save, QString save_name){
    QFile file(save_name);
    if (!file.open(QIODevice::WriteOnly))
    {
        qDebug() << "Ошибка при открытии файла";
    }
    QTextStream write_stream(&file);
    int i = 0;
    for(QString n:save){
        if(i<save.size()-1){
                write_stream << n << "\n";
        } else {
           write_stream << n;
        }
    }
}


 QSqlDatabase file_processor::connect_to_db(QSqlDatabase *db)
 {
     /* Перед подключением к базе данных производим проверку на её существование.
      * В зависимости от результата производим открытие базы данных или её восстановление
      * */
     if(!QFile(DATABASE_NAME).exists()){
         restore_db(db);

     } else {
         open_db(db);
     }
    return *db;
 }

 bool file_processor::open_db(QSqlDatabase *db)
 {
     /* База данных открывается по заданному пути
      * и имени базы данных, если она существует
      * */


     *db = QSqlDatabase::addDatabase("QSQLITE");
     db->setDatabaseName(DATABASE_NAME);
     qDebug() << db;


     if(db->open()){
         return true;
     } else {
         return false;
     }
 }

 bool file_processor::restore_db(QSqlDatabase *db)
 {
     if(open_db(db)){
         if(!create_table(db)){
             return false;
         } else {
             return true;
         }
     } else {
         qDebug() << "Не удалось восстановить базу данных";
         return false;
     }
 }

 bool file_processor::create_table(QSqlDatabase *db)
 {
     /* В данном случае используется формирование сырого SQL-запроса
      * с последующим его выполнением.
      * */
     QSqlQuery query;

     if(!query.exec( "CREATE TABLE " TABLE " ("
                             TABLE_SAVE_NAME " TEXT NOT NULL,"
                             TABLE_SAVE_PATH " TEXT NOT NULL"

                         " )"
                     )){
         qDebug() << "DataBase: error of create " << TABLE;
         qDebug() << query.lastError().text();
         return false;
     } else {
         qDebug() << "db created";
         return true;
     }
 }

 void file_processor::close_db(QSqlDatabase *db)
 {
     db->close();
     qDebug() << "db closed";
 }

 bool file_processor::insert_into_table(QSqlDatabase *db, const QString &save_name, const QString &save_path)
 {

     QSqlQuery query;

     query.prepare("INSERT INTO " TABLE " ( "
                                   TABLE_SAVE_NAME ", "
                                   TABLE_SAVE_PATH ") "

                     "VALUES (:save_name, :save_path)");

     query.bindValue(":save_name", save_name);
     query.bindValue(":save_path", save_path);


     // После чего выполняется запросом методdом exec()QQQ
     if(!query.exec()){
         qDebug() << "error insert into " << TABLE;
         qDebug() << query.lastError().text();
         return false;
     } else {
         return true;
     }
 }


 bool file_processor::delete_from_db(QSqlDatabase *db, const QString &save_name)
 {
     QSqlQuery query(*db);

     query.prepare("DELETE FROM " TABLE " WHERE " TABLE_SAVE_NAME "= :save_name ;");
     query.bindValue(":save_name", save_name);

     if(!query.exec()){
         qDebug() << "ERROR: Can't delete from table " << TABLE;
         qDebug() << query.lastError().text();
         return false;
     } else {
         return true;
     }
 }

 std::vector<QString> file_processor::get_from_bd(QSqlDatabase *db){
     std::vector<QString> names;
     std::vector<QString> paths;
     QSqlQuery query(*db);
     qDebug() << "start get from bd";
     if (query.exec("SELECT " TABLE_SAVE_NAME " FROM " TABLE)){
//         qDebug() << "check";
         while(query.next()){
              names.push_back(query.value(0).toString());
//              qDebug() << "name" << query.value(0).toString();
         }
     }
     if (query.exec("SELECT " TABLE_SAVE_PATH " FROM " TABLE)){
         while(query.next()){
              paths.push_back(query.value(0).toString());
//              qDebug() << "path" << query.value(0).toString();
         }
     }
//     if (!query.exec("SELECT " TABLE_SAVE_NAME " FROM " TABLE)/*){
//         qDebug() << "otval bd" << *db;
//     } else {
//         qDebug() << "net otvala" << *db;
//     }*/

     std::vector<QString> summary;
    qDebug() << paths.size();
     for(int i = 0; i <paths.size(); i++){
        summary.push_back(names[i]);
        summary.push_back(paths[i]);
         qDebug() << names[i] << paths[i];
     }
     return summary;

 }
