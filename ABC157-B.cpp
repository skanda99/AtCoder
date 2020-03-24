
// problem: "https://atcoder.jp/contests/abc157/tasks/abc157_b"

#include<bits/stdc++.h>

using namespace std;

void isIn(int x,vector<vector<int>>&V)
{
    int i,j;
    for(i=0;i!=3;i++)
        for(j=0;j!=3;j++)
            if(V[i][j] == x)
                V[i][j] = 0;
}

bool Diag(vector<vector<int>>&V)
{
    if(V[0][0] == 0 && V[1][1] == 0 && V[2][2] == 0)
        return true;

    return V[2][0] == 0 && V[1][1] == 0 && V[0][2] == 0;
}

bool Row(vector<vector<int>>&V)
{
    int i;
    for(i=0;i!=3;i++)
        if(V[i][0] == 0 && V[i][1] == 0 && V[i][2] == 0)
            return true;

    return false;
}

bool Col(vector<vector<int>>&V)
{
    int i;
    for(i=0;i!=3;i++)
    if(V[0][i] == 0 && V[1][i] == 0 && V[2][i] == 0)
        return true;

    return false;
}

bool checkZero(vector<vector<int>>&V)
{
    return Diag(V) || Row(V) || Col(V);     // define
}

int main()
{
    vector<vector<int>>V(3,vector<int>(3,0));
    int i,j;
    for(i=0;i!=3;i++)
        for(j=0;j!=3;j++)
            cin>>V[i][j];

    int n,x;
    cin>>n;
    while(n--)
    {
        cin>>x;
        isIn(x,V);      // define
    }

    if(checkZero(V))        // define
        cout<<"Yes";
    else
        cout<<"No";

    return 0;
}
