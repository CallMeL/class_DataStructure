////
////  test2.cpp
////  test
////
////  Created by 林彦汐19074519 on 2021/3/10.
////
//
//#include <iostream>
//#include <stdio.h>
//#include <string>
//using namespace std;
//
////要求：循环数组q[0...m-1]，只有队列头指针front，设置计数器count，实现判空、入队、出队
//template <class T>
//class Queue{
//public:
//    void clean();
//    bool enQueue(const T item);//item 入队
//    bool deQueue(T& item);
//    bool getFront(T& item);
//    bool isEmpty();
//    bool isFull();
//};
//template <class T>
//class arrQueue:public Queue<T>{
//private:
//    int maxSize;
//    int count;
//    int front;
//    T * q;
//public:
//    arrQueue(int size){
//        maxSize = size;
//        q = new T[maxSize];
//        front = 0;
//        count = 0;
//    }
//    bool isEmpty(){
//        if(count==0)return true;
//        return false;
//    }
//    //入队
//    bool enQueue(const T item){
//        if(count==maxSize){
//            cout<<"erro:the Queue is full!"<<endl;
//            return false;
//        }
//        q[count] = item;
//        count++;
//        return true;
//    }
//    //出队
//    bool deQueue(T& item){
//        if(count==0){
//            cout<<"erro:the Queue is empty"<<endl;
//            return false;
//        }
//        item = q[front];
//        front = front +1;
//        count--;
//        return true;
//    }
//    void outputQueue(){
//        if(count==0){
//            cout<<"the Queue is empty!";
//            cout<<endl;
//            return;
//        }
//        cout<<"the Queue has: ";
//        for(int i =0;i<count;i++){
//            cout<<q[i]<<" ";
//        }
//        cout<<endl;
//        return;
//    }
//    
//};
//int main(){
//    arrQueue<int> myq = arrQueue<int>(10);
//    myq.enQueue(1);myq.enQueue(2);myq.enQueue(3);
//    myq.outputQueue();
////    myq.enQueue(4);myq.enQueue(5);myq.enQueue(6);
////    myq.enQueue(7);myq.enQueue(8);myq.enQueue(9);
////    myq.enQueue(10);
////    myq.outputQueue();
//////测试满表
////    myq.enQueue(11);
////    myq.outputQueue();
////测试删除
//    int de;
//    myq.deQueue(de);
//    cout<<"delete "<<de<<" from the Queue"<<endl;
//    cout<<"now ";myq.outputQueue();
//
//    myq.deQueue(de);
//    cout<<"delete "<<de<<" from the Queue"<<endl;
//    cout<<"now ";myq.outputQueue();
//
//    myq.deQueue(de);
//    cout<<"delete "<<de<<" from the Queue"<<endl;
//    cout<<"now ";myq.outputQueue();
////测试空表
//    myq.deQueue(de);
//    
//    return 1;
//}
