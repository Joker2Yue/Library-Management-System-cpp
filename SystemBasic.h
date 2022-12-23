/*
 * @Author: Joker Yue, Joker_Yue@qq.com
 * @Date: 2022-11-10 20:13:13
 * @LastEditors: Joker Yue
 * @LastEditTime: 2022-11-14 21:45:47
 * @FilePath: \bookOnly\SystemBasic.h
 * @Description:����д����һЩϵͳ��������Ӧ����Ϊ������ĸ���
 */

#ifndef SYSTEM_BASIC_H
#define SYSTEM_BASIC_H

// #pragma once

#define EXIT 1
#define llui unsigned long long int
#define _CRT_SECURE_NO_WARNINGS																													   // VSȥ������
#define CURL_STATICLIB																															   // VSȥ������
#define CLEAR_FFLUSH cin.ignore(std::numeric_limits<streamsize>::max(), '\n')																	   //��������������ã���ʾ����cin.sync();
#define WHITE SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE) //��ɫ
#define RED SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);									   //��ɫ
#define GREEN SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN)									   //��ɫ
#define BLUE SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE)									   //��ɫ
#define YELLOW SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN)				   //��ɫ
#define PINK SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE)					   //��ɫ
#define CYAN SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE)				   //��ɫ
#define GRAY SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY)														   //��ɫ
#define HIDDEN_CURSOR                         \
	CONSOLE_CURSOR_INFO cursor_hide = {1, 0}; \
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_hide); //���ع��
#define SHOW_CURSOR                           \
	CONSOLE_CURSOR_INFO cursor_show = {1, 1}; \
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_show); //��ʾ���

#include <string>	 //֧��string����
#include <sstream>	 //֧��String������
#include <iostream>	 //�����������������io��
#include <conio.h>	 //����֧�ּ�������(getch)
#include <windows.h> //����֧����ɫ���ú���Ļ�ȴ�
#include <time.h>	 //����֧����ʾʱ���ʱ��ȴ�
#include <fstream>	 //����֧���ļ���дfile��
#include <vector>	 //��������洢��������
using namespace std;

class SystemBasic
{
public:
	//�Զ��幹�캯��
	SystemBasic(string adminNm = "admin", string adminPwd = "admin")
	{
		adminName = adminNm;
		adminPassword = adminPwd;
	}

	/*   ---------------------------   */
	/*   ---------ϵͳ�������-------   */
	//��ȡ��ǰϵͳʱ�䣬����ֵΪstring����,mode=0ʱ�������ʱ��
	string getTime(string mode = "accuracy");
	//��modeΪ'y'ʱ�����û�����y�Լ���������y����0�����෵��1
	//��modeΪ'n'ʱ�����û�����n���˳�������n����1�����෵��0
	//��֮����0�ͼ���������1���˳�
	int nyContinue(const string tipMessage = "������[Y]�Լ���", const char mode = 'y') const;
	//����yes���ܼ���������������ȷ����0
	int yesContinue(string Msg = "������������\'yes\'�Լ�������") const;
	//��������
	string inputPwd(unsigned long long pwdLength);
	//��¼�������������3�ν��������ʾ����ѡ���˳����˳����᷵��1
	int failTimes(int failTimes) const;
	//�ַ���ת���֣��ظ�����ֱ��������ȷ
	// length�涨��Ҫ�����ֳ��ȣ�Ĭ��Ϊ10
	// tipMsg��ʾ��Ϣ errMsg������Ϣ
	double str2Num(llui length = 10, string tipMsg = "������:", string errMsg = "������Ϣ�����Ϲ淶������������:");

	/*   ---------------------------   */
	/*   ---------ϵͳ��Ҫ����-------   */
	//�ָ�ģʽ
	void fileRec();
	//ϵͳ��½
	int sysLogin(string username, string password);
	//������
	void mainForm();

	/*   -------------------------   */
	/*   --------����Ա����--------   */
	//�޸Ĺ���Ա��Ϣ
	int modAdmin();
	//�����û���
	string returnName();
	//��������
	string returnPassword();

protected:
	string adminPassword;
	string adminName;
};

#endif