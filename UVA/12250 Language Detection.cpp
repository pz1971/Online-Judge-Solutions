#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    size_t tc{};
    while(cin>> s)
    {
        tc++;
        if(s.compare("#")==0)
            break;
        cout<< "Case "<< tc<< ": ";

        if(s.compare("HELLO")==0)
            cout<< "ENGLISH";
        else if(s.compare("HOLA")==0)
            cout<< "SPANISH";
        else if(s.compare("HALLO")==0)
            cout<< "GERMAN";
        else if(s.compare("BONJOUR")==0)
            cout<< "FRENCH";
        else if(s.compare("CIAO")==0)
            cout<< "ITALIAN";
        else if(s.compare("ZDRAVSTVUJTE")==0)
            cout<< "RUSSIAN";
        else
            cout<< "UNKNOWN";

        cout<< endl;
    }
    return 0;
}
