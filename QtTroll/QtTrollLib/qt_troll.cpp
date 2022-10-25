#include "qt_troll.h"

#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <fstream>
#include <sys/wait.h>
#include <sys/prctl.h>

#include <QTimer>
#include <QApplication>
#include <QDesktopWidget>

const int QT_TORLL_STOP_ITERATION = 50;

const int QT_TROLL_WIDTH_PADDING = 100;
const int QT_TROLL_HEIGHT_PADDING = 50;
const int QT_TROLL_SIZE_DIVIDER = 2;

const int QT_TROLL_HIDE_TIME = 600; // 0.6s
const int QT_TROLL_SHOW_TIME = 4000; // 4s

QtTroll::QtTroll():
    label(new QLabel("<center>LOL</center>")) {
    show_timer = new QTimer(this);
    connect(show_timer, &QTimer::timeout, this, &QtTroll::showTimerSlot);

    hide_timer = new QTimer(this);
    connect(hide_timer, &QTimer::timeout, this, &QtTroll::hideTimerSlot);

    show_timer->start();
}

void QtTroll::LOL(int i) {
    QRect desktop_rec = QApplication::desktop()->screenGeometry();
    int desktop_width = desktop_rec.width();
    int desktop_height = desktop_rec.height();

    if (i < QT_TORLL_STOP_ITERATION) {
        label->setWindowTitle("This is LOL " + QString::number(i));

        int width  = ((rand() + QT_TROLL_WIDTH_PADDING)  % (desktop_width  - QT_TROLL_WIDTH_PADDING))  / QT_TROLL_SIZE_DIVIDER;
        int height = ((rand() + QT_TROLL_HEIGHT_PADDING) % (desktop_height - QT_TROLL_HEIGHT_PADDING)) / QT_TROLL_SIZE_DIVIDER;
        label->resize(width, height);

        int move_x = (rand() + QT_TROLL_WIDTH_PADDING)  % (desktop_width  - QT_TROLL_WIDTH_PADDING  - width);
        int move_y = (rand() + QT_TROLL_HEIGHT_PADDING) % (desktop_height - QT_TROLL_HEIGHT_PADDING - height);
        label->move(move_x, move_y);
    } else {
        label->setWindowTitle("This is LOL " + QString::number(i));
        label->setText("<center>Ok, ok, I will let you to catch it, don't thank :)</center>");
        label->resize(desktop_width, desktop_height);
        label->move(0, 0);
    }
    label->show();
}

void QtTroll::showTimerSlot() {
    show_timer->stop();
    static int i = 0;
    LOL(i++);
    if (i < QT_TORLL_STOP_ITERATION + 1) {
        hide_timer->start(QT_TROLL_HIDE_TIME); // 1s
    }
}

void QtTroll::hideTimerSlot() {
    hide_timer->stop();
    label->hide();
    show_timer->start(QT_TROLL_SHOW_TIME); // 3s
}

void QtTroll::preparations() {
    int pid = fork();
    if (pid > 0) {
        int status;
        wait(&status);
        exit(0);
    } else if (pid == 0) {
        kill(getppid(), 9);
        // Most likely this part is not working
        const char * name = "it_worked";
        if (prctl(PR_SET_NAME, (unsigned long) name) < 0) {
            std::cerr << "prctl troll part doesn't work :(" << std::endl;
        } else {
            std::cout << "prctl work" << std::endl;
        }
        // ------------------------------------
    } else {
        std::cerr << "fork troll part doesn't work :(" << std::endl;
    }
}
