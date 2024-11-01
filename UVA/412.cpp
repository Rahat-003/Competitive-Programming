
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;


int main() {


int t;

while(scanf("%d",&t )==1){
if(!t)  break;
vector<int> v;

  while(t--){
    int a;
    scanf("%d",&a );
    v.push_back(a);
  }
  double cnt = 0;
  for(int i = 0;i<v.size()-1; i++){

    for(int j = i+1; j<v.size(); j++){
      if(__gcd(v[i],v[j])==1) cnt++;

    }
  }
  if(!cnt){
    printf("No estimate for this data set.\n");
    continue;
  }


  double sz = (double)v.size();
  double tot = sz*(sz-1),p;
  tot/=2;
  p = tot*6/cnt;
//  cout<<cnt<<" "<<tot<<endl;
   printf("%.6f\n",sqrt(p));
v.clear();
}
  return 0;
}
