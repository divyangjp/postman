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
        return (boost::iequals(cstr, m_sWord.c_str()));
    }

    bool operator <(const WordTrack& wt)
    {
        //This is ok as case is not imp. 
        //we are more concerned about unique words in a page
        //so while inserting words in set, they are already lower cased
        //Good IDEA!!! not sure...
        return (m_sWord < wt.m_sWord);
    }
};

struct LinkTrack
{
    std::string     m_sLink;
    unsigned int    m_Level;

    bool operator()(const char* cstr) const
    {
        return (boost::iequals(cstr, m_sLink.c_str()));
    }

    bool operator <(const LinkTrack& lt)
    {
        //This is okay as links are lower cased before inserting
        //into vector... snap!
        return (m_sLink < lt.m_sLink);
    }
};

#endif //_COMMON_H_
