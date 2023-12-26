#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "game_window.h"
#include "help_browser.h"
#include "load_game_window.h"
#include "new_game_window.h"
#include "settings_window.h"
#include "about_window.h"
#include "file_processor.h"
#include <qwidget.h>
#include "file_processor.h"
#include <QSqlDatabase>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_main_menu_button_clicked();

    void on_main_menu_button_2_clicked();

    void on_main_menu_button_3_clicked();

    void on_main_menu_button_4_clicked();

    void on_main_menu_button_5_clicked();

    void on_main_menu_button_6_clicked();

    void on_main_menu_button_7_clicked();

    void on_main_menu_wiki_anchorClicked(const QUrl &arg1);

private:
    Ui::MainWindow *ui;
    game_window *game_window_var;
    help_browser *help_browser_var;
    load_game_window *load_game_window_var;
    new_game_window *new_game_window_var;
    settings_window *settings_window_var;
    about_window *about_window_var;
    file_processor *file_processor_var;

};

#endif // MAINWINDOW_H
