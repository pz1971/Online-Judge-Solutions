#include <bits/stdc++.h>
using   namespace  std ;
using LL  =  long long ;

bool isLeapYear(int year){
    if (year % 400 == 0) return true;
    else if(year % 100 == 0) return false;
    else if(year % 4 == 0) return true;
    else return false;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int test_cases ;
    cin >> test_cases ;
    
    for(int tc = 1 ; tc <= test_cases ; tc++){
        int d, m, y, qy ;
        cin >> d >> m >> y >> qy ;
        if(d == 29 && m == 2){
            int cnt = 0 ;
            for(int i = y + 1 ; i <= qy ; i++)
                cnt += (int) isLeapYear(i) ;
            cout<< "Case "<< tc<< ": " << cnt << endl ;
        }
        else{
            cout<< "Case "<< tc<< ": " << qy-y << endl ;
        }
    }

    return 0;
}