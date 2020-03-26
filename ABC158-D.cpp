
// problem: "https://atcoder.jp/contests/abc158/tasks/abc158_d"

#include<bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin>>s;

    int q;
    cin>>q;

    deque<char>B,E;
    int c = 0;

    while(q--)
    {
        int t;
        cin>>t;

        if(t == 1)
            c++;

        else
        {
            int f;
            char ch;

            cin>>f>>ch;

            if(c%2)
            {
                if(f == 1)
                    E.push_back(ch);
                else
                    B.push_back(ch);
            }
            else
            {
                if(f == 1)
                    B.push_back(ch);
                else
                    E.push_back(ch);
            }
        }
    }

    if(c%2)
    {
        while(!E.empty())
        {
            cout<<E.back();
            E.pop_back();
        }

        reverse(s.begin(),s.end());
        cout<<s;

        while(!B.empty())
        {
            cout<<B.front();
            B.pop_front();
        }
    }
    else
    {
        while(!B.empty())
        {
            cout<<B.back();
            B.pop_back();
        }

        cout<<s;

        while(!E.empty())
        {
            cout<<E.front();
            E.pop_front();
        }
    }

    return 0;
}
