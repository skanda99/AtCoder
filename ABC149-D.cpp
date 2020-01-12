
// problem: "https://atcoder.jp/contests/abc149/tasks/abc149_d"

#include<bits/stdc++.h>

using namespace std;

int maxP(int n,char c,int k,map<char,vector<int>>&M,string &t,int r,int s,int p)
{
    if(n < 0)
        return 0;

    if(M[c][n] == -1)
    {
        int m = 0;

        if(c != 'r' && t[n] == 's')
            m = max(m,maxP(n-k,'r',k,M,t,r,s,p)+r);

        if(c != 's' && t[n] == 'p')
            m = max(m,maxP(n-k,'s',k,M,t,r,s,p)+s);

        if(c != 'p' && t[n] == 'r')
            m = max(m,maxP(n-k,'p',k,M,t,r,s,p)+p);

        if(c == 'r')
        {
            m = max(m,maxP(n-k,'p',k,M,t,r,s,p));
            m = max(m,maxP(n-k,'s',k,M,t,r,s,p));
        }

        if(c == 'p')
        {
            m = max(m,maxP(n-k,'r',k,M,t,r,s,p));
            m = max(m,maxP(n-k,'s',k,M,t,r,s,p));
        }

        if(c == 's')
        {
            m = max(m,maxP(n-k,'p',k,M,t,r,s,p));
            m = max(m,maxP(n-k,'r',k,M,t,r,s,p));
        }

        M[c][n] = m;
    }

    return M[c][n];
}

int main()
{
    int n,k,r,s,p;
    cin>>n>>k>>r>>s>>p;

    string t;
    cin>>t;

    map<char,vector<int>>M;
    M['r'] = vector<int>(n+1,-1);
    M['s'] = vector<int>(n+1,-1);
    M['p'] = vector<int>(n+1,-1);
    M['n'] = vector<int>(n+1,-1);

    int i,S;
    S = 0;
    for(i=n-1;i>n-1-k;i--)
        S += maxP(i,'n',k,M,t,r,s,p);       // define

    cout<<S;

    return 0;
}
