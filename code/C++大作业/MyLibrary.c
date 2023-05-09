#include "totalmenu.h"

int main()
{
    initdata();
    login(); //��¼
    return 0;
}

void initdata() //�� vip.txt �� book.txt �н��ļ����ݶ���
{
    vipnum = 0;
    booknum = 0;
    FILE *fp1 = fopen("vip.txt", "rb");
    if (fp1 == NULL)
        exit(1);
    int i = 0;
    while (!feof(fp1))
        if (fscanf(fp1, "%s", &vipname[i].name))
            if (fscanf(fp1, "%d", &vipname[i].point))
            {
                if (vipname[i++].point == 0)
                    break;
                vipnum++;
            }
    fclose(fp1);

    FILE *fp2 = fopen("book.txt", "rb");
    if (fp2 == NULL)
        exit(1);
    i = 0;
    while (!feof(fp2))
        if (fscanf(fp2, "%s", &booktype[i].name))
            if (fscanf(fp2, "%d", &booktype[i].point))
            {
                if (booktype[i++].point == 0)
                    break;
                booknum++;
            }
    fclose(fp2);
}

void savedata()
{
    FILE *fp3 = fopen("vip.txt", "w");
    //�ļ������
    for (int i = 0; i < vipnum; i++)
    {
        fprintf(fp3, "%s %d\n", vipname[i].name, vipname[i].point);
    }
    fclose(fp3); //�����Ա��Ϣ

    FILE *fp4 = fopen("book.txt", "w");
    //�ļ������
    for (int i = 0; i < booknum; i++)
    {
        fprintf(fp4, "%s %d\n", booktype[i].name, booktype[i].point);
    }
    fclose(fp4);
    //�����鼮��Ϣ
}

void mainmenu() //���˵�
{
    printf("����������������������������������������������������\n\
*      ͼ�����۹���ϵͳ      *\n\
*         1.��Ա����         *\n\
*         2.�鼮����         *\n\
*         3.�������         *\n\
*         4.ע��             *\n\
����������������������������������������������������\n");
    char a, b;
    a = getchar();
    b = getchar();
    if (b == '\n')
        ;
    else
        exit(0); //��ֹ�Ƿ�����
    if (a == '1')
        vipmenu();
    if (a == '2')
        bookmenu();
    if (a == '3')
        shopsum();
    if (a == '4')
        login();
    exit(0); //�Ƿ�����
}

void login()
{
    printf("����������������������������������������������������\n\
*   ͼ�����۹���ϵͳ  *\n\
*      1.��¼ϵͳ     *\n\
*      2.�˳�         *\n\
����������������������������������������������������\n");
    char a = getchar();
    if (a == '1')
    {
        a = getchar();
        if (a == '\n')
        {
            int cnt = 0;
            while (true)
            {
                char name[30], password[30];
                if (cnt == 3)
                    exit(0); //���������˳�
                printf("�������˺ţ�");
                gets(name);
                printf("���������룺");
                gets(password);
                if (strcmp(name, "admin"))
                    ;
                else
                {
                    if (strcmp(password, "123456"))
                        ;
                    else
                    {
                        printf("��¼�ɹ�!\n");
                        mainmenu(); //��¼�ɹ�
                    }
                }
                printf("�˺����벻ƥ��,��ʣ%d�λ���\n", 2 - cnt);
                cnt++;
            }
        }
    }        //��¼
    exit(0); //δ������ȷ����
}

void vipmenu()
{
    printf("ͼ�����۹���ϵͳ>��Ա����\n\
����������������������������������������������������\n\
*  1.��ʾ���л�Ա        *\n\
*  2.��ӻ�Ա��Ϣ        *\n\
*  3.�޸Ļ�Ա��Ϣ        *\n\
*  4.�������˵�          *\n\
����������������������������������������������������\n\
");
    char a, b;
    a = getchar();
    b = getchar();
    if (b == '\n')
        ;
    else
        exit(0);  //��ֹ�Ƿ�����
    if (a == '1') //�鿴��Ա
    {
        printf("ͼ�����۹���ϵͳ > ��Ա��Ϣ���� > ��ʾ��Ա��Ϣ\n\
��Ա��      ����     ����\n");
        for (int i = 1; i <= vipnum; i++)
        {
            printf("%4d%12s%8d\n", i, vipname[i - 1].name, vipname[i - 1].point);
        }
        vipmenu();
    }
    if (a == '2') //��ӻ�Ա
    {
        printf("ͼ�����۹���ϵͳ > ��Ա��Ϣ���� > ������Ա��Ϣ\n\
�������»�Ա����:");
        gets(vipname[vipnum].name);
        printf("�������Ա����:");
        scanf("%d", &vipname[vipnum++].point);
        getchar();
        printf("��ӳɹ�!\n"); //�ṹ�������
        savedata();
        vipmenu();
    }
    if (a == '3')
    {
        int changeNum;
        char changeName[30];
        printf("ͼ�����۹���ϵͳ > ��Ա��Ϣ���� >�޸Ļ�Ա��Ϣ\n\
������Ҫ�޸ĵĻ�Ա��:");
        scanf("%d", &changeNum);
        getchar();
        printf("������Ҫ�޸ĵĻ�Ա����:");
        gets(changeName);
        if (changeNum >= 1 && changeNum <= vipnum && !strcmp(changeName, vipname[changeNum - 1].name))
        {
            printf("������Ҫ�޸ĵĻ���:");
            scanf("%d", &vipname[changeNum - 1].point);
            printf("�޸ĳɹ���");
            getchar(); //����س�
            savedata();
        }
        else
        {
            printf("��Ա�ź�������ƥ��\n");
        }
        vipmenu();
    }
    if (a == '4')
        mainmenu(); //�����˵�
    exit(0);        //�Ƿ�����
}

void bookmenu()
{
    printf("ͼ�����۹���ϵͳ >�鼮����\n\
����������������������������������������������������\n\
* 1.�鿴��Ŀ   *\n\
* 2.����鼮   *\n\
* 3.ɾ���鼮   *\n\
* 4.�������˵� *\n\
����������������������������������������������������\n");
    char a, b;
    a = getchar();
    b = getchar();
    if (b == '\n')
        ;
    else
        exit(0);  //��ֹ�Ƿ�����
    if (a == '1') //�鿴book
    {
        bookall(); //�鿴�����鼮
        bookmenu();
    }
    if (a == '2') //���book
    {
        printf("ͼ�����۹���ϵͳ >�鼮����>����鼮\n\
������ͼ������");
        gets(booktype[booknum].name);
        printf("������ͼ���Ǯ��");
        scanf("%d", &booktype[booknum++].point);
        getchar();
        printf("��ӳɹ�!\n");
        savedata();
        bookmenu();
    }

    if (a == '3')
    {
        char changeName[30];
        printf("ͼ�����۹���ϵͳ >�鼮����>�鼮�¼�\n\
������Ҫɾ����ͼ��������");
        gets(changeName);
        for (int i = 0; i < booknum; i++)
        {
            if (strcmp(changeName, booktype[i].name))
                ;
            else
            {
                booktype[i].point = -1;
                printf("�ҵ���ͼ�飬λ��Ϊ��%d\nɾ���ɹ�\n", i + 1);
                savedata();
                bookmenu();
            }
        }
        printf("δ�ҵ���ͼ�飬ɾ��ʧ�ܡ�\n");
        bookmenu();
    }
    if (a == '4')
        mainmenu(); //�����˵�
    exit(0);        //�Ƿ�����
}

void bookall()
{
    printf("ͼ�����۹���ϵͳ>�鼮����>�鼮�б�\n\
ͼ���        ͼ����       ͼ���Ǯ\n");
    for (int i = 1; i <= booknum; i++) //�۸����-1����ɾ��
    {
        if (booktype[i - 1].point && booktype[i - 1].point != -1)
            printf("%4d%16s%12d\n", i, booktype[i - 1].name, booktype[i - 1].point);
    }
}

void shopsum()
{
    printf("ͼ�����۹���ϵͳ >�������");
    bookall();
    int vipnum, bookNumber, buyNum;
    char y, n;
    printf("�������Ա�ţ�");
    scanf("%d", &vipnum);
    printf("������Ҫ������鼮��ţ�");
    scanf("%d", &bookNumber);
    printf("��������Ҫ�����������");
    scanf("%d", &buyNum);
    getchar();
    if (buyNum * booktype[bookNumber - 1].point <= vipname[vipnum - 1].point)
    {
        vipname[vipnum - 1].point -= buyNum * booktype[bookNumber - 1].point;
        printf("�������ͼ��Ϊ%s������Ϊ%d���ܶ�Ϊ%d\n�Ƿ��������y/n����\n",
               booktype[bookNumber - 1].name, buyNum, buyNum * booktype[bookNumber - 1].point);
        y = getchar();
        n = getchar();
        if (y == 'y' && n == '\n')
            shopsum();
    }
    else
    {
        printf("���㣬���ֵ\n");
    }
    savedata();
    mainmenu();
}