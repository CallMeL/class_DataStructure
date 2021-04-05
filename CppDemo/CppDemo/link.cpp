#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

// 单链表结点
struct LNode {
    int data;    // 数据域
    LNode *next; // 指针域
};

typedef LNode LNode;     // LNode表示单链表的一个结点
typedef LNode *LinkList; // LinkList表示一个单链表

// 初始化单链表
void InitList(LinkList &L) {
    L = new LNode;
    L->next = NULL;
}

// 判断单链表是否为空
bool Empty(LinkList &L) {
    if (L->next == NULL) {
        return true;
    } else {
        return false;
    }
}

// 获取单链表长度
int GetLength(LinkList &L) {
    LNode *p = L->next;
    int length = 0;
    while (p != NULL) {
        p = p->next;
        length++;
    }
    return length;
}

// 按位查找：查找第i个结点
LNode *GetElem(LinkList &L, int i) {
    if (i < 0) {
        return NULL; // i值不合法
    }
    LNode *p = L;
    int j = 0;
    while (p != NULL && j < i) {
        p = p->next;
        j++;
    }
    return p;
}

// 按值查找：查找数据域为e的结点
LNode *GetLNode(LinkList &L, int e) {
    LNode *p = L->next;
    while (p != NULL && p->data != e) {
        p = p->next;
    }
    return p;
}

// 头插法建立单链表
LinkList List_HeadInsert(LinkList &L) {
    int e;
    cin >> e;
    while (e != 9999) {
        LNode *s = new LNode;
        s->data = e;
        s->next = L->next;
        L->next = s;
        cin >> e;
    }
    return L;
}

// 尾插法建立单链表
LinkList List_TailInsert(LinkList &L) {
    LNode *r = L; // r为尾指针
    int e;
    cin >> e;
    while (e != 9999) {
        LNode *s = new LNode;
        s->next = r->next;
        s->data = e;
        r->next = s;
        r = s; // 将r置为新的尾指针
        cin >> e;
    }
    r->next = NULL; // 尾指针的next置为NULL
    return L;
}

// 前插操作：在p结点之前插入数据e
bool InsertPriorNode(LNode *p, int e) {
    if (p == NULL) {
        return false;
    }
    LNode *s = new LNode;
    s->next = p->next;
    s->data = p->data; // 数据后移，模拟结点后移
    p->next = s;
    p->data = e; // 将前结点置为新插入的结点
    return true;
}

// 后插操作：在p结点之后插入数据e
bool InsertNextNode(LNode *p, int e) {
    if (p == NULL) {
        return false;
    }
    LNode *q = new LNode;
    q->data = e;
    q->next = p->next;
    p->next = q;
    return true;
}

// 按位序插入
bool InserstList(LinkList &L, int i, int e) {
    if (i < 1) { // i值不合法
        return false;
    }
    LNode *p = GetElem(L, i - 1); // 遍历查找i-1个结点
    InsertNextNode(p, 5244);      // 使用后插法
    /*  // 使用前插法，达到同样效果
    LNode *p = GetElem(L, i);
    InsertPriorNode(p, 5244);
    */
    return true;
}

// 删除p结点的后继结点
bool DeleteNextDNode(LNode *p) {
    if (p == NULL || p->next == NULL) {
        return false;
    }
    LNode *s = new LNode;
    s = p->next;
    p->next = s->next;
    delete s;
    return true;
}

// 删除指定结点
bool DeleteNode(LNode *p) {
    if (p == NULL) {
        return false;
    }
    LNode *s = new LNode;
    s = p->next;       // q指向被删除结点
    p->data = s->data; // 数据前移，模拟结点前移
    p->next = s->next; // 断开与被删除结点的联系
    delete s;
    return true;
}

// 按位序删除
bool ListDelte(LinkList &L, int i, int &e) {
    if (i < 1) {
        return false;
    }
    /*  // 按结点删除，实现同样效果
    LNode *p = GetElem(L, i);  // 被删除结点
    e = p->data;
    DeleteNode(p);
    */
    LNode *p = GetElem(L, i - 1);
    e = p->next->data;
    DeleteNextDNode(p);  // 删除前一结点的后继结点
    return true;
}

// 遍历单链表
void TraverseList(LinkList &L) {
    if (L->next == NULL) {
        return;
    }
    LNode *p = L->next; // 指向头指针
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int main() {
    LinkList L;
    InitList(L);

    L = List_TailInsert(L); // 尾插法
    // L = List_HeadInsert(L);  // 头插法
    TraverseList(L);

    InserstList(L, 1, 5244);
    TraverseList(L);

    int e = -1;
    ListDelte(L, 3, e);
    cout << "被删除的值：" << e << endl;
    TraverseList(L);
    cout << "长度：" << GetLength(L) << endl;
    return 0;
}


