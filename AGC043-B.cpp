
// problem: "https://atcoder.jp/contests/agc043/tasks/agc043_b"

#include<bits/stdc++.h>
#define p 2

using namespace std;

int nCr(int n,int r)
{
    while(n)
    {
        //cout<<n<<' '<<r<<' '<<(n&1)<<' '<<(r&1)<<'\n';
        if((n&1) == 0 && (r&1) == 1)
            return 0;

        n = n>>1;
        r = r>>1;
    }

    return 1;
}

int func(int n,string &s)
{
    int i;
    vector<int>V(n);

    bool one,two,three;
    one = two = three = 0;
    for(i=0;i!=n;i++)
    {
        if(s[i] == '1')
            one = 1;
        else if(s[i] == '2')
            two = 1;
        else
            three = 1;
    }

    if(two)
    {
//        cout<<"Entered two:\n";

        for(i=0;i!=n;i++)
            V[i] = (s[i]-'1')%p;

        int S = 0;
        for(i=0;i!=n;i++)
            if(V[i])
            {
                S = (S + nCr(n-1,i))%p;
//                cout<<S<<'\n';
            }


        if(S)
            return 1;
        else
            return 0;
    }

    for(i=0;i!=n;i++)
    {
        if(s[i] == '1')
            V[i] = 0;
        else
            V[i] = 1;
    }

    int S = 0;
    for(i=0;i!=n;i++)
        if(V[i])
            S = (S + nCr(n-1,i))%p;

    if(S)
        return 2;

    return 0;
}

int main()
{
    int n;
    string s;
    cin>>n>>s;

    cout<<func(n,s)<<'\n';        // define

//    cout<<nCr(9,0)<<' '<<nCr(9,6)<<' '<<nCr(9,9);
    return 0;
}
