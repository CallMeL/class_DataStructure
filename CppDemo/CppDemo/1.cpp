//
//  1.cpp
//  CppDemo
//
//  Created by 陈汐 on 2021/3/8.
//

#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

// 单链表结点
struct Node {
    int data;    // 数据域
    Node *next; // 指针域
    Node(int x):data(x),next(nullptr){}
};

class linkList{
private:
    Node *head,*tail;
    int size;
public:
    linkList() {
        head = tail = nullptr;
        size = 0;
    }
    void append(int val){
        if(tail!=nullptr){
            Node *node=new Node(val);
            tail->next=node;
            tail=node;
        }
        else{
            //尾节点为空，那么头节点也为空，然后首尾节点都为新节点
            tail=new Node(val);
            head=tail;
        }
        ++size;
        
    }
    void output(){
        Node *t = head;
        while (t->next!=nullptr) {
            cout<<t->data<<" ";
            cout<<endl;
        }
    }

};
int main(){
    cout<<"please enter numbers in added order"<<endl;
    cout<<"for example: 1,3,4,5,6"<<endl;
    cout<<"enter 0 to quit"<<endl;
    int i;
    linkList mylist = linkList();
    for(cin>>i;i!=0;){
        mylist.append(i);
        cin>>i;
    }
    mylist.output();
    return 1;
}

