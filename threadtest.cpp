#include <iostream>
#include <stdexcept>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <thread>
#include <chrono>
#include <windows.h>
#include <stdio.h>
#include <tchar.h>

using namespace std;
void greetings()
{
    cout << "\u001B[31mUsage:                                                                " << endl;
    cout << "     ThreadLaunch \u001B[32m[filename]                                          " << endl;
    cout << "\u001B[34m     if there isn't filename, default name = commands.txt   \u001B[37m" << endl;
}

bool file_exists (const std::string& name) {
    ifstream f(name.c_str());
    return f.good();
}

vector<string> readlines(ifstream& f)
{
    vector<string> str_array;
    string str;
    ///int idx = 0;
    ///string* line = new string[commandcounts];
    if(f.is_open())
    {
        
        while(getline(f,str))
        {
            ///cout << line[idx].c_str() << " size=" << line[idx].size() << endl;
            str_array.push_back(str);

        }
        f.close();
    }
    return str_array;
}

int shellCmd(string cmd, string result) {
    char buffer[512];
    result = "";

    // Open pipe to file
    FILE* pipe = popen(cmd.c_str(), "r");
    if (!pipe) {
        return false;
    }

    // read till end of process:
    while (!feof(pipe)) {
        // use buffer to read and add to result
        if (fgets(buffer, sizeof(buffer), pipe) != NULL)
            result += buffer;
    }

    pclose(pipe);
    return 1L;
}

int fork_win(TCHAR* cmd)
{
    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    ZeroMemory( &si, sizeof(si) );
    si.cb = sizeof(si);
    ZeroMemory( &pi, sizeof(pi) );
    printf(" forking... the command: (%s) [%d]\n",cmd,strlen((const char*) cmd));
    // Start the child process. 
    if( !CreateProcess( NULL,   // No module name (use command line)
        cmd,        // Command line
        NULL,           // Process handle not inheritable
        NULL,           // Thread handle not inheritable
        FALSE,          // Set handle inheritance to FALSE
        0,              // No creation flags
        NULL,           // Use parent's environment block
        NULL,           // Use parent's starting directory 
        &si,            // Pointer to STARTUPINFO structure
        &pi )           // Pointer to PROCESS_INFORMATION structure
    ) 
    {
        printf( "CreateProcess failed (%d).\n", GetLastError() );
        return 0L;
    }

    /// Wait until child process exits.
    ///WaitForSingleObject( pi.hProcess, INFINITE );

    // Close process and thread handles. 
    CloseHandle( pi.hProcess );
    CloseHandle( pi.hThread );

    return 0L;
}


int main(int argc, char* argv[]) 
{
    if(argc <=1 )
    {
        greetings();
        return 0L;
    }
    vector<string> commands;
    if(file_exists(argv[argc-1]))
    {
        ifstream infile(argv[argc-1]);
        commands = readlines(infile);
    }else
    {
        cout << " The \u001B[32m" << argv[argc-1] << "\u001B[37m isn't be found! \n The default commands.txt will be opened! \n" << endl;
        ifstream infile("commands.txt");
        commands = readlines(infile);
    }

    string result;
    for(vector<string>::iterator it_i = commands.begin();it_i != commands.end();++it_i )
    {
        fork_win((TCHAR *)(it_i.base()->c_str()));
    }
    this_thread::sleep_for (std::chrono::seconds(5)); /// 主執行緒(main) 先等待 5秒, 待子執行緒(各個cmd)發射後才結束...
    return 0;
}