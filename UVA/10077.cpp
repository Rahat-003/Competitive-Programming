#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;
vector <int> v;

void solve(int nominator, int denominator) {
    if(nominator == 1) return;
    v.push_back(nominator / denominator);
    solve(denominator, nominator % denominator);

}

int main() {
    int m ,n;
    while(scanf("%d %d", &m, &n)) {
        if(m == 1 && n == 1) break;
        v.clear();

        if(m < n) {
            v.push_back(0);
            solve(n, m);
        }
        else
            solve(m, n);

        int x=v.size()-1;
        v[x]-=1;
        for(int i = 0; i < v.size(); i++){
            for(int j = 0; j < v[i]; j++){
                if(i % 2!=0) printf("L");
                else printf("R");}
        }
        printf("\n");
        for(int i=0;i<v.size();i++){
            cout<<v[i]<<" ";
        }
    cout<<endl;
    }
    return 0;
}
