
// problem: "https://atcoder.jp/contests/abc147/tasks/abc147_d"

#include<bits/stdc++.h>
#define ll long long
#define p (ll)(1e9+7)

using namespace std;

ll XORSUM (vector<ll>&V,ll n)
{
    ll s,i,j,m;
    s = i = 0;

    while(i < 61)
    {
        m = 0;
        for(j=0;j!=n;j++)
        {
            if(V[j]&1)
                m++;

            V[j] = V[j]>>1;
        }

        s = (s+(((m*(n-m))%p)*((((ll)1)<<i)%p))%p)%p;
        i++;
    }

    return s;
}

int main()
{

    ll n;
    cin>>n;

    ll i;
    vector<ll>V;
    for(i=0;i!=n;i++)
    {
        ll x;
        cin>>x;

        V.push_back(x);
    }

    cout<<XORSUM(V,n);      // define

    return 0;
}
