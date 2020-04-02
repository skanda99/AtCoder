
// problem: "https://atcoder.jp/contests/agc043/tasks/agc043_a"

#include<bits/stdc++.h>

using namespace std;

int valOf(vector<string>&M,int i,int j,vector<vector<int>>&V)
{
    if(i-1 >= 0 && j-1 >= 0)
    {
        if(M[i][j] == '.')
            return min(V[i-1][j],V[i][j-1]);
        else
        {
            int x,y;

            if(M[i-1][j] == '.')
                x = V[i-1][j]+1;
            else
                x = V[i-1][j];

            if(M[i][j-1] == '.')
                y = V[i][j-1]+1;
            else
                y = V[i][j-1];

            return min(x,y);
        }
    }
    else if(j == 0 && i != 0)
    {
        if(M[i][j] == '.')
            return V[i-1][j];
        else
        {
            if(M[i-1][j] == '.')
                return V[i-1][j]+1;
            else
                return V[i-1][j];
        }
    }
    else if(j != 0 && i == 0)
    {
        if(M[i][j] == '.')
            return V[i][j-1];
        else
        {
            if(M[i][j-1] == '.')
                return V[i][j-1]+1;
            else
                return V[i][j-1];
        }
    }

    if(M[i][j] == '.')
        return 0;

    return 1;
}

int minFlips(vector<string>&M,int h,int w)
{
    vector<vector<int>>V(h,vector<int>(w,0));
    int i,j;

    for(i=0;i!=h;i++)
        for(j=0;j!=w;j++)
            V[i][j] = valOf(M,i,j,V);         // define

    return V[h-1][w-1];
}

int main()
{
    int h,w;
    cin>>h>>w;

    vector<string>M(h);
    int i;
    for(i=0;i!=h;i++)
        cin>>M[i];

    cout<<minFlips(M,h,w);      // define

    return 0;
}
