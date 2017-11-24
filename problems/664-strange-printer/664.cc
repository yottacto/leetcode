#include <iostream>
#include <vector>
#include <string>
#include "664.hh"

int main()
{
    std::string s{"aaabbb"};
    std::cout << Solution{}.strangePrinter(s) << "\n";
    s = "aba";
    std::cout << Solution{}.strangePrinter(s) << "\n";
    s = "abcbcba";
    std::cout << Solution{}.strangePrinter(s) << "\n";
    s = "";
    std::cout << Solution{}.strangePrinter(s) << "\n";
    s = "baacdddaaddaaaaccbddbcabdaabdbbcdcbbbacbddcabcaaa";
    std::cout << Solution{}.strangePrinter(s) << "\n";
    s = "acadaea";
    std::cout << Solution{}.strangePrinter(s) << "\n";
    s = "ydfatmztyqgmuxjedlxcaftgflhuqldooiqjxqfvinjcksgqeguglnosavorgrhxcaizsnwabfcnalfgrzmepaypxniegsdisljk";
    std::cout << Solution{}.strangePrinter(s) << "\n";
    s = "wvlebzffurrvtleexawevsdyxfbbqqonnztpayuvrnskzyoyymcvhitenwffnvscvnrvlosebmqakgzltdgclcgayngniyqfojdz";
    std::cout << Solution{}.strangePrinter(s) << "\n";
    s = "wpxvdcjbxbrgvozwskdiaxgpktksqdhmsgjxluakvtrsiqrccwldtrudngydjhrdocdbwfltzeojuhlzdwewqabdibirjbwzdbcz";
    std::cout << Solution{}.strangePrinter(s) << "\n";
    s = "tbgtgb";
    std::cout << Solution{}.strangePrinter(s) << "\n";
}

