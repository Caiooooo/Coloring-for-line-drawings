#include "totalmenu.h"

int main()
{
    initdata();
    login(); //登录
    return 0;
}

void initdata() //从 vip.txt 和 book.txt 中将文件数据读入
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
    //文件里添加
    for (int i = 0; i < vipnum; i++)
    {
        fprintf(fp3, "%s %d\n", vipname[i].name, vipname[i].point);
    }
    fclose(fp3); //保存会员信息

    FILE *fp4 = fopen("book.txt", "w");
    //文件里添加
    for (int i = 0; i < booknum; i++)
    {
        fprintf(fp4, "%s %d\n", booktype[i].name, booktype[i].point);
    }
    fclose(fp4);
    //保存书籍信息
}

void mainmenu() //主菜单
{
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━\n\
*      图书销售管理系统      *\n\
*         1.会员管理         *\n\
*         2.书籍管理         *\n\
*         3.购物结算         *\n\
*         4.注销             *\n\
━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    char a, b;
    a = getchar();
    b = getchar();
    if (b == '\n')
        ;
    else
        exit(0); //防止非法输入
    if (a == '1')
        vipmenu();
    if (a == '2')
        bookmenu();
    if (a == '3')
        shopsum();
    if (a == '4')
        login();
    exit(0); //非法输入
}

void login()
{
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━\n\
*   图书销售管理系统  *\n\
*      1.登录系统     *\n\
*      2.退出         *\n\
━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
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
                    exit(0); //错误三次退出
                printf("请输入账号：");
                gets(name);
                printf("请输入密码：");
                gets(password);
                if (strcmp(name, "admin"))
                    ;
                else
                {
                    if (strcmp(password, "123456"))
                        ;
                    else
                    {
                        printf("登录成功!\n");
                        mainmenu(); //登录成功
                    }
                }
                printf("账号密码不匹配,还剩%d次机会\n", 2 - cnt);
                cnt++;
            }
        }
    }        //登录
    exit(0); //未输入正确数字
}

void vipmenu()
{
    printf("图书销售管理系统>会员管理\n\
━━━━━━━━━━━━━━━━━━━━━━━━━━\n\
*  1.显示所有会员        *\n\
*  2.添加会员信息        *\n\
*  3.修改会员信息        *\n\
*  4.返回主菜单          *\n\
━━━━━━━━━━━━━━━━━━━━━━━━━━\n\
");
    char a, b;
    a = getchar();
    b = getchar();
    if (b == '\n')
        ;
    else
        exit(0);  //防止非法输入
    if (a == '1') //查看会员
    {
        printf("图书销售管理系统 > 会员信息管理 > 显示会员信息\n\
会员号      姓名     积分\n");
        for (int i = 1; i <= vipnum; i++)
        {
            printf("%4d%12s%8d\n", i, vipname[i - 1].name, vipname[i - 1].point);
        }
        vipmenu();
    }
    if (a == '2') //添加会员
    {
        printf("图书销售管理系统 > 会员信息管理 > 新增会员信息\n\
请输入新会员姓名:");
        gets(vipname[vipnum].name);
        printf("请输入会员积分:");
        scanf("%d", &vipname[vipnum++].point);
        getchar();
        printf("添加成功!\n"); //结构体里添加
        savedata();
        vipmenu();
    }
    if (a == '3')
    {
        int changeNum;
        char changeName[30];
        printf("图书销售管理系统 > 会员信息管理 >修改会员信息\n\
请输入要修改的会员号:");
        scanf("%d", &changeNum);
        getchar();
        printf("请输入要修改的会员姓名:");
        gets(changeName);
        if (changeNum >= 1 && changeNum <= vipnum && !strcmp(changeName, vipname[changeNum - 1].name))
        {
            printf("请输入要修改的积分:");
            scanf("%d", &vipname[changeNum - 1].point);
            printf("修改成功！");
            getchar(); //读入回车
            savedata();
        }
        else
        {
            printf("会员号和姓名不匹配\n");
        }
        vipmenu();
    }
    if (a == '4')
        mainmenu(); //回主菜单
    exit(0);        //非法输入
}

void bookmenu()
{
    printf("图书销售管理系统 >书籍管理\n\
━━━━━━━━━━━━━━━━━━━━━━━━━━\n\
* 1.查看书目   *\n\
* 2.添加书籍   *\n\
* 3.删除书籍   *\n\
* 4.返回主菜单 *\n\
━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    char a, b;
    a = getchar();
    b = getchar();
    if (b == '\n')
        ;
    else
        exit(0);  //防止非法输入
    if (a == '1') //查看book
    {
        bookall(); //查看所有书籍
        bookmenu();
    }
    if (a == '2') //添加book
    {
        printf("图书销售管理系统 >书籍管理>添加书籍\n\
请输入图书名：");
        gets(booktype[booknum].name);
        printf("请输入图书价钱：");
        scanf("%d", &booktype[booknum++].point);
        getchar();
        printf("添加成功!\n");
        savedata();
        bookmenu();
    }

    if (a == '3')
    {
        char changeName[30];
        printf("图书销售管理系统 >书籍管理>书籍下架\n\
请输入要删除的图书书名：");
        gets(changeName);
        for (int i = 0; i < booknum; i++)
        {
            if (strcmp(changeName, booktype[i].name))
                ;
            else
            {
                booktype[i].point = -1;
                printf("找到该图书，位置为：%d\n删除成功\n", i + 1);
                savedata();
                bookmenu();
            }
        }
        printf("未找到该图书，删除失败。\n");
        bookmenu();
    }
    if (a == '4')
        mainmenu(); //回主菜单
    exit(0);        //非法输入
}

void bookall()
{
    printf("图书销售管理系统>书籍管理>书籍列表\n\
图书号        图书名       图书价钱\n");
    for (int i = 1; i <= booknum; i++) //价格等于-1代表被删除
    {
        if (booktype[i - 1].point && booktype[i - 1].point != -1)
            printf("%4d%16s%12d\n", i, booktype[i - 1].name, booktype[i - 1].point);
    }
}

void shopsum()
{
    printf("图书销售管理系统 >购物结算");
    bookall();
    int vipnum, bookNumber, buyNum;
    char y, n;
    printf("请输入会员号：");
    scanf("%d", &vipnum);
    printf("请输入要购买的书籍编号：");
    scanf("%d", &bookNumber);
    printf("请输入您要购买的数量：");
    scanf("%d", &buyNum);
    getchar();
    if (buyNum * booktype[bookNumber - 1].point <= vipname[vipnum - 1].point)
    {
        vipname[vipnum - 1].point -= buyNum * booktype[bookNumber - 1].point;
        printf("您购买的图书为%s，数量为%d，总额为%d\n是否继续？（y/n）：\n",
               booktype[bookNumber - 1].name, buyNum, buyNum * booktype[bookNumber - 1].point);
        y = getchar();
        n = getchar();
        if (y == 'y' && n == '\n')
            shopsum();
    }
    else
    {
        printf("余额不足，请充值\n");
    }
    savedata();
    mainmenu();
}