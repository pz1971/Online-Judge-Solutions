#include<bits/stdc++.h>
using   namespace      std;
typedef long long      LL;
typedef vector<int>    VI;
typedef pair<int,int>  PII;

LL BS(LL n){
	LL l = 0, u = sqrt(n) * 2LL, m, ret = l;

	while(l <= u){
		m = (l + u) / 2;

		if(m * (m + 1) / 2 == n)
			return m;
		else if(m * (m + 1) / 2 > n)
			u = m - 1;
		else{
			ret = m;
			l = m + 1;
		}
	}

	return ret;
}

int main(){

	int t;
	LL n;
	cin>> t;

	while(t--){
		cin>>  n;
		cout<< BS(n)<< endl;
	}

	return 0;
}