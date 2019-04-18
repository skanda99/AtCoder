
// problem: "https://atcoder.jp/contests/abc122/tasks/abc122_d"

#include<iostream>
#include<vector>
#include<string>
#include<map>
#define ll long long
#define p 1000000007

using namespace std;

vector<string>C = {"A","C","G","T"};
vector<map<string,ll>>M(101);

ll num(ll n,string s)
{
    if(s=="AGC")
        return 0;
    else if(s=="ACG")
        return 0;
    else if(s=="GAC")
        return 0;
    else if(n==0)
        return 1;


    if(M[n].find(s) == M[n].end())
    {
        if(s=="AGC")
            M[n][s] = 0;
        else if(s=="ACG")
            M[n][s] = 0;
        else if(s=="GAC")
            M[n][s] = 0;
        else if(s[2]=='C' && (s[1]=='G' || s[0]=='G'))
        {
            M[n][s] = 0;
            ll i;
            for(i=1;i!=4;i++)
                M[n][s] = (M[n][s]+num(n-1,C[i]+s[0]+s[1]))%p;
        }
        else
        {
            M[n][s] = 0;
            ll i;
            for(i=0;i!=4;i++)
                M[n][s] = (M[n][s]+num(n-1,C[i]+s[0]+s[1]))%p;
        }
    }

    return M[n][s];
}

int main()
{
    ll n;
    cin>>n;

    ll ans,i,j,k;
    ans = 0;
    for(i=0;i!=4;i++)
        for(j=0;j!=4;j++)
            for(k=0;k!=4;k++)
                ans = (ans+num(n-3,C[i]+C[j]+C[k]))%p;      // define num()

    cout<<ans;
    return 0;
}
