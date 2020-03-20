
// problem: "https://atcoder.jp/contests/abc155/tasks/abc155_d"

#include<bits/stdc++.h>
#define ll long long
#define p1 (ll)(-1e18)
#define p2 (ll)(1e18)

using namespace std;

ll negBS(ll i,ll j,ll M,ll k,vector<ll>&V)
{
    if(i > j)
        return 0;

    ll m = (i+j)/2;

    if(V[k] * V[m] < M)
        return max(negBS(i,m-1,M,k,V),(ll)(V.size()-m));

    return negBS(m+1,j,M,k,V);
}

ll posBS(ll i,ll j,ll M,ll k,vector<ll>&V)
{
    if(i > j)
        return 0;

    ll m = (i+j)/2;

    if(V[k] * V[m] < M)
        return max(posBS(m+1,j,M,k,V),(ll)(m-k));

    return posBS(i,m-1,M,k,V);
}


ll binarySearch(ll l,ll r,vector<ll>&V,ll k)
{
    if(l >= r-1)
        return l;

    ll m = (l+r)/2;
    ll i,c;
    c = 0;
    for(i=0;i!=V.size()-1;i++)
    {
        if(V[i] < 0)
            c += negBS(i+1,V.size()-1,m,i,V);       // define

        else
            c += posBS(i+1,V.size()-1,m,i,V);       // define
    }

    if(c <= k-1)
        return binarySearch(m,r,V,k);

    return binarySearch(l,m,V,k);
}

int main()
{
    ll n,k;
    cin>>n>>k;

    vector<ll>V(n);
    ll i;
    for(i=0;i!=n;i++)
        cin>>V[i];

    sort(V.begin(),V.end());
    cout<<binarySearch(p1,p2,V,k);        // define

    return 0;
}
