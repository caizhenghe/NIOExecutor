#define  _CRT_SECURE_NO_WARNINGS

#include "NIOExecutor.h"

static int Execute(BASEEXECUTORTASK *pArgs)
{
    int iExit = 0;
    switch (pArgs->iState)
    {
    case NIOEXECUTOR_STATE_START:
        printf("Task %d execute...\n", pArgs->iTaskId);
        pArgs->iState = NIOEXECUTOR_STATE_STOP;
        break;
    case NIOEXECUTOR_STATE_STOP:
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
    printf("启动状态机...\n");
    THREAD Thread = { 0 };
    NIOEXECUTOR *pExecutor = new NIOEXECUTOR;

    ThreadCreate(NIOEXECUTOR::ThreadFunc, pExecutor, &Thread);

    printf("添加任务...\n");
    while (1){
        scanf("%d", &iInput);
        /* 编译器内部作了优化，不会重复分配内存，用该种方法传参会导致TaskList中的pArgs指向同一个对象 */
        //BASEEXECUTORTASK Task = { 0 };
        /* 在退出任务列表时释放内存，不会导致内存泄露 */
        BASEEXECUTORTASK *pTask = new BASEEXECUTORTASK;
        pTask->iTaskId = ++iTaskId;
        pTask->iState = NIOEXECUTOR_STATE_START;
        pExecutor->Submit(Execute, pTask);
    }
    return 0;
}