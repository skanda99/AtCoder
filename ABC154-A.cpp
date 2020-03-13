
// problem: "https://atcoder.jp/contests/abc154/tasks/abc154_a"

#include<bits/stdc++.h>

using namespace std;

int main()
{
    string s1,s2;
    cin>>s1>>s2;

    int a,b;
    cin>>a>>b;

    string s3;
    cin>>s3;

    if(s3 == s1)
        cout<<a-1<<' '<<b;
    else
        cout<<a<<' '<<b-1;

    return 0;
}
