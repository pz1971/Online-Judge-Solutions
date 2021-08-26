#include<bits/stdc++.h>
using   namespace      std;
typedef long long      LL;
typedef vector<int>    VI;
typedef pair<int,int>  PII;

double const pi = acos(-1.0);

int main(){

	double x1, y1, x2, y2, x3, y3, a, b, c, s, del, ans;

	cout<< fixed<< showpoint<< setprecision(2);

	while (cin>> x1>> y1>> x2>> y2>> x3>> y3){
		a = sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
		b = sqrt((x2 - x3)*(x2 - x3) + (y2 - y3)*(y2 - y3));
		c = sqrt((x3 - x1)*(x3 - x1) + (y3 - y1)*(y3 - y1));

		s = (a + b + c)/2.0;
		del = sqrt(s*(s-a)*(s-b)*(s-c));

		ans = pi * a * b * c / (2.0 * del);
		cout<< ans<< endl;
	}

	return 0;
}