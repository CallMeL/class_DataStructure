//
//  array.h
//  test
//
//  Created by 陈汐 on 2021/4/1.
//

#ifndef array_h
#define array_h


#endif /* array_h */
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
template <class T>
class List{
    void clear();
    bool isEmpty();
    bool append(const T value);
    bool insert(const int p,const T value);
    bool deleteItem(const int p);
    T getValue(const T value);
    bool setValue(const int p,const T value);
    bool getPos(int&p,const T value);
};
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
        if(curLen==0){
            cout<<"no element!";
        }
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
    T getValue(const T value){
        return aList[value];
    }
    int getSize(){
        return curLen;
    }
};
