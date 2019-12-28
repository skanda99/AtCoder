
// problem: "https://atcoder.jp/contests/abc145/tasks/abc145_c"

#include<bits/stdc++.h>
#define ll long long
#define Pair pair<ll,ll>

using namespace std;

int main()
{
    ll n,i;

    cin>>n;

    ll x,y;
    vector<Pair>V;

    for(i=0;i!=n;i++)
    {
        cin>>x>>y;
        V.push_back(Pair(x,y));
    }

    ll j;
    double s = 0.0;
    for(i=0;i!=n-1;i++)
    {
        for(j=i+1;j!=n;j++)
        {
            s += sqrt(pow(V[i].first-V[j].first,2) + pow(V[i].second-V[j].second,2));
        }
    }

    cout<<fixed;
    cout<<setprecision(12)<<s * 2.0 / n;

    return 0;
}
