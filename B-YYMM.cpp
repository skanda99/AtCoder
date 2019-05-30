
// problem: "https://atcoder.jp/contests/abc126/tasks/abc126_b"

#include<iostream>
#include<string>

using namespace std;

string check(string &s)
{
    string s1 = s.substr(0,2);
    string s2 = s.substr(2,2);

    if(stoi(s1)<=12 && stoi(s1)>0 && stoi(s2)<=12 && stoi(s2)>0)
        return "AMBIGUOUS";

    else if(stoi(s1)<=12 && stoi(s1)>0)
        return "MMYY";

    else if(stoi(s2)<=12 && stoi(s2)>0)
        return "YYMM";

    return "NA";
}

int main()
{
    string s;
    cin>>s;

    cout<<check(s);

    return 0;
}
