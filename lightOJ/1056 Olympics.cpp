#include<bits/stdc++.h>
using   namespace      std;
typedef long long      LL;
typedef vector<int>    VI;
typedef pair<int,int>  PII;

int main(){

	int t ;
	cin >> t ;
	cout << fixed << showpoint << setprecision(7) ;

	for(int tc = 1 ; tc <= t ; tc++){
		double a, b;
		char ch ;
		cin >> a >> ch >> b ;

        // a triangle forms connecting two end points of b
		double c = sqrt(a*a + b*b) / 2.0 ;
		double theta = acos((2*c*c - b*b) / (2*c*c)) ;		// radian
		
		double lo = 0.0, hi = 400.0, mid, val ;
		while(fabs(hi - lo) > 1e-12){
			mid = (hi + lo) / 2.0 ;
			// s = r*theta == length of the portion of a circle that creates angle theta at the center
            val = 2 * mid * (a + c*theta) ;

			if(fabs(val - 400.00) < 1e-12){
				break ;
			}
			else if(val > 400.00){
				hi = mid - 1e-12 ;
			}
			else{
				lo = mid + 1e-12 ;
			}
		}

		cout<< "Case "<< tc<< ": "<< a*mid << " " << b*mid << endl;
	}

	return 0;
}