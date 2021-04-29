#ifndef DEMO_H
#define DEMO_H

#include <QDialog>

namespace Ui {
class demo;
}

class demo : public QDialog
{
    Q_OBJECT

public:
    explicit demo(QWidget *parent = nullptr);
    ~demo();

private slots:
    void on_nestedGoToPage2_clicked();

    void on_nestedGoToPage1_clicked();

private:
    Ui::demo *ui;
};

#endif // DEMO_H
