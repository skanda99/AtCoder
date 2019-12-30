
// problem: "https://atcoder.jp/contests/abc146/tasks/abc146_c"

#include<bits/stdc++.h>
#define ll long long

using namespace std;

ll numD(ll n)
{
    ll c = 0;
    while(n)
    {
        c++;
        n /= 10;
    }

    return c;
}

ll highestN(ll l,ll r,ll a,ll b,ll x)
{
    if(l > r)
        return INT_MIN;

    ll m = (l+r)/2;
    ll d = numD(m);
    ll c = a*m + b*d;

    if(c <= x)
        return max(m,highestN(m+1,r,a,b,x));

    return highestN(l,m-1,a,b,x);
}

int main()
{
    ll a,b,x;

    cin>>a>>b>>x;

    cout<<highestN(0,(ll)(1e9),a,b,x);      // define

    return 0;
}
