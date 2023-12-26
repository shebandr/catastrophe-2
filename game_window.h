#ifndef GAME_WINDOW_H
#define GAME_WINDOW_H

#include <QMainWindow>
#include <QDebug>
#include "load_game_window.h"
#include <QString>
#include <vector>
#include "file_processor.h"
#include "help_browser.h"
#include "save_current_game_window.h"
#include "QColor"
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QMouseEvent>
#include <QGraphicsView>
#include <QGraphicsSceneMouseEvent>
#include <QTimer>
#include <QApplication>
#include <QObject>
#include <string>
#include <iostream>
namespace Ui {
class game_window;
}

class game_window :  public QMainWindow
{
    Q_OBJECT

public:
    explicit game_window(QWidget *parent = 0);
    ~game_window();
    void load_save(std::vector<QString> *cur_str);
    void build_from_save();
    void calculate_dynamic_values();
    void placing_fabric_block(int x, int y, int type);

signals:
    void back_to_menu();

public slots:
    void handle_click(int x, int y);
    void show_value();
private slots:

    void on_back_to_main_menu_clicked();

    void on_save_game_clicked();

    void on_load_game_clicked();

    void on_wiki_clicked();

    void on_cancel_button_clicked();

    void on_solar_panel_button_clicked();

    void on_mining_center_button_clicked();

    void on_deconstruct_button_clicked();

private:
    Ui::game_window *ui;
    help_browser *help_browser_var;
    load_game_window *load_game_window_var;
    save_current_game_window *save_current_game_window_var;
    std::vector<QString> loading_save;
    int money_value_var;
    int energy_value_var;
    int solar_panels_num;
    int mining_centers_num;
    QGraphicsScene *scene;
    int current_type;

protected:
    void mousePressEvent(QMouseEvent *event) override;

};

#endif // GAME_WINDOW_H
