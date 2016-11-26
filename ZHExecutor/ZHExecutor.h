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

typedef struct ZHEXECUTORTASK {
    int(*pFunc)(BASEEXECUTORTASK *);
    BASEEXECUTORTASK *pArgs;
}ZHEXECUTORTASK;

class ZHEXECUTOR{
private :
     volatile int bStop;
     ZHEXECUTORTASK pTaskList[ZHEXECUTOR_TASK_MAX];
public :
    ZHEXECUTOR();
    ~ZHEXECUTOR();
    /**
    *  CreateThread
    *  @abstract     ִ���̣߳�����ִ��TaskList�е�����
    *
    *  @param[in]    pArgs     �������
    *
    *  @return     ZHEXECUTOR_EC_OK ִ�гɹ�
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
    *  @return     ZHEXECUTOR_EC_OK ִ�гɹ�
    *              ZHEXECUTOY_EC_FAILURE ִ��ʧ��
    */
    int Submit(int(*pFunc)(BASEEXECUTORTASK *), BASEEXECUTORTASK *pArgs);

    /**
    *  ClearTask
    *  @abstract     ��TaskList���Ƴ�����
    *
    *  @param[in]    pTask     ����
    *
    *  @return     ZHEXECUTOR_EC_OK ִ�гɹ�
    *              ZHEXECUTOY_EC_FAILURE ִ��ʧ��
    */
    int ClearTask(ZHEXECUTORTASK *pTask);
};

