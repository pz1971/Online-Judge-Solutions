#include<bits/stdc++.h>
using   namespace      std;
typedef long long      LL;
typedef vector<int>    VI;
typedef pair<int,int>  PII;

double F(string m, int d){
	double ret;
	if(m == "January")
		ret = 1.0;
	else if(m == "February")
		ret = 2.0;
	else if(m == "March")
		ret = 3.0;
	else if(m == "April")
		ret = 4.0;
	else if(m == "May")
		ret = 5.0;
	else if(m == "June")
		ret = 6.0;
	else if(m == "July")
		ret = 7.0;
	else if(m == "August")
		ret = 8.0;
	else if(m == "September")
		ret = 9.0;
	else if(m == "October")
		ret = 10.0;
	else if(m == "November")
		ret = 11.0;
	else if(m == "December")
		ret = 12.0;
	ret = ((ret * 100.0) + d)/100.0;
	return ret;
}

int main(){

	int t;
	cin>> t;
	char ch;
	int d1, d2;
	string m1, m2;
	LL y1, y2;
	double r1, r2;
	for(int tc=1; tc<= t; tc++){
		cin>> m1>> d1>> ch>> y1;
		cin>> m2>> d2>> ch>> y2;
		r1 = F(m1, d1);
		r2 = F(m2, d2);
		if(r1 > 2.29){
			y1++;
		}
		if(r2 < 2.29){
			y2--;
		}
		
		LL cnt = (y2/4) - (y1/4);
		if(y1%4 == 0)
			cnt++;
		cnt -= (y2/100) - (y1/100);
		if(y1%100 == 0)
			cnt--;
		cnt += (y2/400) - (y1/400);
		if(y1%400 == 0)
			cnt++;
		
		cout<< "Case "<< tc<< ": "<< cnt<< endl;
	}

	return 0;
}