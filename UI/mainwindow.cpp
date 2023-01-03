#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_loginwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    initUI();
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::eventFilter(QObject *watched, QEvent *event)
{
    if(watched == m_lgW && event->type() == QEvent::MouseButtonPress)
    {
        m_lgW->setFocus();
        if(m_keyboard->state())
        {
            m_keyboard->popIn(0, this->height()/3);
        }
    }
    else if(watched == m_lgW->ui->userNameLineEdit && event->type() == QEvent::MouseButtonPress)
    {
        m_lgW->ui->userNameLineEdit->setFocus();
        if(!m_keyboard->state())
        {
            m_keyboard->popUp(0, this->height()/3);
        }
    }
    else if (watched == m_lgW->ui->passwordLineEdit && event->type() == QEvent::MouseButtonPress)
    {
        m_lgW->ui->passwordLineEdit->setFocus();
        if(!m_keyboard->state())    //隐藏->弹出
        {
            m_keyboard->popUp(0, this->height()/3);
        }
    }

    return QWidget::eventFilter(watched, event);
}

void MainWindow::initUI()
{
    m_lgW = new LoginWindow(this);
//    m_adW = new AdminWindow(this);

    m_keyboard = new Keyboard(this);
}

