#include "mainwindow.h"
#include <QApplication>
#include <QString>
#include <QCoreApplication>
#include <QDebug>
#include <QFile>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QString path_css = QCoreApplication::applicationDirPath () ;
    QFile file_css(path_css + "/styles.css");
    file_css.open(QFile::ReadOnly);
    QString strCSS = QLatin1String(file_css.readAll());
    a.setStyleSheet(strCSS);
    w.showFullScreen();
    return a.exec();
}
