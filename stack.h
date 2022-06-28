#ifndef STACK_H
#define STACK_H

#define overflow -1
#define underflow -2
#define fail_malloc -3
#define OK 0
typedef int status ;

template <class T>
class Stack {
private:
    T *start;
    T *current, *end;
    static int MAX_SIZE;//所有栈的最大空间，与具体的栈无关
    int max_size; //本栈的最大空间，与具体的栈有关
public:
    Stack(int n=0);//构造函数，默认构造空栈，也可以指定栈的大小n
    ~Stack();
    status push(T p);
    status pop();
    bool empty()const;
    bool full()const;
    status top(T& x);
    int getSize();
};

#endif
