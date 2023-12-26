#include "game_window.h"
#include "ui_game_window.h"

game_window::game_window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::game_window)
{
    ui->setupUi(this);
    ui->back_to_main_menu->setObjectName("main_menu_button");
    ui->save_game->setObjectName("main_menu_button");
    ui->load_game->setObjectName("main_menu_button");
    ui->wiki->setObjectName("main_menu_button");

    ui->solar_panel_button->setObjectName("main_menu_button");
    ui->mining_center_button->setObjectName("main_menu_button");
    ui->cancel_button->setObjectName("main_menu_button");
    ui->deconstruct_button->setObjectName("main_menu_button");
    setMouseTracking(true);
    solar_panels_num = 0;
    mining_centers_num = 0;
    money_value_var = 0;
    energy_value_var = 0;
    scene = new QGraphicsScene;
    scene->setBackgroundBrush(QColor(28, 28, 28));
    ui->main_game->setScene(scene);
    current_type = 0;
    qDebug() << scene;
    scene->setSceneRect(0, 0, 1190, 890);

    if(loading_save.size()<2){
        loading_save.push_back("50");
        loading_save.push_back("50");
        load_save(&loading_save);
    }

 QTimer::singleShot(2000, this, SLOT(show_value()));


}

void game_window::show_value(){
    energy_value_var= energy_value_var + solar_panels_num;
    money_value_var = money_value_var + mining_centers_num;

    ui->money_value->setText(QString::number(money_value_var));
    ui->energy_value->setText(QString::number(energy_value_var));
    QTimer::singleShot(2000, this, SLOT(show_value()));
}

game_window::~game_window()
{
    delete ui;
}



void game_window::load_save(std::vector<QString> *cur_str){
    qDebug() << cur_str->size();
    loading_save = *cur_str;
    qDebug() << loading_save.size() << loading_save[0];
        this->build_from_save();

}


void game_window::build_from_save(){
    qDebug() <<"in object: " << loading_save.size();

    if(loading_save.size()>1){
        qDebug() << loading_save[0];

    }


    scene->setBackgroundBrush(QColor(28, 28, 28));
    ui->main_game->setScene(scene);

    qDebug() << "start loading" << loading_save.size();
    if(loading_save.size()>2){
        for(int i = 2; i<loading_save.size();i++){
            qDebug() << i << " : " << loading_save[i];
            QStringList temp = loading_save[i].split(" ");

            if((i-2)%3==0){
                placing_fabric_block(temp[0].toInt(), temp[1].toInt(), temp[2].toInt());
            }
        }
    }



}

void game_window::calculate_dynamic_values(){

}


void game_window::placing_fabric_block(int x, int y, int type){
    switch (type) {
    case 1:
    {

    QPixmap sprite("144.png");
    QGraphicsPixmapItem* spriteItem = new QGraphicsPixmapItem(sprite);
    spriteItem->setPos(x, y);
    scene->addItem(spriteItem);
    solar_panels_num++;
    qDebug() << solar_panels_num << " solar";

    break;
}
    case 2:
{

    QPixmap sprite("145.png");
    QGraphicsPixmapItem* spriteItem = new QGraphicsPixmapItem(sprite);
//    spriteItem->setPixmap(sprite);
    spriteItem->setPos(x, y);
    scene->addItem(spriteItem);
    mining_centers_num++;
    qDebug() <<  mining_centers_num << "mining";
    break;
}    }
}



void game_window::on_back_to_main_menu_clicked()
{

    this->close();
    emit back_to_menu();
}

void game_window::on_save_game_clicked()
{

    save_current_game_window_var = new save_current_game_window(this);
    loading_save[0] = QString::number(money_value_var);
    loading_save[1] = QString::number(energy_value_var);
    qDebug() << "saving" << loading_save[0] << " " << loading_save[1] << " " << QString::number(money_value_var) << " " << QString::number(energy_value_var);

    save_current_game_window_var->set_data(loading_save);
    save_current_game_window_var->showFullScreen();
}

void game_window::on_load_game_clicked()
{
    load_game_window_var = new load_game_window(this);
    load_game_window_var->showFullScreen();
    qDebug() << "load game";
}

void game_window::on_wiki_clicked()
{
    help_browser_var = new help_browser("index.html", this);
    help_browser_var->showFullScreen();
}

void game_window::on_cancel_button_clicked()
{
//    QGraphicsScene scene;
//    QGraphicsView *test;
//    scene.setBackgroundBrush(Qt::black);
//    scene.addEllipse(500, 500, 50, Qt::black);
//    ui->main_game->setScene(&scene);
//    scene.update();
//    test->setBackgroundBrush(Qt::black);

    qDebug() << "cancel";
}


void game_window::handle_click(int x, int y){
    placing_fabric_block(x, y, 0);
    qDebug() << x << y;
}



    void game_window::mousePressEvent(QMouseEvent *event)
    {
        int x = event->x();
        int y = event->y();
        x = ((x-330 + 10) / 100) * 100;
        y = ((y-60 + 10) / 100) * 100;
        qDebug() << "Mouse clicked at x: " << x << " y: " << y;
        loading_save.push_back( QString::number(x) + " " +  QString::number(y) + " " +  QString::number(current_type));
        placing_fabric_block(x,y, current_type);
        // Выводим координаты в диалоговом окне

    }


void game_window::on_solar_panel_button_clicked()
{
    current_type = 1;
}

void game_window::on_mining_center_button_clicked()
{
    current_type = 2;
}

void game_window::on_deconstruct_button_clicked()
{
    current_type = 0;
}
