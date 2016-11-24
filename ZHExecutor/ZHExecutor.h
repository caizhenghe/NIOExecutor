#include<process.h>

#define ZHEXECUTOR_EC_OK 0
#define ZHEXECUTOY_EC_FAILURE -1

/**
*  CreateThread
*  @abstract     ִ���̣߳�����ִ��TaskList�е�����
*
*  @param[in]    pArgs     �������
*
*  @return     ZHEXECUTOR_EC_OK ִ�гɹ�
*              ZHEXECUTOY_EC_FAILURE ִ��ʧ��
*/
int ThreadFunc(void *pArgs);

/**
*  Submit
*  @abstract     ��Task�ύ��TaskList��
*
*  @param[in]    pArgs     �������
*
*  @return     ZHEXECUTOR_EC_OK ִ�гɹ�
*              ZHEXECUTOY_EC_FAILURE ִ��ʧ��
*/
int Submit();