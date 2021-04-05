////
////  ch2.cpp
////  test
////
////  Created by 林彦汐19074519 on 2021/3/11.
////
//
//
//#include <iostream>
//#include <stdio.h>
//#include <string>
//using namespace std;
//template <class T>
//class List{
//    void clear();
//    bool isEmpty();
//    bool append(const T value);
//    bool insert(const int p,const T value);
//    bool deleteItem(const int p);
//    T getValue(const T value);
//    bool setValue(const int p,const T value);
//    bool getPos(int&p,const T value);
//};
//template <class T>
//class arrList:public List<T>{
//private:
//    T*aList;
//    int maxSize;
//    int curLen;
//    int position;
//public:
//    arrList(const int size){
//        maxSize = size;
//        aList = new T[maxSize];
//        curLen = position = 0;
//    }
//    ~arrList(){
//        delete [] aList;
//    }
//    void clear(){
//        delete [] aList;
//        curLen = position = 0;
//        aList = new T[maxSize];
//    }
//    //判空
//    bool isEmpty(){
//        if (curLen==0) {
//            return true;
//        } else {
//            return false;
//        }
//    }
//    //追加
//    void append(const T value){
//        if(curLen==maxSize){
//            cout<<"error:can't append,the list is full"<<endl;
//            return;
//        }
//        aList[curLen] = value;
//        curLen++;
//    }
//    //插入一个元素
//    bool insert(const int p,const T value){
//        int i;
//        if(curLen>=maxSize){
//            cout<<"erro:array is full"<<endl;
//            return false;
//        }
//        if(p<0||p>curLen){
//            cout<<"erro:illegal position"<<endl;
//            return false;
//        }
//        for(i=curLen;i>p;i--) aList[i] = aList[i-1];
//        aList[p] = value;
//        curLen++;
//        return true;
//    }
//    //删除一个元素
//    bool deleteItem(const int p){
//        int i;
//        if(curLen<=0){
//            cout<<"erro:empty array!"<<endl;
//            return false;
//        }
//        if(p<0||p>curLen-1){
//            cout<<"erro:illegal position!"<<endl;
//            return false;
//        }
//        for(i=p;i<curLen-1;i++) aList[i] = aList[i+1];
//        curLen--;
//        return true;
//    }
//    //全部输出
//    void output(){
//        if(curLen==0){
//            cout<<"no element!";
//        }
//        for(int i =0;i<curLen;i++){
//            cout<<aList[i]<<" ";
//        }
//        cout<<endl;
//    }
//    //找寻值为value的位置，传给p
//    bool getPos(int&p,const T value){
//        int i;
//        for(i=0;i<curLen;i++){
//            if(value==aList[i]){
//                p=i;
//                return true;
//            }
//        }
//        return false;
//    }
//    T getValue(const T value){
//        return aList[value];
//    }
//    int getSize(){
//        return curLen;
//    }
//};
////有n个人坐在圆桌周围，现在从第s个人开始报数，数到第m个人出列，然后从出列的下一个人开始报数，数到第m个人又出列，直到完全出列为止。
////Josephus问题：对于任意给定整数n、s、m，求出按出列次序得到的n个人员序列。
//
//bool Josephus(int n,int s,int m){
//    //a数组用来存放之前的，b数列用来存放之后的；
//    //初始化
//    arrList<int> a = arrList<int>(n);
//    arrList<int> b = arrList<int>(n);
//    //a初始化
//    for(int i=0;i<n;i++) a.append(i+1);
//    //cout<<"before: ";
//    //a.output();
//    //cout<<endl;
//
//    //call:当前报数人下标，out：当前出列人位置，temp：出列人数值
//    int call = s-1;
//    int out;
//    int temp=0;
//    int size;
////MARK:主循环
//    while (!a.isEmpty()) {
//        size = a.getSize();
//
//        out = call+m-1;
////        cout<<"out:"<<out%size;
//        temp=a.getValue(out%size);
////        cout<<" temp:"<<temp<<endl;
//        b.append(temp);
//        a.deleteItem(out%size);
//        call = (out%size);
////一些过程调试输出
////        cout<<"a: ";
////        a.output();
////        cout<<"b: ";
////        b.output();
////        cout<<endl;
//    }
//
//
//   // cout<<"after: ";
//    b.output();
//    cout<<endl;
//    return true;
//}
//
//int main(){
////参考正确结果
////Josephus(5, 2, 4)：5 4 1 3 2
////Josephus(7, 5, 2)：6 1 3 5 2 7 4
////Josephus(10, 3, 1)： 3 ～2 顺序
//   int n=0;int s=0;int m=0;
////    cout<<"hi there!this program is to solve Josephus Problem"<<endl;
////    cout<<"now please enter n: the toltal number"<<endl;
//    cin>>n;
////    cout<<"now please enter s: the specified begin point in the circle"<<endl;
//    cin>>s;
////    cout<<"now please enter m: the skipped number"<<endl;
//   cin>>m;
////    cout<<"you entered n:"<<n<<" "<<"s:"<<s<<" "<<"m:"<<m<<endl<<endl;
//    Josephus(n, s, m);
//    return 0;
//}
