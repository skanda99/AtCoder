
// problem: "https://atcoder.jp/contests/abc156/tasks/abc156_e"

#include<bits/stdc++.h>
#define ll long long
#define p (ll)(1e9+7)

using namespace std;

void Fact (vector<ll>&V)
{
    ll i;
    V[0] = 1;
    for(i=1;i!=V.size();i++)
        V[i] = (V[i-1]*i)%p;
}

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

ll nCr (ll n,ll r,vector<ll>&V)
{
    return (V[n] * power((V[r]*V[n-r])%p,p-2))%p;       // define
}

ll func(ll n,ll k)
{
    vector<ll>V(n+1);
    Fact(V);

    ll m = min(k,n-1);
    ll i,s;
    s = 1;

    for(i=1;i!=m+1;i++)
        s = (s + (nCr(n,i,V) * nCr(n-1,n-i-1,V))%p)%p;        // define

    return s;
}

int main()
{
    ll n,k;
    cin>>n>>k;

    cout<<func(n,k);        // define

    return 0;
}
