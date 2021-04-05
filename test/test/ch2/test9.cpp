////
////  test9.cpp
////  test
////
////  Created by 林彦汐19074519 on 2021/3/8.
////
//
//#include <iostream>
//#include <stdio.h>
//#include <string>
//using namespace std;
//
//// 单链表结点
//struct Node {
//    int data;    // 数据域
//    Node *next; // 指针域
//    Node(int x):data(x),next(nullptr){}
//};
//
//class linkList{
//private:
//    Node *head,*tail;
//    int size;
//public:
//    linkList() {
//        head = tail = nullptr;
//        size = 0;
//    }
//    void append(int val){
//        if(tail!=nullptr){
//            Node *node=new Node(val);
//            tail->next=node;
//            tail=node;
//        }
//        else{
//            //尾节点为空，那么头节点也为空，然后首尾节点都为新节点
//            tail=new Node(val);
//            head=tail;
//        }
//        ++size;
//    }
//    void output(){
//        Node *t = head;
//      
//        while (t->next!=nullptr) {
//            cout<<t->data<<" ";
//            t=t->next;
//        }
//        if(t->next==nullptr) cout<<t->data;
//        cout<<endl;
//    }
//    
//    int getsize(){
//        return size;
//    }
//    //   void getIntersection(arrList withA,arrList *toC){
//    void getIntersection(linkList withA,linkList *toC){
//        //withA表示和A集合求交集，toC表示赋值给C
//        Node *p,*q;
//        Node *temp = nullptr;
//        //temp 是为了储存B中数据相同的位置，避免又从头开始找数据
//        p=head;
//        q=withA.head;
//        //AB都只有一个元素时
//        if(q->data==p->data){
//            toC->append(p->data);
//        }
//
//        while (q->next!=nullptr) {
//            if(p->data==q->data){
//                toC->append(q->data);
//                q = q->next;
//                temp = p;
//            }
//            if(p->next!=nullptr){
//                p = p->next;
//            }
//            //当遍历了一遍B之后，没有相同的数，此时要寻找的A里数向下走一位，B指针从尾部回到上一次的位置，因为是递增且无重复值，所以没有必要从头开始
//            if(p->next==nullptr){
//                //AB都判断到最后一个数据时
//                if(q->next == nullptr) {
//                    if(q->data==p->data){
//                        toC->append(p->data);
//                    }
//                    return;
//                }
//                p = temp;
//                q = q->next;
//            }
//        }
//    }
//};
//int main(){
//    //前期数据准备
//    linkList A = linkList();
//    linkList B = linkList();
//    linkList C = linkList();
//    A.append(2);
//    A.append(3);A.append(9);A.append(10);A.append(21);A.append(33);A.append(50);
//    B.append(3);
//    B.append(2);B.append(3);  B.append(10); B.append(12); B.append(21); B.append(25); B.append(30);B.append(33);B.append(50);
//    cout<<"A: ";A.output();
//    cout<<endl;
//    cout<<"B: ";B.output();
//    cout<<endl;
//    
//    //测试程序
//    B.getIntersection(A, &C);
//    if(C.getsize()!=0){
//        cout<<"The intersection of A and B is: ";
//        C.output();
//    }
//    //AB没有交集时
//    else{
//        cout<<"Oh there is no intercection between A and B"<<endl;
//    }
//    return 1;
//}
//
