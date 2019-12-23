
// problem: "https://atcoder.jp/contests/abc144/tasks/abc144_e"

#include<bits/stdc++.h>
#define ll long long

using namespace std;

ll binarySearch(ll l,ll r,vector<ll>&A,vector<ll>&F,ll K)
{
    if(l > r)
        return LLONG_MAX;

    ll i,m,k;
    k = K;
    m = (l+r)/2;

    for(i=0;i!=A.size();i++)
    {
        if(A[i]*F[i] > m)
            k = k - ceil(A[i]-m*1.0/F[i]);

        if(k < 0)
            return binarySearch(m+1,r,A,F,K);
    }

    return min(m,binarySearch(l,m-1,A,F,K));
}

int main()
{
    ll n,k;
    cin>>n>>k;

    vector<ll>A,F;
    ll i,x;

    for(i=0;i!=n;i++)
    {
        cin>>x;
        A.push_back(x);
    }

    for(i=0;i!=n;i++)
    {
        cin>>x;
        F.push_back(x);
    }

    sort(A.begin(),A.end());
    sort(F.begin(),F.end(),greater<ll>());

    cout<<binarySearch(0,(ll)(1e12),A,F,k);       // define

    return 0;
}
