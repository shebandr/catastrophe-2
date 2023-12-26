#ifndef SETTINGS_WINDOW_H
#define SETTINGS_WINDOW_H

#include <QObject>
#include <QWidget>
#include <QString>
#include <QTextBrowser>
#include <QPushButton>

namespace Ui {
class settings_window;
}

class settings_window : public QWidget
{
    Q_OBJECT

public:
    explicit settings_window(QWidget *parent = 0);
    ~settings_window();

private slots:
    void on_close_button_clicked();

private:
    Ui::settings_window *ui;
    QPushButton *close_button;
};

#endif // SETTINGS_WINDOW_H
