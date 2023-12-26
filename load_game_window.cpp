#include "load_game_window.h"
#include "ui_load_game_window.h"
#include "file_processor.h"
#include "game_window.h"
#include <QDebug>

load_game_window::load_game_window(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::load_game_window)
{
    ui->setupUi(this);
    close_button = new QPushButton();
    close_button->setShortcut(Qt::Key_Escape );

    ui->close_button->setObjectName("main_menu_button");
    ui->crutch_2->setObjectName("crutch");


    QSqlDatabase db;
    db = file_processor_var->connect_to_db(&db);
//    file_processor_var->insert_into_table(&db, "third game", "szg.sd");
    all_saves_var = file_processor_var->get_from_bd(&db);
//    qDebug() << all_saves_var.size();


    for(int i = 0; i<all_saves_var.size(); i++){
        if(i%2==0){
//            qDebug() << "start fill table" << i << "iteration";
            QListWidgetItem *new_item = new QListWidgetItem(all_saves_var[i]);
//            qDebug() << "a";
        ui->saves_table->addItem(new_item);
        }
    }
}

load_game_window::~load_game_window()
{
    delete ui;
}

void load_game_window::on_close_button_clicked()
{
    this->close();
}


void load_game_window::on_saves_table_itemClicked(QListWidgetItem *item)
{
    QString text = item->data(0).toString();
//    qDebug() << text;
    int index = 0;
    for(int i = 0; i<all_saves_var.size();i++){
        if(i%2==0){
            if(text==all_saves_var[i]){
//                qDebug() << i;
                index = i;
                break;
            }
        }
    }
    qDebug() << all_saves_var[index] << all_saves_var[index+1];
    std::vector<QString> loading_save;
    file_processor_var->save_import(&loading_save, all_saves_var[index+1]);
    game_window *game_window_var = new game_window();
    game_window_var->load_save(&loading_save);
    game_window_var->showFullScreen();
    this->close();
}
