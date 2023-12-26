#ifndef SAVE_CURRENT_GAME_WINDOW_H
#define SAVE_CURRENT_GAME_WINDOW_H

#include <QWidget>
#include <QDebug>
#include <QString>
#include <vector>
#include <QSqlDatabase>
#include "file_processor.h"

namespace Ui {
class save_current_game_window;
}

class save_current_game_window : public QWidget
{
    Q_OBJECT

public:
    explicit save_current_game_window(QWidget *parent = 0, std::vector<QString> cur_save = {});
    ~save_current_game_window();
    void set_data(std::vector<QString> saving_data);
private slots:
    void on_close_button_clicked();

    void on_save_button_clicked();

private:
    Ui::save_current_game_window *ui;
    file_processor *file_processor_var;
    std::vector<QString> current_save;
};

#endif // SAVE_CURRENT_GAME_WINDOW_H
