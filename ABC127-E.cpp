
// problem: "https://atcoder.jp/contests/abc127/tasks/abc127_e"

#include<bits/stdc++.h>
#define p 1000000007
#define ll long long

using namespace std;

vector<ll>F(200001,-1);

ll fact(ll n)
{
    if(n == 0)
        return 1;

    if(F[n] == -1)
        F[n] = (n*fact(n-1))%p;

    return F[n];
}

ll power(ll a,ll n)
{
    if(n==0)
        return 1;

    ll b = 1;
    if(n%2)
        b = a;

    a = power(a,n/2);
    ll ans = (((a*a)%p)*b)%p;

    return ans;
}

ll nCm(ll n,ll m)
{
    ll a = fact(n);
    ll b = (fact(n-m)*fact(m))%p;       // define

    ll  ans = (a*power(b,p-2))%p;         // define

    return ans;
}

int main()
{
    ll n,m,k;
    cin>>n>>m>>k;

    ll i;
    ll ans = 0;
    for(i=0;i!=n;i++)
        ans = (ans+(((((m*m)%p)*i)%p)*(n-i))%p)%p;
    for(i=0;i!=m;i++)
        ans = (ans+(((((n*n)%p)*i)%p)*(m-i))%p)%p;

    cout<<(ans*nCm(n*m-2,k-2))%p;       // define

    return 0;
}
