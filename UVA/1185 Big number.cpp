#include<bits/stdc++.h>
using   namespace      std;
typedef long long      LL;
typedef vector<int>    VI;
typedef pair<int,int>  PII;

const int MX = 1e7+5 ;
double ar[MX] ;

void precalculate(){
	ar[0] = 0.0 ;
	for(int i = 1; i<MX ; i++){
		ar[i] = ar[i - 1] + log10( (double)i ) ;
	}
}

long long factDigits(int n)
{
    if (n < 0)
        return 0;
    if (n <= 1)
        return 1;
 
    // Kamenetsky formula
    double x = ((n * log10(n / M_E) +
                log10(2 * M_PI * n) /
                2.0));
    return floor(x) + 1;
}

void approach_1(){
	precalculate() ;

	int t , n ;
	cin >> t ;

	while (t--)
	{
		cin >> n;
		cout<< ( LL) floor(ar[n]) + 1 << endl; 
	}
}

void approach_2(){
	int t , n ;
	cin >> t ;

	while (t--)
	{
		cin >> n;
		cout<< factDigits( n ) << endl; 
	}
}

int main(){

	// approach_1() ;
	approach_2() ;

	return 0;
}