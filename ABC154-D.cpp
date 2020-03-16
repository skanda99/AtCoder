
// problem: "https://atcoder.jp/contests/abc154/tasks/abc154_d"

#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;

    vector<int>V(n);
    int i;
    for(i=0;i!=n;i++)
        cin>>V[i];

    for(i=1;i!=n;i++)
        V[i] += V[i-1];

    for(i=n-1;i!=k-1;i--)
        V[i] -= V[i-k];

    double ans = 0.0;

    for(i=k-1;i!=n;i++)
        ans = max(ans,(V[i]+k)/2.0);

    cout<<fixed;
    cout<<setprecision(12)<<ans;

    return 0;
}
