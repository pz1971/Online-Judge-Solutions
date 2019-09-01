#include<bits/stdc++.h>
using   namespace      std;
typedef long long      LL;
typedef vector<int>    VI;
typedef pair<int,int>  PII;
const double EXP = 2.718281828;

double calculate_e(double D){
	double x = 5417.7530 * ( (1/273.16) - 1/(D + 273.16) );
	return 6.11 * pow( EXP, x );
}

double calculate_h(double e){
	return 0.5555 * ( e - 10.0 ) ;
}

int main(){

	string typeT, typeD, typeH, str;
	double T, D, H, h, e, x;
	cout<< fixed<< showpoint<< setprecision(1);
	while(cin>> str){
		if(str == "E")
			break;
		typeT = typeD = typeH = "...";
		if(str == "T"){
			typeT = str;
			cin>> T;
		}
		else if(str == "D"){
			typeD = str;
			cin>> D;
		}
		else if(str == "H"){
			typeH = str;
			cin>> H;
		}

		cin>> str;

		if(str == "T"){
			typeT = str;
			cin>> T;
		}
		else if(str == "D"){
			typeD = str;
			cin>> D;
		}
		else if(str == "H"){
			typeH = str;
			cin>> H;
		}

		if(typeH == "..."){
			e = calculate_e(D);
			h = calculate_h(e);
			H = T + h ;
		}

		else if(typeT == "..."){
			e = calculate_e(D);
			h = calculate_h(e);
			T = H - h;
		}

		else if(typeD == "..."){
			e = ((H - T)/0.5555) + 10.0;
			x = ( log10(e/6.11) / log10(EXP) ) / 5417.7530;
			D = 273.16/(1 - 273.16*x) - 273.16;
		}
		cout<< "T "<< T<< " D "<< D<< " H "<< H<< endl;
	}

	return 0;
}