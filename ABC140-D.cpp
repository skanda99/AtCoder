
// problem: "https://atcoder.jp/contests/abc140/tasks/abc140_d"

#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,k;
    string s;

    cin>>n>>k;

    cin>>s;

    if(s.size() == 1)
        cout<<0;

    else
    {
        int i,j,p,l;
        i = 1;
        l = s.size();
        p = 0;

        if(s[0] == 'R')
        {
            for(j=0;j!=n;j++)
            {
                if(s[j] == 'L')
                    s[j] = 'R';
                else
                    s[j] = 'L';
            }
        }

        while(k && i < l)
        {
            if(s[i] == 'R')
            {
                j = i;
                while(j < l && s[j] == 'R')
                {
                    p++;
                    j++;
                }

                if(j == l)
                {
                    if(k)
                    {
                        k--;
                    }
                }
                else
                {
                    if(k)
                    {
                        k--;
                        p++;
                    }
                }

                i = j+1;
            }

            else
            {
                p++;
                i++;
            }
        }

        while(i < l)
        {
            if(s[i] == s[i-1])
                p++;

            i++;
        }

        cout<<p;
    }

    return 0;
}
