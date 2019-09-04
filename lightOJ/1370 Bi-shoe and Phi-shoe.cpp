#include<bits/stdc++.h>
using   namespace      std;
typedef long long      LL;
typedef vector<int>    VI;
typedef pair<int,int>  PII;

int phi[1000100];
void sievePHI(){
	for(int i=1; i<1000100; i++){
		phi[i] = i;
	}
	for(int i=2; i<1000100; i++){
		if(phi[i] == i){
			for(int j=i; j< 1000100; j+=i)
				phi[j] = phi[j]/i*(i-1);
		}
	}
}

int ar[1000100];

int main(){

	sievePHI();
	
	int it = 2;

	for(int i=1; i<1000100; i++){
		if(i <= phi[it]){
			ar[i] = it;
		}
		else{
			for(++it ; it<1000100; it++){
				if(i <= phi[it]){
					ar[i] = it;
					break;
				}
			}
		}
	}
	
	int t;
	scanf("%d", &t);
	LL sum;
	int n, a;
	for(int tc=1; tc<=t; tc++){
		scanf("%d", &n);
		sum = 0LL;
		while(n--){
			scanf("%d", &a);
			sum += ar[a];
		}
		printf("Case %d: %lld Xukha\n", tc, sum);
	}

	return 0;
}