
// problem: "https://atcoder.jp/contests/abc158/tasks/abc158_a"

#include<bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin>>s;

    if(s[0] != s[1] || s[1] != s[2] || s[2] != s[0])
        cout<<"Yes";
    else
        cout<<"No";

    return 0;
}
