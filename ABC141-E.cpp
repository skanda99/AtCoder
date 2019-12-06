
// problem: "https://atcoder.jp/contests/abc141/tasks/abc141_e"

#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    string s;

    cin>>n>>s;

    int i,j;

    vector<vector<int>>V(n+1,vector<int>(n+1,0));

    for(i=0;i!=n;i++)
    {
        for(j=0;j!=n;j++)
        {
            if(s[i] == s[j])
                V[i+1][j+1] = min(V[i][j]+1,j-i);
            else
                V[i+1][j+1] = 0;
        }
    }

    int m = 0;
    for(i=1;i!=n+1;i++)
        for(j=i+1;j!=n+1;j++)
            m = max(m,V[i][j]);

    cout<<m;

    return 0;
}
