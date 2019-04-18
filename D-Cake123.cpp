
// problem: "https://atcoder.jp/contests/abc123/tasks/abc123_d"

#include<iostream>
#include<queue>
#include<set>
#include<algorithm>
#define ll long long int
#define defv vector<ll>
using namespace std;

struct Node
{
    ll s,x,y,z;

    Node(ll s,ll x,ll y,ll z): s(s),x(x),y(y),z(z) {}
};

struct compareF
{
    bool operator()(Node const& p1,Node const& p2)
    {
        return p1.s<p2.s;
    }
};

struct index
{
    ll x,y,z;

    index(ll x,ll y,ll z): x(x),y(y),z(z) {}
};


auto Sfind(auto it1,auto it2,index p)
{
    for(auto it=it1;it!=it2;it++)
    {
        if((*it).x==p.x && (*it).y==p.y && (*it).z==p.z)
            return it;
    }

    return it2;
}

void printKLargest(defv &A,ll X,defv &B,ll Y,defv &C,ll Z,ll K)
{
    priority_queue<Node,vector<Node>,compareF>Q;        // define compareF
    vector<index>S;

    ll M = A[0]+B[0]+C[0];
    Q.push(Node(M,0,0,0));
    S.push_back(index(0,0,0));

    ll k = 0;

    while(k<K && !Q.empty())
    {
        cout<<Q.top().s<<'\n';
        k++;

        Node p(Q.top());
        Q.pop();

        if(p.x+1<X)
        {
            M = A[p.x+1]+B[p.y]+C[p.z];

            if(Sfind(S.begin(),S.end(),index(p.x+1,p.y,p.z)) == S.end())       // define
            {
                Q.push(Node(M,p.x+1,p.y,p.z));
                S.push_back(index(p.x+1,p.y,p.z));
            }
        }

        if(p.y+1<Y)
        {
            M = A[p.x]+B[p.y+1]+C[p.z];

            if(Sfind(S.begin(),S.end(),index(p.x,p.y+1,p.z)) == S.end())
            {
                Q.push(Node(M,p.x,p.y+1,p.z));
                S.push_back(index(p.x,p.y+1,p.z));
            }
        }

        if(p.z+1<Z)
        {
            M = A[p.x]+B[p.y]+C[p.z+1];

            if(Sfind(S.begin(),S.end(),index(p.x,p.y,p.z+1)) == S.end())
            {
                Q.push(Node(M,p.x,p.y,p.z+1));
                S.push_back(index(p.x,p.y,p.z+1));
            }
        }
    }
}

int main()
{
    ll X,Y,Z,K;
    cin>>X>>Y>>Z>>K;

    ll i;
    vector<ll>A(X);
    for(i=0;i!=X;i++)
        cin>>A[i];

    vector<ll>B(Y);
    for(i=0;i!=Y;i++)
        cin>>B[i];

    vector<ll>C(Z);
    for(i=0;i!=Z;i++)
        cin>>C[i];

    sort(A.begin(),A.end(),greater<ll>());
    sort(B.begin(),B.end(),greater<ll>());
    sort(C.begin(),C.end(),greater<ll>());

    printKLargest(A,X,B,Y,C,Z,K);     // define

    return 0;
}
