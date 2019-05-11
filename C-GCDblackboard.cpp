
// problem: "https://atcoder.jp/contests/abc125/tasks/abc125_c"

#include<iostream>
#include<vector>

using namespace std;

int gcd(int a,int b)
{
    if(b==0)
        return a;

    if(a>b)
        return gcd(b,a%b);
    else
        return gcd(a,b%a);
}

int main()
{
    int n;
    cin>>n;

    vector<int>V(n);
    vector<int>L(n);
    vector<int>R(n);

    int i;
    for(i=0;i!=n;i++)
        cin>>V[i];

    L[0] = V[0];
    R[n-1] = V[n-1];
    for(i=1;i!=n;i++)
    {
        L[i] = gcd(L[i-1],V[i]);
        R[n-i-1] = gcd(R[n-i],V[n-i-1]);
    }

    int m;
    m = L[n-2];
    for(i=1;i!=n-1;i++)
        m = max(m,gcd(L[i-1],R[i+1]));

    m = max(m,R[1]);

    cout<<m;

    return 0;
}
