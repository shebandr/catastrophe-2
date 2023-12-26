#include "new_game_window.h"
#include "ui_new_game_window.h"

new_game_window::new_game_window(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::new_game_window)
{
    ui->setupUi(this);
    close_button = new QPushButton();
    close_button->setShortcut(Qt::Key_Escape );

    ui->close_button->setObjectName("main_menu_button");
}

new_game_window::~new_game_window()
{
    delete ui;
}

void new_game_window::on_close_button_clicked()
{
    this->close();
}
