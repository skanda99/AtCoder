
// problem: "https://atcoder.jp/contests/abc126/tasks/abc126_d"

#include<iostream>
#include<vector>
#include<utility>
#define mP(x,y) pair<int,int>(x,y)

using namespace std;

void dfs(vector<pair<int,int>>G[],vector<bool>&C,int n,int i,vector<bool>&V)
{
    if(V[i])
        return;

    V[i] = 1;
    int j;
    for(j=0;j!=G[i].size();j++)
    {
        if(!V[G[i][j].first])
        {
            if(!(G[i][j].second%2))
                C[G[i][j].first] = C[i];

            else
                C[G[i][j].first] = !C[i];

            dfs(G,C,n,G[i][j].first,V);
        }
    }
}

int main()
{
    int n,m;
    cin>>n;

    m = n;
    vector<pair<int,int>>G[n+1];
    while(--n)
    {
        int x,y,w;

        cin>>x>>y>>w;

        G[x].push_back(mP(y,w));
        G[y].push_back(mP(x,w));
    }

    vector<bool>C(m+1,false);
    vector<bool>V(m+1,false);
    dfs(G,C,m,1,V);         // define

    int i;
    for(i=1;i!=m+1;i++)
        cout<<C[i]<<'\n';

    return 0;
}
