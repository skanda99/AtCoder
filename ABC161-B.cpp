
// problem: "https://atcoder.jp/contests/abc161/tasks/abc161_b"

#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;

    int i;
    vector<int>V(n);
    for(i=0;i!=n;i++)
        cin>>V[i];

    sort(V.begin(),V.end(),greater<int>());
    int s = 0;
    for(i=0;i!=n;i++)
        s += V[i];

    if(V[m-1] < s/(4.0*m))
        cout<<"No";
    else
        cout<<"Yes";

    return 0;
}
