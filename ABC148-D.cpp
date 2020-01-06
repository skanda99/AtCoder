
// problem: "https://atcoder.jp/contests/abc148/tasks/abc148_d"

#include<bits/stdc++.h>

using namespace std;

int minBreak(vector<int>&V,int n)
{
    int i,j,c;
    j = 1;
    c = 0;

    for(i=0;i!=n;i++)
    {
        if(V[i] == j)
            j++;
        else
            c++;
    }

    if(c == n)
        return -1;
        
    return c;
}

int main()
{
    int n;
    cin>>n;

    int i,x;
    vector<int>V;

    for(i=0;i!=n;i++)
    {
        cin>>x;
        V.push_back(x);
    }

    cout<<minBreak(V,n);        // define

    return 0;
}
