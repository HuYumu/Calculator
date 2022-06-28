#include "calculator.h"
#include "ui_calculator.h"
#include "stack.cpp"
Calculator::Calculator(QWidget *parent): QWidget(parent), ui(new Ui::Calculator)
{
    in = "";
    ret = "";
    ui->setupUi(this);
}

Calculator::~Calculator()
{
    delete ui;
}

int Calculator::priority(char op){
    switch(op){
        case '(': return 0;
        case '-': return 1;
        case '+': return 2;
        case '/': return 3;
        case '*': return 4;
        case '|': return 5;
        case '&': return 6;
        case '!': return 7;
    }
    return -2;
}

int Calculator::subCount(int op,int num1,int num2){
        switch(op){
            case 1: {
                num2=num1-num2;
                break;
            }
            case 2: {
                num2=num1+num2;
                break;
            }

            case 3: {
                if(!num2){
                    throw "被除数不得为0";
                }
                num2=num1/num2;
                break;
            }
            case 4: {
                num2=num1*num2;
                break;
            }
            case 5:{
                num2 = num1||num2;
                break;
            }
            case 6:{
                num2 = num1&&num2;
                break;
            }
            case 7:{
                num2 = !num2;
                break;
            }
        }
        return num2;
}

void Calculator::startCount(Stack<int>& ops,Stack<int>& nums){
    int op = 0, num1 = 0, num2 = 0;
    ops.top(op);
    ops.pop();
    nums.top(num2);
    nums.pop();
    if(op != 7){
        nums.top(num1);
        nums.pop();
    }
    nums.push(subCount(op,num1,num2));
    ops.top(op);
}

bool Calculator::calculate(std::string s,int &ret){
    Stack<int> ops(20);
    Stack<int> nums(20);
    int count=0,op=0,num=0;
    int pos=0;
    ops.push(-1);
    s += "#";
    try{
        while(s[pos]!='#'){//遍历字符串
            if(s[pos]>47&&s[pos]<58){//数字
                if(count > 0){
                    if(num == 0 && s[pos]>47&&s[pos]<58){
                        throw "数字0后不得有数字";
                    }//排错1
                    num *= 10;//移位
                }
                num += (int)(s[pos]-48);
                ++pos;
                ++count;
            }
            else{//符号
                if(count){
                    nums.push(num);
                    num = 0;
                    count = 0;
                }//说明之前的数字已经录完,入栈
                if(s[pos]==')'){
                    ops.top(op);
                    while(op>0){
                        startCount(ops,nums);
                        ops.top(op);
                    }
                    ops.pop();
                    ++pos;
                    continue;
                }
                op=priority(s[pos]);
                if(op == -2){
                    throw "当前符号格式错误";
                }//排错2

                if(op == 5 || op == 6){
                    ++pos;
                }//解决&&占两个字符的情况

                if(s[pos+1]!='('&s[pos+1]<48||s[pos+1]>57){
                    throw "+-*/&||(!不能还是+-*/&||)!";
                }//排错3
                int temp_op;
                ops.top(temp_op);
                if(op == 0 || op>temp_op){
                    ops.push(op);
                    ++pos;
                }//比栈顶符号优先级高就压入
                else{
                    startCount(ops,nums);
                }//比栈顶符号优先级低就进行子运算
            }
        }
        if(count)
            nums.push(num);
        while(op!=-1){
            startCount(ops,nums);
            ops.top(op);
        }
        nums.top(ret);
        return true;
    }
    catch(const char* ero_msg){
        eroMsg = QString::fromStdString(ero_msg);
        return false;
    }

}


void Calculator::on_num1_clicked()
{
    in+="1";
    ui->input->setText(in);
}

void Calculator::on_num2_clicked()
{
    in+="2";
    ui->input->setText(in);
}


void Calculator::on_num3_clicked()
{
    in+="3";
    ui->input->setText(in);
}

void Calculator::on_num4_clicked()
{
    in+="4";
    ui->input->setText(in);
}

void Calculator::on_num5_clicked()
{
    in+="5";
    ui->input->setText(in);
}

void Calculator::on_num6_clicked()
{
    in+="6";
    ui->input->setText(in);
}

void Calculator::on_num7_clicked()
{
    in+="7";
    ui->input->setText(in);
}

void Calculator::on_num8_clicked()
{
    in+="8";
    ui->input->setText(in);
}

void Calculator::on_num9_clicked()
{
    in+="9";
    ui->input->setText(in);
}

void Calculator::on_num0_clicked()
{
    in+="0";
    ui->input->setText(in);
}

void Calculator::on_clear_clicked()
{
    in = "";
    ret = "";
    ui->input->setText(in);
    ui->output->setText(ret);
}//清零



void Calculator::on_op8_clicked()
{
    int ret = 0;
    std::string in_ = in.toStdString();
    if(calculate(in_,ret)){
        ui->output->setText(QString::number(ret));
    }
    else{
        ui->errorMsg->setText(eroMsg);
    }

}//=

void Calculator::on_op1_clicked()
{
    in += "+";
    ui->input->setText(in);
}//+


void Calculator::on_op2_clicked()
{
    in += "-";
    ui->input->setText(in);
}//-

void Calculator::on_op3_clicked()
{
    in += "*";
    ui->input->setText(in);
}//*

void Calculator::on_op4_clicked()
{
    in += "/";
    ui->input->setText(in);
}// /



void Calculator::on_op5_clicked()
{
    in += "&&";
    ui->input->setText(in);
}// &&


void Calculator::on_op6_clicked()
{
    in += "||";
    ui->input->setText(in);
}// ||



void Calculator::on_op7_clicked()
{
    in += "!";
    ui->input->setText(in);
}// !


void Calculator::on_op9_clicked()
{
    in += "(";
    ui->input->setText(in);
}

void Calculator::on_op10_clicked()
{
    in += ")";
    ui->input->setText(in);
}
