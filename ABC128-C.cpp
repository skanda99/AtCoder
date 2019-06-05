
// problem: "https://atcoder.jp/contests/abc128/tasks/abc128_c"

#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,m,i,j,k,x;
    cin>>n>>m;

    //int i;
    vector<unordered_set<int>>V(m);
    for(i=0;i!=m;i++)
    {
        //int j,k;
        cin>>k;

        for(j=0;j!=k;j++)
        {
            //int x;
            cin>>x;
            V[i].insert(x-1);
        }
    }

    vector<int>P(m);
    for(i=0;i!=m;i++)
        cin>>P[i];

    // for(j=0;j!=m;j++)
    // {
    //     for(auto it=V[j].begin();it!=V[j].end();it++)
    //         cout<<*it<<' ';
    //     cout<<'\n';
    // }

    int num = 0;
    for(i=0;i!=(int)pow(2,n);i++)
    {
        vector<int>numSwitch(m,0);
        for(j=1,x=0;j<=i;j=j<<1,x++)
        {
            //cout<<(j&i)<<' ';

            if((j&i)!=0)
            {
                //int k;
                for(k=0;k!=m;k++)
                    if(V[k].find(x)!=V[k].end())     // fill it up
                        numSwitch[k]++;
            }
        }

        //cout<<'\n';
        // for(j=0;j!=m;j++)
        //     cout<<numSwitch[j]<<' ';
        // cout<<'\n';


        int c = 0;
        for(j=0;j!=m;j++)
        {
            if((numSwitch[j]-P[j])%2 == 0)
                c++;
            else
                break;
        }

        if(c == m)
            num++;
    }

    cout<<num;

    return 0;
}
