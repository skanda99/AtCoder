
// problem: "https://atcoder.jp/contests/abc153/tasks/abc153_e"

#include<bits/stdc++.h>
#define ll long long

using namespace std;

ll minMagicPts(ll i,ll h,vector<ll>&A,vector<ll>&B,vector<vector<ll>>&V)
{
    if(h <= 0)
        return 0;

    if(i < 0)
        return INT_MAX;

    if(V[i][h] == -1)
        V[i][h] = min(minMagicPts(i-1,h,A,B,V), minMagicPts(i,h-A[i],A,B,V)+B[i]);

    return V[i][h];
}

int main()
{
    ll h,n;
    cin>>h>>n;

    vector<ll>A(n),B(n);

    ll i;
    for(i=0;i!=n;i++)
        cin>>A[i]>>B[i];

    vector<vector<ll>>V(n,vector<ll>(h+1,-1));

    cout<<minMagicPts(n-1,h,A,B,V);       // define

    return 0;
}
