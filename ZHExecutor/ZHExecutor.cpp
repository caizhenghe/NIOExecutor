#include "ZHExecutor.h"

ZHEXECUTOR::ZHEXECUTOR()
{
    bStop = 0;
    for (int i = 0; i < ZHEXECUTOR_TASK_MAX; i++)
    {
        pTaskList[i] = { 0 };
    }
}

ZHEXECUTOR::~ZHEXECUTOR(){
// nothing todo
}

void *ZHEXECUTOR::ThreadFunc(void *pArgs)
{
    ZHEXECUTOR *pExecutor = (ZHEXECUTOR *)pArgs;
    while (!pExecutor->bStop)
    {
        for (int i = 0; i < ZHEXECUTOR_TASK_MAX; i++)
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

int ZHEXECUTOR::Submit(int(*pFunc)(BASEEXECUTORTASK *), BASEEXECUTORTASK *pArgs)
{
    for (int i = 0; i < ZHEXECUTOR_TASK_MAX; i++)
    {
        if (pTaskList[i].pFunc == NULL)
        {
            ZHEXECUTORTASK *pTask = &pTaskList[i];
            pTask->pFunc = pFunc;
            pTask->pArgs = pArgs;
            break;
        }
    }
    return ZHEXECUTOR_EC_OK;
}

int ZHEXECUTOR::ClearTask(ZHEXECUTORTASK *pTask)
{
    pTask->pFunc = NULL;
    pTask->pArgs = { 0 };
    return ZHEXECUTOR_EC_OK;
}