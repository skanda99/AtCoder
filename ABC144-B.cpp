
// problem: "https://atcoder.jp/contests/abc144/tasks/abc144_b"

#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;

    cin>>n;

    int i,j;

    for(i=1;i!=10;i++)
        for(j=1;j!=10;j++)
            if(i*j == n)
            {
                cout<<"Yes";
                exit(0);
            }

    cout<<"No";
    
    return 0;
}
