
// problem: "https://atcoder.jp/contests/abc140/tasks/abc140_c"

#include<bits/stdc++.h>

using namespace std;

int main()
{

    int n;
    cin>>n;

    vector<int>V;
    int i,s,x;

    for(i=0;i!=n-1;i++)
    {
        cin>>x;
        V.push_back(x);
    }

    s = V[n-2];

    for(i=n-3;i>=0;i--)
        s += min(V[i],V[i+1]);

    s += V[0];

    cout<<s;

    return 0;
}
