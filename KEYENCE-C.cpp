
// problem: "https://atcoder.jp/contests/keyence2020/tasks/keyence2020_c"

#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ll n,k,s;
    cin>>n>>k>>s;

    vector<ll>V;
    while(k-- && n--)
        V.push_back(s);

    if(s != (ll)(1e9))
        while(n--)
            V.push_back(s+1);

    else
        while(n--)
            V.push_back(1);

    ll i;
    for(i=0;i!=V.size();i++)
        cout<<V[i]<<' ';

    return 0;
}
