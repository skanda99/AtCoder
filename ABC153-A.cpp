
// problem: "https://atcoder.jp/contests/abc153/tasks/abc153_a"

#include<bits/stdc++.h>

using namespace std;

int main()
{
    int h,a;
    cin>>h>>a;

    if(h%a)
        cout<<h/a+1;
    else
        cout<<h/a;

    return 0;
}
