
// problem: "https://atcoder.jp/contests/abc149/tasks/abc149_b"

#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ll a,b,k;
    cin>>a>>b>>k;

    if(a < k)
    {
        b = b-(k-a);

        if(b < 0)
            b = 0;
            
        a = 0;
    }
    else
    {
        a = a-k;
    }

    cout<<a<<' '<<b;

    return 0;
}
