
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> v;
map<int,int> edge;
stack<int> path;
vector<int> circuit;
int n,e;

void Hierholzer_undirected(){
    int a;

    for(int i = 0 ; i<n; i++){
        if(v[i].size() & 1) {
            a = i;
            break;
        }

        if(v[i].size()) a = i;
    }+

    path.push(a);
    int current = a, next;




    while(!path.empty()){

        if(edge[current]){
            next = v[current].back();

            path.push(next);
            edge[current]--;

            edge[next]--;
            auto it = find(v[next].begin(),v[next].end(),current);
            v[next].erase(it);

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
cout<<endl;

}

int main(){

cin>>n>>e;

v.resize(n);

while(e--){
    int a,b;
    cin>>a>>b;
    v[a].push_back(b);
    v[b].push_back(a);
    edge[a]++;
    edge[b]++;
}

Hierholzer_undirected();


return 0;
}
