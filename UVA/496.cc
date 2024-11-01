#include <bits/stdc++.h>
#include <cstdio>
#include <vector>
#include <list>
using namespace std;


int main(){

string s,t;
while(getline(cin,s)){
    istringstream iss(s);
    int n;
    set<int> p,q;
    while(iss>>n){
        p.insert(n);
    }
    getline(cin,t);
    istringstream jss(t);
    while(jss>>n){
        q.insert(n);
    }
    vector<int> u(p.begin(),p.end());
    vector<int> v(q.begin(),q.end());
    if(u==v){
        puts("A equals B");
    }
    else if(u.size()<v.size()){
        bool fl = false;

        int i,cnt = 0;
        for(i = 0; i<u.size(); i++){
            if(count(v.begin(),v.end(),u[i] )!=1){
                fl = true;
                cnt++;
            }
        }
      if(cnt==i)    puts("A and B are disjoint");
    else  if(cnt!=i && cnt)    puts("I'm confused!");
    else  if(!fl)  puts("A is a proper subset of B");
    }
    else if(v.size()<u.size()){
        bool fl = false;
        int i,cnt = 0;
        for(i = 0; i<v.size(); i++){
            if(count(u.begin(),u.end(),v[i] )!=1){
                fl = true;
                cnt++;
            }
        }
      if(cnt==i)    puts("A and B are disjoint");
      else if(cnt!=i && cnt)    puts("I'm confused!");
      else  if(!fl) puts("B is a proper subset of A");
    }

    else if(u.size()==v.size()){
            bool fl = false;
        for(auto i:u){
            if(count(v.begin(),v.end(),i)==1){
                puts("I'm confused!");
                fl = true;
                break;
            }
        }
        if(!fl)    puts("A and B are disjoint");
    }

}

return 0;
}
