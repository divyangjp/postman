/**
 * @file PageData.h
 * @brief Class to hold individual page data
 * @author Divyang Patel <divyang.jp@gmail.com>
 * @version 1.0
 * @date 2015-06-05
 */

#ifndef _PAGEDATA_H_
#define _PAGEDATA_H_

#include <string>
#include <set>
#include <vector>
#include "Common.h"

class PageData
{
    public:
        PageData();
        ~PageData(){}

        inline void SetPageUrl(std::string& url)
        {
            m_PageUrl = url;
        }
        inline std::string GetPageUrl()
        {
            return m_PageUrl;
        }

        void AddWord(const std::string& word);

        void AddLink(const std::string& link);

    private:
        std::string m_PageUrl;
        std::set<WordTrack> m_WordSet;
        std::vector<LinkTrack> m_LinkVec;
};



#endif //_PAGEDATA_H_
