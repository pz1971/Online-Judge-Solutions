#include<bits/stdc++.h>
using   namespace      std;
typedef long long      LL;
typedef vector<int>    VI;
typedef pair<int,int>  PII;

double const pi = acos(-1.0);

int main(){

	double R, N, r, I, E, theta;
	cout<< fixed << showpoint<< setprecision(10);
	while(cin>> R>> N){
		r = R*sin(pi/N)/(1.0 + sin(pi/N));
		if(N == 1.0){
			r = R;
			I = E = 0.0;
		}
		else if(N == 2.0){
			r = R/2.0;
			I = 0.0;
			E = pi*R*R - N*(pi*r*r);
		}
		else{
			theta = (pi*(N-2)) / N;
			I = ((r*2.0)*(r*2.0)*N)/(4.0*tan(pi/N)) - N*(r*r*theta/2.0);
			E = (pi*R*R) - N*(pi*r*r) - I;
		}
		cout<< r<< " "<< I<< " "<< E<< endl;
	}

	return 0;
}