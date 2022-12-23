/*
 * @Author: Joker Yue, Joker_Yue@qq.com
 * @Date: 2022-11-10 20:13:15
 * @LastEditors: Joker Yue
 * @LastEditTime: 2022-11-14 21:48:36
 * @FilePath: \bookOnly\SystemBasic.cpp
 * @Description:ϵͳ����֧��
 */
#include "SystemBasic.h"

//��ȡϵͳ����ʱ��
string SystemBasic::getTime(string mode)
{
    // �ɵ�localtime������ȡʱ�䣬�ѱ�����
    // time_t timep;
    // time(&timep);
    // char tmp[256];
    // strftime(tmp, sizeof(tmp), "%Y-%m-%d %H:%M:%S", localtime(&timep));

    time_t time_seconds = time(0);
    struct tm now_time;
    localtime_s(&now_time, &time_seconds);

    std::stringstream ss; // string_stream���
    if (mode == "accuracy")
        ss << now_time.tm_year + 1900 << "-" << now_time.tm_mon + 1 << "-"
           << now_time.tm_mday << "," << now_time.tm_hour << ":"
           << now_time.tm_min << ":" << now_time.tm_hour;
    else
        ss << now_time.tm_year + 1900 << "-" << now_time.tm_mon + 1 << "-" << now_time.tm_mday;
    // std::cout << ss.str() << std::endl;

    return ss.str();
}

// �﷨˵����cin.sync();//��ջ�����
int SystemBasic::nyContinue(const string tipMessage, const char mode) const
{
    char key;
    cout << tipMessage << endl;
    key = _getch();
    if (mode == 'y')
    {
        if (key == 'Y' || key == 'y')
        {
            cin.sync(); //��ջ�����
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
    ���û�ȷ������ĺ������û�����N/n����0����������1
    tipMessage��ʾ��ʾ�û���������� */
}
int SystemBasic::yesContinue(string Msg) const
{
    cout << Msg << endl;
    string yesCtn;
    cin >> yesCtn;
    if (yesCtn == "yes" || yesCtn == "YES") //����YESѡ�����
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
        // �˸�����������ɾ��������ɾ����һ���ַ�������˸��
        if (key == '\b')
        {
            if (passwordIndex > 0)
            {
                // ab	\b �˸�
                printf("\b \b");
                passwordIndex--;
                // ʹ��erase����ɾ�������ڶ����ַ�
                passwordKey.erase(passwordKey.end() - 1);
            }
            continue;
        }
        //	13 �س�
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
                // ��������ַ�����passwordKeyβ��
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
    system("color 14"); //����
    FILE *fileBook = fopen("bookData.txt", "r");
    HIDDEN_CURSOR; //���ع��
    printf(":-(\n����ϵͳ��������,��Ҫ��������,���������Ѽ���Ϣ,�벻Ҫ�ر�...\n");
    Sleep(1000);
    for (int i = 0; i < 100; i++)
    {
        printf("%d%%", i);
        Sleep(50);
        printf("\b\b\b");
    }
    if (fileBook == NULL)
        remove("bookData.txt"); //ɾ���ļ�
    Sleep(1000);
    cout << "��⵽��ʧbookData.txt�����ڳ����޸�..." << endl;
    cout << "��������ļ�..." << endl;
    Sleep(1000);
    cout << "��ӳɹ���������������ָ��..." << endl;
    fileBook = fopen("bookData.txt", "w"); //��дģʽ��w�����ļ��������������½��ļ�
    Sleep(1000);
    cout << "�ɹ���" << endl;
    Sleep(500);                            //��ʱ1�룬�����ü�Ǯ
    fileBook = fopen("bookData.txt", "r"); //���³����� д ģʽ����bookData.txt
    system("cls");                         //����
    if (fileBook != NULL)
    {
        system("color Af"); //����
        printf("�޸���ɣ���������������\n");
        printf("ϵͳ����3���ر�...\n");
        Sleep(1000);
        printf("2���ر�...\n");
        Sleep(1000);
        printf("1���ر�...\n");
    }
    else
    {
        system("color 14"); //����
        printf(":-(\n�޸�ʧ�ܣ����ֶ���������ϵ����\n");
        printf("��ϵ��ʽ��\nQQ:848484848\nEmail:");
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
        cout << "�����������" << failTimes << "�Σ��Ƿ������[Y]" << endl;
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
    string changeStr; //��Ҫת����string
    double wantNum;   //���ᴫ����Num
    while (cin >> changeStr)
    {
        //�ж�������ַ����Ƿ�Ϸ�
        int isStrAvl = 1;
        for (llui i = 0; i < changeStr.length(); i++)
        {
            //��ֹ�������֣���ֹ���ֱ�length��
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
    printf("�������˺ţ�");
    BLUE; //��ɫ

    cin >> name;
    GREEN;
    cout << "����������: ";
    BLUE;
    pwd = this->inputPwd(10);

    //�ַ����жϣ�����ǹ���Ա������ת������Ա����
    if (pwd == password && name == username)
    {
        GREEN;
        printf("��¼�ɹ���\n");
        WHITE;
        return 0;
    }
    else
    {
        RED;
        printf("�û������������\n");
        WHITE;
        return EXIT;
    }
}

void SystemBasic::mainForm()
{
    system("color 05"); // f1��ǰһ��fΪ����ɫ����һ��Ϊǰ��ɫ����ɫ
    // tab ==> ������	 shift+tab <== ������
    WHITE; //��ɫ
    printf("==================================\n");
    printf("=          ħ�����ϵͳ\t         =\n");
    printf("=           %s\t         =\n", getTime("date").c_str());
    WHITE; //��ɫ
    printf("==================================\n=");
    CYAN; //��ɫ
    printf("           1. ��¼\t         ");
    WHITE; //��ɫ
    printf("=\n=           ");
    YELLOW; //��ɫ
    printf("2. ��������\t      	 ");
    WHITE; //��ɫ
    printf("=\n=           ");
    PINK; //��ɫ
    printf("3. ����ָ��\t         ");
    WHITE; //��ɫ
    printf("=\n=           ");
    GREEN; //��ɫ
    printf("4. ��Ʒ��Ϣ\t         ");
    WHITE; //��ɫ
    printf("=\n=           ");
    RED; //��ɫ
    printf("?. �˳�\t         ");
    WHITE; //��ɫ
    printf("=\n==================================\n");
    GRAY; //��ɫ
    printf("������ : ");
    GREEN; //��ɫ
}

//�޸��û���Ϣ
int SystemBasic::modAdmin()
{

    if (this->nyContinue("�޸���Ϣ?[Y]"))
        return 0;
    // this->getUserDetail(head); //��ʾ�û���Ϣ

    if (!this->nyContinue("�޸��û���?[Y]"))
    {
        printf("������:");
        cin >> this->adminName;
        printf("�޸ĳɹ���");
        cout << "����ǰ���û�����: " << this->adminName << "!" << endl;
    }
    if (!this->nyContinue("�޸�����?[Y]"))
    {
        string oldPsd, newPsd1, newPsd2;
        int failTimes = 0;
        cout << "�����������:";
        oldPsd = inputPwd(18);
        while (oldPsd != this->adminPassword)
        {
            // failTimes++;
            cout << "����������������룺";
            oldPsd = inputPwd(18);
            // if (failTimes >= 3)
            // {
            //     cout << "�����������" << failTimes << "�Σ��Ƿ������" << endl;
            //     if (this->nyContinue())
            //         return;
            // }
            if (this->failTimes(++failTimes))
                break;
        }
        cout << "������������:";
        newPsd1 = this->inputPwd(18);
        while (newPsd1 != newPsd2)
        {
            cout << "���ٴ�����������:";
            newPsd2 = this->inputPwd(18);
            if (newPsd1 == newPsd2)
                break;
            else
            {
                cout << "�������벻һ�£���������������:";
                newPsd1 = inputPwd(18);
            }
        }
        this->adminPassword = newPsd1;
        cout << "�����޸ĳɹ���������μǣ�" << endl;
    }
    return 1;
}



//�����û���
string SystemBasic::returnName(){
    return this->adminName;
}
//��������
string SystemBasic::returnPassword(){
    return this->adminPassword;
}