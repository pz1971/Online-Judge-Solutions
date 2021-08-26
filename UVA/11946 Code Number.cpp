#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    while(cin>> t)
    {
        getchar();
        while(t--)
        {
            vector <char> str;
            string s;
            while(getline(cin, s))
            {
                if(s.size()==0)
                    break;
                int l= s.size();
                for(int i=0; i<l; i++)
                {
                    if(s.at(i)>='0' && s.at(i)<='9')
                    {
                        int n = s.at(i) - '0';
                        switch (n)
                        {
                        case 0:
                            str.push_back('O');
                            break;
                        case 1:
                            str.push_back('I');
                            break;
                        case 2:
                            str.push_back('Z');
                            break;
                        case 3:
                            str.push_back('E');
                            break;
                        case 4:
                            str.push_back('A');
                            break;
                        case 5:
                            str.push_back('S');
                            break;
                        case 6:
                            str.push_back('G');
                            break;
                        case 7:
                            str.push_back('T');
                            break;
                        case 8:
                            str.push_back('B');
                            break;
                        case 9:
                            str.push_back('P');
                            break;
                        }
                    }
                    else
                    {
                        str.push_back(s.at(i));
                    }
                }
                str.push_back('\n');
            }
            int l = str.size();
            for(int i=0; i<l; i++)
                cout<< str.at(i);
            if(t!=0)
                cout<< endl;
        }
    }
    return 0;
}
