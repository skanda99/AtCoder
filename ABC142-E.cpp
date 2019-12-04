
// problem: "https://atcoder.jp/contests/abc142/tasks/abc142_e"

#include<bits/stdc++.h>

using namespace std;

int minCost(int j,int i,vector<vector<int>>&dp,vector<int>&Cost,vector<int>&State,int n)
{
    if(i == (1<<n)-1)
        return 0;

    if(j == -1)
        return (int)(1e9);

    if(dp[j][i] == -1)
        dp[j][i] = min(minCost(j-1,i,dp,Cost,State,n),Cost[j]+minCost(j-1,i|State[j],dp,Cost,State,n));

    return dp[j][i];
}

int main()
{
    int n,m;

    cin>>n>>m;

    vector<int>Cost,State;
    int i,j;

    for(i=0;i!=m;i++)
    {
        int a,b,s;
        cin>>a>>b;

        Cost.push_back(a);

        s = 0;
        for(j=0;j!=b;j++)
        {
            int x;

            cin>>x;

            s += 1<<(x-1);
        }

        State.push_back(s);
    }

    vector<vector<int>>dp(m,vector<int>((1<<n),-1));

    if(minCost(m-1,0,dp,Cost,State,n) > 1e8)    // define
        cout<<-1;
    else
        cout<<minCost(m-1,0,dp,Cost,State,n);

    return 0;
}
