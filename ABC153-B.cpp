
// problem: "https://atcoder.jp/contests/abc153/tasks/abc153_b"

#include<bits/stdc++.h>

using namespace std;

int main()
{
    int h,n;
    cin>>h>>n;

    vector<int>A(n);
    int i;

    for(i=0;i!=n;i++)
        cin>>A[i];

    for(i=1;i!=n;i++)
        A[i] += A[i-1];

    (A[n-1] >= h) ? cout<<"Yes" : cout<<"No";

    return 0;
}
