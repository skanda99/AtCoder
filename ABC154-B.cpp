
// problem: "https://atcoder.jp/contests/abc154/tasks/abc154_b"

#include<bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin>>s;

    int i;
    for(i=0;i!=s.size();i++)
        s[i] = 'x';

    cout<<s;

    return 0;
}
