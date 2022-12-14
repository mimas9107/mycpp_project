#include <windows.h>
#include <vector>
#include <iostream>

using namespace std;
// Structure that includes all screen hanldes and rectangles

struct cMonitorsVec
{
    std::vector<int>       iMonitors;
    std::vector<HMONITOR>  hMonitors;
    std::vector<HDC>       hdcMonitors;
    std::vector<RECT>      rcMonitors;

    static BOOL CALLBACK MonitorEnum(HMONITOR hMon, HDC hdc, LPRECT lprcMonitor, LPARAM pData)
    {
        cMonitorsVec* pThis = reinterpret_cast<cMonitorsVec*>(pData);
        pThis->hMonitors.push_back(hMon);
        cout << "hMon:" << hMon << endl;
        pThis->hdcMonitors.push_back(hdc);
        cout << "hDC:" << hdc << endl;
        pThis->rcMonitors.push_back(*lprcMonitor);
        cout << "lprcMonitor:" << lprcMonitor << endl;
        pThis->iMonitors.push_back(pThis->hdcMonitors.size());
        cout << "hdcMonitors.size:" << pThis->hdcMonitors.size() << endl;
        return TRUE;
    }
    cMonitorsVec()
    {
        HDC hdc = GetWindowDC(GetDesktopWindow());
        EnumDisplayMonitors(hdc, 0, MonitorEnum, (LPARAM)this);

    }

};

int main()
{
    cMonitorsVec Monitors;
    for (int monitorIndex=0;  monitorIndex < Monitors.iMonitors.size(); monitorIndex++)
    {
        std::wcout << "Screen id: " << monitorIndex << std::endl;
        std::wcout << "-----------------------------------------------------" << std::endl;
        std::wcout << " - screen left-top corner coordinates : (" << Monitors.rcMonitors[monitorIndex].left
                                                                   << "," << Monitors.rcMonitors[monitorIndex].top
                                                                   << ")" << std::endl;
        wcout << Monitors.hdcMonitors[monitorIndex] << endl;
        PatBlt(Monitors.hdcMonitors[monitorIndex],1,1,200,200,0);

        std::wcout << " - screen dimensions (width x height) : (" << std::abs(Monitors.rcMonitors[monitorIndex].right - Monitors.rcMonitors[monitorIndex].left)
                                                                 << "," << std::abs(Monitors.rcMonitors[monitorIndex].top - Monitors.rcMonitors[monitorIndex].bottom)
                                                                 << ")" << std::endl;
        std::wcout << "-----------------------------------------------------" << std::endl;
    }
}