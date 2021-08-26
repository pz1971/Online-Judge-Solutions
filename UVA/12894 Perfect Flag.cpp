#include <iostream>
#define whatIs(x)       cerr<< #x << " = "<< x<< endl;
using namespace std ;

int x0, y0, x1, y1, cx, cy, r ;

bool valid(){
	int length = abs(x1 - x0) ;
	int width = abs(y1 - y0) ;
	int disx = abs(x0 - cx) ;
	int disy = abs(y0 - cy) ;

	if(length * 6 != width * 10)
		return false ;
	if(length != r * 5)
		return false ;
	if(disx * 20 != 9 * length)
		return false ;
	if(disy * 2 != width)
		return false ;
	
	return true ;
}

int main(){

	int test_case ;
	cin >> test_case ;
	
	while(test_case--){
		cin >> x0 >> y0 >> x1 >> y1>> cx >> cy >> r ;
		cout << (valid() ? "YES" : "NO") << endl ;
	}

	return 0;
}