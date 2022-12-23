/*
 * @Author: Joker Yue, Joker_Yue@qq.com
 * @Date: 2022-11-10 19:36:46
 * @LastEditors: Joker Yue
 * @LastEditTime: 2022-11-16 22:24:11
 * @FilePath: \BookEditOnly\Book.cpp
 * @Description:类：书的实现
 */
#include "Book.h"
// const Book *head;
// using namespace System;

//修改书籍名称
void Book::setBookName()
{
    if (this->nyContinue("请确认是否要修改书名?[Y]"))
        return;
    printf("请输入:");
    cin >> this->bookName;
    printf("修改成功！\n");
}
//修改书籍作者
void Book::setBookAuthor()
{

    if (this->nyContinue("请确认是否要修改作者?[Y]"))
        return;
    printf("请输入:");
    cin >> this->bookAuthor;
    printf("修改成功！\n");
}
//修改书籍价格
void Book::setBookPrice()
{
    if (this->nyContinue("请确认是否要修改价格?[Y]"))
        return;
    if ((bookPrice = this->str2Num(5, "请输入价格: ", "价格设定错误！请重新输入价格: ")) != 0)
        cout << "修改成功!" << endl;
}
//修改书籍出版社
void Book::setBookPress()
{
    if (this->nyContinue("请确认是否要修改出版社?[Y]"))
        return;
    printf("请输入:");
    cin >> this->bookPress;
    printf("修改成功！\n");
}
//修改书籍库存
void Book::setBookNum()
{
    if (this->nyContinue("请确认是否要修改库存?[Y]"))
        return;
    if ((bookPrice = this->str2Num(5, "请输入库存: ", "库存设定错误！请重新输入库存: ")) != 0)
        cout << "修改成功!" << endl;
}

//读取书籍信息
void Book::getBookDetailAdmin(const Book *head)
{
    system("cls");
    cout << "书名\t\t" << this->bookName << endl;
    cout << "ISBN\t\t" << this->bookIsbn << endl;
    cout << "作者\t\t" << this->bookAuthor << endl;
    cout << "价格\t\t" << this->bookPrice << endl;
    cout << "出版社\t\t" << this->bookPress << endl;
    cout << "当前藏书\t" << this->bookNum << endl;
    cout << "当前借阅\t" << this->lentNum << endl;
    this->listThisBookLendMsg(this->headLend);
    this->fileSaveBook(head);
    return;
}

//修改书籍信息
void Book::modThisBookInfo(const Book *head)
{
    if (this->nyContinue())
        return;

    //修改书籍名称
    setBookName();
    //修改书籍作者
    setBookAuthor();
    //修改书籍价格
    setBookPrice();
    //修改书籍出版社
    setBookPress();
    //修改书籍库存
    setBookNum();

    fileSaveBook(head);
}

//行式展示书籍信息
void Book::listAllBook(Book *head)
{
    if (this->countAllBook(head) == 0)
    {
        cout << "暂无图书，请添加后查看" << endl;
        return;
    }
    while (1)
    {
        printf("  编号   %20s %10s %10s %20s %20s %10s %10s\n", "书名", "作者", "价格", "出版社", "ISBN", "库存", "借阅");
        Book *p1;
        int showIndex = 1;
        p1 = head->next;
        while (p1 != NULL)
        {
            //输出格式中选择string.c_str()方法，是为了匹配printf中的%s数据要求(char*而不是string)
            //选择用printf而不是cout输出是为了更方便对齐和节省时间
            printf("第%03d项  %20s %10s %10.2f %20s %20s %10d %10d\n",
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
    cout << "[E]选择操作/[D]删除操作/[.]取消操作" << endl;
    char key = _getch();
    cin.sync(); //清空缓冲区
    if (key == 'E' || key == 'e')
    {
        cout << "请输入要进行操作的书籍的ISBN: ";
        string tmpISBN;
        int failTimes = 0;
        Book *wantDetailBook = new Book; //要进行详细操作的书籍
        while (cin >> tmpISBN)
        {
            wantDetailBook = searchBook(head, tmpISBN);
            if (wantDetailBook == NULL)
                cout << "没有此书，请重新输入:";
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
        cin.sync(); //清空缓冲区
    return EXIT;
}

//展示书籍借阅信息
void Book::listThisBookLendMsg(Lend *headLend)
{
    if (this->lentNum == 0)
    { // cout << "暂无借阅，请稍后查看" << endl;
        cout << "[L]借出操作/[.]取消操作" << endl;
        char key = _getch();
        cin.sync(); //清空缓冲区
        if (key == 'L' || key == 'l')
        {
            if (this->nyContinue("开始借阅[Y]"))
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
        printf("  编号   %20s %10s %20s %20s\n", "借阅者姓名", "借阅者ID", "借阅时间", "借阅备注");
        Lend *p1 = headLend->next;
        int showIndex = 1;
        while (p1 != NULL)
        {
            //输出格式中选择string.c_str()方法，是为了匹配printf中的%s数据要求(char*而不是string)
            //选择用printf而不是cout输出是为了更方便对齐
            printf("第%03d项  %20s %10d %20s %20s \n",
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
    cout << "[R]归还操作/[L]借出操作/[.]取消操作" << endl;
    char key = _getch();
    cin.sync(); //清空缓冲区
    if (key == 'R' || key == 'r')
    {
        cout << "[A]全部归还/[.]选择归还" << endl;
        char value = _getch();
        cin.sync(); //清空缓冲区
        if (value == 'A' || value == 'a')
        {
            this->yesContinue();
            cout << "正在删除..." << endl;
            // headLend->delAllMsg(headLend);
            headLend->next = NULL; //我直接将后置设置NULL，OK删除完毕（憨 :-)
            cout << "删除成功" << endl;
            this->bookNum += this->lentNum;
            this->lentNum = 0;
            return EXIT;
        }

        cout << "请输入要进行归还的借阅者ID: ";
        int tmpID;
        int failTimes = 0;
        Lend *wantDelLend = new Lend; //要进行详细操作的书籍
        while (cin >> tmpID)
        {
            wantDelLend = headLend->searchLend(headLend, tmpID);
            if (wantDelLend == NULL)
                cout << "没有此借阅信息，请重新输入:";
            else
                break;
            failTimes++;
            if (this->failTimes(failTimes))
                return 0;
        }
        wantDelLend->delThisMsg(headLend);
        cout << "归还成功" << endl;
        this->lentNum--;
        this->bookNum++;
        return 0;
    }
    else if (key == 'L' || key == 'l')
    {
        if (this->lentNum >= this->bookNum)
        {
            cout << "此图书已无余书!" << endl;
            return 0;
        }
        else
        {
            if (this->nyContinue("开始借阅[Y]"))
                return 0;
            //如果借阅失败，退出
            if (!this->headLend->newLend(this->headLend, this))
            {
                this->lentNum++;
                this->bookNum--;
            }
        }
        return 0;
    }
    else
        cin.sync(); //清空缓冲区
    // this->fileSaveBook(headBook);
    //由于种种关系，无法再在此方法内进行保存文件，请每次使用此方法时手动进行保存！！！！
    return EXIT;
}

// 搜寻书本
// mode为搜索方式，为0时为静默搜索，将会返回是否有重复ISBN，有的话返回其地址
//如果找到了目标书籍，将会返回其地址，否则返回NULL
//为1时为按照isbn搜索，为2时将按照书名搜索
Book *Book::searchBook(const Book *head, string bookInfo, int mode) const
{
    // system("cls");
    Book *p1;
    p1 = head->next;
    if (mode == 1)
    {
        //遍历节点直到找到头
        while (p1 != NULL)
        {
            //如果有书籍与传入参数相同
            if (bookInfo == p1->bookIsbn)
            {
                cout << "找到书籍!" << endl;
                //显示这个的书籍信息
                p1->getBookDetailAdmin(head);
                return p1;
            }
            p1 = p1->next;
            cout << "未找到书籍!请重新输入: ";
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
                cout << "找到书籍!" << endl;
                p1->getBookDetailAdmin(head);
                findFlag = 1;
            }
            p1 = p1->next;
            if (!findFlag)
                cout << "未找到书籍!请重新输入: ";
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

//添加书籍
void Book::addBook(Book *head)
{
    // system("cls");
    if (head->nyContinue())
    {
        cout << "您取消了操作！" << endl;
        return;
    }
    Book *p1 = head; //创建p1，并从头开始遍历一直找到尾
    while (p1->next != NULL)
    {
        p1 = p1->next;
    }
    Book *newBookPoint = new Book; //创建一个新对象newBookPoint好接在p1上，这个时候默认构造函数将会帮助我们填写好多信息的
    string tmpInfo;

    // 让用户输入一本图书的信息，将会继续创建新的节点
    cout << "请输入ISBN: ";
    //循环输入，直到输入正确格式
    while (cin >> tmpInfo)
    {
        if (searchBook(head, tmpInfo, 0) != NULL)
            cout << "已有此书,请重新输入: ";
        else
        {
            newBookPoint->bookIsbn = tmpInfo;
            break;
        }
    }

    printf("请输入书名: ");
    cin >> newBookPoint->bookName;

    printf("请输入作者: ");
    cin >> newBookPoint->bookAuthor;

    newBookPoint->bookPrice = this->str2Num(5, "请输入价格: ", "价格设定错误！请重新输入价格: ");

    printf("请输入出版社: ");
    cin >> newBookPoint->bookPress;

    newBookPoint->bookNum = this->str2Num(5, "请输入库存: ", "库存设定错误！请重新输入库存: ");

    p1->next = newBookPoint;

    fileSaveBook(head); // 写入文件
    cout << "保存成功" << endl;
}

//删除书籍
void Book::delBook(Book *head)
{
    cout << "请选择:[A]全部删除/[C]选择删除/[.]取消删除" << endl;
    char key = _getch();
    if (key == 'A' || key == 'a')
    {
        if (head->yesContinue("高危操作!请手动输入\'yes\'!"))
        {
            cout << "操作被取消，正在退出..." << endl;
            return;
        }
        head->next = NULL;
        cout << "删除成功！" << endl;
        fileSaveBook(head);
    }

    else if (key == 'C' || key == 'c')
    {
        Book *p1 = head, *p2 = head->next;
        int failTimes = 0; //记录错误次数
        cout << "请输入要删除的书籍的ISBN: " << endl;
        string tmpBookISBN;
        while (cin >> tmpBookISBN)
        {
            p2 = searchBook(head, tmpBookISBN, 0);
            if (p2 == NULL)
            {
                failTimes++;
                cout << "没有此书籍，请重新输入" << endl;
            }
            else
                break;
            if (failTimes >= 3)
            {
                cout << "您已输入错误" << failTimes << "次，是否继续？" << endl;
                if (head->nyContinue())
                    return;
            }
        }

        //将p1推到p2的上一个
        while (p1->next != p2)
            p1 = p1->next;
        //将p1后继设置为p2的后继，这样就完成了删除p2
        p1->next = p2->next;
        //释放p2
        delete (p2);
        //保存
        fileSaveBook(head);

        cout << "YES!删除成功" << endl;
    }
    else
        return;
}

//计算书籍总数
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

//文件读入
void Book::fileLoadBook(Book *head)
{
    Book *p, *p2;    // p是每次都要创建新的Book对象以存放每次循环读取的数据
    ifstream fileIn; //文件流
    fileIn.open("bookData.txt");

    if (!fileIn.is_open())
    {
        fileIn.close();
        this->fileRec();
    }

    p2 = head; // p2从头节点开始

    //读取管理员信息和总书籍信息
    fileIn >> head->adminName >> head->adminPassword >> head->bookNum >> head->lentNum;

    while (1)
    {
        p = new Book; //创建新的Book对象然后依次读入
        fileIn >> p->bookIsbn >> p->bookName >> p->bookAuthor >> p->bookPress >> p->bookPrice >> p->bookNum >> p->lentNum;

        //这里是读入借阅信息!!!!!!!!
        if (p->lentNum) //如果有借阅信息
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
        //读入借阅信息结束!!!!!!!!!

        if (fileIn.fail()) //判断是否到文件结尾
        {
            delete p;        //删除指向头节点的p
            p2->next = NULL; //将最后的Book对象的后继设置为NULL
            break;
        }

        p2->next = p;  //将p2后继设置为p
        p2 = p2->next; //将p2向尾移动，以持续拼接
    }

    // cout << "YES!加载成功 " << endl;

    fileIn.close();
}

//文件保存
void Book::fileSaveBook(const Book *head) const
{
    Book *p;          //定义p接在head后面
    ofstream fileOut; //文件流
    fileOut.open("bookData.txt");

    //写出管理员信息和总书籍信息
    fileOut << head->adminName << "\t" << head->adminPassword << '\t'
            << head->bookNum << '\t' << head->lentNum << endl;

    p = head->next;
    //依次写出
    while (p)
    {
        fileOut << p->bookIsbn << "\t" << p->bookName << "\t" << p->bookAuthor << "\t"
                << p->bookPress << "\t" << p->bookPrice << "\t" << p->bookNum << "\t" << p->lentNum << "\t";
        fileOut << endl;

        Lend *lendP2 = p->headLend->next;
        //从head开始保存，这会把每一本书的headHead中的信息保存，但这样会使txt每一行都有信息
        while (lendP2)
        {
            fileOut << lendP2->returnThisLendUserID() << "\t" << lendP2->returnThisLendUserName() << "\t"
                    << lendP2->returnThisLendTime() << "\t" << lendP2->returnThisLendMsg() << "\t";
            lendP2 = lendP2->next;
        }

        p = p->next;
        fileOut << endl;
    }

    // cout << "YES!保存成功 " << endl;
    fileOut.close();
}

// 管理员页面
void Book::adminBookMenu(Book *head)
{
    int input;

    while (1)
    {
        system("cls");
        system("color 02"); // 02中前一个0为背景色，黑色。后一个为前景色，绿色，但是这里没用，被FOREGROUND_替代了

        WHITE; //白色
        printf("==================================\n=");
        BLUE; //蓝色
        printf("          图书管理系统          ");
        WHITE; //白色
        printf("=\n==================================\n=");
        YELLOW; //黄色
        printf("          1. 添加图书      	 ");
        WHITE; //白色
        printf("=\n=          ");
        PINK; //粉色
        printf("2. 图书列表      	 ");
        WHITE; //白色
        printf("=\n=          ");
        BLUE; //蓝色
        printf("3. 查找图书      	 ");
        WHITE; //白色
        printf("=\n=          ");
        CYAN; //青色
        printf("4. 删除图书      	 ");
        WHITE; //白色
        printf("=\n=          ");
        YELLOW; //黄色
        printf("5. 清点图书      	 ");
        WHITE; //白色
        printf("=\n=          ");
        GREEN; //绿色
        printf("6. 修改信息      	 ");
        // WHITE; //白色
        // printf("=\n=          ");
        // BLUE; //绿色
        // printf("7. 清点图书           ");
        // WHITE; //白色
        // printf("=\n=          ");
        // BLUE; //绿色
        // printf("8. 管理用户           ");
        WHITE;
        printf("=\n=");
        RED; //红色
        printf("          0. 退出系统           ");
        WHITE; //白色
        printf("=\n");
        printf("==================================\n");
        GRAY; //灰色
        printf("请输入 0 ~ 7: ");
        GREEN; //绿色
        scanf("%d", &input);
        WHITE; //白色
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
            int searchMode = 1; //按照ISBN搜索
            if (!this->nyContinue("是否切换为按照书名搜索？当前为按照ISBN搜索[Y]"))
            {
                cout << "已切换，当前搜索模式为按照书名搜索" << endl
                     << "请输入要搜索的书名: ";
                searchMode = 2;
            }
            else
                cout << "未切换，当前搜索模式为按照ISBN搜索" << endl
                     << "请输入要搜索的ISBN: ";
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
                cout << "共有书籍" << head->bookNum << "本" << endl;
                cout << "共已借阅" << head->lentNum << "本" << endl;
            }
            else
                cout << "无藏书，请添加图书" << endl;
        }
        break;
        case 6:
        {
            if (head->modAdmin())
                fileSaveBook(head);
        }
        break;
        // case 7:
        //     // printf("藏书数量：%d\n已借出：%d\n未借出：%d",countBooks(0),countBooks(1),countBooks(2));
        //     break;
        // case 8:
        //     // manageUser();
        //     break;
        case 0:
            WHITE; //白色
            return;
        }
        system("pause");
    }
}
