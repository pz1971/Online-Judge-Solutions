#include<bits/stdc++.h>
using   namespace      std;
typedef long long      LL;
typedef vector<int>    VI;
typedef pair<int,int>  PII;

const int maxBit = 64;

int main(){

	unsigned long long t, n, ans;
	cin>> t;
	for(int tc = 1; tc<= t; tc++){
		cin>> n;
		if(n == 0){
			cout<< "Case "<< tc<< ": 0"<< endl;
			continue;
		}

		bitset<maxBit> bs(n);
		int onoroy = bs.count();

		for(int i=1; i<64; i++){
			if(bs[i] == 0 && bs[i-1] == 1){
				bs[i] = 1;
				for(--i; i>=0; i--)
					bs[i] = 0;
				break;
			}
		}

		int x = onoroy - bs.count();
		for(int i=0; i < x; i++)
			bs[i] = 1;	
		
		ans = bs.to_ullong();
		cout<< "Case "<< tc<< ": "<< ans<< endl;
	}

	return 0;
}