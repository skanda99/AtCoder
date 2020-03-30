
// problem: "https://atcoder.jp/contests/abc159/tasks/abc159_e"

#include<bits/stdc++.h>

using namespace std;

int detCuts(vector<string>&M,vector<int>&V,int h,int w,int k)
{
    int c = 0;
    int i,j,l,x;

    vector<int>C(V.size(),0);
    for(i=0;i!=w;i++)
    {
        l = 0;
        x = 0;
        for(j=0;j!=h;j++)
        {
            if(M[j][i] == '1')
            {
                if(j < V[l])
                {
                    C[l]++;
                    x++;
                }
                else
                {
                    while(j >= V[l])
                        l++;

                    C[l]++;
                    x = 1;
                }
            }

            if(x > k)
                return -1;
        }

        for(l=0;l!=C.size();l++)
        {
            if(C[l] > k)
            {
                c++;

                for(l=0;l!=C.size();l++)
                    C[l] = 0;

                l = 0;
                for(j=0;j!=h;j++)
                {
                    if(M[j][i] == '1')
                    {
                        if(j < V[l])
                            C[l]++;
                        else
                        {
                            l++;
                            C[l]++;
                        }
                    }
                }

                break;
            }
        }
    }

    return c + V.size() - 1;
}

int minDetCuts(vector<string>&M,int h,int w,int k)
{
    int i,j,n,m,p;
    n = pow(2,h-1);
    m = h+w;
    for(i=0;i!=n;i++)
    {
        vector<int>V;
        p = i;
        j = 1;
        while(p)
        {
            if(p&1)
                V.push_back(j);

            j++;
            p = p>>1;
        }

        V.push_back(h);

        int ans = detCuts(M,V,h,w,k);

        if(ans != -1)
            m = min(m,ans);
    }

    return m;
}

int main()
{
    int h,w,k;

    cin>>h>>w>>k;

    vector<string>M(h);
    int i;
    for(i=0;i!=h;i++)
        cin>>M[i];


    // test
    // vector<int>V = {2,10};
    // cout<<detCuts(M,V,h,w,k);

    cout<<minDetCuts(M,h,w,k);      // define
    return 0;
}
