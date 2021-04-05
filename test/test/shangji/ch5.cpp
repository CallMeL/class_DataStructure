////
////  ch5.cpp
////  test
////
////  Created by 陈汐 on 2021/3/28.
////
//
//
//#include <stdio.h>
//#include <iostream>
//#include <stdio.h>
//#include <string>
//
//using namespace std;
////MARK:最小堆
//template <class T>
//class MinHeap {
//private:
//    T*heapArray;
//    int CurrentSize;
//    int MaxSize;
//    void swap(int pos_x,int pos_y);
//    void BuildHeap(){
//        for (int i =CurrentSize/2-1; i>=0; i--) {
//            siftDown(i);
//        }
//    };
//
//public:
//    MinHeap(const int n){
//        if(n<=0)return;
//        CurrentSize=0;
//        MaxSize=n;
//        heapArray = new T[MaxSize];
//        BuildHeap();
//    };
//    virtual~MinHeap(){
//        delete []heapArray;
//    };
//    bool isEmpty();
//    bool isLeaf(const int pos){
//        return (pos>=CurrentSize/2)&&(pos<CurrentSize);
//    };
//    void bulidHeap(){
//        for(int i=CurrentSize/2-1;i>=0;i--){
//            siftDown(i);
//        }
//    };
//    int leftChild(const int pos){
//        return 2*pos+1;
//    };
//    int rightChild(const int pos){
//        return 2*pos+2;
//    };
//    int parent(const int pos){
//        return (pos-1)/2;
//    };
//    bool remove(int pos,T &node){
//        if ((pos<0)||(pos>=CurrentSize)) {
//            return false;
//        }
//        node = heapArray[pos];
//        heapArray[pos] = heapArray[--CurrentSize];
//        if (heapArray[parent(pos)]>heapArray[pos]) {
//            siftUp(pos);
//        }
//        else{
//            siftDown(pos);
//        }
//        return true;
//    };
//    bool inset(const T& newNode){
//        if(CurrentSize==MaxSize)return false;
//        heapArray[CurrentSize]=newNode;
//        siftUp(CurrentSize);
//        CurrentSize++;
//        return true;
//    };
//    void removeMin(T& remove){
//        if (CurrentSize==0) {
//            cout<<"erro!no element to delete"<<endl;
//        }
//        else{
//            swap(0, --CurrentSize);
//            if (CurrentSize>1) {
//                siftDown(0);
//                remove = heapArray[CurrentSize];
//            }
//        }
//    };
//    void siftUp(int position){
//        int tempPos = position;
//        T temp = heapArray[tempPos];
//        while ((tempPos>0)&&(heapArray[parent(tempPos)]>temp)) {
//            heapArray[tempPos]=heapArray[parent(tempPos)];
//            tempPos = parent(tempPos);
//        }
//        heapArray[tempPos]=temp;
//    };
//    void siftDown(int left){
//        int i =left;
//        int j = leftChild(i);
//        T temp = heapArray[i];
//        while (j<CurrentSize) {
//            if ((j<CurrentSize-1)&&(heapArray[j]>heapArray[j+1]))
//                j++;
//            if(temp>heapArray[j]){
//                heapArray[i] = heapArray[j];
//                i=j;
//                j=leftChild(j);
//            }
//            else break;
//        }
//        heapArray[i]=temp;
//    };
//};
//template<class T>
//struct HuffmanTreeNode{
//private:
//    T info;
//    HuffmanTreeNode<T> *left;
//    HuffmanTreeNode<T> *right;
//    HuffmanTreeNode<T> *root;
//public:
//    HuffmanTreeNode();
//    HuffmanTreeNode(const T& ele);
//    HuffmanTreeNode(const T& ele,HuffmanTreeNode<T> *l,HuffmanTreeNode<T> *r);
//    T value() const;
//    HuffmanTreeNode<T> * leftchild() const;
//    HuffmanTreeNode<T> * rightchild() const;
//    void setLeftchild(HuffmanTreeNode<T> *);
//    void setRightchile(HuffmanTreeNode<T> *);
//    void setValue(const T&val);
//    bool isLeaf() const;
//};
//
//template<class T>
//class HuffmanTree {
//private:
//    HuffmanTreeNode<T> *root;
//    void mergeTree(HuffmanTreeNode<T> &h1,HuffmanTreeNode<T> &h2,HuffmanTreeNode<T> *parent);
//    void deleteTree(HuffmanTreeNode<T> *root);
//public:
//    HuffmanTree(T weight[],int n){
//        MinHeap<HuffmanTreeNode<T>> heap(n);
//        HuffmanTreeNode<T> *parent,firstchild,secondchild;
//        HuffmanTreeNode<T> *NodeList = new HuffmanTreeNode<T>[n];
//        for (int i=0; i<n; i++) {
//
//        }
//    };
//    virtual ~HuffmanTree(){
//        deleteTree(root);
//    };
//};
//
//
////Huffman编码，利用代码5.12建立Huffman编码树的源代码
////包括计算各个字母对应代码的函数以及对信息进行编码与解码的函数
////扫描整个文件，以生成文件中各个字母的实际使用频率
////在编码文件的开头储存Huffman树，以便解码函数使用
