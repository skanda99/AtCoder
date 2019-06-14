
// problem: "https://atcoder.jp/contests/abc129/tasks/abc129_d"

#include<bits/stdc++.h>

using namespace std;

struct node
{
    int l,r,u,d;
};

int main()
{
    int h,w;
    cin>>h>>w;
    string s;
    vector<string>S(h);
    int i,j;
    for(i=0;i!=h;i++)
        cin>>S[i];

    vector<vector<node>>V(h,vector<node>(w));

    for(i=0;i!=h;i++)
    {
        // storing left occupied indices
        for(j=0;j!=w;j++)
        {
            if(j==0 && S[i][j]!='#')
                V[i][j].l = -1;
            else if(S[i][j] == '#')
                V[i][j].l = j;
            else
                V[i][j].l = V[i][j-1].l;
        }

        // storing right occupied indices
        for(j=w-1;j>=0;j--)
        {
            if(j==w-1 && S[i][j]!='#')
                V[i][j].r = w;
            else if(S[i][j]=='#')
                V[i][j].r = j;
            else
                V[i][j].r = V[i][j+1].r;
        }
    }

    for(j=0;j!=w;j++)
    {
        // storing top occupied indices
        for(i=0;i!=h;i++)
        {
            if(i==0 && S[i][j]!='#')
                V[i][j].u = -1;
            else if(S[i][j]=='#')
                V[i][j].u = i;
            else
                V[i][j].u = V[i-1][j].u;
        }

        // storing down occupied indices
        for(i=h-1;i>=0;i--)
        {
            if(i==h-1 && S[i][j]!='#')
                V[i][j].d = h;
            else if(S[i][j]=='#')
                V[i][j].d = i;
            else
                V[i][j].d = V[i+1][j].d;
        }
    }

    int M = 0;
    for(i=0;i!=h;i++)
    {
        for(j=0;j!=w;j++)
        {
            M = max(M,j-V[i][j].l-1 + V[i][j].r-j-1 + i-V[i][j].u-1 + V[i][j].d-i-1 + 1);
        }
    }

    cout<<M;

    return 0;
}
