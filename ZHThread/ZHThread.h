#ifndef _ZH_THREAD_H_
#define _ZH_THREAD_H_

#ifdef __cplusplus
extern "C" {
#endif
#include<process.h>
#include<windows.h>

#define ZHTHREAD_EC_OK 0
#define ZHTHREAD_EC_FAILURE -1

/*线程描述符结构体*/
typedef struct ZHTHREAD{
    HANDLE hThread;
    DWORD  lThreadID;
    void *(* pFunc)(void *);
    void *pArgs;
    void *pDataResult;
}ZHTHREAD;

int ZHThreadCreate(void *(* pFunc)(void *),void *pArgs,ZHTHREAD *pThread);

unsigned int __stdcall ThreadFun(void *pThread);

#ifdef __cplusplus
}
#endif
#endif