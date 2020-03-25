
// problem: "https://atcoder.jp/contests/abc157/tasks/abc157_d"

#include<bits/stdc++.h>
#define Pair pair<int,int>

using namespace std;

int Parent(int p,vector<int>&P)
{
    while(P[p] != -1)
        p = P[p];

    return p;
}

int DFS(int i,vector<int>G[],int n,vector<int>&S)
{
    int j,c;
    c = 1;
    for(j=0;j!=G[i].size();j++)
    {
        if(S[G[i][j]] == -1)
        {
            S[G[i][j]] = 0;
            c += DFS(G[i][j],G,n,S);
        }
    }

    return c;
}

void setS(int i,vector<int>G[],int n,vector<int>&S,int p)
{
    int j;
    for(j=0;j!=G[i].size();j++)
    {
        if(S[G[i][j]] != p)
        {
            S[G[i][j]] = p;
            setS(G[i][j],G,n,S,p);
        }
    }
}

void countFriends(vector<int>G[],int n,vector<Pair>&F,int m,vector<Pair>&B,int k)
{
    vector<int>S(n+1,-1);
    int i;
    for(i=1;i!=n+1;i++)
    {
        if(S[i] == -1)
        {
            S[i] = 0;
            S[i] = DFS(i,G,n,S);      // define
            setS(i,G,n,S,S[i]);
        }
    }

    vector<int>P(n+1,-1);
    for(i=0;i!=m;i++)
    {
        int p1,p2;
        p1 = Parent(F[i].first,P);      // define
        p2 = Parent(F[i].second,P);     // define

        if(p1 != p2)
            P[max(p2,p1)] = min(p1,p2);
    }

    vector<int>Block(n+1,0);
    for(i=0;i!=k;i++)
    {
        if(Parent(B[i].first,P) == Parent(B[i].second,P))
        {
            Block[B[i].first]++;
            Block[B[i].second]++;
        }
    }

    // test
    // for(i=1;i!=n+1;i++)
    //     cout<<S[i]<<' ';
    //
    // cout<<'\n';
    // for(i=1;i!=n+1;i++)
    //     cout<<P[i]<<' ';
    //
    // cout<<'\n';
    // for(i=1;i!=n+1;i++)
    //     cout<<Block[i]<<' ';
    //
    // cout<<'\n';

    for(i=1;i!=n+1;i++)
        cout<<S[i]-1-Block[i]-(int)G[i].size()<<' ';

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m,k;
    cin>>n>>m>>k;

    vector<int>G[n+1];
    vector<Pair>F;
    int i;
    for(i=0;i!=m;i++)
    {
        int x,y;
        cin>>x>>y;

        G[x].push_back(y);
        G[y].push_back(x);

        F.push_back(Pair(min(x,y),max(x,y)));
    }

    sort(F.begin(),F.end());

    vector<Pair>B;
    for(i=0;i!=k;i++)
    {
        int x,y;
        cin>>x>>y;

        B.push_back(Pair(x,y));
    }

    countFriends(G,n,F,m,B,k);      // define

    return 0;
}
