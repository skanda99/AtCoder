
// problem: "https://atcoder.jp/contests/abc152/tasks/abc152_b"

#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ll a,b;
    cin>>a>>b;

    ll m = min(a,b);
    ll M = max(a,b);

    M--;
    while(M--)
        m = 10*m + m%10;

    cout<<m;
    
    return 0;
}
