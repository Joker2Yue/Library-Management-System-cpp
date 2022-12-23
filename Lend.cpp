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

//一个系统功能对象，以使用系统功能 :-)

//通过搜索借阅者用户ID返回此借阅信息
Lend *Lend::searchLend(Lend *head, int id) const
{

    // system("cls");
    Lend *p1;
    p1 = head->next;
    //遍历节点直到找到尾部
    while (p1 != NULL)
    {
        //如果有信息与传入参数相同
        if (id == p1->lendUserId)
            return p1;
        p1 = p1->next;
    }

    return NULL;
}

//删除此借阅信息
void Lend::delThisMsg(Lend *head)
{

    Lend *p1 = head;

    cout << "正在归还..." << endl;
    while (p1->next != this)
        p1 = p1->next;

    //将本对象的后继设置为p1后继，这样就完成了删除本对象
    p1->next = this->next;

    cout << "归还成功!" << endl;
    return;
}

//删除所有借阅信息
// void delAllMsg(Lend *head);

//添加新借阅 ，添加成功返回0，添加失败1
int Lend::newLend(Lend *head, SystemBasic *sysFun)
{

    // SystemBasic *sysFunc = new SystemBasic;
    int UserId;
    // this->lentNum = 1;

    // system("cls");
    Lend *p1 = head; //创建p1，从头开始遍历一直找到尾
    while (p1->next != NULL)
        p1 = p1->next;
    Lend *newLendMsgPoint = new Lend; //创建一个新对象newLendMsgPoint好接在p1上

    UserId = sysFun->str2Num(10, "请输入借阅者ID:", "ID为10位以内的数字类型,请重新输入:");
    // cout<<"请输入借阅者ID:";
    // cin>>UserId;
    if (searchLend(head, UserId))
    {
        cout << "此用户已借阅！正在退出.." << endl;
        return EXIT;
    }
    newLendMsgPoint->lendUserId = UserId;

    cout << "请输入借阅者姓名:";
    cin >> newLendMsgPoint->lendUserName;

    cout << "请输入借阅备注:";
    cin >> newLendMsgPoint->lendMessage;

    newLendMsgPoint->lendTime = sysFun->getTime();
    cout << "成功借出!" << endl;

    p1->next = newLendMsgPoint;
    return 0;
}

//数据读写
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