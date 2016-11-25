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
    printf("����״̬��...\n");
    ZHTHREAD Thread = { 0 };
    ZHEXECUTOR *pExecutor = new ZHEXECUTOR;

    /*��ͨ��Ա������Ҫ�����Ա����ָ��������*/
    ZHThreadCreate(ZHEXECUTOR::ThreadFunc, pExecutor, &Thread);

    printf("�������...\n");
    while (1){
        scanf("%d", &iInput);
        BASEEXECUTORTASK Task = { 0 };
        Task.iTaskId = iTaskId++;
        Task.iState = ZHEXECUTOR_STATE_START;
        pExecutor->Submit(Execute, &Task);
    }

    return 0;
}