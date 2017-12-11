#include <bits/stdc++.h>
using namespace std;

int prime(long long int x){
	if(x==1) return 0;
	if(x==2) return 1;
	if(x%2==0) return 0;
	for(int i=3;i<=sqrt(x);i++){
		if(x%i==0)
			return 0;
	}
	return 1;
}

int main(){
    int t;
    cin>>t;
    while(t--){
    	long long int n,m,i;
    	cin>>n>>m;
    	for(i=n;i<=m;i++){
    		if(prime(i))
    			cout<<i<<"\n";
    	}
    }

    return 0;
}
