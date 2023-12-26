#include "help_browser.h"
#include "ui_help_browser.h"

help_browser::help_browser(QString path,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::help_browser)
{
    ui->setupUi(this);

    close_button = new QPushButton();
    close_button->setShortcut(Qt::Key_Escape );
    ui->text_browser->setSource(path);
    ui->close_button->setObjectName("main_menu_button");
    ui->crutch_2->setObjectName("crutch");
}

help_browser::~help_browser()
{
    delete ui;
}


void help_browser::on_close_button_clicked()
{
     this->close();
}
