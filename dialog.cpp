#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    num = 0;
    m_timer = new QTimer(this);
    connect(m_timer, SIGNAL(timeout()), this, SLOT(myTimer()));
    m_timer -> start(1000);
}

Dialog::~Dialog()
{
    delete ui;
    m_timer -> stop();
}

void Dialog::myTimer()
{
    ui->label->setNum(num++);
    qDebug() << "myTimer...";
}

