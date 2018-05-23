#include "ThreadUtils.h"

int ThreadCreate(void *(*pFunc)(void *), void *pArgs, THREAD *pThread)
{
    pThread->pFunc = pFunc;
    pThread->pArgs = pArgs;
    pThread->pDataResult = NULL;
    pThread->hThread = _beginthreadex(NULL, 0, ThreadFun, pThread, 0, &pThread->lThreadID);

    if (pThread->hThread == NULL)
    {
        return (THREAD_EC_FAILURE);
    }

    return (THREAD_EC_OK);
}

unsigned int __stdcall ThreadFun(void *pThread)
{
    ZHTHREAD *p = pThread;
    p->pDataResult = p->pFunc(p->pArgs);
    return 0;
}