#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<int> v(1000,0);
void pf(){
    v[1]=1;
    for(int i=2;i<=1000;i++){
        if(v[i]==0) {
            v[i] = i;
        }
    for(int j=2*i;j<=1000;j+=i){
        if(v[j]==0) v[j]=i;
    }
    }
}
bool isSphenic(int MAX){
    set<int> s;
    s.clear();
    while(MAX>1){

        int x=s.size();
        s.insert(MAX);
        if(x==s.size() || x>3){
            return false;
        }
        MAX/=v[MAX];
    }
return (s.size()==3);
}

int main(){
pf();
int n;
while(cin>>n)
  if(isSphenic(n))  cout<<"true"<<endl;
  else cout<<"false"<<endl;
return 0;
}
