#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n;
    while(cin>> n && n!=0)
    {
        vector <int> bin;
        int cnt_1{0};
        while(n)
        {
            bin.push_back(n%2);
            if(n%2==1)
                cnt_1++;
            n /= 2;
        }
        cout<< "The parity of ";
        for(int l=bin.size(); l>0; l--)
            cout<< bin.at(l-1);
        cout<< " is "<< cnt_1<< " (mod 2)."<< endl;
    }
    return 0;
}
