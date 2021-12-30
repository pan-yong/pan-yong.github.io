#include<stdio.h>
#include <string.h>
#define N 50  //宏定义 最多的输入数据为50 

struct Employees
{
    char name[100];               //姓名
    char ID[100];                //职工编号 
    double salay1;              //基本工资
    double salay2;             //职务工资
    double allowance;         //津贴
    double insurance1;       //医疗保险
    double insurance2;      //养老保险
    double insurance3;     //失业保险 
    double money;         //公积金 
    double money1;       //应发工资 
    double money0;      //实发工资 
    double tax;        //个人税 
}P[N];
int Numbers = 0;

void menu()
{
    printf(" 欢迎使用工资管理系统\n");
    printf(" ****工资管理系统****\n");
    printf("┃   ----功能----  ┃\n");
    printf("┃   1---输入功能   ┃\n");
    printf("┃   2---排序功能   ┃\n");
    printf("┃   3---统计功能   ┃\n");
    printf("┃   4---查询功能   ┃\n");
    printf("┃   5---修改功能   ┃\n");
    printf("┃   6---删除功能   ┃\n");
    printf("┃   7---退出系统   ┃\n");
    
    printf(" Tips:\n 1.输入数据时请确保数据正确\n 2.操作时请不要心急，避免操作失误\n 3.进行每一步时请看清提示，然后进行下一步\n 4.系统功能尚有缺陷，请多多包涵\n"); //提示 
}

void loadData(char *filename)
{
    FILE *fp;
    if( (fp = fopen(filename, "r")) != NULL)
        {
            while(!feof(fp))
                {
                    fscanf(fp,"%s%s", P[Numbers].ID,P[Numbers].name);
                    fscanf(fp,"%lf%lf", &P[Numbers].salay1, &P[Numbers].salay2);
                    fscanf(fp,"%lf%lf", &P[Numbers].allowance, &P[Numbers].insurance1);
                    fscanf(fp,"%lf%lf", &P[Numbers].insurance2, &P[Numbers].insurance3);
                    fscanf(fp,"%lf%lf", &P[Numbers].money, &P[Numbers].money1);
                    fscanf(fp,"%lf%lf", &P[Numbers].money0, &P[Numbers].tax);
                    Numbers++;  // 全局变量，记录总人数
                }
            fclose(fp);
        }
}

void Input()
{
    int i, n, m, j;
    printf("请输入要输进去的信息个数（小于50）\n");
    scanf("%d", &n);
    
    if (n < 0 || n > 50) return ;
    
    printf("请按如下提示输入数据：\n");
    printf("职工编号\t姓名\t基本工资\t职务工资\t津贴\t医疗保险\t养老保险\t失业保险\t公积金\n");

    for (i = 1; i <= n; i++)
    {
        do {
            scanf("%s", P[i].ID);
            for (m = 1; m <= i; m++)
                {
                    if (strcmp(P[i].ID, P[m].ID) == 0) break;
                }
            if (m < i)
                printf("编号重复，请重新输入\n");
            else break;
        } while (1);
    }
    
}
void EnterPaixu()
{
}


int main()
{
    int t, quit = 0;
    menu();
    loadData("data.txt");//
    
    while( !quit && scanf("%d", &t) != EOF)
    {
        switch(t)
        {
            case 1:Input();break;
            case 2:EnterPaixu();break;
            case 3: break;//统计
            case 4: break;//查询
            case 5: break;//修改
            case 6: break;//删除
            case 7: 
                    printf("确认退出吗?(y/n)\n");
                    char yesorno[10];
                    scanf("%s", yesorno);
                    if (0 ==strcmp(yesorno, "y") || 0 ==strcmp(yesorno, "Y"))
                    {
                        printf("感谢使用本系统,再见!");
                        quit = 1;
                    }
                    else{
                        menu();
                    }
                break;//退出
            default:printf("输入错误\n"); menu();
        }
    }
    return 0;
}

