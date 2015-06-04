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
        CurlWrap(std::string url, std::string& readBuffer);
        ~CurlWrap(){ curl_easy_cleanup(m_pcurl); }

    private:
        CURL*       m_pcurl;
        CURLcode    m_result;

    private:
        //not sure whether copy ctor and = allowed, so
        CurlWrap(const CurlWrap&);
        CurlWrap& operator=(const CurlWrap&);
};




#endif //_CURLWRAP_H_
