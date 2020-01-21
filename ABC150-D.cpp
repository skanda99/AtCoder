
// problem: "https://atcoder.jp/contests/abc150/tasks/abc150_d"

#include<bits/stdc++.h>
#define ll unsigned long long

using namespace std;

ll GCD(ll a,ll b)
{
    if(a < b)
        return GCD(b,a);

    if(b == 0)
        return a;

    return GCD(b,a%b);
}

ll LCM(vector<ll>&V,ll i,ll lcm)
{
    return (V[i]*lcm) / GCD(V[i],lcm);      // define
}

ll SCM(vector<ll>&V,ll n,ll m)
{
    ll i;
    for(i=0;i!=n;i++)
        V[i] = V[i]/2;


    ll lcm = V[0],l;
    for(i=0;i!=n;i++)
    {
        l = LCM(V,i,lcm);     // define

        if((l/lcm)%2 == 0 || (l/V[i])%2 == 0 || l > m)
            return 0;

        lcm = l;
    }

    ll M = (m-(m%lcm))/lcm;

    return M/2 + M%2;
}

int main()
{
    ll n,m;
    cin>>n>>m;

    vector<ll>V;
    ll i,x;
    for(i=0;i!=n;i++)
    {
        cin>>x;
        V.push_back(x);

        if(x%2 == 1)
        {
            cout<<0;
            exit(0);
        }
    }

    cout<<SCM(V,n,m);       //define

    return 0;
}
