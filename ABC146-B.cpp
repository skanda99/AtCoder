
// problem: "https://atcoder.jp/contests/abc146/tasks/abc146_b"

#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;

    string s;
    cin>>s;

    int i;
    for(i=0;i!=s.size();i++)
        s[i] = (char)((s[i]-'A'+n)%26 + 'A');

    cout<<s;

    return 0;
}
