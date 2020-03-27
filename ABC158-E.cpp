
// problem: "https://atcoder.jp/contests/abc158/tasks/abc158_e"

#include<bits/stdc++.h>
#define ll long long

using namespace std;

ll power(ll a,ll n,ll p)
{
    if(!n)
        return 1;

    ll b = 1;
    if(n%2)
        b = a;

    ll ans = power(a,n/2,p);
    ans = ((ans*ans)%p * b)%p;

    return ans;
}

ll numStr(string &s,ll n,ll p)
{
    if(p == 2 || p == 5)
    {
        ll c,i;
        c = 0;
        for(i=0;i!=n;i++)
            if(stoi(s.substr(i,1))%p == 0)
                c += i+1;

        return c;
    }


    vector<ll>V(n,0);
    ll i,x;
    x = 0;
    for(i=0;i!=n;i++)
    {
        x = ((x * 10)%p + stoi(s.substr(i,1)))%p;       // define
        V[i] = (x * power(power(10,i,p),p-2,p))%p;        // define
    }

    ll c = 0;
    vector<ll>P(p,0);
    for(i=0;i!=n;i++)
    {
        if(V[i] == 0)
            c += 1 + P[V[i]];
        else
            c += P[V[i]];

        P[V[i]]++;
    }

    return c;
}

int main()
{
    ll n,p;
    cin>>n>>p;

    string s;
    cin>>s;

    cout<<numStr(s,n,p);        // define

    return 0;
}
