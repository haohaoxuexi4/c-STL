//
//  Slist.hpp
//  c++STL
//
//  Created by 仙女 on 2017/6/15.
//  Copyright © 2017年 仙女. All rights reserved.
//

#ifndef Slist_hpp
#define Slist_hpp

#include <stdio.h>

/*
 采用双向链表
 
 */
//template <typename N>

/*
 迭代器类的定义
 */
//template <typename N>

template <typename N>
class Slist
{
public:
    //构造函数
    Slist():thesize(0),head(NULL),tail(NULL)
    {
    }
    //重载赋值函数
    const Slist& operator=(const Slist& L)
    {
        if(this==&L) return *this;
        //for (o; <#condition#>; <#increment#>) {
        //    <#statements#>
        //}
        return *this;
    }
    // 重载 ==
    bool operator ==(const Slist& L)
    {
        return head==L.head && tail==L.tail && thesize==L.thesize;
    }
    //析构函数
    ~Slist()
    {
        Node* tmp=head;
        while(head!=NULL)
        {
            delete tmp;
            tmp=head;
            head=head->next;
        }
    }
    //大小
    ssize_t size() const
    {
        return thesize;
    }
    //是否为空
    bool isEmpty() const
    {
        return size()==0;
    }
public:
    class const_iterator
    {
    public:
        //构造函数
        const_iterator(Node * n=NULL):current(n){};
        //重载 *
        const N& operator * () const
        {
            retrieve();
        }
        //重载 前置 ++
        const_iterator & operator ++()
        {
            current=current->next;
            return *this;
        }
        //重载 后置 ++
        const_iterator & operator ++ (int)
        {
            const_iterator ret=*this;
            ++*this;
            return ret;
        }
        bool operator == (const const_iterator & iter) const
        {
            return current==iter.current;
        }
        bool operator!=(const const_iterator& iter) const
        {
            return !(this->operator==(iter));
        }
        
    protected:
        //定义一个node*变量保存迭代器位置，声明为protect,是为了派生类能访问到
        Node<N>* current;
        const N& retrieve() const
        {
            current->data;
        }
        //const_iterator(Node<N>* p):current(p){}
        friend class Slist<N>;
    };

    
private:
    struct Node{
        N data;
        struct Node* prev; //前向
        struct Node* next;  //后向
        Node(N d):data(d),prev(NULL),next(NULL)
        {
        }
    };
    Node* head;  //头
    Node* tail;  //尾
    ssize_t thesize; //节点数目
};

#endif /* Slist_hpp */
