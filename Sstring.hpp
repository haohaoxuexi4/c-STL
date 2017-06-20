//
//  Sstring.hpp
//  c++STL
//
//  Created by 仙女 on 2017/6/15.
//  Copyright © 2017年 仙女. All rights reserved.
//

#ifndef Sstring_hpp
#define Sstring_hpp

#include <stdio.h>
#include <string.h>
class Sstring
{
public:
    Sstring();
    Sstring(const char* str);
    Sstring(const Sstring& string);  //拷贝构造函数
    
    Sstring& operator=(const Sstring& str);//重载=
    
    ~Sstring();
    
    ssize_t size() const{return len;} //获取长度
    const char* c_str() const{return data;} //获取c字符串
    
private:
    char* data;
    ssize_t len;
};

#endif /* Sstring_hpp */
