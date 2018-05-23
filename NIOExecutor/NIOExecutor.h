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
    *  @abstract     ִ���̣߳�����ִ��TaskList�е�����
    *
    *  @param[in]    pArgs     �������
    *
    *  @return     NIOEXECUTOR_EC_OK ִ�гɹ�
    *              ZHEXECUTOY_EC_FAILURE ִ��ʧ��
    */
    static void *ThreadFunc(void *pArgs);

    /**
    *  Submit
    *  @abstract     ��Task�ύ��TaskList��
    *
    *  @param[in]    pFunc     Task����
    *  @param[in]    pArgs     �������
    *
    *  @return     NIOEXECUTOR_EC_OK ִ�гɹ�
    *              ZHEXECUTOY_EC_FAILURE ִ��ʧ��
    */
    int Submit(int(*pFunc)(BASEEXECUTORTASK *), BASEEXECUTORTASK *pArgs);

    /**
    *  ClearTask
    *  @abstract     ��TaskList���Ƴ�����
    *
    *  @param[in]    pTask     ����
    *
    *  @return     NIOEXECUTOR_EC_OK ִ�гɹ�
    *              ZHEXECUTOY_EC_FAILURE ִ��ʧ��
    */
    int ClearTask(NIOEXECUTORTASK *pTask);
};