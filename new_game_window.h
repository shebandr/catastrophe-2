#ifndef new_game_window_H
#define new_game_window_H

#include <QObject>
#include <QWidget>
#include <QString>
#include <QTextBrowser>
#include <QPushButton>

namespace Ui {
class new_game_window;
}

class new_game_window : public QWidget
{
    Q_OBJECT

public:
    explicit new_game_window(QWidget *parent = 0);
    ~new_game_window();

private slots:
    void on_close_button_clicked();

private:
    Ui::new_game_window *ui;
    QPushButton *close_button;
};

#endif // new_game_window_H
