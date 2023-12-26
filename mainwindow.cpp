#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "help_browser.h"
#include "load_game_window.h"
#include "new_game_window.h"
#include <QGridLayout>
#include <QString>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->main_menu_button_2->setObjectName("main_menu_button");
    ui->main_menu_button_4->setObjectName("main_menu_button");
    ui->main_menu_button_5->setObjectName("main_menu_button");
    ui->main_menu_button_6->setObjectName("main_menu_button");
    ui->main_menu_button_7->setObjectName("main_menu_button");
    game_window_var = new game_window();
    connect(game_window_var, &game_window::back_to_menu, this, &MainWindow::show );
    QSqlDatabase db;
    file_processor_var->connect_to_db(&db);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_main_menu_button_clicked()
{
    // ТУТ НАДО СДЕЛАТЬ ЗАГРУЗКУ СЕЙВА

    std::vector<QString> last_save;
    QSqlDatabase db;
    db = file_processor_var->connect_to_db(&db);
    std::vector<QString> all_saves_var = file_processor_var->get_from_bd(&db);
    file_processor_var->save_import(&last_save, all_saves_var[all_saves_var.size()-1]);
    qDebug() << "continue load: " << last_save.size() << last_save[0]<< last_save[1];
    game_window_var->load_save(&last_save);
    game_window_var->showFullScreen();
    this->close();
    qDebug() << "pressed continue";
}

void MainWindow::on_main_menu_button_2_clicked()
{

    game_window_var->showFullScreen();
    this->close();
    qDebug() << "pressed new game";
}

void MainWindow::on_main_menu_button_3_clicked()
{
    settings_window_var = new settings_window(this);
    settings_window_var->showFullScreen();
    qDebug() << "settings";
}

void MainWindow::on_main_menu_button_4_clicked()
{
//    help_browser_var = new help_browser(QCoreApplication::applicationDirPath () + "/cw/index.html", this);
    help_browser_var = new help_browser("index.html", this);
    help_browser_var->showFullScreen();
    qDebug() << "wiki";
}

void MainWindow::on_main_menu_button_5_clicked()
{
    about_window_var = new about_window("about.html", this);
    about_window_var->showFullScreen();
    qDebug() << "about";
}

void MainWindow::on_main_menu_button_6_clicked()
{
    qDebug() << "exit";
    exit(0);
}

void MainWindow::on_main_menu_button_7_clicked()
{

    load_game_window_var = new load_game_window(this);
    load_game_window_var->showFullScreen();
    qDebug() << "load game";
}

void MainWindow::on_main_menu_wiki_anchorClicked(const QUrl &arg1)
{

}
