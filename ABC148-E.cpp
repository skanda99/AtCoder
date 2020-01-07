
// problem: "https://atcoder.jp/contests/abc148/tasks/abc148_e"

#include<bits/stdc++.h>
#define ll long long

using namespace std;

ll count_0(ll n)
{
    if(n%2)
        return 0;
        
    ll c = 0;
    ll i;

    i = 5;
    while(i <= n)
    {
        c += n/(i*2);
        i *= 5;
    }

    return c;
}

int main()
{
    ll n;
    cin>>n;

    cout<<count_0(n);       // define
    return 0;
}
