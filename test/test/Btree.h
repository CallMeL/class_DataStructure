
/*数据结构：二叉树*/

#include <iostream>
#include <list>
#include <stack>
#include <queue>

using namespace std;

/*二叉树结点*/
template <typename T>
class BiTreeNode{
public:
   T data;
   BiTreeNode<T>* left;
   BiTreeNode<T>* right;
   BiTreeNode(T data){
       this->data = data;
       this->left = NULL;
       this->right = NULL;
   }
};

template <typename T>
class BiTree{
private:
   int size;/*树中结点的个数*/
public:
   BiTreeNode<T>* root;/*根结点的指针*/

   BiTree(){size=0;root=NULL;};
   ~BiTree(){remove(root);};
    BiTreeNode<T>* CreatTree(int elements[], int size);
   bool insert_left(BiTreeNode<T>* node,T data);/*将data插入到node的左孩子*/
   bool insert_right(BiTreeNode<T>* node,T data);/*将data插入到node的右孩子*/
   bool remove(BiTreeNode<T>* &node);/*删除以node为根的子树*/
   bool preorderR(BiTreeNode<T>* node,list<T>* l);/*递归实现：先序遍历以node为根的树，并将遍历结果保存到l中*/
   bool preorderI(BiTreeNode<T>* node,list<T>* l);/*迭代实现：先序遍历以node为根的树，并将遍历结果保存到l中*/
   bool inorderR(BiTreeNode<T>* node,list<T>* l);/*递归实现：中序遍历以node为根的树，并将遍历结果保存到l中*/
   bool inorderI(BiTreeNode<T>* node,list<T>* l);/*迭代实现：中序遍历以node为根的树，并将遍历结果保存到l中*/
   bool postorderR(BiTreeNode<T>* node,list<T>* l);/*递归实现：后序遍历以node为根的树，并将遍历结果保存到l中*/
   bool postorderI(BiTreeNode<T>* node,list<T>* l);/*迭代实现：后序遍历以node为根的树，并将遍历结果保存到l中*/
   bool level(BiTreeNode<T>* node,list<T>* l);/*层次遍历以node为根的树，并将变量结果保存到l中*/
   int height(BiTreeNode<T>* node);/*以node为根的树的高度*/
};

template <typename T>
BiTreeNode<T>* CreatTree(int elements[], int size){
    if (size < 1)
    {
        return NULL;
    }
    //动态申请size大小的指针数组
    BiTreeNode<T> **nodes = new BiTreeNode<T>*[size];
    //将int数据转换为TreeNode节点
    for (int i = 0; i < size; i++)
    {
        if (elements[i] == 0)
        {
            nodes[i] = NULL;
        }
        else
        {
            nodes[i] = new BiTreeNode<T>(elements[i]);
        }
    }
    queue<BiTreeNode<T>*> nodeQueue;
    nodeQueue.push(nodes[0]);
 
    BiTreeNode<T> *node;
    int index = 1;
    while (index < size)
    {
        node = nodeQueue.front();
        nodeQueue.pop();
        nodeQueue.push(nodes[index++]);
        node->setleft(nodeQueue.back());
        //node->left = nodeQueue.back();
        nodeQueue.push(nodes[index++]);
        node->setRight(nodeQueue.back());
        //node->right = nodeQueue.back();
    }
    return nodes[0];
};

/**************************************************************************
Function:insert_left
Description:将data插入到node的左孩子
Input:二叉树结点node,数据data
Output:插入是否成功
***************************************************************************/
template <typename T>
bool BiTree<T>::insert_left(BiTreeNode<T>* node,T data){
   if(node==NULL){//允许空树插入结点
       if(size>0)
           return false;
       else
           root = new BiTreeNode<T>(data);
   }else{
       if(node->left!=NULL)
           return false;
       else
           node->left = new BiTreeNode<T>(data);
   }
   size++;
   return true;
}
/**************************************************************************
Function:insert_right
Description:将data插入到node的右孩子
Input:二叉树结点node,数据data
Output:插入是否成功
***************************************************************************/
template <typename T>
bool BiTree<T>::insert_right(BiTreeNode<T>* node,T data){
   if(node==NULL){
       if(size>0)
           return false;
       else
           root = new BiTreeNode<T>(data);
   }else{
       if(node->right!=NULL)
           return false;
       else
           node->right = new BiTreeNode<T>(data);
   }
   size++;
   return true;
}

/**************************************************************************
Function:remove
Description:删除以node为根的子树
Input:二叉树结点node的引用
Output:删除是否成功
***************************************************************************/
template <typename T>
bool BiTree<T>::remove(BiTreeNode<T>* &node){
   /*之所以要传入指针的引用，是因为不但要释放node指向的空间，
   同样也需要将node内保存的地址更改为NULL*/
   if(node==NULL)
       return false;
   if(remove(node->left)&&remove(node->right)){
       delete node;//释放p指向的空间
       node = NULL;//清空p内的地址
       size--;
       return true;
   }else
       return false;
}

/**************************************************************************
Description:先序遍历以node为根的数，并将遍历结果保存到l中
Input:二叉树结点node，列表l
Output:遍历是否成功
***************************************************************************/
template <typename T>
bool BiTree<T>::preorderR(BiTreeNode<T>* node,list<T>* l){
   if(node==NULL||l==NULL)
       return false;
   l->push_back(node->data);
   preorderR(node->left,l);
   preorderR(node->right,l);
   return true;
}
template <typename T>
bool BiTree<T>::preorderI(BiTreeNode<T>* node,list<T>* l){
   if(node==NULL||l==NULL)
       return false;
   stack<BiTreeNode<T>*> s;
   BiTreeNode<T>* p = node;
   while(p!=NULL||!s.empty()){
       if(p!=NULL){
           //压入栈时输出
           l->push_back(p->data);
           s.push(p);
           p = p->left;
       }else{
           p = s.top();
           s.pop();
           p = p->right;
       }
   }
   return true;
}
/**************************************************************************
Function:inorderR、inorderI
Description:中序遍历以node为根的数，并将遍历结果保存到l中
Input:二叉树结点node，列表l
Output:遍历是否成功
***************************************************************************/
template <typename T>
bool BiTree<T>::inorderR(BiTreeNode<T>* node,list<T>* l){
   if(node==NULL||l==NULL)
       return false;
   inorderR(node->left,l);
   l->push_back(node->data);
   inorderR(node->right,l);
   return true;
}
template <typename T>
bool BiTree<T>::inorderI(BiTreeNode<T>* node,list<T>* l){
   if(node==NULL||l==NULL)
       return false;
   stack<BiTreeNode<T>*> s;
   BiTreeNode<T>* p = node;
   while(!s.empty()||p!=NULL){
       if(p!=NULL){
           s.push(p);
           p = p->left;//下一个该访问的结点
       }else{
           p = s.top();
           s.pop();//要访问就弹出
           l->push_back(p->data);//弹出栈时输出
           p = p->right;//下一个该访问的结点
       }
   }
   return true;
}
/**************************************************************************
Function:postorderR、postorderI
Description:后序遍历以node为根的数，并将遍历结果保存到l中
Input:二叉树结点node，列表l
Output:遍历是否成功
***************************************************************************/
template <typename T>
bool BiTree<T>::postorderR(BiTreeNode<T>* node,list<T>* l){
   if(node==NULL||l==NULL)
       return false;
   postorderR(node->left,l);
   postorderR(node->right,l);
   l->push_back(node->data);
   return true;
}
template <typename T>
bool BiTree<T>::postorderI(BiTreeNode<T>* node,list<T>* l){
   if(node==NULL||l==NULL)
       return false;
   stack<BiTreeNode<T>*> s;
   BiTreeNode<T>* p = node;
   BiTreeNode<T>* pre = NULL;//用于标记先前访问过的结点
   while(!s.empty()||p!=NULL){
       if(p!=NULL){
           s.push(p);
           p = p->left;
       }else{
           BiTreeNode<T>* right = s.top()->right;
           if(right!=NULL&&right!=pre){
               p = right;
           }else{
               //在p==NULL且right!=NULL&&right!=pre时，
               //说明要访问栈顶结点了
               pre = s.top();
               l->push_back(pre->data);
               s.pop();
           }
       }
   }
   return true;
}
/**************************************************************************
Function:level
Description:层次遍历以node为根的树，并将变量结果保存到l中
Input:二叉树结点node，列表l
Output:遍历是否成功
***************************************************************************/
template <typename T>
bool BiTree<T>::level(BiTreeNode<T>* node,list<T>* l){
   if(node==NULL||l==NULL)
       return false;
   queue<BiTreeNode<T>*> q;
   q.push(node);
   BiTreeNode<T>* p = NULL;
   while(!q.empty()){
       p = q.front();
       q.pop();
       l->push_back(p->data);
       if(p->left!=NULL)q.push(p->left);
       if(p->right!=NULL)q.push(p->right);
   }
   return true;
}

/**************************************************************************
Function:height
Description:以node为根的树的高度
Input:二叉树结点node
Output:树的高度
***************************************************************************/
template <typename T>
int BiTree<T>::height(BiTreeNode<T>* node){
   if(node==NULL)
       return 0;
   int left_height = height(node->left);
   int right_height = height(node->right);
   return max(left_height,right_height)+1;
}
/**************************************************************************
int main(){
   BiTree<int>* biTree = new BiTree<int>();
   
   构建二叉树：
      3
    6   2
   8 9
   
   biTree->insert_left(biTree->root,3);
   biTree->insert_left(biTree->root,6);
   biTree->insert_right(biTree->root,2);
   biTree->insert_left(biTree->root->left,8);
   biTree->insert_right(biTree->root->left,9);
   list<int> l;
   list<int>::iterator iter;
   //先序遍历
   biTree->preorderR(biTree->root,&l);
   cout<<endl<<"先序遍历(递归)：";
   for(iter=l.begin();iter!=l.end();iter++)
       cout<<*iter<<",";
   l.clear();
   biTree->preorderI(biTree->root,&l);
   cout<<endl<<"先序遍历(迭代)：";
   for(iter=l.begin();iter!=l.end();iter++)
       cout<<*iter<<",";
   l.clear();

   //中序遍历
   biTree->inorderR(biTree->root,&l);
   cout<<endl<<"中序遍历(递归)：";
   for(iter=l.begin();iter!=l.end();iter++)
       cout<<*iter<<",";
   l.clear();
   biTree->inorderI(biTree->root,&l);
   cout<<endl<<"中序遍历(迭代)：";
   for(iter=l.begin();iter!=l.end();iter++)
       cout<<*iter<<",";
   l.clear();

   //后序遍历
   biTree->postorderR(biTree->root,&l);
   cout<<endl<<"后序遍历(递归)：";
   for(iter=l.begin();iter!=l.end();iter++)
       cout<<*iter<<",";
   l.clear();
   biTree->postorderI(biTree->root,&l);
   cout<<endl<<"后序遍历(迭代)：";
   for(iter=l.begin();iter!=l.end();iter++)
       cout<<*iter<<",";
   l.clear();

   //层次遍历
   biTree->level(biTree->root,&l);
   cout<<endl<<"层次遍历：";
   for(iter=l.begin();iter!=l.end();iter++)
       cout<<*iter<<",";
   l.clear();
   cout<<endl<<biTree->height(biTree->root);
   delete biTree;
}

 ***************************************************************************/
