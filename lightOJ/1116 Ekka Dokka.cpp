#include<bits/stdc++.h>
using   namespace      std;
typedef long long      LL;
typedef vector<int>    VI;
typedef pair<int,int>  PII;

int main(){

	int t;
	cin>> t;
	
	LL w;

	for(int tc=1; tc<= t; tc++){
		cin>> w;
		if(w%2){
			cout<< "Case "<< tc<< ": Impossible\n";
			continue;
		}
		for(LL i=2; i<=w; i+=2){
			if(w%i==0 && (w/i)%2==1){
				cout<< "Case "<< tc<< ": "<< (w/i)<< " "<< i<< endl;
				break;
			}
		}
	}

	return 0;
}