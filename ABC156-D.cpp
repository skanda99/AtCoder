
// problem: "https://atcoder.jp/contests/abc156/tasks/abc156_d"

#include<bits/stdc++.h>
#define ll long long
#define p (ll)(1e9+7)

using namespace std;

ll power(ll a,ll n)
{
    if(!n)
        return 1;

    ll b = 1;
    if(n%2)
        b = a;

    ll ans = power(a,n/2);

    ans = ((ans*ans)%p * b)%p;

    return ans;
}

ll nCr(ll n,ll r)
{
    ll a,b,i;

    a = 1;
    for(i=1;i!=r+1;i++)
        a = (a*i)%p;

    b = 1;
    for(i=n;i>=n-r+1;i--)
        b = (b*i)%p;

    ll ans = (b * power(a,p-2))%p;

    return ans;
}

int main()
{
    ll n,a,b;
    cin>>n>>a>>b;

    ll ans = (power(2,n)-1)%p;      // define
    ans = (ans+2*p - nCr(n,a) - nCr(n,b))%p;        // define

    cout<<ans;

    return 0;
}
