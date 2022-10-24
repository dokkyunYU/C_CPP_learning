// 검증수
// https://www.acmicpc.net/problem/2475

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main(void)
{
    string sstr;
    getline(cin, sstr);
    stringstream ss;
    // ss << sstr;
    ss.str(sstr);
    int num = 0, allsum = 0;
    while (ss >> num)
        allsum += num * num;
    cout << allsum % 10;
    return 0;
}