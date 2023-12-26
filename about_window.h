#ifndef ABOUT_WINDOW_H
#define ABOUT_WINDOW_H

#include <QObject>
#include <QWidget>
#include <QString>
#include <QTextBrowser>
#include <QPushButton>

namespace Ui {
class about_window;
}

class about_window : public QWidget
{
    Q_OBJECT

public:
    explicit about_window(QString path, QWidget *parent = 0);
    ~about_window();

private slots:
    void on_close_button_clicked();

private:
    Ui::about_window *ui;
    QTextBrowser *text_browser;
    QPushButton *close_button;
};

#endif // ABOUT_WINDOW_H
