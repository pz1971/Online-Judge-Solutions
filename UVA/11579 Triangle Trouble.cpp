#include<bits/stdc++.h>
using   namespace      std;
typedef long long      LL;
typedef vector<int>    VI;
typedef pair<int,int>  PII;

int main(){

	int t, n;
	double s, del;
	cin>> t;
	cout<< fixed<< showpoint<< setprecision(2);
	while(t--){
		cin>> n;
		double ar[n];
		for(int i=0; i<n; i++)
			cin>> ar[i];
		sort(ar, ar+n);
		del = 0.0;
		for(int i=n-1; i>1; i--){
			if(ar[i-2]+ar[i-1] > ar[i]){
				s = (ar[i-2]+ar[i-1]+ar[i])/2.0;
				del = max(del, sqrt(s*(s-ar[i])*(s-ar[i-1])*(s-ar[i-2])));
			}
		}
		cout<< del<< endl;
	}

	return 0;
}