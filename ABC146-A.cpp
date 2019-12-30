
// problem: "https://atcoder.jp/contests/abc146/tasks/abc146_a"

#include<bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin>>s;

    int x;

    if(s == "SUN")
        x = 7;
    else if(s == "SAT")
        x = 1;
    else if(s == "FRI")
        x = 2;
    else if(s == "THU")
        x = 3;
    else if(s == "WED")
        x = 4;
    else if(s == "TUE")
        x = 5;
    else if(s == "MON")
        x = 6;

    cout<<x;

    return 0;
}
