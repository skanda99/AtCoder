
// problem: "https://atcoder.jp/contests/abc126/tasks/abc126_e"

#include<iostream>
#include<vector>

using namespace std;

bool dfs(vector<int>G[],int i,vector<bool>&V)
{
    if(V[i])
        return false;

    V[i] = true;
    int j;
    for(j=0;j!=G[i].size();j++)
        dfs(G,G[i][j],V);

    return true;
}

int main()
{
    int n,m;
    cin>>n>>m;

    vector<int>G[n+1];
    while(m--)
    {
        int x,y,z;
        cin>>x>>y>>z;

        G[x].push_back(y);
        G[y].push_back(x);
    }

    int i,c;
    c = 0;
    vector<bool>V(n+1,false);
    for(i=1;i!=n+1;i++)
        if(dfs(G,i,V))
            c++;

    cout<<c;

    return 0;
}
