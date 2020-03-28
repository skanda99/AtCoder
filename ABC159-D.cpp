
// problem: "https://atcoder.jp/contests/abc159/tasks/abc159_d"

#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ll n;
    cin>>n;

    ll i;
    vector<ll>V(n);
    for(i=0;i!=n;i++)
        cin>>V[i];

    vector<ll>C(n+1,0);
    for(i=0;i!=n;i++)
        C[V[i]]++;

    ll c = 0;
    for(i=0;i!=n+1;i++)
        c += (C[i]-1) * C[i]/2;

    for(i=0;i!=n;i++)
        cout<<c - C[V[i]] + 1<<'\n';

    return 0;
}
