////
////  ch2_2.cpp
////  test
////
////  Created by 陈汐 on 2021/3/27.
////
//
//#include <stdio.h>
//#include <iostream>
//#include <stdio.h>
//#include <string>
//using namespace std;
//template<class T>
//struct Node {
//    T data;    // 数据域
//    Node *next; // 指针域
//    bool isout=false;
//    Node(T x):data(x),next(nullptr){}
//};
//template<class T>
//class linkList{
//private:
//    Node<T> *head,*tail,*current;
//    int size;
//public:
//    linkList() {
//        head = tail = nullptr;
//        size = 0;
//    }
//    void append(T val){
//        if(tail!=nullptr){
//            Node<T> *node=new Node<T>(val);
//            tail->next=node;
//            tail=node;
//            tail->next=head;
//        }
//        else{
//            //尾节点为空，那么头节点也为空，然后首尾节点都为新节点
//            tail=new Node<T>(val);
//            head=tail;
//            tail->next=head;
//        }
//        ++size;
//
//    }
//    void output(){
//        Node<T> *t = head;
//        for (int i=0; i<size; i++) {
//            cout<<t->data<<" ";
//            t=t->next;
//        }
//
//        cout<<endl;
//    }
//    int getsize(){
//        return size;
//    }
//    void setStart(int n){
//        int i=0;
//        current=head;
//        if (n==1) {
//            current=tail;
//            //cout<<current->data<<endl;
//        }
//        if (n==2) {
//            current=head;
//        }
//        while (i<n-2) {
//            current=current->next;
//            i++;
//        }
//        //cout<<current->data;
//    }
//    T call(int m){
//        int i=0;
//        while (i<m) {
//            //cout<<"num:"<<current->data<<" isout: "<<current->isout<<" i:"<<i<<endl;
//            current=current->next;
//            if(!current->isout)i++;
//        }
//        current->isout=true;
//        //cout<<"out: "<<current->data<<endl;
//        return current->data;
//    }
//};
//
////有n个人坐在圆桌周围，现在从第s个人开始报数，数到第m个人出列，然后从出列的下一个人开始报数，数到第m个人又出列，直到完全出列为止。
////Josephus问题：对于任意给定整数n、s、m，求出按出列次序得到的n个人员序列。
//bool Josephus(int n,int s,int m){
//    //initial
//    linkList<int> list1=linkList<int>();
//
//    for (int i=0; i<n; i++) {
//        list1.append(i+1);
//    }
//    //cout<<"before: ";
//    //list1.output();
//    list1.setStart(s);
//    for (int i=0; i<n; i++) {
//        cout<<list1.call(m)<<" ";
//    }
//    //cout<<"after: ";
//
//    return true;
//}
//int main(){
//    int n,s,m;
//    cin>>n;
//    cin>>s;
//    cin>>m;
//    Josephus(n,s,m);
//
//
//}
