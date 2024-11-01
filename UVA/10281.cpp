#include <bits/stdc++.h>
using namespace std;

struct node{
  double time,h,m,s,speed,iniDis, speedNow;
  string H,M,S;

  string bal(int x,string q){
    int i;
    for( i=x;i<q.size(); i++){
      if(q[i]==':' || q[i]==' ')  break;
    }
      string m = q.substr(x,i-x);
      return m;
    }


  node(string a,double d,double e,double f,double g){
  speed = d;
  time = e;
  iniDis = f;
  speedNow = g;
  H = bal(0,a);
  M = bal(H.size()+1,a);
  S = bal(H.size()+M.size()+2,a);

  }
};

string dtos(double a){
  stringstream ss;
  ss<<a;
  string s = ss.str();
  return s;
}

int main(){

//  freopen("tst.txt","r",stdin);

string p;
vector<node>  v;
bool fl = false;
int id = 0;

double dist = 0, speedNow;

while(getline(cin,p)){
  if(!p.size()) break;
  istringstream iss(p);
  double h,m,s, speed = -1; char c;
  string t = p;

  iss>>h>>c>>m>>c>>s>>speed;
  double time = h*3600+m*60+s;

  if(!fl){
  dist = 0;
  speedNow = speed;
  v.push_back(node(t,speed,time,dist,speedNow));
  }
  else{
  node  previous = v[id-1];
  double timeDif = time - previous.time;
  dist += timeDif/3600*speedNow;
  v.push_back(node(t,speed,time,dist,speedNow));
  }

  if(speed!=-1) speedNow = speed;
  else{
      node x = v[v.size()-1];
//    if(x.speed==-1){
    cout<<x.H<<":"<<x.M<<":"<<x.S;
    cout<<" "<<fixed<<setprecision(2)<<x.iniDis<<" km"<<endl;

  }


fl = true;
id++;



}
/*
for(int i=0;i<v.size(); i++){
  node x = v[i];
  if(x.speed==-1){
    cout<<x.H<<":"<<x.M<<":"<<x.S;
    printf(" %.2f km\n",x.iniDis);
  }
}

*/




return 0;
}
