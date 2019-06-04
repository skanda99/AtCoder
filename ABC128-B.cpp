
// problem: "https://atcoder.jp/contests/abc128/tasks/abc128_b"

#include<bits/stdc++.h>

using namespace std;

struct Node
{
    string s;
    int i,p;

    Node (string s,int i,int p) : s(s),i(i),p(p) {}
};

bool func (Node n1,Node n2)
{
    if(n1.s == n2.s)
        return n1.p>n2.p;

    return n1.s < n2.s;
}

int main()
{
    int n;
    cin>>n;
    int i;
    vector<Node>V;

    for(i=0;i!=n;i++)
    {
        string s;
        int p;

        cin>>s>>p;

        V.push_back(Node(s,i+1,p));
    }

    sort(V.begin(),V.end(),func);

    for(i=0;i!=n;i++)
        cout<<V[i].i<<'\n';

    return 0;
}
