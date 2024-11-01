#include <vector>
#include <cstdio>

using namespace std;

void m(auto &v ){
    for(int i = 0 ; i<10; i++)
        v.push_back(i);
}

void print(auto &v){

    for(auto it : v)
        printf("%d ",it);

printf("\n");
}



int main(){

vector<int> v,u;


m(v);
print(v);

m(u);
print(u);


}
