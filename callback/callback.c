#include <windows.h>
#include <string.h>
#include <sedio.h>

HWND hNotepad = NULL;

//枚举窗口时用到回调函数
bool CALLBACK EnumFunction(HWND hWnd, LPARAM lParam)
{
    //由窗口句柄得到窗口标题
    WCHAR strTitle[255] = {0};
    GetWindowText(hWnd, strTitle, 255);

    if(0 == lstrcmpW(strTitle, L"无标题 - 记事本“))
    {
        //找到记事本窗口，保存句柄
        hNotepad = hWnd;

        //终止枚举
        return FALSE;
    }
    else
    {
        //让系统提供下一个窗口
        return TRUE;
    }
}

int main(int argc, char *argv[])
{
    //枚举顶层窗口
    //系统api函数EnumWindows
    EnumWindows(EnumFunction, NULL)

    printf("记事本窗口句柄是:%x\n", hNotepad);
}