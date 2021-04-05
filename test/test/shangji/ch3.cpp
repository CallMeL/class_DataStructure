//
//  ch3.cpp
//  test
//
//  Created by 林彦汐19074519 on 2021/3/13.
//
//实现表达式求值算法（包括中缀表达式转为后缀表达式和后缀表达式求值两部分的实现）

#include "model.h"
//优先级比较函数
bool compareP(string top,string input){
    //只要优先级不低于就返回真
    // ‘/’=92，'*'=42 ‘+‘=43，‘-’=45，'#'=35
    //优先级：参考
//    char table[9][9] = {   //算符优先级表
//    //           +   -   *   /   ^   !   (   )   #
//        /* + */ '>','>','<','<','<','<','<','>','>',
//        /* - */ '>','>','<','<','<','<','<','>','>',
//        /* * */ '>','>','>','>','<','<','<','>','>',
//        /* / */ '>','>','>','>','<','<','<','>','>',
//        /* ^ */ '>','>','>','>','>','<','<','>','>',
//        /* ! */ '>','>','>','>','>','>',' ','>','>',
//        /* ( */ '<','<','<','<','<','<','<','=',' ',
//        /* ) */ ' ',' ',' ',' ',' ',' ',' ',' ',' ',
//        /* # */ '<','<','<','<','<','<','<',' ','='
//        // 栈顶运算符
//    };
//top高才返回true
    if(top.compare("(")==0) return false;
    if(top.compare("*")==0||top.compare("/")==0)
        return true;
    else{
        if(input.compare("*")==0||input.compare("/")==0)
            return false;
        //都是+或-
        return true;
    }
}
//return code  1:missing "(";2: missing ")"
//前缀转后缀
int toPostfixExp(arrStack<string> *infixStack,arrStack<string> *postfixStack){
    arrStack<string> tempStack = arrStack<string>(20);
    while (!infixStack->isEmpty()) {
        string temp; infixStack->pop(temp);
        string top;
        //开括号
        if(temp.compare("(")==0){
            tempStack.push(temp);
        }
        //闭括号
        else if(temp.compare(")")==0){
            if(tempStack.isEmpty()){
                cout<<"erro: irregular input"<<endl;
                return 1;
            }
            else{
                string db;
                tempStack.pop(db);
                while (db.compare("(")!=0) {
                    postfixStack->push(db);
                    tempStack.pop(db);
                }
            }

        }
        //操作符
        else if(temp.compare("+")==0||temp.compare("-")==0||temp.compare("*")==0||temp.compare("/")==0){
            tempStack.getTop(top,false);
            while(!tempStack.isEmpty()&&(top.compare("(")!=0)&&compareP(top,temp)){
                string db;
                tempStack.pop(db);
                postfixStack->push(db);
                tempStack.getTop(top,false);
            }
            tempStack.push(temp);
        }
        //操作数直接入栈
        else{
            postfixStack->push(temp);
        }


    }
    //最后处理
    while (!tempStack.isEmpty()) {
        string db;
        tempStack.pop(db);
        postfixStack->push(db);
        if(db=="("){
            cout<<"erro: irregular input"<<endl;
            return 2;
        }
    }
    cout<<"postfixExp: ";
    postfixStack->output();
    return 0;
}
//计算后缀表达式的值
int colculat(arrStack<string> postfixStack){
    int result=0;
    int a;int b;
    arrStack<int> temp = arrStack<int>(20);
    string j;postfixStack.pop(j);
    while (j.compare("=")!=0) {
        if (j.compare("+")==0) {
            temp.pop(a);
            temp.pop(b);
            result = a+b;
            //cout<<result<<" ";
            temp.push(result);
        }
        else if (j.compare("-")==0) {
            temp.pop(a);
            temp.pop(b);
            result = a-b;
            //cout<<result<<" ";
            temp.push(result);
        }
        else if (j.compare("*")==0) {
            temp.pop(a);
            temp.pop(b);
            result = a*b;
            //cout<<result<<" ";
            temp.push(result);
        }
        else if (j.compare("/")==0) {
            temp.pop(a);
            temp.pop(b);
            result = b/a;
            //cout<<result<<" ";
            temp.push(result);
        }
        else{
            temp.push(stoi(j));
        }
        postfixStack.pop(j);
    }

    return result;
}

int main(){
    //TODO: reinput
//    cout<<"please enter an arithmetic expression"<<endl;
    arrStack<string> infixStack = arrStack<string>(20);
    arrStack<string> postfixStack = arrStack<string>(20);
    arrList<string> infixArry = arrList<string>(20);
    string temp;
    cin>>temp;
    //输入形式：回车
    //为了顺序，先用数组暂存
    while (temp.compare("#")!=0) {
        infixArry.append(temp);
        cin>>temp;
    }
    int len = infixArry.getLen()-1;
    while (len>=0) {
        temp = infixArry.getItem(len);
        len--;
        infixStack.push(temp);
    }
    cout<<"infixExp: ";
    infixStack.output();
    //转化成后缀
    toPostfixExp(&infixStack, &postfixStack);
    //处理后缀表达式
    arrStack<string> newStack = arrStack<string>(20);
    string a;
    newStack.push("=");
    while (!postfixStack.isEmpty()) {
        postfixStack.pop(a);
        newStack.push(a);
    }
    //newStack.output();
    //后缀表达时求值
    int result = colculat(newStack);
    //输出
    //infixStack.output();
    cout<<result<<endl;
    return 0;

}
