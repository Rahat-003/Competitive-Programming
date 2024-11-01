#include <iostream>
using namespace std;
typedef long long ll;
#include <bitset>
string simple(string s){
    string t;
    for(int i = 0; i<s.size(); i++){
        if( (s[i] - '0') ){
            for(int j = i; j<s.size(); j++)
                t.push_back(s[j]);
            return t;
        }
    }
}

int main(){

ll n ;
while(1==scanf("%lld",&n)){
    if(!n)  break;
    string bin = bitset<32> (n).to_string();
//    cout<<bin<<" "<<bin.size()<<endl;
    ll sum = 0;
    bin = simple(bin);
    for(ll i =0; i<bin.size(); i++){
        sum+= (bin[i] - '0');
    }
    printf("The parity of %s is %lld (mod 2).\n",bin.c_str(),sum);
//    to_long long();
}


return 0;
}
