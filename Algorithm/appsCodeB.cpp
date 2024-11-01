#include <bits/stdc++.h>
using namespace std;

struct data{

    string name,tweet;
    int follower, tweetVal;
    bool trending;

    int uniqueLower[30], uniqueUpper[30]; // Taking case sensitive and ignoring other characters like [',' , '.'] etc;

    data(){};

    data(string _name, int _follower, string _tweet, bool _trending){
        name = _name;
        follower = _follower;
        trending = _trending;
        tweet = _tweet;

        int len = tweet.size(), uniqueCnt = 0;

        memset(uniqueLower, 0, sizeof uniqueLower);
        memset(uniqueUpper, 0, sizeof uniqueUpper);

        for(int i = 0; i<tweet.size(); i++){
            char c = tweet[i];
            if(c>='a' && c<='z'){
                uniqueLower[c - 'a']++;
            }
            if(c>='A' && c<='Z'){
                uniqueUpper[c - 'A']++;
            }
        }

        for(int i = 0; i<30; i++){
            if(uniqueLower[i] > 0)  uniqueCnt++;
            if(uniqueUpper[i] > 0)  uniqueCnt++;
        }
        tweetVal = len * uniqueCnt;
    }


    bool operator < (const data &n) const {
        if(trending!=n.trending){
            return trending > n.trending;
        }
        if(tweetVal!=n.tweetVal)  return tweetVal > n.tweetVal;
        if(follower!=n.follower)  return follower > n.follower;
        return name < n.name;
    }
};



data getData(string s){
    int n = s.size(), i = 0, follower = 0;;
    string name,tweet;
    bool trending = 0;

    for(i = 0; i<n; i++){
        if(s[i]==' ')   break;
        name.push_back(s[i]);
    }

    i++;

    for(; i<n; i++){
        if(s[i]==' ')   break;
        follower*=10;
        follower+=(s[i] - '0');
    }

    i++;

    for(; i<n; i++){
        if(s[i]=='<')  continue;
        if(s[i]=='>')  break;
        tweet.push_back(s[i]);
    }

    for(; i<n; i++){
        if(s[i]=='#'){
            trending = true;
            break;
        }
    }
    return data(name, follower, tweet, trending);
}






int main(){

    vector<data> user;

    while(1){
        string s;
        getline(cin,s);
        if(s.size()==0) break;
        data cur = getData(s);
        user.push_back(cur);
    }

    sort(user.begin(), user.end());

    for(int i = 0; i<(int)user.size(); i++){
        cout << user[i].name << " " << user[i].follower << "\n";
    }

    return 0;
}




