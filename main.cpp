#include <iostream>
#include <windows.h>
#include "Helper.h"
#include "Base64.h"
#include "KeyConstants.h"
using namespace std;

int main()
{
    MSG msg;
    while(GetMessage(&msg,NULL,0,0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg); //forwards message to the system
    }
    return 0;
}
