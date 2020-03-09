
// problem: "https://atcoder.jp/contests/abc153/tasks/abc153_c"

#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ll n,k;
    cin>>n>>k;

    vector<ll>V(n);
    int i;

    for(i=0;i!=n;i++)
        cin>>V[i];

    sort(V.begin(),V.end(),greater<ll>());

    ll sum = 0;
    for(i=k;i<n;i++)
        sum += V[i];

    cout<<sum;

    return 0;
}
