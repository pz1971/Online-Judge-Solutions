#include <bits/stdc++.h>
using   namespace  std ;
typedef long   long LL ;

#define mid ((hi + lo) >> 1)
#define left (cur << 1)
#define right (left | 1)

LL powmod(LL base, LL exp, LL modulus = ((1ULL << 63) - 1ULL)){
	base %= modulus;
	long long result = 1;
	while (exp > 0) {
		if (exp & 1LL) result = (result * base) % modulus;
		base = (base * base) % modulus;
		exp >>= 1;
	}
	return result;
}

const int mx = 1e5 + 5 ;
LL B, P ;
int L, N ;
LL tree[mx * 3] ;

void build(int cur, int lo, int hi){
	tree[cur] = 0LL ;
	if(lo < hi){
		build(left, lo, mid) ;
		build(right, mid + 1, hi) ;
	}
}

LL update(const int I, const LL V, int cur, int lo, int hi){
	if(I < lo || I > hi)
		return tree[cur] ;
	else if(lo == hi)
		return tree[cur] = (V * powmod(B, (LL)(L - I), P)) % P ;
	else 
		return tree[cur] = (update(I, V, left, lo, mid)
			+ update(I, V, right, mid + 1, hi)) % P ;
}

LL query(const int I, const int J, int cur, int lo, int hi) {
	if(lo > J || hi < I)
		return 0LL ;
	if(I <= lo && hi <= J)
		return tree[cur] ;
	return (query(I, J, left, lo, mid) + query(I, J, right, mid + 1, hi)) % P ;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	while(cin >> B >> P >> L >> N){
		if(!(B|P|L|N))	break ;

		build(1, 1, L) ;
		
		string type ;
		int I, V, J ;
		while(N--){
			cin >> type ;
			if(type == "E"){
				cin >> I >> V ;
				update(I, V, 1, 1, L) ;
			}
			else {
				cin >> I >> J ;
				LL ans = query(I, J, 1, 1, L) ;
				ans = (ans * powmod( powmod(B, (LL)(L - J), P) , P - 2, P) ) % P ;
				cout << ans << endl ;
			}
		}

		cout << "-" << endl ;
	}

	return 0;
}