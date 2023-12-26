#include "about_window.h"
#include "ui_about_window.h"

about_window::about_window(QString path, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::about_window)
{
    ui->setupUi(this);
    close_button = new QPushButton();
    close_button->setShortcut(Qt::Key_Escape );
    ui->text_browser->setSource(path);
    ui->close_button->setObjectName("main_menu_button");
}

about_window::~about_window()
{
    delete ui;
}

void about_window::on_close_button_clicked()
{
    this->close();
}
