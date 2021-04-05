////
////  1.cpp
////  CppDemo
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
//
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
//    int getsize(){
//        return size;
//    }
//    int getmin(){
//        return head->data;
//    }
//    int getmax(){
//        return tail->data;
//    }
//    //第三题，删除表中所有大于min且小于max的值
//    //即只保留head和tail
//    void test3(){
//        Node *t;
//        //只有两个数，没有删除必要
//       while(head->next!=tail){
//           t = head->next;
//           head->next=t->next;
//           free(t);
//        }
//
//    }
//
//};
//int main(){
//    //note on screen
//    cout<<"please enter at least 2 numbers in added order"<<endl;
//    cout<<"for example: 1,3,4,5,6"<<endl;
//    cout<<"enter 0 to quit"<<endl;
//    int i;
//    //input to get numbers
//    linkList mylist = linkList();
//    for(cin>>i;i!=0;){
//        mylist.append(i);
//        cin>>i;
//    }
//    //output
//    cout<<"you entered "<<mylist.getsize()<<" numbers,they are:"<<endl;
//    mylist.output();
//    cout<<"the min number is "<<mylist.getmin()<<endl;
//    cout<<"the max number is "<<mylist.getmax()<<endl;
//    //run test3
//    mylist.test3();
//    cout<<"now the only number saved is "<<endl;
//    mylist.output();
//    return 1;
//}
//
