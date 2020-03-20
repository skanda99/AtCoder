
// problem: "https://atcoder.jp/contests/abc155/tasks/abc155_e"

#include<bits/stdc++.h>
#define ll long long

using namespace std;


ll minNotes(string &s,vector<vector<ll>>&V,ll i,ll n,ll p)
{
    if(i == n)
        return 0;

    if(V[i][p] == -1)
    {
        if(!p)
            V[i][p] = min((ll)(s[i]-'0') + minNotes(s,V,i+1,n,p), 10 - (ll)(s[i]-'0') + (i == n-1) + minNotes(s,V,i+1,n,!p));

        else
            V[i][p] = min(9 - (ll)(s[i]-'0') + (i == n-1) + minNotes(s,V,i+1,n,p), 1 + (ll)(s[i]-'0') + minNotes(s,V,i+1,n,!p));
    }

    return V[i][p];
}

int main()
{
    string s;
    cin>>s;

    vector<vector<ll>>V(s.size(),vector<ll>(2,-1));
    cout<<minNotes(s,V,0,s.size(),0);     // define

    return 0;
}
