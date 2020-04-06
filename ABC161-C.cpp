
// problem: "https://atcoder.jp/contests/abc161/tasks/abc161_c"

#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ll a,b;
    cin>>a>>b;

    cout<<min(a%b,abs(a%b - b));

    return 0;
}
