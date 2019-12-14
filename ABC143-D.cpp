
// problem: "https://atcoder.jp/contests/abc143/tasks/abc143_d"

#include<bits/stdc++.h>
#define ll long long

using namespace std;

ll binarySearch(vector<ll>&V,ll l,ll r,ll n)
{
    if(l > r)
        return r;

    ll m = (l+r)/2;
    if(V[m] == n)
        return max(m,binarySearch(V,m+1,r,n));

    else if(V[m] > n)
        return binarySearch(V,m+1,r,n);

    return binarySearch(V,l,m-1,n);
}

int main()
{
    ll n;
    cin>>n;

    ll i,x;
    vector<ll>V;

    for(i=0;i!=n;i++)
    {
        cin>>x;
        V.push_back(x);
    }

    ll j,c;
    c = 0;

    sort(V.begin(),V.end(),greater<ll>());

    for(i=0;i!=n-2;i++)
        for(j=i+1;j!=n-1;j++)
            c += binarySearch(V,j+1,n-1,V[i]-V[j]+1)-j;

    cout<<c;

    return 0;
}
