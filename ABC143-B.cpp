
// problem: "https://atcoder.jp/contests/abc143/tasks/abc143_b"

#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;

    int i,x;
    vector<int>V;

    for(i=0;i!=n;i++)
    {
        cin>>x;
        V.push_back(x);
    }

    int s,S;

    s = S = 0;
    for(i=0;i!=n;i++)
    {
        s += V[i];
        S += V[i]*V[i];
    }

    cout<<(s*s-S)/2;

    return 0;
}
