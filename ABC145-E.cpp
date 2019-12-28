
// problem: "https://atcoder.jp/contests/abc145/tasks/abc145_e"

#include<bits/stdc++.h>
#define Pair pair<int,int>

using namespace std;

bool func (Pair p1,Pair p2)
{
    if(p1.first == p2.first)
        return p1.second < p2.second;

    return p1.first > p2.first;
}

int maxH(int n,vector<Pair>&A,int t,vector<vector<int>>&V)
{
    if(n < 0 || t <= 0)
        return 0;

    if(V[n][t] == -1)
        V[n][t] = max(maxH(n-1,A,t-A[n].first,V)+A[n].second,maxH(n-1,A,t,V));

    return V[n][t];
}

int main()
{
    int n,t;
    cin>>n>>t;

    int i,a,b;
    vector<Pair>A;

    for(i=0;i!=n;i++)
    {
        cin>>a>>b;
        A.push_back(Pair(a,b));
    }

    sort(A.begin(),A.end(),func);       // define

    vector<vector<int>>V(n,vector<int>(t+1,-1));
    cout<<maxH(n-1,A,t,V);        // define

    // Test code
    // vector<Pair>B;
    // B.push_back(Pair(14,4));
    // B.push_back(Pair(12,3));
    // B.push_back(Pair(10,8));
    // B.push_back(Pair(20,4));
    // B.push_back(Pair(12,2));
    // B.push_back(Pair(14,1));
    // B.push_back(Pair(14,3));
    //
    // sort(B.begin(),B.end(),func);
    //
    // for(i=0;i!=7;i++)
    //     cout<<B[i].first<<' '<<B[i].second<<'\n';

    return 0;
}
