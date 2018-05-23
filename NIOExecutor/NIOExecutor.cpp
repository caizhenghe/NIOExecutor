#include "NIOExecutor.h"

NIOEXECUTOR::NIOEXECUTOR()
{
    bStop = 0;
    memset(pTaskList, 0x0, sizeof(NIOEXECUTORTASK)*NIOEXECUTOR_TASK_MAX);
}

NIOEXECUTOR::~NIOEXECUTOR(){
    // nothing todo
}

void *NIOEXECUTOR::ThreadFunc(void *pArgs)
{
    NIOEXECUTOR *pExecutor = (NIOEXECUTOR *)pArgs;
    while (!pExecutor->bStop)
    {
        for (int i = 0; i < NIOEXECUTOR_TASK_MAX; i++)
        {
            if (pExecutor->pTaskList[i].pFunc)
            {
                if (pExecutor->pTaskList[i].pFunc(pExecutor->pTaskList[i].pArgs) < 0)
                {
                    delete(pExecutor->pTaskList[i].pArgs);
                    pExecutor->ClearTask(&pExecutor->pTaskList[i]);
                }
            }
        }
        Sleep(1000);
    }
    return NULL;
}

int NIOEXECUTOR::Submit(int(*pFunc)(BASEEXECUTORTASK *), BASEEXECUTORTASK *pArgs)
{
    for (int i = 0; i < NIOEXECUTOR_TASK_MAX; i++)
    {
        if (pTaskList[i].pFunc == NULL)
        {
            NIOEXECUTORTASK *pTask = &pTaskList[i];
            pTask->pFunc = pFunc;
            pTask->pArgs = pArgs;
            break;
        }
    }
    return NIOEXECUTOR_EC_OK;
}

int NIOEXECUTOR::ClearTask(NIOEXECUTORTASK *pTask)
{
    pTask->pFunc = NULL;
    pTask->pArgs = { 0 };
    return NIOEXECUTOR_EC_OK;
}