#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    size_t c{};
    while(cin>> s)
    {
        c++;
        if(s.compare("*")==0)
            break;
        cout<< "Case "<< c<< ": ";
        if(s.compare("Hajj")==0)
            cout<< "Hajj-e-Akbar"<< endl;
        else
            cout<< "Hajj-e-Asghar"<< endl;
    }
    return 0;
}
