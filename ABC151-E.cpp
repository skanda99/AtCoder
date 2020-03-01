
// problem: "https://atcoder.jp/contests/abc151/tasks/abc151_e"

#include<bits/stdc++.h>
#define ll long long
#define p (ll)(1e9+7)

using namespace std;

ll power(ll a,ll n)
{
    if(n == 0)
        return 1;

    ll b = 1;
    if(n%2)
        b = a;

    ll ans = power(a,n/2);
    ans = ((ans*ans)%p * b)%p;

    return ans;
}

void calc_nCr(ll n,ll k,vector<ll>&C)
{
    ll i,b;
    C[k] = 1;
    for(i=k+1;i!=n+1;i++)
    {
        b = power(i-k,p-2);     // define
        C[i] = ((C[i-1]*i)%p * b)%p;
    }
}


int main()
{
    ll n,k;
    cin>>n>>k;

    vector<ll>C(n+1,0);
    calc_nCr(n,k-1,C);

    ll i,x;
    vector<ll>V;
    for(i=0;i!=n;i++)
    {
        cin>>x;
        V.push_back(x);
    }

    sort(V.begin(),V.end());

    ll Min,Max,j;
    j = n-1;
    Min = 0;

    for(i=0;j>=k-1;i++,j--)
        Min += (V[i]*C[j])%p;

    Max = 0;
    j = n-1;
    for(i=n-1;j>=k-1;i--,j--)
        Max += (V[i]*C[j])%p;

    cout<<(Max-Min+p)%p;

    return 0;
}
