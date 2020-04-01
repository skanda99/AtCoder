
// problem: "https://atcoder.jp/contests/abc159/tasks/abc159_f"

#include<bits/stdc++.h>
#define ll long long
#define p (ll)(998244353)

using namespace std;

ll totSeg(ll i,ll s,vector<ll>&A,vector<vector<ll>>&V)
{
    if(i < 0 || s < 0)
        return 0;
    else if(s == A[i] && i > 0)
        return i+1+totSeg(i-1,s,A,V);
    else if(s == A[i])
        return i+1;


    if(V[i][s] == -1)
        V[i][s] = (totSeg(i-1,s-A[i],A,V) + totSeg(i-1,s,A,V))%p;


    return V[i][s];
}

int main()
{
    ll n,s;
    cin>>n>>s;

    vector<ll>A(n);
    ll i;
    for(i=0;i!=n;i++)
        cin>>A[i];

    vector<vector<ll>>V(n,vector<ll>(s+1,-1));

    //totSeg(n-1,s,A,V);      // define
    ll m = (totSeg(0,s,A,V) * n)%p;
    for(i=1;i!=n;i++)
        m = (m + ((p+totSeg(i,s,A,V)-totSeg(i-1,s,A,V)) * (n-i))%p)%p;

    cout<<m;

    return 0;
}
