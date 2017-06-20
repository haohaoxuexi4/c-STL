//
//  Svector.hpp
//  c++STL
//
//  Created by 仙女 on 2017/6/15.
//  Copyright © 2017年 仙女. All rights reserved.
//

#ifndef Svector_hpp
#define Svector_hpp

#include <stdio.h>
#include <string.h>
/*
 一块连续空间
当空间不够时，再重新分配
 通过指针操作
 
 简单迭代器 begin()  end()
 
 push_back() 实现
 */
#define PREPSIZE 10  //初始化预留大小


template<typename T>
class Svector
{
   
public:
    //构造函数
    Svector(ssize_t inisize=0):initsize(inisize),finalsize(PREPSIZE+initsize)
    {
        arrHead=new T[finalsize];
    }
    //拷贝构造函数
    Svector(const Svector& v)
    {
        initsize=v.initsize;
        finalsize=v.finalsize;
        delete [] arrHead;
        arrHead=new T[finalsize];
        memcpy(arrHead, v.arrHead, finalsize);
    }
    //重载赋值 =
    Svector& operator=(const Svector& v)
    {
        if (&v!=this) {
            initsize=v.initsize;
            finalsize=v.finalsize;
            delete [] arrHead;
            arrHead=new T[finalsize];
            memcpy(arrHead, v.arrHead, finalsize);
        }
        return *this;
    }
    //析构函数
    ~Svector()
    {
        delete [] arrHead;
    }
    //大小
    ssize_t size()
    {
        return initsize;
    }
    //是否空
    bool isEmpty()
    {
        return size()==0;
    }
    //改变大小
    void resize(ssize_t newsize)
    {
        if(newsize<=initsize) return;
        if(newsize>finalsize)
        {
            makespae(newsize*2+1);
        }
        initsize=newsize;
    }
    
    void push_back(T t)
    {
        if(initsize==finalsize)
        {
            makespae(2*finalsize+1);
        }
        arrHead[initsize++]=t;
    }
    
    //迭代器
    typedef T* iterator;
    iterator begin()
    {
        return &arrHead[0];
    }
    iterator end()
    {
        return &arrHead[size()-1];
    }
    
private:
    /*
        扩展空间
     */
    void makespae(ssize_t finlsize)
    {
        if(finlsize< initsize) return;
        
        T* tmp=arrHead;
        arrHead=new T[finlsize];
        finalsize=finlsize;
        for(int i=0;i<initsize;i++)
        {
            arrHead[i]=tmp[i];
        }
        //ßmemcpy(arrHead, tmp, tmp->finalsize);
        delete [] tmp;
    }
    
    ssize_t initsize;
    ssize_t finalsize;
    T* arrHead;    //T类型的数组头指针
};
#endif /* Svector_hpp */
