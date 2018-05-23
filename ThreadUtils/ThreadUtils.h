#ifndef _THREAD_UTILS_H_
#define _THREAD_UTILS_H_

#ifdef __cplusplus
extern "C" {
#endif
#include<process.h>
#include<windows.h>

#define THREAD_EC_OK 0
#define THREAD_EC_FAILURE -1

/*线程描述符结构体*/
typedef struct THREAD{
    HANDLE hThread;
    DWORD  lThreadID;
    void *(* pFunc)(void *);
    void *pArgs;
    void *pDataResult;
}THREAD;

int ThreadCreate(void *(* pFunc)(void *),void *pArgs,THREAD *pThread);

unsigned int __stdcall ThreadFun(void *pThread);

#ifdef __cplusplus
}
#endif
#endif