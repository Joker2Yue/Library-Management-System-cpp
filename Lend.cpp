/*
 * @Author: Joker Yue, Joker_Yue@qq.com
 * @Date: 2022-11-15 09:24:41
 * @LastEditors: Joker Yue
 * @LastEditTime: 2022-11-16 21:59:48
 * @FilePath: \BookEditOnly\Lend.cpp
 * @Description:
 */
#include "Lend.h"
// #include "SystemBasic.h"

//һ��ϵͳ���ܶ�����ʹ��ϵͳ���� :-)

//ͨ�������������û�ID���ش˽�����Ϣ
Lend *Lend::searchLend(Lend *head, int id) const
{

    // system("cls");
    Lend *p1;
    p1 = head->next;
    //�����ڵ�ֱ���ҵ�β��
    while (p1 != NULL)
    {
        //�������Ϣ�봫�������ͬ
        if (id == p1->lendUserId)
            return p1;
        p1 = p1->next;
    }

    return NULL;
}

//ɾ���˽�����Ϣ
void Lend::delThisMsg(Lend *head)
{

    Lend *p1 = head;

    cout << "���ڹ黹..." << endl;
    while (p1->next != this)
        p1 = p1->next;

    //��������ĺ������Ϊp1��̣������������ɾ��������
    p1->next = this->next;

    cout << "�黹�ɹ�!" << endl;
    return;
}

//ɾ�����н�����Ϣ
// void delAllMsg(Lend *head);

//����½��� ����ӳɹ�����0�����ʧ��1
int Lend::newLend(Lend *head, SystemBasic *sysFun)
{

    // SystemBasic *sysFunc = new SystemBasic;
    int UserId;
    // this->lentNum = 1;

    // system("cls");
    Lend *p1 = head; //����p1����ͷ��ʼ����һֱ�ҵ�β
    while (p1->next != NULL)
        p1 = p1->next;
    Lend *newLendMsgPoint = new Lend; //����һ���¶���newLendMsgPoint�ý���p1��

    UserId = sysFun->str2Num(10, "�����������ID:", "IDΪ10λ���ڵ���������,����������:");
    // cout<<"�����������ID:";
    // cin>>UserId;
    if (searchLend(head, UserId))
    {
        cout << "���û��ѽ��ģ������˳�.." << endl;
        return EXIT;
    }
    newLendMsgPoint->lendUserId = UserId;

    cout << "���������������:";
    cin >> newLendMsgPoint->lendUserName;

    cout << "��������ı�ע:";
    cin >> newLendMsgPoint->lendMessage;

    newLendMsgPoint->lendTime = sysFun->getTime();
    cout << "�ɹ����!" << endl;

    p1->next = newLendMsgPoint;
    return 0;
}

//���ݶ�д
int Lend::returnThisLendUserID() const
{
    return this->lendUserId;
}
string Lend::returnThisLendUserName() const
{
    return this->lendUserName;
}
string Lend::returnThisLendTime() const
{
    return this->lendTime;
}
string Lend::returnThisLendMsg() const
{
    return this->lendMessage;
}

void Lend::setLend(int id, string name, string time, string msg)
{
    this->lendUserId = id;
    this->lendUserName = name;
    this->lendTime = time;
    this->lendMessage = msg;
}