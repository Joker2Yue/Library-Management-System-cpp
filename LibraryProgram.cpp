/*
 * @Author: Joker Yue, Joker_Yue@qq.com
 * @Date: 2022-11-10 19:35:05
 * @LastEditors: Joker Yue
 * @LastEditTime: 2022-11-20 18:15:10
 * @FilePath: \BookEditOnly\LibraryProgram.cpp
 * @Description:程序入口
 */
/*更新日志：
10-11-2022：第一版
10-11-2022: 类的总体设计:    请参见"/src/Book.svg"和"/src/Book.md"
10-11-2022: SystemBasic:    添加了SystemBasic类并设计了大量方法用于继承与使用
10-11-2022: Book:           添加了Book类并设计了大量方法用于主要的数据与方法
10-11-2022：Book:           添加了管理员登录功能与界面
10-11-2022：SystemBasic:    添加了输入密码时的密码隐藏功能
10-11-2022：SystemBasic:    修复了部分界面排版出错的问题
10-11-2022：SystemBasic:    添加了操作判断：输入n/y yes以继续
10-11-2022：SystemBasic:    修复了缓冲区溢出导致系统无法正常退出的问题
10-11-2022：SystemBasic:    添加了数字合法性的方法
10-11-2022：SystemBasic:    添加了判断失误次数的方法
11-11-2022：Book:           修复了bookData.txt无法读取的问题
11-11-2022：Book:           添加了图书价格合法性的判断
11-11-2022：Book:           添加了在图书查看页面图书库存的判断
11-11-2022：Book:           修复了图书查看页面的借出状态错误的问题
11-11-2022：SystemBasic:    修复了重新进入系统时书籍仓库丢失的问题
11-11-2022：SystemBasic:    添加了无bookData.txt的修复功能
11-11-2022：Book:           添加了在添加书籍时图书ISBN编号的判断功能
11-11-2022：Book:           修复了在添加图书时，图书价格不合法却无法判断的问题
11-11-2022: Book:           添加了删除全部书籍的功能
11-11-2022: SystemBasic:    添加了彩色字体
11-11-2022: SystemBasic:    添加了蓝屏和修复模式 :-)
11-11-2022: SystemBasic:    修改了bookData.txt的修复界面
12-11-2022：SystemBasic:    修复了在蓝屏时进度条超出100%的问题
12-11-2022：SystemBasic:    添加了用于获取系统时间的方法
12-11-2022：Book:           设置了用户借阅时自动填写借阅时间

12-11-2022: 第二版
12-11-2022: Lend:           添加了Lend类用于储存用户借阅信息
12-11-2022: Book:           添加了数据中lendHead指针用于指向第一个Lend类数据以显示借阅信息
12-11-2022: Book:           修复了无藏书时也能修改书籍信息的问题
12-11-2022: Book:           修复了部分界面无法退出的问题
12-11-2022: Lend:           修复了部分排版
12-11-2022: Book:           添加了Lend中信息的文件读写操作
12-11-2022: Book:           修复了Lend中信息的文件读写错误导致数据丢失的问题
12-11-2022: SystemBasic:    添加了获取系统时间方法的模式
12-11-2022: SystemBasic:    解决了由于菱形继承导致的方法冲突
12-11-2022: Book:           删除了Book中部分弃用数据：lendUserId,lendUserName,lendTime
12-11-2022: main:           添加了主界面
12-11-2022: SystemBasic:    添加了主界面显示系统时间
13-11-2022: SystemBasic:    添加了鼠标光标的隐藏和显示功能，并将其运用在蓝屏界面
13-11-2022: Book:           修改文件保存方式，剔除冗余数据
13-11-2022: Book & Lend:    剔除全部无用的注释代码
13-11-2022: SystemBasic:    添加了管理员修改管理员用户的功能
13-11-2022: Book:           修复了管理员修改的数据无法保存的问题
13-11-2022: main:           添加了预加载界面
14-11-2022: main:           添加了预加载界面的加载图 :-)
14-11-2022: Book:           修改了Book中部分情况无法退出、意外退出的问题
14-11-2022: Lend:           修改了next指针的权限（摆烂了）
14-11-2022: main:           添加了主界面的作品信息

14-11-2022: 第三版
14-11-2022: all:            修复了大量界面中异常退出的问题


*/
// LibraryProgram.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。

#include "Book.h"
using namespace std;

//全局变量! Book的head
Book *head = new Book;

void welcomeAndLoad()
{
    // system("color 1");//蓝色
    cout << "       ===    欢迎进入HNIT图书管理系统!   ===" << endl;
    BLUE;
    HIDDEN_CURSOR; ///
    cout << "loading ";
    for (int i = 0; i < 5; i++)
    {
        cout << "\b-";
        Sleep(200);
        cout << "\b\\";
        Sleep(200);
        cout << "\b|";
        Sleep(200);
        cout << "\b/";
        Sleep(200);
    }
    WHITE;
    head->fileLoadBook(head);
    SHOW_CURSOR;
}

int main()
{
    // std::ios::sync_with_stdio(false);//取消std::cin与scanf()的同步，以加快cin的读取速度
    welcomeAndLoad();
    while (1)
    {
        system("cls");
        head->mainForm();

        int input;
        cin >> input;

        if (input == 1)
        {
            // int failTimes=0;
            // while(head->sysLogin())
            // {
            //     cout << "请重新输入："<< endl;
            //     if(head->failTimes(++failTimes)) break;
            // }
            if (!head->sysLogin(head->returnName(), head->returnPassword()))
                head->adminBookMenu(head);
            else
            {
                cout << "按任意键以返回上级";
                _getch();
            }
        }
        else if (input == 2)
        {
            cout << "关于我们：\n\t该图书管理软件旨在将图书管理员\n从繁重图书管理模式下拯救出去！" << endl;
            _getch();
            cout << endl;
        }
        else if (input == 3)
        {
            cout << "懂不懂熟能生巧这个道理啊喂（战术后仰）。" << endl;
            _getch();
            cout << endl;
        }
        else if (input == 4)
        {
            BLUE;
            cout << "小队成员：梁梦婷,谭玲洁,汪泽东,罗越" << endl;
            YELLOW;
            cout << "特色功能：文件储存,系统多级菜单,彩色字体,动态存储,密码系统,系统时间" << endl;
            PINK;
            cout << "技术简介: 动态链表,文件读写,宏指令,Windows库" << endl;
            WHITE;
            _getch();
            cout << endl;
        }
        else
        {
            RED; //红色
            cout << "正在退出系统..." << endl;
            WHITE; //白色
            return 0;
        }
    }

    return 0;
}
