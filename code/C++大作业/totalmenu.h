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
void initdata();//���ļ���������
void savedata();//��������
void shopsum();//�������
void bookall();//�鿴�����鼮

typedef struct Vipguest{
    char name[10];
    int point;
}Vip;
Vip vipname[30]={/*"����",100,"��С��",9999*/};
int vipnum=0;//vip��Ŀ
//����VIP��Ϣ

typedef struct booklist{
    char name[20];
    int point;
}Book;
Book booktype[30]={/*"����C����",100,"C Minues Less",9999,"worse C--",2*/};
int booknum=0;//ͼ������
//�����鵥

#endif