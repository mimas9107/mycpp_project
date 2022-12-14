#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

int main() {
    vector<std::string> str_array;
    ///cout << "vector size: " << str_array.size() << endl;
    std::ifstream in("commands.txt");
    std::string str;
    while(std::getline(in,str))
    {
        if(str.size() > 0)
        {
            str_array.push_back(str);
        }
    }
    in.close();

    cout<< "vector size: " << str_array.size() << endl;
    for(std::string& line : str_array)
    {
        std::cout << line << std::endl;
    }

    return 0;
}
