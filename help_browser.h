#ifndef HELP_BROWSER_H
#define HELP_BROWSER_H


#include <QObject>
#include <QWidget>
#include <QString>
#include <QTextBrowser>
#include <QPushButton>

namespace Ui {
class help_browser;
}

class help_browser : public QWidget
{
    Q_OBJECT

public:
    explicit help_browser(QString path, QWidget *parent = 0);
    ~help_browser();
    static void show_page();
private slots:
    void on_close_button_clicked();

private:
    Ui::help_browser *ui;
    QTextBrowser *text_browser;
    QPushButton *close_button;
    void close_button_func();
};

#endif // HELP_BROWSER_H
