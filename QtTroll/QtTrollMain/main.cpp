#include <iostream>
#include "../QtTrollLib/qt_troll.h"
#include <sys/wait.h>

#include <QApplication>

int main(int argc, char* argv[]) {
    QtTroll::preparations();
    QApplication a(argc, argv);
    QtTroll t;
    return a.exec();
}
