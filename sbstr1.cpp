#include <bits/stdc++.h>
using namespace std;
stack <char> s;

void pr(stack <char> s){
	//s.pop();
	char q;
	q=s.top();
	while(q!='('){
		cout<<q;
		s.pop();
		q=s.top();
	}
	s.pop();
}
int main(){
    int t;
    cin>>t;
    while(t--){
    	string str;
    	cin>>str;
    	int len = str.size();
    	int i=0;
    	for(i=0;i<len;i++){
    		if(isalpha(str[i]))
    			cout<<str[i];
    		else if(str[i]==')')
    			pr(s);
    		else{
    			if(str[i]=='+') cout<<"-";
    			s.push(str[i]);
    		}
    	}
    	cout<<"\n";
    }
    return 0;
}
