#include "demo.h"
#include "ui_demo.h"

demo::demo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::demo)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentWidget(ui->page_1);
    ui->stackedWidget_2->setCurrentWidget(ui->page);
    ui->stackedWidget->setAnimation(QEasingCurve::Type::OutQuart);
    ui->stackedWidget->setSpeed(300);
    connect(ui->prev,&QAbstractButton::clicked,[this]{
        if(ui->stackedWidget->slideInPrev()){
            ui->prev->setEnabled(false);
            ui->next->setEnabled(false);
        }
    });
    connect(ui->next,&QAbstractButton::clicked,[this]{
        if(ui->stackedWidget->slideInNext()){
            ui->prev->setEnabled(false);
           ui->next->setEnabled(false);
        }
    });
    connect(ui->stackedWidget,&SlidingStackedWidget::animationFinished,[this]{
        ui->prev->setEnabled(true);
        ui->next->setEnabled(true);
    });
}

demo::~demo()
{
    delete ui;
}

void demo::on_nestedGoToPage2_clicked()
{
    ui->stackedWidget_2->slideInNext();
}

void demo::on_nestedGoToPage1_clicked()
{
    ui->stackedWidget_2->slideInPrev();
}
