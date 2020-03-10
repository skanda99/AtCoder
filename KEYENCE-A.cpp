
// problem: "https://atcoder.jp/contests/keyence2020/tasks/keyence2020_a"

#include<bits/stdc++.h>

using namespace std;

int main()
{
    int h,w,n;
    cin>>h>>w>>n;

    h = max(h,w);
    if(n%h)
        cout<<n/h+1;
    else
        cout<<n/h;

    return 0;
}
