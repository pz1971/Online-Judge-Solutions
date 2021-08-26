#include<bits/stdc++.h>
using   namespace      std;
typedef long long      LL;
typedef vector<int>    VI;
typedef pair<int,int>  PII;

LL p, q, r, s, t, u;

double func(double x){
	return (double)((double)p +  exp(x) * ( q * sin(x) + r * cos(x) + s * tan(x) + t * x * x + u ));
}

double BS(){
	double l = 0.0, u = 1.0, m, val;

	if(fabs(func(l)) < 1e-7)	return l;
	if(fabs(func(u)) < 1e-7)	return u;

	while(l + 1e-9 <= u){
		m = (l + u) / 2.0;
		val = func(m);
		
		if(fabs(val) < 1e-7)
			return m;
		else if(fabs(val) > fabs(func(m + 1e-9)))
			l = m ;
		else 
			u = m ;
	}

	return m;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	double x;
	cout<< fixed<< showpoint<< setprecision(4);

	while(cin>> p>> q>> r>> s>> t>> u){
		x = BS();
		
		if( fabs(func(x)) > 1e-7){
			cout<< "No solution"<< endl;
		}
		else {
			cout<< x<< endl;
		}
	}

	return 0;
}
