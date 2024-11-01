#include <vector>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <iomanip>
using namespace std;
typedef pair<double,double> pp;

vector<pp> v;

vector<vector<double>> gr,hr;

int n;
double weight;

double dist(double x1,double x2, double y1, double y2){
  double ans =  sqrt( (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1) );
  return ans;
}

void make(){

for(int i = 0;i<v.size(); i++){
//    gr[i][i] = 0;
  for(int j = i+1; j<v.size(); j++){

    double x1 = v[i].first;   double y1 = v[i].second;
    double x2 = v[j].first;   double y2 = v[j].second;
    double ans = dist(x1,x2,y1,y2);

    gr[i][j] = ans;
    gr[j][i] = ans;
  }
}

}

void fw(){

  for(int k =0; k<n; k++)
  for(int i = 0 ; i<n; i++){
    for(int j = 0;j<n;j++){

      gr[i][j] = min( gr[i][j], gr[i][k] + gr[k][j] );

      if(gr[i][k]<gr[0][1] && gr[k][j]<gr[0][1]){

          gr[i][j] = min( gr[i][j], max( gr[i][k],gr[k][j] ) );

        }

    }

  }

  hr = gr;

    weight = gr[0][1];
/*
  for(int k = 0; k<n; k++){

    for(int i = 0;i<n;i++){
      for(int j = 0; j<n; j++){

        if(hr[i][k]<weight && hr[k][j]<weight){

          hr[i][j] = min( hr[i][j], max( hr[i][k],hr[k][j] ) );

        }

      }
    }
  }
*/


}

int main(){

/*
freopen("tst.txt","r",stdin);
freopen("t.txt","w",stdout);

*/
int tc = 0;



while(scanf("%d",&n)){
    if(!n)  break;

    gr.assign(n,vector<double>(n,0));
    hr = gr;

  for(int i = 0 ;i<n;i++){
    double a,b;
    scanf("%lf %lf",&a,&b);
    v.push_back(pp(a,b));
  }

make();

fw();


printf("Scenario #%d\nFrog Distance = ",++tc);

cout<<fixed<<setprecision(3)<<weight<<endl<<endl;


v.clear();
}


return 0;
}
