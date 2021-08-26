#include <bits/stdc++.h>
using   namespace  std ;
typedef long   long LL ;

class cube{
public:
	char side[6] ;

	cube(){
	}
	cube(string s){
		for(int i = 0 ; i < 6 ; i++)
			side[i] = s[i] ;
	}

	void rotate(const int sideNo){
		if(sideNo == 0){
			char temp = side[1] ;
			side[1] = side[3] ;
			side[3] = side[4] ;
			side[4] = side[2] ;
			side[2] = temp ;
		}
		else if(sideNo == 1){
			char temp = side[5] ;
			side[5] = side[3] ;
			side[3] = side[0] ;
			side[0] = side[2] ;
			side[2] = temp ;
		}
		else{
			char temp = side[1] ;
			side[1] = side[5] ;
			side[5] = side[4] ;
			side[4] = side[0] ;
			side[0] = temp ;
		}
	}
};

bool equal(const cube &c1, const cube &c2){
	for(int i = 0 ; i < 6 ; i++)
		if(c1.side[i] != c2.side[i])
			return false ;
	return true ;
}

int main(){

	string line ;

	while(cin >> line){
		cube c1(line.substr(0, 6)) ;
		cube c2(line.substr(6)) ;
		
		int rc = 0 , bc = 0 , gc = 0 ;
		for(int i = 0 ; i < 6 ; i++){
			if(c1.side[i] == 'r')
				rc++ ;
			else if(c1.side[i] == 'g')
				gc++ ;
			else
				bc++ ;

			
			if(c2.side[i] == 'r')
				rc-- ;
			else if(c2.side[i] == 'g')
				gc-- ;
			else
				bc-- ;
		}

		if(rc || bc || gc){
			cout << "FALSE" << endl ;
			continue ;
		}

		bool f = false ;
		for(int i = 1 ; i <= 4 ; i++){
			c1.rotate(0) ;
			for(int j = 1 ; j <= 4 ; j++){
				c1.rotate(1) ;
				for(int k = 1 ; k <= 4 ; k++){
					c1.rotate(2) ;
					if(equal(c1, c2)){
						f = true ;
						break ;
					}
				}
				if(f)	break ;
			}
			if(f)	break ;
		}

		cout << (f ? "TRUE" : "FALSE") << endl ;
	}

	return 0;
}