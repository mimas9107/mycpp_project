#include <windef.h>
#include <winbase.h>
#include <winuser.h>
#include <windows.h>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int get_idle_duration(){
    int systemUptime = GetTickCount();    // was Environment.TickCount
    int idleTicks = 0;

    LASTINPUTINFO lastInputInfo;
    lastInputInfo.cbSize = sizeof (lastInputInfo);
    lastInputInfo.dwTime = 0;
    if (GetLastInputInfo(&lastInputInfo)) {        
        int lastInputTicks = (int)lastInputInfo.dwTime;
        idleTicks = systemUptime - lastInputTicks;
    }
    return idleTicks/1000;
}

int main() {
    
    int idleT;
    /* 設定 程式執行後不要有 console視窗 */
    ShowWindow(FindWindowA("ConsoleWindowClass", NULL), false);

    while(true){
        idleT = get_idle_duration();
        /* 若 idleT > 60 就作點什麼事: */
        if(idleT>=60)
        {
            /* printf("%d seconds\n", (idleT > 0)? idleT: 0); */
            mouse_event(0x0001,5,0,0,0);
            Sleep(1000);
            mouse_event(0x0001,0,5,0,0);
            Sleep(1000);
            mouse_event(0x0001,-5,0,0,0);
            Sleep(1000);
            mouse_event(0x0001,0,-5,0,0);
            Sleep(1000);

        }
        Sleep(60000); /* 休息60秒減少CPU占用*/
    }
    /* 把console釋放掉 */
    FreeConsole();
    return 0;
}