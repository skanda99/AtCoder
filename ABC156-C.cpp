
// problem: "https://atcoder.jp/contests/abc156/tasks/abc156_c"

#include<bits/stdc++.h>
#define ll long long

using namespace std;

int minPts(int x,vector<int>&V,int n)
{
    int i,s=0;
    for(i=0;i!=n;i++)
        s += (x-V[i])*(x-V[i]);

    return s;
}

int main()
{
    int n;
    cin>>n;

    int i;
    vector<int>V(n);
    for(i=0;i!=n;i++)
        cin>>V[i];

    int s = 0;
    for(i=0;i!=n;i++)
        s += V[i];

    int x = s/n;
    x = min(minPts(x,V,n),minPts(x+1,V,n));

    cout<<x;

    return 0;
}
