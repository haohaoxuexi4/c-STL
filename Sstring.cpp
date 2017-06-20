//
//  Sstring.cpp
//  c++STL
//
//  Created by 仙女 on 2017/6/15.
//  Copyright © 2017年 仙女. All rights reserved.
//

#include "Sstring.hpp"

Sstring::Sstring()
{
    data=new char[1];
    len=1;
    data[0]='\0';
}

Sstring::Sstring(const char* str)
{
    len=strlen(str);
    data=new char[len+1];
    data[len]='\0';
}
Sstring::Sstring(const Sstring& str)
{

    len=str.len;
    data=new char[len+1];
    memcpy(data, str.data, len);
    data[len]='\0';
}

Sstring::~Sstring()
{
    delete [] data;
    data=NULL;
    len=0;
}

Sstring& Sstring::operator=(const Sstring &str)
{

    if(&str==this)   return *this;
    
    delete [] data;
    len=str.len;
    data=new char[len];
    memcpy(data, str.data, len);
    data[len]='\0';
    return *this;

}
