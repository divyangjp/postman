/**
 * @file Common.h
 * @brief Common stuff (DS, Const, #define etc)
 * @author Divyang Patel <divyang.jp@gmail.com>
 * @version 1.0
 * @date 2015-06-04
 */
#ifndef _COMMON_H_
#define _COMMON_H_

#include <string>
#include <boost/algorithm/string.hpp>

struct WordTrack
{
    std::string     m_sWord;
    double          m_dCount;
    
    bool operator()(const char* cstr) const
    {
        //Ignore case because APPLE/apple is the same Apple... :P
        return !(boost::iequals(cstr, m_sWord.c_str()));
    }
};



#endif //_COMMON_H_
