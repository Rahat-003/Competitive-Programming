#include <bits/stdc++.h>
using namespace std;
map<string, vector<pair<string,int>>> mp;
void add_edge(string u,string v, int w)
{
    mp[u].push_back(make_pair(v,w));
    mp[v].push_back(make_pair(u,w));
}


int main()
{
    int e;
    cin>>e;
    while(e--)
    {
        string a,b;
        int c;
        cin>>a>>b>>c;
        add_edge(a,b,c);
    }
    for(auto i=mp.begin(); i!=mp.end(); ++i)
    {
        cout<<i->first<<"->";
        for(auto it=i->second.begin(); it!=i->second.end(); ++it)
        {
            cout<<it->first<<", ";
        }
        cout<<endl;
    }
    cout<<mp.size()<<" ";

    return 0;
}
