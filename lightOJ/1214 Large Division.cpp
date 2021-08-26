#include<bits/stdc++.h>
using   namespace      std;
typedef long long      LL;
typedef vector<int>    VI;
typedef pair<int,int>  PII;

bool divisible(string a, LL b){
	if(b < 0)	b = 0 - b;

	LL num = 0;
	int i=0;
	if(a[i] == '-')	i++;

	for( ; i<a.size(); i++){
		num = (num * 10 + (a[i] - '0')) % b;
	}

	return (num==0);
}

int main(){

	int t;
	string a;
	LL b;
	cin>> t;
	for(int tc=1; tc<=t ;tc++){
		cin>> a>> b;
		cout<< "Case "<< tc<< ": ";
		if(divisible(a, b)){
			cout<< "divisible\n";
		}
		else{
			cout<< "not divisible\n";
		}
	}

	return 0;
}