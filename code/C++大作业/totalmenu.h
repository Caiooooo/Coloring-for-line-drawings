#ifndef _TOTALMENU_H_
#define _TOTALMENU_H_

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
void login();
void mainmenu();
void vipmenu();
void bookmenu();
void initdata();//从文件读入数据
void savedata();//保存数据
void shopsum();//购物结算
void bookall();//查看所有书籍

typedef struct Vipguest{
    char name[10];
    int point;
}Vip;
Vip vipname[30]={/*"坤坤",100,"苏小海",9999*/};
int vipnum=0;//vip数目
//储蓄VIP信息

typedef struct booklist{
    char name[20];
    int point;
}Book;
Book booktype[30]={/*"海神C法典",100,"C Minues Less",9999,"worse C--",2*/};
int booknum=0;//图书总数
//储存书单

#endif