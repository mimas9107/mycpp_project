#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <sys/stat.h>
#include <unistd.h>
#define DEBUG_OUT;

using namespace std;
void greetings()
{
    cout << "\u001B[31mUsage:                                                                " << endl;
    cout << "     readline \u001B[32m[filename]                                              " << endl;
    cout << "\u001B[34m     if there isn't filename, default name = commands.txt   \u001B[37m" << endl;
}
bool file_exists (const std::string& name) {
    ifstream f(name.c_str());
    return f.good();
}

int readlines(ifstream& f){
    if(f.is_open())
    {
        string line;
        while(getline(f,line))
        {
            cout << line.c_str() << " size=" << line.size() << endl;
            cout << line.c_str() << endl;
            

        }
        f.close();
    }
    return 0L;
}

int main(int argc, char* argv[])
{
    if(argc <=1 )
    {
        greetings();
        return 0L;
    }
    /*cout << "argc= " << argc << endl;
    for(int i=0;i<argc;i++)
    {
        cout << "i="<< i << ": " << argv[i] << endl;
    }*/
    if(file_exists(argv[argc-1]))
    {
        ifstream infile(argv[argc-1]);
        readlines(infile);
    }else
    {
        cout << " The \u001B[32m" << argv[argc-1] << "\u001B[37m isn't be found! \n The default commands.txt will be opened! \n" << endl;
        ifstream infile("commands.txt");
        readlines(infile);

    }
    
    

    
    return 0L;
}




