/**
 * @file CurlWrap.h
 * @brief Wrapper class for Curl library which fetches web pages
 * @author Divyang Patel <divyang.jp@gmail.com>
 * @version 1.0
 * @date 2015-06-04
 */

#ifndef _CURLWRAP_H_
#define _CURLWRAP_H_

#include <string>
#include <curl/curl.h>

class CurlWrap
{
    public:
        CurlWrap();
        ~CurlWrap(){ curl_easy_cleanup(m_pcurl); }

        int FetchPage(std::string& url, std::string& readbuff);

    private:
        static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
        {
            ((std::string*)userp)->append((char*)contents, size * nmemb);
            return size * nmemb;
        }

    private:
        CURL*       m_pcurl;
        CURLcode    m_result;
        bool        m_reset;


    private:
        //not sure whether copy ctor and = allowed, so
        CurlWrap(const CurlWrap&);
        CurlWrap& operator=(const CurlWrap&);
};




#endif //_CURLWRAP_H_
