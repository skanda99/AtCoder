
// problem: "https://atcoder.jp/contests/abc125/tasks/abc125_d"

#include<iostream>
#include<vector>
#include<limits.h>
#include<math.h>
#define ll long long

using namespace std;

vector<vector<ll>>dp(100001,vector<ll>(2,LONG_MIN));

ll maxim(int i,int x,vector<ll>&V)
{
    if(i == V.size()-1)
        return pow(-1,x)*V[i];

    if(dp[i][x] == LONG_MIN)
        dp[i][x] = max(pow(-1,x)*V[i]+maxim(i+1,0,V),pow(-1,x+1)*V[i]+maxim(i+1,1,V));

    return dp[i][x];
}

int main()
{
    int n;
    cin>>n;

    vector<ll>V(n);
    int i;
    for(i=0;i!=n;i++)
        cin>>V[i];

    cout<<maxim(0,0,V);

    return 0;
}
