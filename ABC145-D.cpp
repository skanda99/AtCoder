
// problem: "https://atcoder.jp/contests/abc145/tasks/abc145_d"

#include<bits/stdc++.h>
#define ll long long
#define p (ll)(1e9+7)

using namespace std;

ll fact(ll n,vector<ll>&F)
{
    // if(n == 0)
    //     return 1;
    //
    // //cout<<"Fact: "<<n<<'\n';
    //
    // if(F[n] == -1)
    //     F[n] = (fact(n-1,F)*n)%p;

    return F[n];
}

ll Pow(ll a,ll m)
{
    if(m == 0)
        return 1;

    ll b,c;
    b = 1;

    if(m%2)
        b = a;

    c = Pow(a,m/2);
    a = (((c*c)%p)*b)%p;

    return a;
}

int main()
{
    ll x,y;

    cin>>x>>y;

    ll n1,n2,m1,m2;

    m1 = y-x;
    m2 = (y+x)/3;

    n1 = (m1+m2)/2;
    n2 = (m2-m1)/2;

    if(n1+2*n2 != x || 2*n1+n2 != y || n1 < 0 || n2 < 0)
    {
        cout<<0;
        exit(0);
    }

    vector<ll>F(2000001);
    ll i;
    F[0] = 1;
    for(i=1;i!=2000001;i++)
        F[i] = (i*F[i-1])%p;

    ll a,b;
    a = fact(n1+n2,F);
    b = (fact(n1,F)*fact(n2,F))%p;
    b = Pow(b,p-2);

    cout<<(a*b)%p;

    // Test code
    // ll i;
    // for(i=0;i!=2000001;i++)
    //     cout<<i<<' '<<fact(i,F)<<'\n';

    return 0;
}
