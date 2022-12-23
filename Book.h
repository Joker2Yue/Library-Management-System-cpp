/*
 * @Author: Joker Yue, Joker_Yue@qq.com
 * @Date: 2022-11-10 19:36:46
 * @LastEditors: Joker Yue
 * @LastEditTime: 2022-12-03 19:36:01
 * @FilePath: \final1120Book_LibraryProgram\Book.h
 * @Description:
 */
#pragma once
#include "SystemBasic.h"
#include "Lend.h"
// using namespace System;
class Book : public SystemBasic
{
private:
	//书籍基本信息
	string bookIsbn;   // 发行编号 唯一值
	string bookName;   // 书名
	string bookAuthor; // 作者
	string bookPress;  // 出版社
	double bookPrice;  // 价格
	// int allBookNum;	   //书籍总数
	int bookNum; // 数量，在head中存放的是全部书籍总数
	// int lendNum;	   //已借阅的书籍数量
	//书籍借阅信息
	int lentNum; // 借出数量，0为未借出，在head中存放的是当前书籍借出总数

	// int lendUserId;		 //借阅者ID
	// string lendUserName; //借阅者姓名
	// string lendTime;	 //借阅时间
	// string lendMessage;	 //借阅备注

	//借阅信息的head指针
	Lend *headLend;
	//指向下一个Book对象的指针
	Book *next;

	/* 这里是一些方法 */
	//修改书籍名称
	void setBookName();
	//修改书籍作者
	void setBookAuthor();
	//修改书籍价格
	void setBookPrice();
	//修改书籍出版社
	void setBookPress();
	//修改书籍库存
	void setBookNum();

public:
	//定义构造函数，用于新添加的书籍
	Book(string book_isbn = "null", string book_name = "null", string author_name = "null", string book_press = "null",
		 double book_price = 0.0, int book_num = 1, int lend_num = 0,
		 string adminNm = "admin", string adminPwd = "admin")
		: SystemBasic(adminNm, adminPwd),
		  bookIsbn(book_isbn), bookName(book_name), bookAuthor(author_name), bookPress(book_press), bookPrice(book_price), bookNum(book_num),
		  lentNum(lend_num), next(NULL)
	{
		headLend = new Lend;
	}
	//读取某一本书籍的详细信息
	void getBookDetailAdmin(const Book *head);
	//修改书籍信息
	void modThisBookInfo(const Book *head);
	//展示所有书籍的基本信息
	void listAllBook(Book *head);
	//所有书籍下的修改信息，退出输出1
	int commandAllBook(Book *head);
	//展示此书籍的借阅信息
	//由于种种关系，无法再在此方法内进行保存文件，请每次使用此方法时手动进行保存！！！！
	void listThisBookLendMsg(Lend *headLend);
	//此书籍的修该信息，退出返回1
	int commandThisBookLendMsg(Lend *headLend);
	// 搜寻书本
	Book *searchBook(const Book *head, string bookInfo, int mode = 0) const;
	//添加书籍
	void addBook(Book *head);
	//删除书籍
	void delBook(Book *head);
	//计算书籍总数
	int countAllBook(Book *head) const;
	//文件加载Book
	void fileLoadBook(Book *head);
	//文件保存进Book
	void fileSaveBook(const Book *head) const;

	//管理员页面
	void adminBookMenu(Book *head);
};
