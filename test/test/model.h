//
//  model.h
//  test
//
//  Created by 陈汐 on 2021/3/14.
//

#ifndef model_h
#define model_h
#endif /* model_h */
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
//MARK:栈
//栈是一种限定在一端进行插入和删除的线性表，只能对线性表的一端进行操作
template <class T>
class Stack{
public:
    void clear();
    bool push(const T item);
    bool pop(T & item);
    bool getTop(T & item);
    bool isEmpty();
    bool isFull();
};

//MARK:顺序栈
//顺序栈的本质是简化的顺序表
template <class T>
class arrStack: public Stack<T>{
private:
    int mSize;
    int top;
    T *st;
public:
    arrStack(){
        top = -1;
    }
    arrStack(int size){
        mSize = size;
        top = -1;
        st = new T[mSize];
    }
    ~arrStack(){
        
    }
    void clear(){
        top = -1;
    }
    bool push(const T item){
//        if(top==mSize-1){
//            cout<<"the stack is full"<<endl;
//            return false;
//        }
        //可以改变长度的栈
        if(top==mSize-1){
            T *newSt = new T[mSize*2];
            for(int i=0;i<top;i++){
                newSt[i] = st[i];
            }
            delete [] st;
            st = newSt;
            mSize = mSize*2;
        }
        top = top+1;
        st[top] = item;
        return true;
    }
    bool pop(T & item){
        if(top == -1){
            cout<<"erro:the stack is empty!"<<endl;
            return false;
        }
        item = st[top];
        top--;
        return true;
    }
    bool getTop(T & item,bool show){
        if(top == -1){
            if(show) cout<<"erro:the stack is empty!"<<endl;
            return false;
        }
        item = st[top];
        return true;
    }
    bool isEmpty(){
        if(top==-1)return true;
        return false;
    }
    void output(){
        int temp = top;
        while (temp!=-1) {
            cout<<st[temp]<<" ";
            temp--;
        }
        cout<<endl;
    }
    
};
//MARK:链式栈
//链式栈的本质是简化的链表
template <class T>
struct Node {
    T data;    // 数据域
    Node *next; // 指针域
    Node(T x):data(x),next(nullptr){}
    Node(){next = nullptr;}
    Node(T x,Node * ptr){
        data = x;
        next = ptr;
    }
};
template <class T>
class linkStack:public Stack<T>{
private:
    int size;
    Node<T> *top;

public:
    linkStack(int defSize){
        size = 0;
        top = NULL;
    }
    ~linkStack(){
        clear();
    }
    void clear(){
        while (top!=NULL) {
            Node<T> *temp = top;
            top = top->next;
            delete temp;
        }
        size = 0;
    }
    bool push(const T item){
        Node<T> *temp = new Node<T>(item,top);
        top = temp;
        size++;
        return true;
    }
    bool pop(T &item){
        Node<T> *temp;
        if(size==0){
            cout<<"erro:the stack is empty!"<<endl;
            return false;
        }
        item = top->data;
        temp = top->next;
        delete top;
        top = temp;
        size--;
        return true;
    }
    bool getTop(T &item){
        if(size==0){
            cout<<"erro:the stack is empty!"<<endl;
            return false;
        }
        item = top->data;
        return true;
    }
};

//按照学习顺序给出抽象数据类型定义
//MARK:线性表的抽象数据类型定义

template <class T>
class List{
    void clear();
    bool isEmpty();
    bool append(const T value);
    bool insert(const int p,const T value);
    bool deleteItem(const int p);
    bool getValue(const int p,const T value);
    bool setValue(const int p,const T value);
    bool getPos(int&p,const T value);
};
//线性表的存储结构分两类
//定长的顺序存储结构，实现后的线性表称为顺序表或向量。特点是有下标，访问方便，因此是随机存取。物理相邻关系就表示了元素逻辑上的相邻关系
//变长的线性存储结构，实现后的线性表称为链表
//MARK:一种顺序表的类定义
//TODO:继续写，notabilit 43 页，以及具体函数的实现
template <class T>
class arrList:public List<T>{
private:
    T*aList;
    int maxSize;
    int curLen;
    int position;
public:
    arrList(const int size){
        maxSize = size;
        aList = new T[maxSize];
        curLen = position = 0;
    }
    ~arrList(){
        delete [] aList;
    }
    void clear(){
        delete [] aList;
        curLen = position = 0;
        aList = new T[maxSize];
    }
    //判空
    bool isEmpty(){
        if (curLen==0) {
            return true;
        } else {
            return false;
        }
    }
    //追加
    void append(const T value){
        if(curLen==maxSize){
            cout<<"error:can't append,the list is full"<<endl;
            return;
        }
        aList[curLen] = value;
        curLen++;
    }
    //插入一个元素
    bool insert(const int p,const T value){
        int i;
        if(curLen>=maxSize){
            cout<<"erro:array is full"<<endl;
            return false;
        }
        if(p<0||p>curLen){
            cout<<"erro:illegal position"<<endl;
            return false;
        }
        for(i=curLen;i>p;i--) aList[i] = aList[i-1];
        aList[p] = value;
        curLen++;
        return true;
    }
    //删除一个元素
    bool deleteItem(const int p){
        int i;
        if(curLen<=0){
            cout<<"erro:empty array!"<<endl;
            return false;
        }
        if(p<0||p>curLen-1){
            cout<<"erro:illegal position!"<<endl;
            return false;
        }
        for(i=p;i<curLen-1;i++) aList[i] = aList[i+1];
        curLen--;
        return true;
    }
    //全部输出
    void output(){
        for(int i =0;i<curLen;i++){
            cout<<aList[i]<<" ";
        }
        cout<<endl;
    }
    //找寻值为value的位置，传给p
    bool getPos(int&p,const T value){
        int i;
        for(i=0;i<curLen;i++){
            if(value==aList[i]){
                p=i;
                return true;
            }
        }
        return false;
    }
    int getLen(){
        return curLen;
    }
    T getItem(const int i){
        if(i<0||i>curLen-1){
            cout<<"erro:illegal position!"<<endl;
            return aList[0];
        }
        return aList[i];
    }

};
