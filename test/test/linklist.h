//
//  linklist.h
//  test
//
//  Created by 陈汐 on 2021/3/27.
//

#ifndef linklist_h
#define linklist_h
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
#endif /* linklist_h */
template<class T>
struct Node {
    T data;    // 数据域
    Node *next; // 指针域
    Node(T x):data(x),next(nullptr){}
};
template<class T>
class linkList{
private:
    Node<T> *head,*tail;
    int size;
public:
    linkList() {
        head = tail = nullptr;
        size = 0;
    }
    void append(T val){
        if(tail!=nullptr){
            Node<T> *node=new Node<T>(val);
            tail->next=node;
            tail=node;
        }
        else{
            //尾节点为空，那么头节点也为空，然后首尾节点都为新节点
            tail=new Node<T>(val);
            head=tail;
        }
        ++size;

    }
    void output(){
        Node<T> *t = head;

        while (t->next!=nullptr) {
            cout<<t->data<<" ";
            t=t->next;
        }
        if(t->next==nullptr) cout<<t->data;
        cout<<endl;
    }
    int getsize(){
        return size;
    }
    int getmin(){
        return head->data;
    }
    int getmax(){
        return tail->data;
    }

};
