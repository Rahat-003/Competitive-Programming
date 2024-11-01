#include <bits/stdc++.h>
using namespace std;

/// prints eulerian path or cycle.. graph must have eulerian path

vector<vector<int>> v;
map<int,int> edge,indeg;

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

int n,e;

int initialize(){
    int i = 0,j;
    for( i = 0 ; i<n; i++)
        if(edge[i]-indeg[i]==1) return i;
    /*
    for(j = 0; j<n;j++)
        if(indeg[j]-edge[j]==1) break;

        v[j].push_back(i);
        edge[j]++;
        return i;
*/
}

int main(){

cin>>n>>e;

v.resize(n);

while(e--){
    int a,b;
    cin>>a>>b;
    v[a].push_back(b);
    edge[a]++;
    indeg[b]++;
}
int a = initialize();
//cout<<a<<endl;
Hierholzer(a);


return 0;
}
