#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include "UI/subpage/subpage.h"
#include "UI/zwidget/keyboard/keyboard.h"
#include <QValidator>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    virtual bool eventFilter(QObject *watched, QEvent *event);

private:
    void initUI();


private:
    Ui::MainWindow *ui;

    LoginWindow *m_lgW;
    AdminWindow *m_adW;

    Keyboard *m_keyboard;
};
#endif // MAINWINDOW_H
