#pragma once
#include "common.h"
class Solution {
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string encodeString = "";
        for (int i = 0; i < longUrl.size(); i++)
        {
            encodeString += longUrl[i] + '30';
        }
        return encodeString;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        string decodeString = "";
        for (int i = 0; i < shortUrl.size(); i++)
        {
            decodeString += shortUrl[i] - '30';
        }
        return decodeString;
    }
};