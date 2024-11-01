#include <bits/stdc++.h>
using namespace std;

#define mx 10005



int main(){

    freopen("input.txt", "r", stdin);

    vector<string> version[mx];

    int curVersion = 1;

    string curString;
    getline(cin, curString);

    int n = curString.size();

    for(int i = 1; i < n-1; ){

        if(curString[i]==' ' || curString[i]==','){
            i++;
            continue;
        }

        int nxt = n;

        string cur;

        for(int j = i; j<n-1; j++){
            if(curString[j]==','){
                nxt = j;
                break;
            }
            cur.push_back(curString[j]);
        }
        version[1].push_back(cur);
        i = nxt;
    }

    while(1){
        string s;
        getline(cin, s);
        if(s.size()==0) break;

        int n = s.size();

        string given1, given2;

        // Add opertation
        if(s[0]=='A'){
            for(int i = 4; i<n; i++){
                given1.push_back(s[i]);
            }

            ++curVersion;

            for(auto i:version[curVersion-1]){
                version[curVersion].push_back(i);
            }
            version[curVersion].push_back(given1);
        }
        // Modify Version
        if(s[0]=='M'){
            int last = n;
            //Modify-
            //01234567
            for(int i = 7; i<n; i++){
                if(s[i]==' '){
                    last = i+1;
                    break;
                }
                given1.push_back(s[i]);
            }
            for(int i = last; i<n; i++){
                if(s[i]==' ')   continue;
                given2.push_back(s[i]);
            }

            curVersion++;

            for(auto i:version[curVersion-1]){
                version[curVersion].push_back(i);
            }

            for(int i = 0; i<version[curVersion].size(); i++){
                string curData = version[curVersion][i];
                if(curData==given1){
                    version[curVersion][i] = given2;
                    break;
                }
            }
        }

        // Check Version

        if(s[0]=='C'){
            //Check version:
            //01234567890123

            int checkVersion = 0;
            string val;

            for(int i = 14; i<n; i++){
                if(s[i]>='0' && s[i]<='9'){
                    checkVersion*=10;
                    checkVersion+=s[i] - '0';
                }
                else{
                    for(int j = i; j<n; j++){
                        if(s[j]==' ')   continue;
                        val.push_back(s[j]);
                    }
                    break;
                }
            }

            bool flag = 0;

            for(auto i: version[checkVersion]){
                if(i==val){
                    flag = 1;
                    break;
                }
            }

            puts(flag ? "Yes" : "No");
        }

    }


//    Print all Version

//    for(int i = 1; i<=curVersion; i++){
//        for(auto j:version[i]){
//            cout << j << " " ;
//        }
//        cout << endl;
//    }


    return 0;
}

