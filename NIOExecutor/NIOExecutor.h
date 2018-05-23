#include<stdio.h>
#include<iostream>
#include<process.h>
#include<windows.h>
#include"ThreadUtils.h"

#define NIOEXECUTOR_EC_OK 0
#define NIOEXECUTOR_EC_FAILURE -1
#define NIOEXECUTOR_TASK_MAX 10
#define NIOEXECUTOR_STATE_START 0
#define NIOEXECUTOR_STATE_STOP -1

typedef struct BASEEXECUTORTASK{
    int iTaskId;
    int iState;
}BASEEXECUTORTASK;

typedef struct NIOEXECUTORTASK {
    int(*pFunc)(BASEEXECUTORTASK *);
    BASEEXECUTORTASK *pArgs;
}NIOEXECUTORTASK;

class NIOEXECUTOR{
private:
    volatile int bStop;
    NIOEXECUTORTASK pTaskList[NIOEXECUTOR_TASK_MAX];
public:
    NIOEXECUTOR();
    ~NIOEXECUTOR();
    /**
    *  CreateThread
    *  @abstract     执行线程，不断执行TaskList中的任务
    *
    *  @param[in]    pArgs     传入参数
    *
    *  @return     NIOEXECUTOR_EC_OK 执行成功
    *              ZHEXECUTOY_EC_FAILURE 执行失败
    */
    static void *ThreadFunc(void *pArgs);

    /**
    *  Submit
    *  @abstract     将Task提交到TaskList中
    *
    *  @param[in]    pFunc     Task函数
    *  @param[in]    pArgs     传入参数
    *
    *  @return     NIOEXECUTOR_EC_OK 执行成功
    *              ZHEXECUTOY_EC_FAILURE 执行失败
    */
    int Submit(int(*pFunc)(BASEEXECUTORTASK *), BASEEXECUTORTASK *pArgs);

    /**
    *  ClearTask
    *  @abstract     从TaskList中移除任务
    *
    *  @param[in]    pTask     任务
    *
    *  @return     NIOEXECUTOR_EC_OK 执行成功
    *              ZHEXECUTOY_EC_FAILURE 执行失败
    */
    int ClearTask(NIOEXECUTORTASK *pTask);
};