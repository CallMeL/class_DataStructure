//////
//////  test.cpp
//////  test
//////
//////  Created by 陈汐 on 2021/3/14.
//////
////
////
////MARK:链式
////二叉树结点
//#include <stack>
//using namespace std;
//template <class T>
//class BinaryTreeNode{
//private:
//    T infom;
//    BinaryTreeNode<T> *left;
//    BinaryTreeNode<T> *right;
//public:
//    BinaryTreeNode();
//    BinaryTreeNode(const T& ele);
//    BinaryTreeNode(const T& ele,BinaryTreeNode<T> *l,BinaryTreeNode<T> *r);
//    T value() const;
//    void setLeftchild(BinaryTreeNode<T> *Left){
//        left=Left;
//    };
//    void setRightchile(BinaryTreeNode<T> *Right){
//        right=Right;
//    };
//    void setValue(const T&val);
//    bool isLeaf() const;
//};
////二叉树
//template<class T>
//class BinaryTree{
//private:
//    BinaryTreeNode<T> *root;
//public:
//    BinaryTree(){root = NULL;};
//    ~BinaryTree(){DleteBinaryTree(root);};
//    bool isEmpty()const{
//        return (root!=NULL?false:true);
//    };
//    BinaryTreeNode<T> *Root(){return root;};
//    BinaryTreeNode<T> *Parent(BinaryTreeNode<T> *current){
//        stack<BinaryTreeNode<T>* > aStack;
//        BinaryTreeNode<T> *pointer = root;
//        if (root!=NULL&&current!=NULL) {
//            while (!aStack.empty()||pointer) {
//                if (pointer!=NULL) {
//                    if (current==pointer->leftchild()||current==pointer->rightchild())
//                        return pointer;
//
//                    aStack.push(pointer);
//                    pointer=pointer->leftchild();
//                }else{
//                    pointer=aStack.top();
//                    aStack.pop();
//                    pointer=pointer->rightchild();
//                }
//            }
//
//        }
//    };
//
//    void CreatTree(const T&info,BinaryTree<T> &leftTree,BinaryTree<T>&rightTree){
//        root = new BinaryTreeNode<T>(info,leftTree.root,rightTree.root);
//        leftTree.root = rightTree.root=NULL;
//    };
//    void DeleteBinary(BinaryTreeNode<T> *root){
//        if (root!=NULL) {
//            DeleteBinaryTree(root->left);
//            DeleteBinaryTree(root->right);
//            delete root;
//        }
//    };
//    BinaryTreeNode<T> *LeftSibling(BinaryTreeNode<T> *current);
//    BinaryTreeNode<T> *RightSibling(BinaryTreeNode<T> *current);
//    void PreOrder(BinaryTreeNode<T> *root);
//    void InOrder(BinaryTreeNode<T> *root);
//    void PosOrder(BinaryTreeNode<T> *root);
//
//};
//
////递归实现二叉树深度优先周游
//template<class T>
//void BinaryTree<T>:: PreOrder(BinaryTreeNode<T> *root){
//    if(root!=NULL){
//    Visit(root->value());
//    PreOrder(root->leftchild());
//    PreOrder(root->rightchild());
//    }
//}
//template<class T>
//void BinaryTree<T>:: InOrder(BinaryTreeNode<T> *root){
//    if(root!=NULL){
//    InOrder(root->leftchild());
//    Visit(root->value());
//    InOrder(root->rightchild());
//    }
//}
//template<class T>
//void BinaryTree<T>:: PosOrder(BinaryTreeNode<T> *root){
//    if(root!=NULL){
//    PostOrder(root->leftchild());
//    PostOrder(root->rightchild());
//    Visit(root->value());
//    }
//}
////非递归实现/*  ``*/
//
//
