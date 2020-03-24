
// problem: "https://atcoder.jp/contests/abc157/tasks/abc157_c"

#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;


    int i,l;
    char c;
    string s;

    if(n==1)
        s = " ";
    else if(n==2)
        s = "  ";
    else
        s = "   ";

    for(i=0;i!=m;i++)
    {
        cin>>l>>c;

        if(s[l-1] != ' ' && s[l-1] != c)
        {
            cout<<-1;
            exit(0);
        }

        s[l-1] = c;
    }

    for(i=0;i!=n;i++)
    {
        if(!i)
        {
            if(s[i] == ' ' && n > 1)
                s[i] = '1';
            else if(s[i] == ' ' && n == 1)
                s[i] = '0';
        }
        else
        {
            if(s[i] == ' ')
                s[i] = '0';
        }
    }

    if(s[0] == '0' && n > 1)
    {
        cout<<-1;
        exit(0);
    }

    cout<<stoi(s);

    return 0;
}
