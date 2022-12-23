/*
 * @Author: Joker Yue, Joker_Yue@qq.com
 * @Date: 2022-11-15 09:24:41
 * @LastEditors: Joker Yue
 * @LastEditTime: 2022-11-16 22:00:03
 * @FilePath: \BookEditOnly\Lend.h
 * @Description:
 */
#pragma once
#include <string>
#include "SystemBasic.h"
using namespace std;
class Lend
{

    // protected:
private:
    //������Ҫ����Ϊprotected�Ľ���������ļ��洢��BOOK�����޷�ֱ�Ӷ�ȡ��Ҫ��д����
    //���� ������
    //�鼮������Ϣ
    int lendUserId;      //������ID
    string lendUserName; //����������
    string lendTime;     //����ʱ��
    string lendMessage;  //���ı�ע

public:
    //��һ�����ΪpublicΪ�˼���Book�еķ��ʹ�����
    Lend *next;

    // public:
    Lend(int lendUserId = -1, string lendUserName = "�����û�", string lendTime = "����ʱ��", string lendMessage = "������Ϣ")
        : lendUserId(lendUserId), lendUserName(lendUserName), lendTime(lendTime), lendMessage(lendMessage), next(NULL)
    {
    }
    //ͨ�������������û�ID���ش˽�����Ϣ
    Lend *searchLend(Lend *head, int id) const;

    //ɾ���˽�����Ϣ
    void delThisMsg(Lend *head);

    //����½��ģ�ʧ�����1
    int newLend(Lend *head, SystemBasic *sysFun);

    //���ݶ�д
    int returnThisLendUserID() const;
    string returnThisLendUserName() const;
    string returnThisLendTime() const;
    string returnThisLendMsg() const;

    void setLend(int id, string name, string time, string msg);
};
