#include <iostream>
#include <cstring>

using namespace std;
int main()
{
    
    char str1[]="hello";
    char str2[]="Hello";

    ///cout << "str1 = " << str1 << endl;   
    ///cout << "str2 = " << str2 << endl;   

    ///cout << "compare str1 and str2 : " << strcmp(str1, str2) << endl;

    cout << "\n Please input str1 : " ;
    cin >> str1;

    cout << "you inputed a string1: " << str1 << endl;

    cout << "\n Please input str2 : " ;
    cin >> str2;
    cout << "you inputed a string2: " << str2 << endl;

    cout << "compare str1 and str2 : " << strcmp(str1, str2) << endl;

    return 0L;
}