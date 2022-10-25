#ifndef QT_TROLL_H
#define QT_TROLL_H

#include <QMainWindow>
#include <QLabel>

class QtTroll : public QMainWindow
{
    Q_OBJECT
    QTimer *show_timer;
    QTimer *hide_timer;
    QLabel *label;
private slots:
    void showTimerSlot();
    void hideTimerSlot();
public:
    QtTroll();
    void LOL(int i);

    static void preparations();
};

#endif // QT_TROLL_H
