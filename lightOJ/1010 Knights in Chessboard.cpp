#include<bits/stdc++.h>
using   namespace      std;
typedef long long      LL;
typedef vector<int>    VI;
typedef pair<int,int>  PII;

int main(){

	int t;
	scanf("%d", &t);
	int m, n;
	int ans;
	
	for(int tc=1; tc<=t; tc++){
		scanf("%d %d", &m, &n);
		if(m==1 || n==1){
			ans = m*n;
		}
		else if(m==2 || n==2){
			if(m*n < 8){
				ans = 4;
			}
			else{
				ans = (m*n)%8;
				if(ans > 4)
					ans = 4;
				ans += ((m*n)/8)*4;
			}
		}
		else if((m*n)%2==0){
			ans = (m*n)/2;
		}
		else{
			ans = m*(n+1)/2 - m/2;
		}
		printf("Case %d: %d\n", tc, ans);
	}

	return 0;
}
