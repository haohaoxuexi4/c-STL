//
//  Smap.hpp
//  c++STL
//
//  Created by 仙女 on 2017/6/15.
//  Copyright © 2017年 仙女. All rights reserved.
//

#ifndef Smap_hpp
#define Smap_hpp

#include <stdio.h>
#include <list>
#include <vector>
#include <string>
/*
 哈希表，又称散列表  查找效率高，
 解决冲突有很多种方式，这里采用分离链接发，除此之外还有开发地址法和双散列
 */

extern int hash(const std::string& key,const int &tablesize)
{
    //采用公式：h=(k1*32+k2)*32+k3
    long long int hashval=0;
    int count=0;
    for (auto it=key.begin(); it!=key.end(); ++it) {
        if(count++ % 2==0)
        {
            hashval+=(hashval<<5)+*it;
        }
    }
    return hashval%=tablesize;
}
extern int hash(const int& key,const int& tablesize)
{
    return key&tablesize;
}

template <typename Hobject>
class Hashtable
{
public:
    Hashtable(int size=100);//初始化哈希表大小
    ~Hashtable(){}
    bool contains(const Hobject& obj);
    bool insert(const Hobject& obj);
    bool remove(const Hobject& obj);
    
private:
    std::vector<std::list<Hobject>> theList;//哈希表
    int  myhash(const Hobject& obj) const//哈希函数
    {
        return hash(obj, theList.size());
    }
};








#endif /* Smap_hpp */
