
// problem: "https://atcoder.jp/contests/abc144/tasks/abc144_c"

#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ll n,i,j,m;
    cin>>n;

    ll s = sqrt(n);
    m = LLONG_MAX;
    for(i=1;i<=s;i++)
        if(n%i == 0)
            m = min(m,i+n/i);

    cout<<m-2;

    return 0;
}
