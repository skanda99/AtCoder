
// problem: "https://atcoder.jp/contests/abc153/tasks/abc153_d"

#include<bits/stdc++.h>
#define ll long long

using namespace std;

ll numMoves(ll H)
{
    if(!H)
        return 0;

    return 2*numMoves(H/2) + 1;
}

int main()
{
    ll h;
    cin>>h;

    cout<<numMoves(h);      // define

    return 0;
}
