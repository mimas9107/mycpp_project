#include <windows.h>
#include <tlhelp32.h>
#include <string>
#include <iostream>
using namespace std;
HANDLE _process = NULL;
DWORD pid = 0;
DWORD baseAddr = 0;
bool getID(string process)
{
    HANDLE hHandle = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS,0);
    PROCESSENTRY32 entry;
    entry.dwSize = sizeof(entry);
    do
    {
        if(!strcmp((char*)entry.szExeFile,process.c_str()))
        {
            pid = entry.th32ProcessID;
            CloseHandle(hHandle);
            _process = OpenProcess(PROCESS_ALL_ACCESS,false,pid);
            return true;
        }
    } while(Process32Next(hHandle,&entry));
    return false;
}
bool getModuleBaseAddress(string module)
{
    HANDLE hHandle = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE,pid);
    MODULEENTRY32 mentry;
    mentry.dwSize = sizeof(mentry);
    do
    {
        if(!strcmp((char*)mentry.szModule,module.c_str()))
        {
            CloseHandle(hHandle);
            baseAddr = (DWORD)mentry.modBaseAddr;
            return true;
        }
    } while(Module32Next(hHandle,&mentry));
    return false;
}

int main(int argc, char* argv[])
{
    if(argc<=1){
        printf("usage:\n\t enumprocess [detect process] «\n");
        return 1L;
    }
    while(!getID(argv[1])) {Sleep(10);}
    while(!getModuleBaseAddress(argv[1])) {Sleep(10);}
    cout << "PID: " << pid << endl << "Base Address: " << baseAddr;
    return 0;
}