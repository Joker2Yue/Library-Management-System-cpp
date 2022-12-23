/*
 * @Author: Joker Yue, Joker_Yue@qq.com
 * @Date: 2022-11-10 19:36:46
 * @LastEditors: Joker Yue
 * @LastEditTime: 2022-11-16 22:24:11
 * @FilePath: \BookEditOnly\Book.cpp
 * @Description:�ࣺ���ʵ��
 */
#include "Book.h"
// const Book *head;
// using namespace System;

//�޸��鼮����
void Book::setBookName()
{
    if (this->nyContinue("��ȷ���Ƿ�Ҫ�޸�����?[Y]"))
        return;
    printf("������:");
    cin >> this->bookName;
    printf("�޸ĳɹ���\n");
}
//�޸��鼮����
void Book::setBookAuthor()
{

    if (this->nyContinue("��ȷ���Ƿ�Ҫ�޸�����?[Y]"))
        return;
    printf("������:");
    cin >> this->bookAuthor;
    printf("�޸ĳɹ���\n");
}
//�޸��鼮�۸�
void Book::setBookPrice()
{
    if (this->nyContinue("��ȷ���Ƿ�Ҫ�޸ļ۸�?[Y]"))
        return;
    if ((bookPrice = this->str2Num(5, "������۸�: ", "�۸��趨��������������۸�: ")) != 0)
        cout << "�޸ĳɹ�!" << endl;
}
//�޸��鼮������
void Book::setBookPress()
{
    if (this->nyContinue("��ȷ���Ƿ�Ҫ�޸ĳ�����?[Y]"))
        return;
    printf("������:");
    cin >> this->bookPress;
    printf("�޸ĳɹ���\n");
}
//�޸��鼮���
void Book::setBookNum()
{
    if (this->nyContinue("��ȷ���Ƿ�Ҫ�޸Ŀ��?[Y]"))
        return;
    if ((bookPrice = this->str2Num(5, "��������: ", "����趨����������������: ")) != 0)
        cout << "�޸ĳɹ�!" << endl;
}

//��ȡ�鼮��Ϣ
void Book::getBookDetailAdmin(const Book *head)
{
    system("cls");
    cout << "����\t\t" << this->bookName << endl;
    cout << "ISBN\t\t" << this->bookIsbn << endl;
    cout << "����\t\t" << this->bookAuthor << endl;
    cout << "�۸�\t\t" << this->bookPrice << endl;
    cout << "������\t\t" << this->bookPress << endl;
    cout << "��ǰ����\t" << this->bookNum << endl;
    cout << "��ǰ����\t" << this->lentNum << endl;
    this->listThisBookLendMsg(this->headLend);
    this->fileSaveBook(head);
    return;
}

//�޸��鼮��Ϣ
void Book::modThisBookInfo(const Book *head)
{
    if (this->nyContinue())
        return;

    //�޸��鼮����
    setBookName();
    //�޸��鼮����
    setBookAuthor();
    //�޸��鼮�۸�
    setBookPrice();
    //�޸��鼮������
    setBookPress();
    //�޸��鼮���
    setBookNum();

    fileSaveBook(head);
}

//��ʽչʾ�鼮��Ϣ
void Book::listAllBook(Book *head)
{
    if (this->countAllBook(head) == 0)
    {
        cout << "����ͼ�飬����Ӻ�鿴" << endl;
        return;
    }
    while (1)
    {
        printf("  ���   %20s %10s %10s %20s %20s %10s %10s\n", "����", "����", "�۸�", "������", "ISBN", "���", "����");
        Book *p1;
        int showIndex = 1;
        p1 = head->next;
        while (p1 != NULL)
        {
            //�����ʽ��ѡ��string.c_str()��������Ϊ��ƥ��printf�е�%s����Ҫ��(char*������string)
            //ѡ����printf������cout�����Ϊ�˸��������ͽ�ʡʱ��
            printf("��%03d��  %20s %10s %10.2f %20s %20s %10d %10d\n",
                   showIndex++,
                   p1->bookName.c_str(),
                   p1->bookAuthor.c_str(),
                   p1->bookPrice,
                   p1->bookPress.c_str(),
                   p1->bookIsbn.c_str(),
                   p1->bookNum,
                   p1->lentNum);
            p1 = p1->next;
        }
        if (commandAllBook(head))
            break;
    }
    return;
}

int Book ::commandAllBook(Book *head)
{
    cout << "[E]ѡ�����/[D]ɾ������/[.]ȡ������" << endl;
    char key = _getch();
    cin.sync(); //��ջ�����
    if (key == 'E' || key == 'e')
    {
        cout << "������Ҫ���в������鼮��ISBN: ";
        string tmpISBN;
        int failTimes = 0;
        Book *wantDetailBook = new Book; //Ҫ������ϸ�������鼮
        while (cin >> tmpISBN)
        {
            wantDetailBook = searchBook(head, tmpISBN);
            if (wantDetailBook == NULL)
                cout << "û�д��飬����������:";
            else
                break;
            failTimes++;
            if (this->failTimes(failTimes))
                return EXIT;
        }
        wantDetailBook->getBookDetailAdmin(head);
        return EXIT;
    }
    else if (key == 'D' || key == 'd')
        this->delBook(head);
    else
        cin.sync(); //��ջ�����
    return EXIT;
}

//չʾ�鼮������Ϣ
void Book::listThisBookLendMsg(Lend *headLend)
{
    if (this->lentNum == 0)
    { // cout << "���޽��ģ����Ժ�鿴" << endl;
        cout << "[L]�������/[.]ȡ������" << endl;
        char key = _getch();
        cin.sync(); //��ջ�����
        if (key == 'L' || key == 'l')
        {
            if (this->nyContinue("��ʼ����[Y]"))
                return;
            else
                this->headLend->newLend(this->headLend, this);
            this->lentNum++;
            this->bookNum--;
            return;
        }
        else
            return;
    }

    while (1)
    {
        system("cls");
        printf("  ���   %20s %10s %20s %20s\n", "����������", "������ID", "����ʱ��", "���ı�ע");
        Lend *p1 = headLend->next;
        int showIndex = 1;
        while (p1 != NULL)
        {
            //�����ʽ��ѡ��string.c_str()��������Ϊ��ƥ��printf�е�%s����Ҫ��(char*������string)
            //ѡ����printf������cout�����Ϊ�˸��������
            printf("��%03d��  %20s %10d %20s %20s \n",
                   showIndex++,
                   p1->returnThisLendUserName().c_str(),
                   p1->returnThisLendUserID(),
                   p1->returnThisLendTime().c_str(),
                   p1->returnThisLendMsg().c_str());
            p1 = p1->next;
        }
        if (commandThisBookLendMsg(headLend))
            return;
    }
}

int Book::commandThisBookLendMsg(Lend *headLend)
{
    cout << "[R]�黹����/[L]�������/[.]ȡ������" << endl;
    char key = _getch();
    cin.sync(); //��ջ�����
    if (key == 'R' || key == 'r')
    {
        cout << "[A]ȫ���黹/[.]ѡ��黹" << endl;
        char value = _getch();
        cin.sync(); //��ջ�����
        if (value == 'A' || value == 'a')
        {
            this->yesContinue();
            cout << "����ɾ��..." << endl;
            // headLend->delAllMsg(headLend);
            headLend->next = NULL; //��ֱ�ӽ���������NULL��OKɾ����ϣ��� :-)
            cout << "ɾ���ɹ�" << endl;
            this->bookNum += this->lentNum;
            this->lentNum = 0;
            return EXIT;
        }

        cout << "������Ҫ���й黹�Ľ�����ID: ";
        int tmpID;
        int failTimes = 0;
        Lend *wantDelLend = new Lend; //Ҫ������ϸ�������鼮
        while (cin >> tmpID)
        {
            wantDelLend = headLend->searchLend(headLend, tmpID);
            if (wantDelLend == NULL)
                cout << "û�д˽�����Ϣ������������:";
            else
                break;
            failTimes++;
            if (this->failTimes(failTimes))
                return 0;
        }
        wantDelLend->delThisMsg(headLend);
        cout << "�黹�ɹ�" << endl;
        this->lentNum--;
        this->bookNum++;
        return 0;
    }
    else if (key == 'L' || key == 'l')
    {
        if (this->lentNum >= this->bookNum)
        {
            cout << "��ͼ����������!" << endl;
            return 0;
        }
        else
        {
            if (this->nyContinue("��ʼ����[Y]"))
                return 0;
            //�������ʧ�ܣ��˳�
            if (!this->headLend->newLend(this->headLend, this))
            {
                this->lentNum++;
                this->bookNum--;
            }
        }
        return 0;
    }
    else
        cin.sync(); //��ջ�����
    // this->fileSaveBook(headBook);
    //�������ֹ�ϵ���޷����ڴ˷����ڽ��б����ļ�����ÿ��ʹ�ô˷���ʱ�ֶ����б��棡������
    return EXIT;
}

// ��Ѱ�鱾
// modeΪ������ʽ��Ϊ0ʱΪ��Ĭ���������᷵���Ƿ����ظ�ISBN���еĻ��������ַ
//����ҵ���Ŀ���鼮�����᷵�����ַ�����򷵻�NULL
//Ϊ1ʱΪ����isbn������Ϊ2ʱ��������������
Book *Book::searchBook(const Book *head, string bookInfo, int mode) const
{
    // system("cls");
    Book *p1;
    p1 = head->next;
    if (mode == 1)
    {
        //�����ڵ�ֱ���ҵ�ͷ
        while (p1 != NULL)
        {
            //������鼮�봫�������ͬ
            if (bookInfo == p1->bookIsbn)
            {
                cout << "�ҵ��鼮!" << endl;
                //��ʾ������鼮��Ϣ
                p1->getBookDetailAdmin(head);
                return p1;
            }
            p1 = p1->next;
            cout << "δ�ҵ��鼮!����������: ";
            return NULL;
        }
    }
    else if (mode == 2)
    {
        while (p1 != NULL)
        {
            int findFlag = 0;
            if (bookInfo == p1->bookName)
            {
                cout << "�ҵ��鼮!" << endl;
                p1->getBookDetailAdmin(head);
                findFlag = 1;
            }
            p1 = p1->next;
            if (!findFlag)
                cout << "δ�ҵ��鼮!����������: ";
            return NULL;
        }
    }
    else
    {
        while (p1 != NULL)
        {
            if (bookInfo == p1->bookIsbn)
                return p1;
            p1 = p1->next;
        }
    }
    return NULL;
}

//����鼮
void Book::addBook(Book *head)
{
    // system("cls");
    if (head->nyContinue())
    {
        cout << "��ȡ���˲�����" << endl;
        return;
    }
    Book *p1 = head; //����p1������ͷ��ʼ����һֱ�ҵ�β
    while (p1->next != NULL)
    {
        p1 = p1->next;
    }
    Book *newBookPoint = new Book; //����һ���¶���newBookPoint�ý���p1�ϣ����ʱ��Ĭ�Ϲ��캯���������������д�ö���Ϣ��
    string tmpInfo;

    // ���û�����һ��ͼ�����Ϣ��������������µĽڵ�
    cout << "������ISBN: ";
    //ѭ�����룬ֱ��������ȷ��ʽ
    while (cin >> tmpInfo)
    {
        if (searchBook(head, tmpInfo, 0) != NULL)
            cout << "���д���,����������: ";
        else
        {
            newBookPoint->bookIsbn = tmpInfo;
            break;
        }
    }

    printf("����������: ");
    cin >> newBookPoint->bookName;

    printf("����������: ");
    cin >> newBookPoint->bookAuthor;

    newBookPoint->bookPrice = this->str2Num(5, "������۸�: ", "�۸��趨��������������۸�: ");

    printf("�����������: ");
    cin >> newBookPoint->bookPress;

    newBookPoint->bookNum = this->str2Num(5, "��������: ", "����趨����������������: ");

    p1->next = newBookPoint;

    fileSaveBook(head); // д���ļ�
    cout << "����ɹ�" << endl;
}

//ɾ���鼮
void Book::delBook(Book *head)
{
    cout << "��ѡ��:[A]ȫ��ɾ��/[C]ѡ��ɾ��/[.]ȡ��ɾ��" << endl;
    char key = _getch();
    if (key == 'A' || key == 'a')
    {
        if (head->yesContinue("��Σ����!���ֶ�����\'yes\'!"))
        {
            cout << "������ȡ���������˳�..." << endl;
            return;
        }
        head->next = NULL;
        cout << "ɾ���ɹ���" << endl;
        fileSaveBook(head);
    }

    else if (key == 'C' || key == 'c')
    {
        Book *p1 = head, *p2 = head->next;
        int failTimes = 0; //��¼�������
        cout << "������Ҫɾ�����鼮��ISBN: " << endl;
        string tmpBookISBN;
        while (cin >> tmpBookISBN)
        {
            p2 = searchBook(head, tmpBookISBN, 0);
            if (p2 == NULL)
            {
                failTimes++;
                cout << "û�д��鼮������������" << endl;
            }
            else
                break;
            if (failTimes >= 3)
            {
                cout << "�����������" << failTimes << "�Σ��Ƿ������" << endl;
                if (head->nyContinue())
                    return;
            }
        }

        //��p1�Ƶ�p2����һ��
        while (p1->next != p2)
            p1 = p1->next;
        //��p1�������Ϊp2�ĺ�̣������������ɾ��p2
        p1->next = p2->next;
        //�ͷ�p2
        delete (p2);
        //����
        fileSaveBook(head);

        cout << "YES!ɾ���ɹ�" << endl;
    }
    else
        return;
}

//�����鼮����
int Book::countAllBook(Book *head) const
{
    Book *p1 = head;
    int cntBook = 0;
    int cntLend = 0;
    while (p1->next != NULL)
    {
        p1 = p1->next;
        cntBook += p1->bookNum;
        cntLend += p1->lentNum;
    }
    head->bookNum = cntBook;
    head->lentNum = cntLend;

    return cntBook;
}

//�ļ�����
void Book::fileLoadBook(Book *head)
{
    Book *p, *p2;    // p��ÿ�ζ�Ҫ�����µ�Book�����Դ��ÿ��ѭ����ȡ������
    ifstream fileIn; //�ļ���
    fileIn.open("bookData.txt");

    if (!fileIn.is_open())
    {
        fileIn.close();
        this->fileRec();
    }

    p2 = head; // p2��ͷ�ڵ㿪ʼ

    //��ȡ����Ա��Ϣ�����鼮��Ϣ
    fileIn >> head->adminName >> head->adminPassword >> head->bookNum >> head->lentNum;

    while (1)
    {
        p = new Book; //�����µ�Book����Ȼ�����ζ���
        fileIn >> p->bookIsbn >> p->bookName >> p->bookAuthor >> p->bookPress >> p->bookPrice >> p->bookNum >> p->lentNum;

        //�����Ƕ��������Ϣ!!!!!!!!
        if (p->lentNum) //����н�����Ϣ
        {
            Lend *lendP2 = p->headLend, *lendP;
            int loadIndex = p->lentNum;
            while (loadIndex--)
            {
                lendP = new Lend;
                int tmpLendID;
                string tmpLendName, tmpLendTime, tmpLendMsg;
                fileIn >> tmpLendID >> tmpLendName >> tmpLendTime >> tmpLendMsg;
                lendP2->setLend(tmpLendID, tmpLendName, tmpLendTime, tmpLendMsg);
                lendP2->next = lendP;
                lendP2 = lendP2->next;
            }
        }
        //���������Ϣ����!!!!!!!!!

        if (fileIn.fail()) //�ж��Ƿ��ļ���β
        {
            delete p;        //ɾ��ָ��ͷ�ڵ��p
            p2->next = NULL; //������Book����ĺ������ΪNULL
            break;
        }

        p2->next = p;  //��p2�������Ϊp
        p2 = p2->next; //��p2��β�ƶ����Գ���ƴ��
    }

    // cout << "YES!���سɹ� " << endl;

    fileIn.close();
}

//�ļ�����
void Book::fileSaveBook(const Book *head) const
{
    Book *p;          //����p����head����
    ofstream fileOut; //�ļ���
    fileOut.open("bookData.txt");

    //д������Ա��Ϣ�����鼮��Ϣ
    fileOut << head->adminName << "\t" << head->adminPassword << '\t'
            << head->bookNum << '\t' << head->lentNum << endl;

    p = head->next;
    //����д��
    while (p)
    {
        fileOut << p->bookIsbn << "\t" << p->bookName << "\t" << p->bookAuthor << "\t"
                << p->bookPress << "\t" << p->bookPrice << "\t" << p->bookNum << "\t" << p->lentNum << "\t";
        fileOut << endl;

        Lend *lendP2 = p->headLend->next;
        //��head��ʼ���棬����ÿһ�����headHead�е���Ϣ���棬��������ʹtxtÿһ�ж�����Ϣ
        while (lendP2)
        {
            fileOut << lendP2->returnThisLendUserID() << "\t" << lendP2->returnThisLendUserName() << "\t"
                    << lendP2->returnThisLendTime() << "\t" << lendP2->returnThisLendMsg() << "\t";
            lendP2 = lendP2->next;
        }

        p = p->next;
        fileOut << endl;
    }

    // cout << "YES!����ɹ� " << endl;
    fileOut.close();
}

// ����Աҳ��
void Book::adminBookMenu(Book *head)
{
    int input;

    while (1)
    {
        system("cls");
        system("color 02"); // 02��ǰһ��0Ϊ����ɫ����ɫ����һ��Ϊǰ��ɫ����ɫ����������û�ã���FOREGROUND_�����

        WHITE; //��ɫ
        printf("==================================\n=");
        BLUE; //��ɫ
        printf("          ͼ�����ϵͳ          ");
        WHITE; //��ɫ
        printf("=\n==================================\n=");
        YELLOW; //��ɫ
        printf("          1. ���ͼ��      	 ");
        WHITE; //��ɫ
        printf("=\n=          ");
        PINK; //��ɫ
        printf("2. ͼ���б�      	 ");
        WHITE; //��ɫ
        printf("=\n=          ");
        BLUE; //��ɫ
        printf("3. ����ͼ��      	 ");
        WHITE; //��ɫ
        printf("=\n=          ");
        CYAN; //��ɫ
        printf("4. ɾ��ͼ��      	 ");
        WHITE; //��ɫ
        printf("=\n=          ");
        YELLOW; //��ɫ
        printf("5. ���ͼ��      	 ");
        WHITE; //��ɫ
        printf("=\n=          ");
        GREEN; //��ɫ
        printf("6. �޸���Ϣ      	 ");
        // WHITE; //��ɫ
        // printf("=\n=          ");
        // BLUE; //��ɫ
        // printf("7. ���ͼ��           ");
        // WHITE; //��ɫ
        // printf("=\n=          ");
        // BLUE; //��ɫ
        // printf("8. �����û�           ");
        WHITE;
        printf("=\n=");
        RED; //��ɫ
        printf("          0. �˳�ϵͳ           ");
        WHITE; //��ɫ
        printf("=\n");
        printf("==================================\n");
        GRAY; //��ɫ
        printf("������ 0 ~ 7: ");
        GREEN; //��ɫ
        scanf("%d", &input);
        WHITE; //��ɫ
        switch (input)
        {
        case 1:
            head->addBook(head);
            break;
        case 2:
            head->listAllBook(head);
            break;
        case 3:
        {
            string bookInfo;
            int searchMode = 1; //����ISBN����
            if (!this->nyContinue("�Ƿ��л�Ϊ����������������ǰΪ����ISBN����[Y]"))
            {
                cout << "���л�����ǰ����ģʽΪ������������" << endl
                     << "������Ҫ����������: ";
                searchMode = 2;
            }
            else
                cout << "δ�л�����ǰ����ģʽΪ����ISBN����" << endl
                     << "������Ҫ������ISBN: ";
            int failTimes = 0;
            cin >> bookInfo;
            while (this->searchBook(head, bookInfo, searchMode) == NULL)
            {
                if (this->failTimes(++failTimes))
                    break;
            }
        }
        break;
        case 4:
            head->delBook(head);
            break;
        case 5:
        {
            if (head->countAllBook(head))
            {
                cout << "�����鼮" << head->bookNum << "��" << endl;
                cout << "���ѽ���" << head->lentNum << "��" << endl;
            }
            else
                cout << "�޲��飬�����ͼ��" << endl;
        }
        break;
        case 6:
        {
            if (head->modAdmin())
                fileSaveBook(head);
        }
        break;
        // case 7:
        //     // printf("����������%d\n�ѽ����%d\nδ�����%d",countBooks(0),countBooks(1),countBooks(2));
        //     break;
        // case 8:
        //     // manageUser();
        //     break;
        case 0:
            WHITE; //��ɫ
            return;
        }
        system("pause");
    }
}
