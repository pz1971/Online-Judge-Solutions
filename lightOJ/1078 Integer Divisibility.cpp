#include<bits/stdc++.h>
using   namespace      std;
typedef long long      LL;
typedef vector<int>    VI;
typedef pair<int,int>  PII;

int main(){

	int t;
	scanf("%d", &t);
	int n, d;
	for(int tc=1; tc<=t; tc++){
		scanf("%d %d", &n, &d);
		int a = 1, num = d;
		while(1){
			num %= n;
			if(num==0)
				break;
			num = num*10 + d;
			a++;
		}
		printf("Case %d: %d\n", tc, a);
	}

	return 0;
}