#ifndef LOAD_GAME_WINDOW_H
#define LOAD_GAME_WINDOW_H

#include <QObject>
#include <QWidget>
#include <QString>
#include <QTextBrowser>
#include <QPushButton>
#include <QSqlDatabase>
#include <QTableWidgetItem>
#include <QListWidget>

#include "file_processor.h"
#include <vector>
namespace Ui {
class load_game_window ;
}

class load_game_window : public QWidget
{
    Q_OBJECT

public:
    explicit load_game_window(QWidget *parent = 0);
    ~load_game_window();
    file_processor *file_processor_var;
private slots:
    void on_close_button_clicked();


    void on_saves_table_itemClicked(QListWidgetItem *item);

private:
    Ui::load_game_window *ui;
    QPushButton *close_button;
    std::vector<QString> all_saves_var;

};

#endif // LOAD_GAME_WINDOW_H
