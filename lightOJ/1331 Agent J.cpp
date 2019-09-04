#include<bits/stdc++.h>
using   namespace      std;
typedef long long      LL;
typedef vector<int>    VI;
typedef pair<int,int>  PII;

int main(){

	int t;
	double r1, r2, r3, a, b, c, A, B, C, s, del;
	cin>> t;
	cout<< fixed<< showpoint<< setprecision(6);
	for(int tc=1; tc<=t ;tc++){
		cin>> r1>> r2>> r3;

		a = r1 + r2;
		b = r1 + r3;
		c = r2 + r3;

		s = (a + b + c) / 2.0;
		del = sqrt(s * (s - a) * (s - b) * (s - c));

		A = acos((b*b + c*c - a*a) / (2.0 * b * c));
		B = acos((c*c + a*a - b*b) / (2.0 * c * a));
		C = acos((a*a + b*b - c*c) / (2.0 * a * b));

		del -= r1*r1*C/2.0 + r2*r2*B/2.0 + r3*r3*A/2.0;
		cout<< "Case "<< tc<< ": "<< del<< endl;
	}

	return 0;
}