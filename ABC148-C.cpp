
// problem: "https://atcoder.jp/contests/abc148/tasks/abc148_c"

#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ll a,b,m;
    cin>>a>>b;

    m = min(a,b);

    while(m)
    {
        if(a%m == 0 && b%m == 0)
            break;

        m--;
    }

    cout<<a*b/m;

    return 0;
}
