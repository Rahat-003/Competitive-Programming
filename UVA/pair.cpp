#include <iostream>
#include <list>
#include <utility>
using namespace std;

int main(){
list<pair<int,int> >li;
int n;
cin>>n;
for(int i=0;i<n;i++){

    int a,b;
    cin>>a>>b;
    li.push_back(make_pair(a,b));
}
for(auto iit=li.begin();iit!=li.end();++iit)
    cout<<iit->first<<" "<<iit->second<<endl;

return 0;
}
