#include<bits/stdc++.h>
using   namespace      std;
typedef long long      LL;
typedef vector<int>    VI;
typedef pair<int,int>  PII;

int main(){

	int n, k, p, x;
	while(cin>> n>> k){
		int cur = 0;

		queue<int> q[n];
		
		for(int i=0; i<n; i++){
			cin>> p;
			while(p--){
				cin>> x;
				q[i].push(x);
			}
			
			for(int j = 0; j<k+2; j++)
				q[i].push(50);
		}

		int jury = 0;
		
		while(k){
			if(q[jury].front() >= cur || q[jury].front() == 50){
				cur += q[jury].front();
				k--;
			}

			q[jury].pop();
			jury = (jury + 1) % n;
		}

		cout<< cur<< endl;
	}

	return 0;
}
