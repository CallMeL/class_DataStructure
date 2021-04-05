////
////  test6.cpp
////  test
////
////  Created by 林彦汐19074519 on 2021/3/11.
////
//
////在长度为n的数组中实现两个栈，使得二者在元素的总数目为n之前都不溢出，并且push和pop的操作时间代价为O(n)
////
//#include <iostream>
//#include <stdio.h>
//#include <string>
//using namespace std;
//template <class T>
//class Stack{
//public:
//    void clear();
//    bool push(const T item);
//    bool pop(T &item);
//    bool getTop(T&item);
//    bool isEmpty();
//    bool isFull();
//
//};
//template <class T>
//class arrStack: public Stack<T>{
//private:
//    int mSize;
//    int top;
//    T *st;
//public:
//    arrStack(){
//        top = -1;
//    }
//    arrStack(int size){
//        mSize = size;
//        top = -1;
//        st = new T[mSize];
//    }
//    void clean(){
//        top = -1;
//    }
//    bool push(const T item){
//        if(top==mSize-1){
//            cout<<"erro:the stack is full!"<<endl;
//            return false;
//        }
//        st[top+1] = item;
//        top++;
//        return true;
//    }
//    bool pop(T &item){
//        if(top==-1){
//            cout<<"erro:the stack is empty!"<<endl;
//            return false;
//        }
//        item = st[top];
//        top--;
//    }
//    int getSize(){
//        return top+1;
//    }
//    int getNum(int i){
//        return st[i];
//    }
//
//};
//class theArry{
//private:
//    int n;
//    arrStack<int> A;
//    arrStack<int> B;
//public:
//    theArry(int size){
//        n = size;
//        arrStack<int> a = arrStack<int>(n);
//        A = a;
//        arrStack<int> b = arrStack<int>(n);
//        B = b;
//    }
//   bool push(const int value,const int choice){
//       //choice:1 for push into A;2 for push into B
//       int sum = A.getSize()+B.getSize();
//       if(sum>=n){
//           cout<<"erro:the two stacks add to the max size of "<<n<<endl;
//           return false;
//       }
//       if(choice==1){
//           A.push(value);
//       }
//       else if(choice==2){
//           B.push(value);
//       }
//       else{
//           cout<<"erro: invalid choice"<<endl;
//           cout<<"choice:1 for push into A;2 for push into B"<<endl;
//           return false;
//       }
//       return true;
//    }
//    bool output(){
//        int sizeA = A.getSize();
//        int sizeB = B.getSize();
//        if(sizeA==0&&sizeB==0){
//            cout<<"erro: no element in both two stacks"<<endl;
//            return false;
//        }
//        cout<<"first stack: ";
//        for(int i=0;i<sizeA;i++){
//            cout<<A.getNum(i)<<" ";
//        }
//        if(sizeA==0)cout<<"empty!";
//        cout<<endl;
//        cout<<"second stack: ";
//        for(int i=0;i<sizeB;i++){
//            cout<<B.getNum(i)<<" ";
//        }
//        if(sizeB==0)cout<<"empty!";
//        cout<<endl;
//        return true;
//    }
//};
//int main(){
//    //1.正常测试
//    theArry myarry = theArry(10);
//    myarry.push(5, 1);myarry.push(6, 1);myarry.push(7, 1);myarry.push(9, 1);myarry.push(10, 1);myarry.push(8, 1);myarry.push(77, 1);myarry.push(15, 1);
//    myarry.push(15, 2);myarry.push(20, 2);
//    myarry.output();
//    myarry.push(20, 2);
//    //2.测空
//    theArry arry2 = theArry(3);
//
//    arry2.push(33, 1);
//    arry2.output();
//    return 0;
//}
