
// problem: "https://atcoder.jp/contests/abc128/tasks/abc128_e"

#include<bits/stdc++.h>
#define Pair pair<int,int>

using namespace std;

struct Node
{
    int x,s,e;

    Node(int x,int s,int e) : x(x),s(s),e(e) { }
};

bool func1 (Node n1,Node n2)
{
    return n1.x<n2.x;
}

bool func2 (Pair p1,Pair p2)
{
    return p1.first<p2.first;
}

int main()
{
    int n,q;
    cin>>n>>q;
    int s,t,x,i;

    vector<Node>works;
    for(i=0;i!=n;i++)
    {
        cin>>s>>t>>x;

        Node n = Node(x,s-x,t-x-1);
        works.push_back(n);
    }

    sort(works.begin(),works.end(),func1);      // define

    // check
    // for(i=0;i!=works.size();i++)
    //     cout<<works[i].x<<' ';
    map<int,int>M;
    for(i=0;i!=q;i++)
    {
        cin>>s;
        M[s] = i;
    }

    vector<Pair>Ends;
    for(i=0;i!=n;i++)
    {
        map<int,int>::iterator it1,it2;
        it1 = M.lower_bound(works[i].s);
        it2 = M.lower_bound(works[i].e);

        if((*it2).first == works[i].e)
            it2++;

        vector<int>Delete;

        for(auto it=it1;it!=it2;it++)
        {
            Ends.push_back(Pair((*it).second,works[i].x));
            Delete.push_back((*it).first);
        }

        for(auto it=Delete.begin();it!=Delete.end();it++)
            M.erase(*it);
    }

    for(auto it=M.begin();it!=M.end();it++)
        Ends.push_back(Pair((*it).second,-1));

    sort(Ends.begin(),Ends.end(),func2);        // define

    for(i=0;i!=q;i++)
        cout<<Ends[i].second<<'\n';

    return 0;
}
