/**
 * @file PageData.cpp
 * @brief
 * @author Divyang Patel <divyang.jp@gmail.com>
 * @version 1.0
 * @date 2015-06-05
 */
#include "PageData.h"

PageData::PageData()
{
}

void PageData::AddWord(const std::string& word)
{
    WordTrack wt(word, 0);
    auto ret = m_WordSet.insert(wt);
    if(ret.second == false) //Word present in set
    {
        auto iter = ret.first;  //get iterator to wordtrack object
        iter->m_count++;
    }
}
