#ifndef BASE64_H
#define BASE64_H

#include<vector>
#include<string>

// use of Base64 algorithm to encode and decode strings.

namespace Base64
{
    std::string base64_encode(const std::string &);
    const std::string &SALT1 = "LM::TB::BB" ;
    const std::string &SALT2 = "_:/_77";
    const std::string &SALT3 = "line=wowC++";

    std::string EncryptB64(std::string s)
    {
       s = SALT1 + s + SALT2 + SALT3;
       s = base64_encode(s); // encoding string with base64
       s.insert(7,SALT3); // installing SALT after 7th position
       s += SALT1;
       s = base64_encode(s);
       s= SALT2 +SALT3 + SALT1;
       s = base64_encode(s);
       s.insert(1,"L");
       s.insert(7,"M");
       return s;
    }

    const std::string &BASE64_CODES = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    std::string base64_encode(const std::string &s)
    {
       std::string ret;   //output string will be filled with encoding characters
       int val = 0;      //index to be used to map input to our table
       int bits = -6;   // bits used to represent number of bits in a sub group (group of 6)
       const unsigned int b63 = 0x3F ; // decimal value is 63

       for (const auto &c : s)
       {
           val = (val << 8) + c; // left binary shift by 8, same as val * 2^8 + c
           bits+=8; // add 8 to numbers of bits when extracting info (octets)
           while(bits >= 0)
           {
               ret.push_back(BASE64_CODES[(val >> bits) & b63]); // does binary right shift + binary AND comparison
               bits -= 6; // decreases the bits by 6 because grouping is by 6 bits

           }
       }
       if (bits > -6)  // means at least one character has been insert
            ret.push_back(BASE64_CODES[((val << 8) >> (bits + 8)) & b63]);

       while(ret.size() % 4)
            ret.push_back('=');

       return ret;
    }
}

#endif // BASE64_H
