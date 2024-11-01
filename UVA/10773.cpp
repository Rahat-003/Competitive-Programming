#include <bits/stdc++.h>
using namespace std;



int main(){
/*
freopen("tst.txt","r",stdin);
freopen("txt.txt","w",stdout);
*/
int t;
cin>>t;
int tc = 0;

while(t--){
  double d,river, boat;
  cin>>d>>river>>boat;

  printf("Case %d: ",++tc);

  double w1 = boat*boat + river*river + 2*river*(-1)*river;
  if(w1<=0 || !boat || !river)  {
    puts("can't determine");
    continue;
  }
  double t1 = d/sqrt(w1);
  double t2 = d/boat;

  double ans = abs(t1-t2);

  cout<<fixed<<setprecision(3)<<ans<<endl;

}

return 0;
}
#include <bits/stdc++.h>
using namespace std;



int main(){

/*
freopen("tst.txt","r",stdin);
freopen("txt.txt","w",stdout);
*/

int t;
cin>>t;
int tc = 0;

while(t--){
  double d,river, boat;
  cin>>d>>river>>boat;

  printf("Case %d: ",++tc);

  double w1 = boat*boat + river*river + 2*river*(-1)*river;
  if(w1<=0 || !boat || !river)  {
    puts("can't determine");
    continue;
  }
  double t1 = d/sqrt(w1);
  double t2 = d/boat;

  double ans = abs(t1-t2);

  cout<<fixed<<setprecision(3)<<ans<<endl;

}

return 0;
}
