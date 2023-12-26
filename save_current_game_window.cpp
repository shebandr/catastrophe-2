#include "save_current_game_window.h"
#include "ui_save_current_game_window.h"

save_current_game_window::save_current_game_window(QWidget *parent, std::vector<QString> cur_save) :
    QWidget(parent),
    ui(new Ui::save_current_game_window)
{
    ui->setupUi(this);
    ui->close_button->setObjectName("main_menu_button");
    ui->save_button->setObjectName("main_menu_button");
    current_save = cur_save;
    ui->label->hide();
}

save_current_game_window::~save_current_game_window()
{
    delete ui;
}

void save_current_game_window::on_close_button_clicked()
{
    this->close();
}

void save_current_game_window::on_save_button_clicked()
{
    ui->label->hide();
    QString new_name = ui->save_text_edit->toPlainText();
    QString new_path = new_name + ".cum";
    QSqlDatabase db;
    db = file_processor_var->connect_to_db(&db);
    std::vector<QString> all_saves_var = file_processor_var->get_from_bd(&db);
    int flag = 1;
    for(int i = 0; i<all_saves_var.size(); i++){
        if(i%2==0){
            if(all_saves_var[i]==new_name){
                flag = 0;
            }
        }
    }
    if(flag){
        file_processor_var->save_export(current_save, new_path);
        file_processor_var->insert_into_table(&db, new_name, new_path);
    }else{
        ui->label->show();
    }

    qDebug() << new_path;
}

void save_current_game_window::set_data(std::vector<QString> saving_data){
    current_save = saving_data;
}
