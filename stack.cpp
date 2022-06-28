#include "stack.h"
#include<iostream>
template<class T>
int Stack<T>::MAX_SIZE = 100;

template<class T>
Stack<T>::Stack(int n) {
    max_size = n > 100? 100 : n;
    start = new T [max_size+2];// 表示栈底位置
    if(!start)//分配失败
        std::cout<<fail_malloc<<std::endl;
    else{
        current = start;//首个元素下标为0
        end = start + max_size + 1;//表示最大栈顶位置
    }
}

template <class T>
Stack<T>::~Stack(){
    delete [] start;
}

template<class T>
status Stack<T>::push(T p) {
    current++;
    if(this->full()){
        current--;
        return overflow;
    }
    if (current < end) {
        *current = p;
        return OK;
    }
}

template<class T>
status Stack<T>::pop() {
    if(this->empty()){
        return underflow;
    }
    else{
        current--;
        return OK;
    }
}

template<class T>
bool Stack<T>::empty()const {
    return current == start ? true : false;
}

template<class T>
bool Stack<T>::full()const {
    return current == end ? true : false;
}

template<class T>
status Stack<T>::top(T &x) {
    if(this->empty()){
        return underflow;
    }
    else{
        x=*current;
        return OK;
    }

}

template<class T>
int Stack<T>::getSize(){
    return current-start;
}

