#define UNICODE
#include <windef.h>
#include <winbase.h>
#include <winuser.h>
#include <windows.h>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

using namespace std;
int main(){
    printf(" This program will act as a fake process and sleep 60 sec...\n");
    printf("hello popo\n sleep 60sec\n");
    for(int c=0;c<60;c++)
    {
       printf("%d\n",c);
       Sleep(1000);
    }
    return 0L;
}