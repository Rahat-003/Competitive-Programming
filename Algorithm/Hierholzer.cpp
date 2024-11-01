#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> v;
map<int,int> edge;
stack<int> path;
vector<int> circuit;

void Hierholzer(int a){

    path.push(a);
    int current = a, next;

    while(!path.empty()){

        if(edge[current]){
            next = v[current].back();
            path.push(next);
            edge[current]--;
            v[current].pop_back();
            current = next;
        }
        else{
            int u = path.top();
            circuit.push_back(u);
            path.pop();
        }

    }
    for(int i = circuit.size()-1; i>=0; i--)
        cout<<circuit[i]<<" ";


}

int main(){

int n,e;
cin>>n>>e;

v.resize(n);
while(e--){
    int a,b;
    cin>>a>>b;
    v[a].push_back(b);
    edge[a]++;
}

int a;
cin>>a;
Hierholzer(a);


return 0;
}
