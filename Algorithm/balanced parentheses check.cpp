#include <bits/stdc++.h>
using namespace std;

string s;
stack<char> stk;

bool check(){
	
	for(int i = 0; i<s.size(); i++){
		char c = '1';
		
		if(s[i]=='(' || s[i]=='{' || s[i]=='[')		stk.push(s[i]);
		
		else{
			if(stk.size()){
				c = stk.top();
				stk.pop();
			}
			if(s[i]==')' && c!='(')		return false;
			if(s[i]=='}' && c!='{')		return false;
			if(s[i]==']' && c!='[')		return false;
		}
	}
	if(stk.size())	return false;
	
	return true;
}

int main(){
	
int t;
scanf("%d",&t);
while(t--){
	
	cin>>s;
	
	if(check())	puts("YES");
	else puts("NO");
	
	while(stk.size())	stk.pop();
}
	
	
return 0;
}
