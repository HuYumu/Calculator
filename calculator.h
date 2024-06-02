#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QWidget>
#include "stack.h"


QT_BEGIN_NAMESPACE
namespace Ui { class Calculator; }
QT_END_NAMESPACE

class Calculator : public QWidget
{
    Q_OBJECT

public:
    Calculator(QWidget *parent = nullptr);
    ~Calculator();

private slots:
    void on_num1_clicked();

    void on_num2_clicked();

    void on_num3_clicked();

    void on_num4_clicked();

    void on_num5_clicked();

    void on_num6_clicked();

    void on_num7_clicked();

    void on_num8_clicked();

    void on_num9_clicked();

    void on_num0_clicked();

    void on_clear_clicked();

    void on_op8_clicked();

    void on_op1_clicked();

    void on_op2_clicked();

    void on_op3_clicked();

    void on_op4_clicked();

    void on_op5_clicked();

    void on_op6_clicked();

    void on_op7_clicked();

    void on_op9_clicked();

    void on_op10_clicked();


private:
    QString in;
    QString ret;
    QString eroMsg;
    Ui::Calculator *ui;
    int priority(char);
    int subCount(int ,int ,int);
    void startCount(Stack<int>&, Stack<int>&);
    bool calculate(std::string,int&);
};
#endif
