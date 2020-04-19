#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    while(getline(cin, s))
    {
        if(s.compare("DONE") == 0)
            break;
        vector <char> str;
        int l, i;
        l = s.size();
        bool invalid = true;
        for(i=0; i<l; i++)
        {
            char ch = s.at(i);
            if(isalpha(ch))
            {
                invalid = false;
                if(isupper(ch))
                    ch = tolower(ch);
                str.push_back(ch);
            }
        }

        if(invalid == true)
            cout<< "You won't be eaten!"<< endl;
        else
        {
            bool eaten = false;

            l = str.size();
            for(i=0; i<=l/2; i++)
            {
                if(str.at(i) != str.at(l-i-1))
                {
                    eaten = true;
                    break;
                }
            }
            if(eaten == false)
                cout<< "You won't be eaten!"<< endl;
            else
                cout<< "Uh oh.."<< endl;
        }
    }
    return 0;
}
