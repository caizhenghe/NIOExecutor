#define  _CRT_SECURE_NO_WARNINGS

#include "ZHExecutor.h"
//#include "ZHThread.h"

int Execute(BASEEXECUTORTASK *pArgs)
{
    int iExit = 0;
    switch (pArgs->iState)
    {
    case ZHEXECUTOR_STATE_START:
        printf("Task %d execute...", pArgs->iTaskId);
        pArgs->iState = ZHEXECUTOR_STATE_STOP;
        break;
    case ZHEXECUTOR_STATE_STOP:
        printf("Task %d stop...", pArgs->iTaskId);
        iExit = -1;
        break;
    }
    return iExit;
}

int main()
{
    int iInput;
    static int iTaskId = 0;
    printf("启动状态机...\n");
    ZHTHREAD Thread = { 0 };
    ZHEXECUTOR *pExecutor = new ZHEXECUTOR;

    /*普通成员函数需要用类成员函数指针来保存*/
    ZHThreadCreate(ZHEXECUTOR::ThreadFunc, pExecutor, &Thread);

    printf("添加任务...\n");
    while (1){
        scanf("%d", &iInput);
        BASEEXECUTORTASK Task = { 0 };
        Task.iTaskId = iTaskId++;
        Task.iState = ZHEXECUTOR_STATE_START;
        pExecutor->Submit(Execute, &Task);
    }

    return 0;
}