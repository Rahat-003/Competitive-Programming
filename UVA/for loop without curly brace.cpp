#include <iostream>
using namespace std;
int main(){


for (int j=1;j<=6 ; j++)
    for ( int i = 1; i<=j ; i++){
        cout<<i;cout<<endl;

}
//
//Is equivalent to:

for (int j=1;j<=6 ; j++)  {
    for ( int i = 1; i<=j ; i++)
    {
        cout<<i;
    }
    cout<<endl;
}


return 0;
}
