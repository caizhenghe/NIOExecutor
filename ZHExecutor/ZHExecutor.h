#include<stdio.h>
#include<iostream>
#include<process.h>
#include<windows.h>
#include"ZHThread.h"

#define ZHEXECUTOR_EC_OK 0
#define ZHEXECUTOR_EC_FAILURE -1
#define ZHEXECUTOR_TASK_MAX 10
#define ZHEXECUTOR_STATE_START 0
#define ZHEXECUTOR_STATE_STOP -1

typedef struct BASEEXECUTORTASK{
    int iTaskId;
    int iState;
}BASEEXECUTORTASK;

typedef struct ZHEXECUTORTASK{
    int iTaskId;
    int(*pFunc)(BASEEXECUTORTASK *);
    BASEEXECUTORTASK *pArgs;
}ZHEXECUTORTASK;

class ZHEXECUTOR{
private :
     volatile int bStop;
     //ZHTHREAD Thread;
     ZHEXECUTORTASK pTaskList[ZHEXECUTOR_TASK_MAX];
public :
    /**
    *  CreateThread
    *  @abstract     执行线程，不断执行TaskList中的任务
    *
    *  @param[in]    pArgs     传入参数
    *
    *  @return     ZHEXECUTOR_EC_OK 执行成功
    *              ZHEXECUTOY_EC_FAILURE 执行失败
    */
    static void *ThreadFunc(void *pArgs);

    /**
    *  Submit
    *  @abstract     将Task提交到TaskList中
    *
    *  @param[in]    pFunc     执行函数
    *  @param[in]    pArgs     传入参数
    *
    *  @return     ZHEXECUTOR_EC_OK 执行成功
    *              ZHEXECUTOY_EC_FAILURE 执行失败
    */
    int Submit(int(*pFunc)(BASEEXECUTORTASK *), BASEEXECUTORTASK *pArgs);

    /**
    *  Start
    *  @abstract     开启状态机
    *
    *  @return     ZHEXECUTOR_EC_OK 执行成功
    *              ZHEXECUTOY_EC_FAILURE 执行失败
    */
    int Start();

    /**
    *  ClearTask
    *  @abstract     从TaskList中移除任务
    *
    *  @param[in]    pTask     任务
    *
    *  @return     ZHEXECUTOR_EC_OK 执行成功
    *              ZHEXECUTOY_EC_FAILURE 执行失败
    */
    int ClearTask(ZHEXECUTORTASK *pTask);
};

