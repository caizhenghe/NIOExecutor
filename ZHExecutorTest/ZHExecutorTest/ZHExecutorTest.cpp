#define  _CRT_SECURE_NO_WARNINGS

#include "ZHExecutor.h"

static int Execute(BASEEXECUTORTASK *pArgs)
{
    int iExit = 0;
    switch (pArgs->iState)
    {
    case ZHEXECUTOR_STATE_START:
        printf("Task %d execute...\n", pArgs->iTaskId);
        pArgs->iState = ZHEXECUTOR_STATE_STOP;
        break;
    case ZHEXECUTOR_STATE_STOP:
        printf("Task %d stop...\n", pArgs->iTaskId);
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

    ZHThreadCreate(ZHEXECUTOR::ThreadFunc, pExecutor, &Thread);

    printf("�������...\n");
    while (1){
        scanf("%d", &iInput);
        /* �������ڲ������Ż��������ظ������ڴ棬�ø��ַ������λᵼ��TaskList�е�pArgsָ��ͬһ������ */
        //BASEEXECUTORTASK Task = { 0 };
        /* ���˳������б�ʱ�ͷ��ڴ棬���ᵼ���ڴ�й¶ */
        BASEEXECUTORTASK *pTask = new BASEEXECUTORTASK;
        pTask->iTaskId = ++iTaskId;
        pTask->iState = ZHEXECUTOR_STATE_START;
        pExecutor->Submit(Execute, pTask);
    }
    return 0;
}