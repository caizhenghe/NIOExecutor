#include<process.h>

#define ZHEXECUTOR_EC_OK 0
#define ZHEXECUTOY_EC_FAILURE -1

/**
*  CreateThread
*  @abstract     执行线程，不断执行TaskList中的任务
*
*  @param[in]    pArgs     传入参数
*
*  @return     ZHEXECUTOR_EC_OK 执行成功
*              ZHEXECUTOY_EC_FAILURE 执行失败
*/
int ThreadFunc(void *pArgs);

/**
*  Submit
*  @abstract     将Task提交到TaskList中
*
*  @param[in]    pArgs     传入参数
*
*  @return     ZHEXECUTOR_EC_OK 执行成功
*              ZHEXECUTOY_EC_FAILURE 执行失败
*/
int Submit();