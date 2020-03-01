
// problem: "https://atcoder.jp/contests/abc151/tasks/abc151_d"

#include<bits/stdc++.h>
#define Pair pair<int,int>

using namespace std;

struct Node
{
    int i,j,n;

    Node(int i,int j,int n) : i(i),j(j),n(n) {}
};

int bfs(vector<vector<bool>>&M,int h,int w,int i,int j)
{

    queue<Node>Q;
    Q.push(Node(i,j,0));
    vector<vector<bool>>V(h,vector<bool>(w,0));
    V[i][j] = true;

    while(!Q.empty())
    {
        Node p = Q.front();
        Q.pop();

        if(p.i-1 >= 0 && p.j >= 0 && M[p.i-1][p.j] && !V[p.i-1][p.j])
        {
            V[p.i-1][p.j] = true;
            Q.push(Node(p.i-1,p.j,p.n+1));
        }

        if(p.i >= 0 && p.j-1 >= 0 && M[p.i][p.j-1] && !V[p.i][p.j-1])
        {
            V[p.i][p.j-1] = true;
            Q.push(Node(p.i,p.j-1,p.n+1));
        }

        if(p.i+1 < h && p.j >= 0 && M[p.i+1][p.j] && !V[p.i+1][p.j])
        {
            V[p.i+1][p.j] = true;
            Q.push(Node(p.i+1,p.j,p.n+1));
        }

        if(p.i >= 0 && p.j+1 < w && M[p.i][p.j+1] && !V[p.i][p.j+1])
        {
            V[p.i][p.j+1] = true;
            Q.push(Node(p.i,p.j+1,p.n+1));
        }

        if(Q.empty())
            return p.n;
    }

    return -1;
}

int MaxDist(vector<vector<bool>>&M,int h,int w)
{
    int Max = 0;
    int i,j;
    for(i=0;i!=h;i++)
    {
        for(j=0;j!=w;j++)
        {
            if(M[i][j])
            {
                Max = max(Max,bfs(M,h,w,i,j));      // define
            }
        }
    }

    return Max;
}

int main()
{
    int h,w;
    cin>>h>>w;

    int i,j;
    char c;
    vector<vector<bool>>M(h,vector<bool>(w,0));

    for(i=0;i!=h;i++)
    {
        for(j=0;j!=w;j++)
        {
            cin>>c;

            if(c == '.')
                M[i][j] = true;

            else
                M[i][j] = false;
        }
    }

    cout<<MaxDist(M,h,w);       // define

    return 0;
}
