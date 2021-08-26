#include<bits/stdc++.h>
using   namespace      std;
typedef long long      LL;
typedef vector<int>    VI;
typedef pair<int,int>  PII;

const double R = 6440.0, pi = acos(-1.0);

int main(){

	double s, ang, ang2, arc, chord;
	string type;
	cout<< fixed<< showpoint<< setprecision(6);
	while(cin>> s>> ang>> type){
		s += R;
		if(type == "min"){
			ang /= 60.0;
		}
		if(ang == 180.00){
			cout<< s*pi<< " "<< 2.0*s<< endl;
			continue;
		}
		if(ang > 180.0)
			ang = 360.0 - ang;
		ang = ang * pi / 180.0;
		ang2 = (pi - ang)/2.0;
		chord = (s / sin(ang2)) * sin(ang);
		arc = s * ang;
		cout<< arc<< " "<< chord<< endl;
	}

	return 0;
}