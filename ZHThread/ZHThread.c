#include "ZHThread.h"

int ZHThreadCreate(void *(*pFunc)(void *), void *pArgs, ZHTHREAD *pThread)
{
    pThread->pFunc = pFunc;
    pThread->pArgs = pArgs;
    pThread->pDataResult = NULL;
    pThread->hThread = _beginthreadex(NULL, 0, ThreadFun, pThread, 0, &pThread->lThreadID);

    if (pThread->hThread == NULL)
    {
        return (ZHTHREAD_EC_FAILURE);
    }

    return (ZHTHREAD_EC_OK);
}

unsigned int __stdcall ThreadFun(void *pThread)
{
    ZHTHREAD *p = pThread;
    p->pDataResult = p->pFunc(p->pArgs);
    return 0;
}