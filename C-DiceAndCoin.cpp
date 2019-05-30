
// problem: "https://atcoder.jp/contests/abc126/tasks/abc126_c"

#include<iostream>
#include<iomanip>
#include<math.h>

using namespace std;

double ans(double n, double k)
{
    double a = 0.0;
    if(n-k+1.0>0.0)
        a = (n-k+1.0)/n;

    for(int i=1;i<min(n+1,k);i++)
        a = a + 1.0/n * (1.0/pow(2.0,ceil(log(k/i)/log(2))));

    return a;
}

int main()
{
    double n,k;
    cin>>n>>k;


    cout<<fixed;
    cout<<setprecision(14)<<ans(n,k);

    return 0;
}
