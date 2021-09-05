#include<bits/stdc++.h>
using   namespace      std;
typedef long long      LL;
typedef vector<int>    VI;
typedef pair<int,int>  PII;

VI primeFactors[1005];
VI primes{2};
int stat[1005];

void sieve(){
	for(int i=3; i*i < 1005; i+=2){
		if(stat[i] == 0){
			primes.push_back(i);
			for(int j=i*i; j < 1005; j += i + i){
				stat[j] = 1;
			}
		}
	}

	for(int i = primes.back() + 2; i < 1005; i+=2){
		if(!stat[i])
			primes.push_back(i);
	}
}

void generateFactors(){
	sieve();

	for(int i=4; i<1005; i++){
		int n = i;

		for(auto j: primes){
			if(j * j > n)
				break;

			if(n % j == 0){
				primeFactors[i].push_back(j);
				while(n % j == 0){
					n /= j;
				}
			}

		}

		if(n != 1 && n != i){
			primeFactors[i].push_back(n);
		}
	}
}

int vis[1005];

int bfs(int s, int t){
	if(s == t)
		return 0;
	if(s > t)
		return -1;

	memset(vis, 0, sizeof vis);
	queue<int> q;
	q.push(s);
	vis[s] = 1;

	while(!q.empty()){
		int temp = q.front();
		q.pop();

		for(auto i: primeFactors[temp]){
			if(i + temp > t)
				continue;
			if(vis[i + temp])
				continue;
			if(i + temp == t)
				return vis[temp];
			q.push(i + temp);
			vis[i + temp] = vis[temp] + 1;
		}
	}

	return -1;
}

int main(){

	generateFactors();

	int T, s, t;
	scanf("%d", &T);

	for(int tc = 1; tc<= T; tc++){
		scanf("%d %d", &s, &t);
		printf("Case %d: %d\n", tc, bfs(s, t));
	}

	return 0;
}