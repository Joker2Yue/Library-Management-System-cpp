/*
 * @Author: Joker Yue, Joker_Yue@qq.com
 * @Date: 2022-11-10 20:13:13
 * @LastEditors: Joker Yue
 * @LastEditTime: 2022-11-14 21:45:47
 * @FilePath: \bookOnly\SystemBasic.h
 * @Description:这里写的是一些系统级方法，应当作为所有类的父类
 */

#ifndef SYSTEM_BASIC_H
#define SYSTEM_BASIC_H

// #pragma once

#define EXIT 1
#define llui unsigned long long int
#define _CRT_SECURE_NO_WARNINGS																													   // VS去除警告
#define CURL_STATICLIB																															   // VS去除警告
#define CLEAR_FFLUSH cin.ignore(std::numeric_limits<streamsize>::max(), '\n')																	   //清除缓冲区，弃用，表示不如cin.sync();
#define WHITE SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE) //白色
#define RED SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);									   //红色
#define GREEN SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN)									   //绿色
#define BLUE SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE)									   //蓝色
#define YELLOW SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN)				   //黄色
#define PINK SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE)					   //粉色
#define CYAN SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE)				   //青色
#define GRAY SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY)														   //灰色
#define HIDDEN_CURSOR                         \
	CONSOLE_CURSOR_INFO cursor_hide = {1, 0}; \
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_hide); //隐藏光标
#define SHOW_CURSOR                           \
	CONSOLE_CURSOR_INFO cursor_show = {1, 1}; \
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_show); //显示光标

#include <string>	 //支持string对象
#include <sstream>	 //支持String对象流
#include <iostream>	 //基本输入输出函数库io流
#include <conio.h>	 //用来支持键盘输入(getch)
#include <windows.h> //用来支持颜色设置和屏幕等待
#include <time.h>	 //用来支持显示时间和时间等待
#include <fstream>	 //用来支持文件读写file流
#include <vector>	 //用来方便存储数组数据
using namespace std;

class SystemBasic
{
public:
	//自定义构造函数
	SystemBasic(string adminNm = "admin", string adminPwd = "admin")
	{
		adminName = adminNm;
		adminPassword = adminPwd;
	}

	/*   ---------------------------   */
	/*   ---------系统插件功能-------   */
	//获取当前系统时间，返回值为string类型,mode=0时完整输出时间
	string getTime(string mode = "accuracy");
	//当mode为'y'时，让用户输入y以继续，输入y返回0，其余返回1
	//当mode为'n'时，让用户输入n以退出，输入n返回1，其余返回0
	//总之返回0就继续，返回1就退出
	int nyContinue(const string tipMessage = "请输入[Y]以继续", const char mode = 'y') const;
	//输入yes才能继续操作，输入正确返回0
	int yesContinue(string Msg = "请完整的输入\'yes\'以继续操作") const;
	//密码虚掩
	string inputPwd(unsigned long long pwdLength);
	//记录错误次数，超过3次将会进行提示并可选择退出，退出将会返回1
	int failTimes(int failTimes) const;
	//字符串转数字，重复请求，直到输入正确
	// length规定需要的数字长度，默认为10
	// tipMsg提示信息 errMsg错误信息
	double str2Num(llui length = 10, string tipMsg = "请输入:", string errMsg = "输入信息不符合规范，请重新输入:");

	/*   ---------------------------   */
	/*   ---------系统重要功能-------   */
	//恢复模式
	void fileRec();
	//系统登陆
	int sysLogin(string username, string password);
	//主界面
	void mainForm();

	/*   -------------------------   */
	/*   --------管理员功能--------   */
	//修改管理员信息
	int modAdmin();
	//返回用户名
	string returnName();
	//返回密码
	string returnPassword();

protected:
	string adminPassword;
	string adminName;
};

#endif