
// problem: "https://atcoder.jp/contests/abc147/tasks/abc147_e"

#include<bits/stdc++.h>
#define p 6401*2

using namespace std;

int minD(vector<vector<int>>&A,vector<vector<int>>&B,int h,int w)
{
    vector<vector<int>>D(h,vector<int>(w,0));
    int i,j;
    for(i=0;i!=h;i++)
        for(j=0;j!=w;j++)
            D[i][j] = abs(A[i][j]-B[i][j]);

    vector<vector<vector<bool>>>V(h,vector<vector<bool>>(w,vector<bool>(p,false)));
    int k;

    V[0][0][D[0][0]] = true;
    for(i=0;i!=h;i++)
    {
        for(j=0;j!=w;j++)
        {
            if(i-1 >= 0)
            {
                for(k=0;k!=p;k++)
                {
                    if(V[i-1][j][k])
                    {
                        V[i][j][abs(D[i][j]-k)] = true;
                        V[i][j][abs(D[i][j]+k)] = true;
                    }
                }
            }

            if(j-1 >= 0)
            {
                for(k=0;k!=p;k++)
                {
                    if(V[i][j-1][k])
                    {
                        V[i][j][abs(D[i][j]-k)] = true;
                        V[i][j][abs(D[i][j]+k)] = true;
                    }
                }
            }
        }
    }

    for(k=0;k!=p;k++)
        if(V[h-1][w-1][k])
            break;

    return k;
}

int main()
{
    int h,w;
    cin>>h>>w;

    int i,j;
    vector<vector<int>>A(h,vector<int>(w,0));
    for(i=0;i!=h;i++)
    {
        for(j=0;j!=w;j++)
        {
            int x;
            cin>>x;
            A[i][j] = x;
        }
    }

    vector<vector<int>>B(h,vector<int>(w,0));
    for(i=0;i!=h;i++)
    {
        for(j=0;j!=w;j++)
        {
            int x;
            cin>>x;
            B[i][j] = x;
        }
    }

    cout<<minD(A,B,h,w);        // define

    return 0;
}
