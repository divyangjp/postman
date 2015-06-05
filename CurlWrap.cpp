/**
 * @file CurlWrap.cpp
 * @brief
 * @author Divyang Patel <divyang.jp@gmail.com>
 * @version 1.0
 * @date 2015-06-04
 */
#include <iostream>
#include "CurlWrap.h"

CurlWrap::CurlWrap():m_reset(false)
{
    m_pcurl = curl_easy_init();
}

int CurlWrap::FetchPage(std::string& url, 
                        std::string& readbuff)
{
    if(m_reset)
    {
        //reset used curl handle
        curl_easy_reset(m_pcurl);
    }
    m_reset = true;
    readbuff.clear();
    curl_easy_setopt(m_pcurl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(m_pcurl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(m_pcurl, CURLOPT_WRITEDATA, &readbuff);
    try
    {
        m_result = curl_easy_perform(m_pcurl);
        if(m_result != CURLE_OK)
        {
            std::cout << "Fetching failed with error : " << curl_easy_strerror(m_result); 
            throw m_result;
        }
    } 
    catch (int err)
    {
        //Do something here based on error code
    }

    return m_result;
}
