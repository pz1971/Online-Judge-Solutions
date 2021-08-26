#include<bits/stdc++.h>
using   namespace      std;
typedef long long      LL;
typedef vector<int>    VI;
typedef pair<int,int>  PII;

int main(){

	int t;
	cin>> t;
	while(t--){
		int f, h, w, x;
		cin>> f>> h>> w;
		
		int ar[f + 2];
		ar[0] = 0;
		for(int i=1; i<=f; i++)
			cin>> ar[i];
		sort(ar + 1, ar + f + 1);
		ar[f + 1] = w;

		int mn = INT_MAX;
		for(int i=1; i< f + 2; i++)
			mn = min(mn, h * (ar[i] - ar[i - 1]));
		cout<< mn<< endl;
	}

	return 0;
}
