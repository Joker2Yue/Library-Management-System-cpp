/*
 * @Author: Joker Yue, Joker_Yue@qq.com
 * @Date: 2022-11-10 20:13:15
 * @LastEditors: Joker Yue
 * @LastEditTime: 2022-11-14 21:48:36
 * @FilePath: \bookOnly\SystemBasic.cpp
 * @Description:系统基础支持
 */
#include "SystemBasic.h"

//获取系统本地时间
string SystemBasic::getTime(string mode)
{
    // 旧的localtime方法获取时间，已被弃用
    // time_t timep;
    // time(&timep);
    // char tmp[256];
    // strftime(tmp, sizeof(tmp), "%Y-%m-%d %H:%M:%S", localtime(&timep));

    time_t time_seconds = time(0);
    struct tm now_time;
    localtime_s(&now_time, &time_seconds);

    std::stringstream ss; // string_stream输出
    if (mode == "accuracy")
        ss << now_time.tm_year + 1900 << "-" << now_time.tm_mon + 1 << "-"
           << now_time.tm_mday << "," << now_time.tm_hour << ":"
           << now_time.tm_min << ":" << now_time.tm_hour;
    else
        ss << now_time.tm_year + 1900 << "-" << now_time.tm_mon + 1 << "-" << now_time.tm_mday;
    // std::cout << ss.str() << std::endl;

    return ss.str();
}

// 语法说明：cin.sync();//清空缓冲区
int SystemBasic::nyContinue(const string tipMessage, const char mode) const
{
    char key;
    cout << tipMessage << endl;
    key = _getch();
    if (mode == 'y')
    {
        if (key == 'Y' || key == 'y')
        {
            cin.sync(); //清空缓冲区
            return 0;
        }
        else
        {

            cin.sync();
            return EXIT;
        }
    }

    else
    {

        if (key == 'n' || key == 'N')
        {

            cin.sync();
            return EXIT;
        }
        else
        {

            cin.sync();
            return 0;
        }
    }
    cin.sync();
    return 1;
    /*
    让用户确认输入的函数，用户输入N/n返回0，其他返回1
    tipMessage表示提示用户输入的文字 */
}
int SystemBasic::yesContinue(string Msg) const
{
    cout << Msg << endl;
    string yesCtn;
    cin >> yesCtn;
    if (yesCtn == "yes" || yesCtn == "YES") //输入YES选择继续
    {
        cin.sync();
        return 0;
    }
    cin.sync();
    return EXIT;
}

string SystemBasic::inputPwd(llui pwdLength)
{
    char key;
    string passwordKey;
    llui passwordIndex = 0;

    while (passwordKey.length() <= pwdLength)
    {
        key = _getch();
        // 退格键：如果输入删除键，就删除上一个字符和这个退格键
        if (key == '\b')
        {
            if (passwordIndex > 0)
            {
                // ab	\b 退格
                printf("\b \b");
                passwordIndex--;
                // 使用erase方法删除倒数第二个字符
                passwordKey.erase(passwordKey.end() - 1);
            }
            continue;
        }
        //	13 回车
        else if (key == 13)
        {
            if (passwordIndex > 0)
                break;
            else
            {
                printf("\n");
            }
        }
        else
        {
            if (passwordIndex < pwdLength)
            {
                printf("*");
                // 将输入的字符加入passwordKey尾部
                passwordKey += key;
            }
            else
            {
                continue;
            }
        }
        passwordIndex++;
    }
    // passwordKey[passwordIndex] = '\0';
    // printf("\n");
    cout << endl;
    return passwordKey;
}

void SystemBasic::fileRec()
{
    system("cls");
    system("color 14"); //蓝屏
    FILE *fileBook = fopen("bookData.txt", "r");
    HIDDEN_CURSOR; //隐藏光标
    printf(":-(\n您的系统遇到问题,需要重新启动,我们正在搜集信息,请不要关闭...\n");
    Sleep(1000);
    for (int i = 0; i < 100; i++)
    {
        printf("%d%%", i);
        Sleep(50);
        printf("\b\b\b");
    }
    if (fileBook == NULL)
        remove("bookData.txt"); //删除文件
    Sleep(1000);
    cout << "检测到丢失bookData.txt，正在尝试修复..." << endl;
    cout << "正在添加文件..." << endl;
    Sleep(1000);
    cout << "添加成功，正在重新设置指针..." << endl;
    fileBook = fopen("bookData.txt", "w"); //以写模式（w）打开文件，这样做可以新建文件
    Sleep(1000);
    cout << "成功！" << endl;
    Sleep(500);                            //延时1秒，想搞快点得加钱
    fileBook = fopen("bookData.txt", "r"); //重新尝试以 写 模式进入bookData.txt
    system("cls");                         //清屏
    if (fileBook != NULL)
    {
        system("color Af"); //绿屏
        printf("修复完成！请重新启动程序\n");
        printf("系统将在3秒后关闭...\n");
        Sleep(1000);
        printf("2秒后关闭...\n");
        Sleep(1000);
        printf("1秒后关闭...\n");
    }
    else
    {
        system("color 14"); //红屏
        printf(":-(\n修复失败！请手动检查或者联系我们\n");
        printf("联系方式：\nQQ:848484848\nEmail:");
    }
    exit(0);
    system("pause");
}

int SystemBasic::failTimes(int failTimes) const
{
    if (failTimes < 3)
        return 0;
    if (failTimes >= 3)
    {
        cout << "您已输入错误" << failTimes << "次，是否继续？[Y]" << endl;
        char key = _getch();
        cin.sync();
        if (key == 'y' || key == 'Y')
            return 0;
    }
    return EXIT;
}

double SystemBasic::str2Num(llui length, string tipMsg, string errMsg)
{
    cout << tipMsg;
    string changeStr; //想要转换的string
    double wantNum;   //将会传出的Num
    while (cin >> changeStr)
    {
        //判断输入的字符串是否合法
        int isStrAvl = 1;
        for (llui i = 0; i < changeStr.length(); i++)
        {
            //防止不是数字，防止数字比length长
            if (!isdigit(changeStr[i]) || changeStr.length() > length)
            {
                isStrAvl = 0;
                break;
            }
        }
        if (isStrAvl)
        {
            wantNum = stoi(changeStr);
            break;
        }
        else
            cout << errMsg;
    }
    return wantNum;
}

int SystemBasic::sysLogin(string username, string password)
{
    string pwd;
    string name;
    GREEN;
    printf("请输入账号：");
    BLUE; //蓝色

    cin >> name;
    GREEN;
    cout << "请输入密码: ";
    BLUE;
    pwd = this->inputPwd(10);

    //字符串判断，如果是管理员，则跳转到管理员界面
    if (pwd == password && name == username)
    {
        GREEN;
        printf("登录成功！\n");
        WHITE;
        return 0;
    }
    else
    {
        RED;
        printf("用户名或密码错误！\n");
        WHITE;
        return EXIT;
    }
}

void SystemBasic::mainForm()
{
    system("color 05"); // f1中前一个f为背景色，后一个为前景色。蓝色
    // tab ==> 右缩进	 shift+tab <== 左缩进
    WHITE; //白色
    printf("==================================\n");
    printf("=          魔法书库系统\t         =\n");
    printf("=           %s\t         =\n", getTime("date").c_str());
    WHITE; //白色
    printf("==================================\n=");
    CYAN; //青色
    printf("           1. 登录\t         ");
    WHITE; //白色
    printf("=\n=           ");
    YELLOW; //黄色
    printf("2. 关于我们\t      	 ");
    WHITE; //白色
    printf("=\n=           ");
    PINK; //粉色
    printf("3. 操作指南\t         ");
    WHITE; //白色
    printf("=\n=           ");
    GREEN; //绿色
    printf("4. 作品信息\t         ");
    WHITE; //白色
    printf("=\n=           ");
    RED; //红色
    printf("?. 退出\t         ");
    WHITE; //白色
    printf("=\n==================================\n");
    GRAY; //灰色
    printf("请输入 : ");
    GREEN; //绿色
}

//修改用户信息
int SystemBasic::modAdmin()
{

    if (this->nyContinue("修改信息?[Y]"))
        return 0;
    // this->getUserDetail(head); //显示用户信息

    if (!this->nyContinue("修改用户名?[Y]"))
    {
        printf("请输入:");
        cin >> this->adminName;
        printf("修改成功，");
        cout << "您当前的用户名是: " << this->adminName << "!" << endl;
    }
    if (!this->nyContinue("修改密码?[Y]"))
    {
        string oldPsd, newPsd1, newPsd2;
        int failTimes = 0;
        cout << "请输入旧密码:";
        oldPsd = inputPwd(18);
        while (oldPsd != this->adminPassword)
        {
            // failTimes++;
            cout << "密码错误，请重新输入：";
            oldPsd = inputPwd(18);
            // if (failTimes >= 3)
            // {
            //     cout << "您已输入错误" << failTimes << "次，是否继续？" << endl;
            //     if (this->nyContinue())
            //         return;
            // }
            if (this->failTimes(++failTimes))
                break;
        }
        cout << "请设置新密码:";
        newPsd1 = this->inputPwd(18);
        while (newPsd1 != newPsd2)
        {
            cout << "请再次输入新密码:";
            newPsd2 = this->inputPwd(18);
            if (newPsd1 == newPsd2)
                break;
            else
            {
                cout << "两次密码不一致，请重新设置密码:";
                newPsd1 = inputPwd(18);
            }
        }
        this->adminPassword = newPsd1;
        cout << "密码修改成功，请务必牢记！" << endl;
    }
    return 1;
}



//返回用户名
string SystemBasic::returnName(){
    return this->adminName;
}
//返回密码
string SystemBasic::returnPassword(){
    return this->adminPassword;
}