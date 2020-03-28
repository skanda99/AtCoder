
// problem: "https://atcoder.jp/contests/abc160/tasks/abc160_b"

#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ll x;
    cin>>x;

    cout<<1000 * (x/500) + ((x%500)/5) * 5;

    return 0;
}
