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
    //害本来要声明为protected的结果不方便文件存储（BOOK类中无法直接读取还要另写方法
    //所以 摆烂了
    //书籍借阅信息
    int lendUserId;      //借阅者ID
    string lendUserName; //借阅者姓名
    string lendTime;     //借阅时间
    string lendMessage;  //借阅备注

public:
    //下一项，声明为public为了减少Book中的访问工作量
    Lend *next;

    // public:
    Lend(int lendUserId = -1, string lendUserName = "借阅用户", string lendTime = "借阅时间", string lendMessage = "借阅信息")
        : lendUserId(lendUserId), lendUserName(lendUserName), lendTime(lendTime), lendMessage(lendMessage), next(NULL)
    {
    }
    //通过搜索借阅者用户ID返回此借阅信息
    Lend *searchLend(Lend *head, int id) const;

    //删除此借阅信息
    void delThisMsg(Lend *head);

    //添加新借阅，失败输出1
    int newLend(Lend *head, SystemBasic *sysFun);

    //数据读写
    int returnThisLendUserID() const;
    string returnThisLendUserName() const;
    string returnThisLendTime() const;
    string returnThisLendMsg() const;

    void setLend(int id, string name, string time, string msg);
};
