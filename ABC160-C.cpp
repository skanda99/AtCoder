
// problem: "https://atcoder.jp/contests/abc160/tasks/abc160_c"

#include<bits/stdc++.h>

using namespace std;

int main()
{
    int k,n;
    cin>>k>>n;

    vector<int>V(n);
    int i;
    for(i=0;i!=n;i++)
        cin>>V[i];

    sort(V.begin(),V.end());
    int m = 0;
    for(i=1;i!=n;i++)
        m = max(m,V[i]-V[i-1]);

    m = max(m,k-V[n-1]+V[0]);
    cout<<k-m;

    return 0;
}
