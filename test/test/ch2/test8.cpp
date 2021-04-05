////
////  test8.cpp
////  test
////
////  Created by 林彦汐 on 2021/3/8.
////
//
//
//#include <iostream>
//#include <stdio.h>
//#include <string>
//using namespace std;
//
//class arrList {
//private:
//    int *aList;
//    int maxSize;
//    int curLen;
//    int position;
//
//public:
//
//    arrList(int size){
//        maxSize = size;
//        aList = new int[maxSize];
//        curLen = position = 0;
//    }
//    bool isempty(){
//        if (curLen==0) {
//            return true;
//        } else {
//            return false;
//        }
//    }
//
//    void append(int value){
//        
//        if(curLen==maxSize){
//            cout<<"error:can't append,the list is full"<<endl;
//            return;
//        }
//        aList[curLen] = value;
//        curLen++;
//    }
//    
//    void output(){
//        for(int i =0;i<curLen;i++){
//            cout<<aList[i]<<" ";
//        }
//        cout<<endl;
//    }
//    //第八题
//    void getIntersection(arrList withA,arrList *toC){
//        //list[i]
//        //b:1,2,3,4,i,b=3
//        //a:2,4,5,6,j
//        //c:2
//        int i = 0;
//        int j = 0;
//        int temp = 0;//储存上一次的位置
//        while(j<withA.curLen){
//            //alist:b
//            //b[i]==a[j]
//            //withA.aList[j]
//            if(aList[i]==withA.aList[j]){
//                toC->append(aList[i]);
//                j++;
//                temp = i;
//            }
//            i++;
//            if(i>curLen){
//                i = temp;
//                j++;
//            }
//        }
//    }
//
//};
//int main(){
//    arrList A = arrList(10);
//    A.append(1);
//    A.append(2);A.append(5);A.append(10);A.append(21);A.append(22);A.append(25);A.append(26);A.append(30);A.append(44);
//    cout<<"A: "; A.output();
//    arrList B = arrList(10);B.append(2);B.append(3);B.append(5);B.append(8);B.append(21);B.append(26);B.append(38);B.append(44);
//    cout<<"B: "; B.output();
//    arrList C = arrList(10);
//    A.getIntersection(B, &C);
//    if(C.isempty()){
//        cout<<"Oh there is no intercetion between A and B"<<endl;
//        return 0;
//    }
//    cout<<"C: ";
//    C.output();
//    return 0;
//
//}
