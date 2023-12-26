#include "settings_window.h"
#include "ui_settings_window.h"

settings_window::settings_window(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::settings_window)
{
    ui->setupUi(this);
    close_button = new QPushButton();
    close_button->setShortcut(Qt::Key_Escape );
    ui->close_button->setObjectName("main_menu_button");
}

settings_window::~settings_window()
{
    delete ui;
}

void settings_window::on_close_button_clicked()
{
    this->close();
}
