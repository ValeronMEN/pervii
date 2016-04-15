#ifndef __MAIN_H__
#define __MAIN_H__

#include <windows.h>

#ifdef BUILD_DLL
    #define DLL_EXPORT __declspec(dllexport)
#else
    #define DLL_EXPORT __declspec(dllimport)
#endif


#ifdef __cplusplus
extern "C"
{
#endif

#include "C:\Users\DrLove\Desktop\lab2\Lab2StaticLib\queue.h"

int DLL_EXPORT compare(queue_t * myqueue);
int DLL_EXPORT reaction(queue_t * myqueue);

#ifdef __cplusplus
}
#endif

#endif // __MAIN_H__
