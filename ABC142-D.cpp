
// problem: "https://atcoder.jp/contests/abc142/tasks/abc142_d"
#include<bits/stdc++.h>
#define ll long long

using namespace std;

bool isPrime(ll n,vector<ll>&prime,vector<bool>&P)
{
    if(n == 1)
        return true;

    if(n < (ll)(1e6+1))
        return P[n];

    ll m = sqrtl(n);
    ll i;
    i = 0;
    while(i < prime.size() && prime[i] <= m)
    {
        if(n%prime[i] == 0)
            return false;

        i++;
    }

    return true;
}

int main()
{
    ll a,b;
    cin>>a>>b;

    ll Min,Max;
    Min = min(a,b);
    Max = max(a,b);

    ll i,j;
    vector<bool>P((ll)(1e6+1),true);
    vector<ll>prime;

    P[0] = P[1] = 0;
    i = 2;
    while(i < (ll)(1e6+1))
    {
        prime.push_back(i);
        j = 2*i;

        while(j < (ll)(1e6+1))
        {
            P[j] = 0;
            j += i;
        }

        i++;
        while(i < (ll)(1e6+1) && P[i] == 0)
            i++;
    }

    vector<ll>div;
    ll m = sqrtl(Min);
    ll c = 0;

    for(i=1;i<=m;i++)
    {
        if(Min%i==0 && isPrime(i,prime,P))
            div.push_back(i);

        if(Min%i == 0 && Min/i > i && isPrime(Min/i,prime,P))
            div.push_back(Min/i);
    }

    for(i=0;i!=div.size();i++)
    {
        if(Max%div[i] == 0)
            c++;
    }

    // for(i=0;i!=div.size();i++)
    //     cout<<div[i]<<' ';


    cout<<c;

    return 0;
}
