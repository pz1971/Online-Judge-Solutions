#include <bits/stdc++.h>
using   namespace  std ;
typedef long   long LL ;

bool getWord(string &word){
    word.clear() ;
    char ch ;
	
	while(1){
		ch = getchar() ;
		if(ch != ' ')
			break ;
	}

    for( ; ch != ' ' && ch != '\n' ; ch = getchar()){
        word.push_back(ch) ;
    }
    return (ch != '\n') ;
}

int main(){

	int t ;
    scanf("%d", &t);
	map<string, int> mp ;
 
    for(int tc = 1 ; tc <= t ; tc++){
        int n;
        scanf("%d", &n);
        getchar() ;
 
        string word ;
		mp[""] = 1 ;
        while(n--){
            getWord(word) ;
            if(word.size() >= 2)
                sort(++(word.begin()), --(word.end())) ;
            mp[word]++ ;
        }
 
        int m ;
        scanf("%d", &m);
        getchar() ;
 
        printf("Case %d:\n", tc);
        while(m--){
            LL ans = 1 ;
            while(true){
                bool f = getWord(word) ;
 
                if(word.size() >= 2)
                    sort(++(word.begin()), --(word.end())) ;
                ans *= mp[word] ;
				if(!f)	break ;
            }
            printf("%lld\n", ans);
        }
		mp.clear() ;
    }

	return 0;
}