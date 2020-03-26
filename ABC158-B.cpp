
// problem: "https://atcoder.jp/contests/abc158/tasks/abc158_b"

#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ll n,a,b;
    cin>>n>>a>>b;

    cout<<a * (n/(a+b)) + min(a,n%(a+b));

    return 0;
}
