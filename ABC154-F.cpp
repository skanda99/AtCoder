
// problem: "https://atcoder.jp/contests/abc154/tasks/abc154_f"

#include<bits/stdc++.h>
#define ll long long
#define p (ll)(1e9+7)
#define n (ll)(2e6+3)

using namespace std;

void calcFact(vector<ll>&V)
{
    V[0] = 1;
    ll i;
    for(i=1;i!=n;i++)
        V[i] = (V[i-1]*i)%p;
}

ll power(ll a,ll m)
{
    if(!m)
        return 1;

    ll b = 1;
    if(m%2)
        b = a;

    ll ans = power(a,m/2);

    ans = ((ans*ans)%p * b)%p;

    return ans;
}


ll nCr(ll a,ll b,vector<ll>&V)
{
    ll ans = (V[a] * power((V[b]*V[a-b])%p,p-2))%p;     // define

    return ans;
}


int main()
{
    ll r1,c1,r2,c2;
    cin>>r1>>c1>>r2>>c2;

    vector<ll>V(n);
    calcFact(V);      // define

    cout<<(nCr(r2+c2+2,c2+1,V) + p - nCr(r1+c2+1,c2+1,V) + p - nCr(r2+c1+1,c1,V) + nCr(r1+c1,c1,V))%p;        // define

    return 0;
}
