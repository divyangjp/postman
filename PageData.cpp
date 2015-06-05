/**
 * @file PageData.cpp
 * @brief
 * @author Divyang Patel <divyang.jp@gmail.com>
 * @version 1.0
 * @date 2015-06-05
 */
#include <algorithm>
#include "PageData.h"

PageData::PageData()
{
}

void PageData::AddWord(const std::string& word)
{
    std::string myword = word;  //not cool... copying :o
    std::transform(myword.begin(), myword.end(), myword.begin(), ::tolower);
    WordTrack wt(myword, 0);
    auto ret = m_WordSet.insert(wt);
    if(ret.second == false) //Word present in set
    {
        auto iter = ret.first;  //get iterator to wordtrack object
        iter->m_count++;
    }
}

void PageData::AddLink(const std::string& link)
{
    if(std::strcmp(link.c_str(), m_PageUrl.c_str()) == 0)    //Don't want to be dopple-ganger :)
    {
        return; //do nothing
    }

    std::string mylink = link;
    std::transform(mylink.begin(), mylink.end(), mylink.begin(), ::tolower);
    LinkTrack lt(mylink, 0);
    m_LinkVec.push_back(lt);
}
