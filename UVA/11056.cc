
#include <bits/stdc++.h>
using namespace std;

vector<string> name;

struct node{
  string n;

  int ms;
  node( string a = "",int d = 0){
    n = a;
    ms = d;
  }

  bool operator < (const node &n1) const {
    string p,q;
    p = n;
    q = n1.n;
    transform(p.begin(),p.end(),p.begin(),::tolower);
    transform(q.begin(),q.end(),q.begin(),::tolower);

    if(ms!=n1.ms) return ms<n1.ms;
    return p<q;


  }
};

vector<node> data;

string cut(string s){
  int i;
  for(int i=s.size()-1; i>=0; i--)
    if(s[i]!=' ') break;
  string t = s.substr(0,i+1);
  return t;
}

void word(string s){

    istringstream iss(s);
    string h;
    string name;
    int a,b,c;
    iss>>name>>h;
    iss>>a>>h;
    iss>>b>>h;
    iss>>c>>h;
    int  tms = a*60*1000 + b*1000 + c;
    data.push_back(node(name,tms));

}



int main(){

int t;
while(cin>>t){
  cin.ignore();
  while(t--){
    string s;
    getline(cin,s);
    word(s);

  }




  sort(data.begin(),data.end());

  int row = 0;
  int i;
  for( i=0;i<data.size(); ++i){
    if(i%2==0)      printf("Row %d\n",++row);

      cout<<data[i].n<<endl;
  }



cout<<endl;
data.clear();


}


return 0;
}
