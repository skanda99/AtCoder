
// problem: "https://atcoder.jp/contests/abc144/tasks/abc144_d"

#include<bits/stdc++.h>
#define lf double
#define ll long long

using namespace std;

int main()
{
    ll a,b,x;
    cin>>a>>b>>x;

    lf theta = atan(a*a*a*1.0/(2.0*(a*a*b-x)));

    if(x >= a*a*a/(2.0*tan(theta)))
        cout<<setprecision(12)<<90.0 - theta * 180.0 / M_PI;
    else
        cout<<setprecision(12)<<90.0 - atan(2.0*x/(a*b*b)) * 180.0 / M_PI;

    return 0;
}
