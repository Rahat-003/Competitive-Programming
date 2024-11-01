#include <bits/stdc++.h>
using namespace std;



map<string,int> user;

stack<string> st;


int main(){
//read;



    while(1){
        string s;
        getline(cin,s);
        if(s.size()==0) break;
        st.push(s);
        user[s]++;
    }

    while((int)st.size()){
        string s = st.top();
        st.pop();
        if(user[s] > 0){
            cout << s << " " << user[s] << "\n";
            user[s] = 0;
        }
    }

    return 0;
}


