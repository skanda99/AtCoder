
// problem: "https://atcoder.jp/contests/abc160/tasks/abc160_d"

#include<bits/stdc++.h>

using namespace std;

void bfs(vector<int>G[],int p,vector<vector<int>>&V)
{
    queue<int>Q;
    Q.push(p);
    V[p][p] = 0;

    while(!Q.empty())
    {
        int i = Q.front();
        Q.pop();

        int j;
        for(j=0;j!=G[i].size();j++)
            if(V[p][G[i][j]] == -1)
            {
                V[p][G[i][j]] = V[p][i]+1;
                Q.push(G[i][j]);
            }
    }
}

int main()
{
    int n,x,y;
    cin>>n>>x>>y;

    vector<int>G[n+1];
    int i;
    for(i=1;i!=n;i++)
    {
        G[i].push_back(i+1);
        G[i+1].push_back(i);
    }

    G[x].push_back(y);
    G[y].push_back(x);

    vector<vector<int>>V(n+1,vector<int>(n+1,-1));
    for(i=1;i!=n+1;i++)
        bfs(G,i,V);     // define

    vector<int>C(n,0);
    int j;
    for(i=1;i!=n+1;i++)
        for(j=1;j!=n+1;j++)
            C[V[i][j]]++;

    for(i=1;i!=n;i++)
        cout<<C[i]/2<<'\n';

    return 0;
}
