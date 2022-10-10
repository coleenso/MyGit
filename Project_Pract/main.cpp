#include "main_window.h"

#include <QApplication>
#include <QFile>

int main(int argc, char *argv[]) {
    setlocale(LC_ALL, "Russian");
    QApplication application(argc, argv);

    QFile qssFile("style_2.qss");
    qssFile.open(QFile::ReadOnly); // Открыть только для чтения
    if (qssFile.isOpen()) {
        QString qss = QLatin1String(qssFile.readAll());
        application.setStyleSheet(qss);
        qssFile.close();
    } else {
        qDebug() << "Не может открыть файл";
    }

    MainWindow window;
    window.show();
    return application.exec();
}
