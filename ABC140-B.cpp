
// problem: "https://atcoder.jp/contests/abc140/tasks/abc140_b"

#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;

    vector<int>A,B,C;
    B.push_back(-1);
    C.push_back(-1);

    int i,x;

    for(i=0;i!=n;i++)
    {
        cin>>x;
        A.push_back(x);
    }

    for(i=0;i!=n;i++)
    {
        cin>>x;
        B.push_back(x);
    }

    for(i=0;i!=n-1;i++)
    {
        cin>>x;
        C.push_back(x);
    }

    int s = B[A[0]];
    for(i=1;i!=n;i++)
    {
        s += B[A[i]];

        if(A[i] == A[i-1]+1)
            s += C[A[i-1]];
    }

    cout<<s;

    return 0;
}
