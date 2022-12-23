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
	//�鼮������Ϣ
	string bookIsbn;   // ���б�� Ψһֵ
	string bookName;   // ����
	string bookAuthor; // ����
	string bookPress;  // ������
	double bookPrice;  // �۸�
	// int allBookNum;	   //�鼮����
	int bookNum; // ��������head�д�ŵ���ȫ���鼮����
	// int lendNum;	   //�ѽ��ĵ��鼮����
	//�鼮������Ϣ
	int lentNum; // ���������0Ϊδ�������head�д�ŵ��ǵ�ǰ�鼮�������

	// int lendUserId;		 //������ID
	// string lendUserName; //����������
	// string lendTime;	 //����ʱ��
	// string lendMessage;	 //���ı�ע

	//������Ϣ��headָ��
	Lend *headLend;
	//ָ����һ��Book�����ָ��
	Book *next;

	/* ������һЩ���� */
	//�޸��鼮����
	void setBookName();
	//�޸��鼮����
	void setBookAuthor();
	//�޸��鼮�۸�
	void setBookPrice();
	//�޸��鼮������
	void setBookPress();
	//�޸��鼮���
	void setBookNum();

public:
	//���幹�캯������������ӵ��鼮
	Book(string book_isbn = "null", string book_name = "null", string author_name = "null", string book_press = "null",
		 double book_price = 0.0, int book_num = 1, int lend_num = 0,
		 string adminNm = "admin", string adminPwd = "admin")
		: SystemBasic(adminNm, adminPwd),
		  bookIsbn(book_isbn), bookName(book_name), bookAuthor(author_name), bookPress(book_press), bookPrice(book_price), bookNum(book_num),
		  lentNum(lend_num), next(NULL)
	{
		headLend = new Lend;
	}
	//��ȡĳһ���鼮����ϸ��Ϣ
	void getBookDetailAdmin(const Book *head);
	//�޸��鼮��Ϣ
	void modThisBookInfo(const Book *head);
	//չʾ�����鼮�Ļ�����Ϣ
	void listAllBook(Book *head);
	//�����鼮�µ��޸���Ϣ���˳����1
	int commandAllBook(Book *head);
	//չʾ���鼮�Ľ�����Ϣ
	//�������ֹ�ϵ���޷����ڴ˷����ڽ��б����ļ�����ÿ��ʹ�ô˷���ʱ�ֶ����б��棡������
	void listThisBookLendMsg(Lend *headLend);
	//���鼮���޸���Ϣ���˳�����1
	int commandThisBookLendMsg(Lend *headLend);
	// ��Ѱ�鱾
	Book *searchBook(const Book *head, string bookInfo, int mode = 0) const;
	//����鼮
	void addBook(Book *head);
	//ɾ���鼮
	void delBook(Book *head);
	//�����鼮����
	int countAllBook(Book *head) const;
	//�ļ�����Book
	void fileLoadBook(Book *head);
	//�ļ������Book
	void fileSaveBook(const Book *head) const;

	//����Աҳ��
	void adminBookMenu(Book *head);
};
