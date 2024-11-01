#include<iostream>

using namespace std;

int main(){

    int N, i, j, isPrime, n;

   // cout << "Enter the value of N\n";
  while(cin >> N){

    // For every number between 2 to N, check
    // whether it is prime number or not
 int cnt=0;
    for(i = 1; i <= N; i++){
        isPrime = 0;

        // Check whether i is prime or not
        for(j = 2; j*j<= i; j++){
             // Check If any number between 2 to i/2 divides I
             // completely If yes the i cannot be prime number
             if(i % j == 0){
                 isPrime = 1;
                 break;
             }
        }

        if(isPrime==0 ){
            cout << i << " ";
            cnt++;
        }

    }
    cout<<endl;
    cout<<cnt<<endl;
  }

   return 0;
}
