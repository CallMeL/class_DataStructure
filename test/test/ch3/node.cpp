////
////  test5.cpp
////  test
////
////  Created by 林彦汐19074519 on 2021/3/11.
////
//
//#include <iostream>
//#include <stdio.h>
//#include <string>
//using namespace std;
////以带头结点的循环链表表示队列，只设置一个指针指向队尾元素，编写队列的初始化，入队，出队
//
//struct Node {
//    int data;    // 数据域
//    Node *next; // 指针域
//    Node(int x):data(x),next(nullptr){}
//    Node(){next = nullptr;}
//};
//class linkList{
//private:
//    int size;
//    Node *tail;
//
//public:
//    linkList(){
//        size = 0;
//        tail = new Node();
//        tail->next = tail;
//    }
//    //入队
//    bool enQueue(int value){
//        Node *head;
//        head = tail->next;
//        Node *temp = new Node(value);
//        temp->next = head;
//        tail->next = temp;
//        tail = temp;
//        size++;
//        return true;
//    }
//    bool deQueue(){
//        Node *head;
//        head=tail->next;
//        if(head==tail){
//            cout<<"erro: no element to delete"<<endl;
//            return false;
//        }
//        Node *p = head->next;
//        head->next=head->next->next;
//        free(p);
//        size--;
//        return true;
//    }
//    bool output(){
//        Node *head = tail->next;
//        Node *temp = head->next;
//        if(head==tail){
//            cout<<"there is no element in the list"<<endl;
//            return false;
//        }
//        cout<<"mylist: ";
//        while (temp!=head) {
//            cout<<temp->data<<" ";
//            temp = temp->next;
//        }
//        cout<<endl;
//        return true;
//    }
//};
//int main(){
//    linkList mylist = linkList();
//    mylist.enQueue(10); mylist.enQueue(20); mylist.enQueue(24);
//    mylist.enQueue(25);mylist.enQueue(33);mylist.enQueue(35);
//    mylist.output();
//    mylist.deQueue();
//    mylist.output();
//    //测试空表
//    linkList thelist = linkList();
//    thelist.deQueue();
//    thelist.output();
//    return 0;
//}
//
//
