
// problem: "https://atcoder.jp/contests/abc120/tasks/abc120_b"

#include<iostream>

using namespace std;

int gcd(int a,int b)
{
    if(b==0)
        return a;

    return gcd(b,a%b);
}

int main()
{
    int A,B,K;
    cin>>A>>B>>K;

    int g = gcd(max(A,B),min(A,B));
    int k,i;
    k = 0;
    for(i=g;i>0;i--)
    {
        if(g%i==0)
            k++;

        if(k==K)
            break;
    }

    cout<<i;

    return 0;
}
