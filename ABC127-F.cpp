
// problem: "https://atcoder.jp/contests/abc127/tasks/abc127_f"

#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    int q;
    cin>>q;

    priority_queue<int>q1;
    priority_queue<int,vector<int>,greater<int>>q2;

    ll a,b,B,l,r;
    l = r = B = 0;
    while(q--)
    {
        int x;

        cin>>x;

        if(x==1)
        {
            cin>>a>>b;

            B += b;

            if(q1.empty())
            {
                l += a;
                q1.push(a);
            }
            else if(q1.top()<a)
            {
                if(q1.size() == q2.size())
                {
                    q2.push(a);
                    r -= q2.top();
                    r += a;
                    l += q2.top();
                    q1.push(q2.top());
                    q2.pop();
                }
                else
                {
                    r += a;
                    q2.push(a);
                }
            }
            else
            {
                if(q1.size() == q2.size())
                {
                    q1.push(a);
                    l += a;
                }
                else
                {
                    q1.push(a);
                    l += a;
                    l -= q1.top();
                    r += q1.top();
                    q2.push(q1.top());
                    q1.pop();
                }
            }
        }

        else
        {
            ll s = B + (q1.size()*q1.top()) - l + r - (q2.size()*q1.top());
            cout<<q1.top()<<' '<<s<<'\n';
        }
    }

    return 0;
}
