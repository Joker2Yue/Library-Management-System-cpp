/*
 * @Author: Joker Yue, Joker_Yue@qq.com
 * @Date: 2022-11-10 19:35:05
 * @LastEditors: Joker Yue
 * @LastEditTime: 2022-11-20 18:15:10
 * @FilePath: \BookEditOnly\LibraryProgram.cpp
 * @Description:�������
 */
/*������־��
10-11-2022����һ��
10-11-2022: ����������:    ��μ�"/src/Book.svg"��"/src/Book.md"
10-11-2022: SystemBasic:    �����SystemBasic�ಢ����˴����������ڼ̳���ʹ��
10-11-2022: Book:           �����Book�ಢ����˴�������������Ҫ�������뷽��
10-11-2022��Book:           ����˹���Ա��¼���������
10-11-2022��SystemBasic:    �������������ʱ���������ع���
10-11-2022��SystemBasic:    �޸��˲��ֽ����Ű���������
10-11-2022��SystemBasic:    ����˲����жϣ�����n/y yes�Լ���
10-11-2022��SystemBasic:    �޸��˻������������ϵͳ�޷������˳�������
10-11-2022��SystemBasic:    ��������ֺϷ��Եķ���
10-11-2022��SystemBasic:    ������ж�ʧ������ķ���
11-11-2022��Book:           �޸���bookData.txt�޷���ȡ������
11-11-2022��Book:           �����ͼ��۸�Ϸ��Ե��ж�
11-11-2022��Book:           �������ͼ��鿴ҳ��ͼ������ж�
11-11-2022��Book:           �޸���ͼ��鿴ҳ��Ľ��״̬���������
11-11-2022��SystemBasic:    �޸������½���ϵͳʱ�鼮�ֿⶪʧ������
11-11-2022��SystemBasic:    �������bookData.txt���޸�����
11-11-2022��Book:           �����������鼮ʱͼ��ISBN��ŵ��жϹ���
11-11-2022��Book:           �޸��������ͼ��ʱ��ͼ��۸񲻺Ϸ�ȴ�޷��жϵ�����
11-11-2022: Book:           �����ɾ��ȫ���鼮�Ĺ���
11-11-2022: SystemBasic:    ����˲�ɫ����
11-11-2022: SystemBasic:    ������������޸�ģʽ :-)
11-11-2022: SystemBasic:    �޸���bookData.txt���޸�����
12-11-2022��SystemBasic:    �޸���������ʱ����������100%������
12-11-2022��SystemBasic:    ��������ڻ�ȡϵͳʱ��ķ���
12-11-2022��Book:           �������û�����ʱ�Զ���д����ʱ��

12-11-2022: �ڶ���
12-11-2022: Lend:           �����Lend�����ڴ����û�������Ϣ
12-11-2022: Book:           �����������lendHeadָ������ָ���һ��Lend����������ʾ������Ϣ
12-11-2022: Book:           �޸����޲���ʱҲ���޸��鼮��Ϣ������
12-11-2022: Book:           �޸��˲��ֽ����޷��˳�������
12-11-2022: Lend:           �޸��˲����Ű�
12-11-2022: Book:           �����Lend����Ϣ���ļ���д����
12-11-2022: Book:           �޸���Lend����Ϣ���ļ���д���������ݶ�ʧ������
12-11-2022: SystemBasic:    ����˻�ȡϵͳʱ�䷽����ģʽ
12-11-2022: SystemBasic:    ������������μ̳е��µķ�����ͻ
12-11-2022: Book:           ɾ����Book�в����������ݣ�lendUserId,lendUserName,lendTime
12-11-2022: main:           �����������
12-11-2022: SystemBasic:    �������������ʾϵͳʱ��
13-11-2022: SystemBasic:    ��������������غ���ʾ���ܣ���������������������
13-11-2022: Book:           �޸��ļ����淽ʽ���޳���������
13-11-2022: Book & Lend:    �޳�ȫ�����õ�ע�ʹ���
13-11-2022: SystemBasic:    ����˹���Ա�޸Ĺ���Ա�û��Ĺ���
13-11-2022: Book:           �޸��˹���Ա�޸ĵ������޷����������
13-11-2022: main:           �����Ԥ���ؽ���
14-11-2022: main:           �����Ԥ���ؽ���ļ���ͼ :-)
14-11-2022: Book:           �޸���Book�в�������޷��˳��������˳�������
14-11-2022: Lend:           �޸���nextָ���Ȩ�ޣ������ˣ�
14-11-2022: main:           ��������������Ʒ��Ϣ

14-11-2022: ������
14-11-2022: all:            �޸��˴����������쳣�˳�������


*/
// LibraryProgram.cpp : ���ļ����� "main" ����������ִ�н��ڴ˴���ʼ��������

#include "Book.h"
using namespace std;

//ȫ�ֱ���! Book��head
Book *head = new Book;

void welcomeAndLoad()
{
    // system("color 1");//��ɫ
    cout << "       ===    ��ӭ����HNITͼ�����ϵͳ!   ===" << endl;
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
    // std::ios::sync_with_stdio(false);//ȡ��std::cin��scanf()��ͬ�����Լӿ�cin�Ķ�ȡ�ٶ�
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
            //     cout << "���������룺"<< endl;
            //     if(head->failTimes(++failTimes)) break;
            // }
            if (!head->sysLogin(head->returnName(), head->returnPassword()))
                head->adminBookMenu(head);
            else
            {
                cout << "��������Է����ϼ�";
                _getch();
            }
        }
        else if (input == 2)
        {
            cout << "�������ǣ�\n\t��ͼ��������ּ�ڽ�ͼ�����Ա\n�ӷ���ͼ�����ģʽ�����ȳ�ȥ��" << endl;
            _getch();
            cout << endl;
        }
        else if (input == 3)
        {
            cout << "���������������������ι��ս����������" << endl;
            _getch();
            cout << endl;
        }
        else if (input == 4)
        {
            BLUE;
            cout << "С�ӳ�Ա��������,̷���,����,��Խ" << endl;
            YELLOW;
            cout << "��ɫ���ܣ��ļ�����,ϵͳ�༶�˵�,��ɫ����,��̬�洢,����ϵͳ,ϵͳʱ��" << endl;
            PINK;
            cout << "�������: ��̬����,�ļ���д,��ָ��,Windows��" << endl;
            WHITE;
            _getch();
            cout << endl;
        }
        else
        {
            RED; //��ɫ
            cout << "�����˳�ϵͳ..." << endl;
            WHITE; //��ɫ
            return 0;
        }
    }

    return 0;
}
