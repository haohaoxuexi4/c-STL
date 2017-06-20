//
//  Smap.cpp
//  c++STL
//
//  Created by 仙女 on 2017/6/15.
//  Copyright © 2017年 仙女. All rights reserved.
//

#include "Smap.hpp"



template <typename Hobject>
Hashtable<Hobject>::Hashtable(int size):theList(size)
{
}
template <typename Hobject>
bool Hashtable<Hobject>::contains(const Hobject& obj)
{

    int hash=myhash(obj);
    
    const std::list<Hobject> & templist=theList[hash];
    auto it=templist.cbegin();
    
    for (; it!=templist.cend()&& *it!=obj; ++it) {
        
    }
    if (it!=templist.cend()) {
        return true;
    }
    else
        return false;
}

/*
 插入函数 如果存在，则返回false,不存在，插入链表最前面 成功返回true,失败返回false
 */
template <typename Hobject>
bool Hashtable<Hobject>::insert(const Hobject &obj)
{
    int hash=myhash(obj);
    std::list<Hobject>& templist=theList[hash];
    
    if (contains(obj)) {
        return false;//存在返回FALSE
    }
    templist.push_back(obj);
    return true;
}
/*
删除指定元素，不存在，返回FALSE， 成功返回TRUE，失败返回false
 */
template <typename Hobject>
bool Hashtable<Hobject>::remove(const Hobject &obj)
{
    int hash=myhash(obj);
    std::list<Hobject>& templist=theList[hash];
    
    auto it=find(templist.begin(),templist.end(),obj);
    if (it==templist.end()) {
        return false;
    }
    templist.erase(it);
    return true;
}

