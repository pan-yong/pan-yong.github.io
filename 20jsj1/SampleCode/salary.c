#include<stdio.h>
#include<string.h> 
void EnterOutput();//输出 
void EnterInput();//输入 
void EnterSort(); //排序 
void EnterStats();//统计
void EnterSearch();//查询
void EnterModify();//修改
void EnterDelete();//删除
void EnterSaveFile(); //报存到文件 

#define N 50  //宏定义 最多的输入数据为50 
#define M 10  //工资类别数
 
struct Employees
{
	char ID[100];                //职工编号 
    char name[100];               //姓名
    double salary[M]; /*依次代表如下工资： 
    double salay1;              //基本工资
    double salay2;             //职务工资
    double allowance;         //津贴
    double insurance1;       //医疗保险
    double insurance2;      //养老保险
    double insurance3;     //失业保险 
    double money;         //公积金 
    double money1;       //应发工资 
    double tax;        //个人税 
    double money0;      //实发工资 
    */

}P[N] = {
	{},// 0号单元没有存储数据 
	{"CSU200501",	"张三",	3000,	900,	5000,	50,	100,	20,	560,	8900,	525,	8375},
	{"CSU200612",	"李四",	2800,	600,	4000,	45,	80,		19,	550,	7400,	285,	7115},
	{"CSU201208",	"王五",	3200,	1000,	5600,	55,	110,	22,	580,	9800,	705,	9095},
	{"CSU201608",	"赵六",	2900,	800,	4800,	48,	100,	21,	560,	8500,	445,	8055},
	{"CSU201698",	"陈七",	3100,	900,	5200,	52,	110,	22,	570,	9200,	585,	8615}
};
int gNumbers = 5;		// P数组中实际数据个数 
char *filename = "data.txt"; // 文件名称 
 void Menu();
int main()
{
	int t, quit = 0;
	//system("mode con cols=140 lines=25");
	Menu(); 
	printf("\n\n请输入操作(0-8)：");
	while (!quit && scanf("%d", &t) != EOF)
	{
		switch(t)
		{
			case 0: EnterOutput(); break;  //显示所有数据 
			case 1: EnterInput(); break; //输入 
			case 2: EnterSort(); break;  //排序 
			case 3: EnterStats();break; //统计
			case 4: EnterSearch();break; //查询
			case 5: EnterModify();break; //修改
			case 6: EnterDelete();break; //删除
			case 7: {	   //退出
						printf("确认退出吗?(y/n)：");
						char yesorno[10];
						scanf("%s", yesorno);
						if (0 == strcmp(yesorno, "y" || 0 == strcmp(yesorno, "Y"))){
							printf("感谢使用本系统,再见！");
							quit = 1;
						}
						break;
					}
			default: system("cls"); Menu();
		}
		printf("\n\n请输入操作(0-8)：");
	}
	return 0;
}
void Menu()
{
	printf("*******************************************************************************************************************\n");
	printf("***************************           欢迎使用工资管理系统           **********************************************\n");
	printf("*******************************************************************************************************************\n\n");
	printf("  0.显示  1.输入  2.排序  3.统计  \n");
	printf("  4.查询  5.修改  6.删除  7.退出  8.清屏\n\n");	
}

// 输出数据项表头 
void OutputHead()
{
	printf("\n职工编号     姓 名  基本工资    职务工资   津贴   医疗保险   养老保险   失业保险  公积金   应发工资  个人税  实发工资\n");
	printf("-----------------------------------------------------------------------------------------------------------------------\n");
 } 
// 输出提示用户要输入数据的表头项
 void OutputInputHead()
 {
 	printf("\n职工编号     姓 名  基本工资    职务工资   津贴   医疗保险   养老保险   失业保险  公积金\n");
	printf("--------------------------------------------------------------------------------\n");
 }
 // 输出一条数据 
void OutputData(struct Employees e)
{
	printf("%8s  %6s  ",e.ID, e.name);
	int i;
	for (i = 0; i < M; i++)
		printf("%8.0f  ", e.salary[i]);
	printf("\n");
}
// 输出表格所有数据 
void EnterOutput()
{
	int i, j;
	OutputHead();
	for (i = 1; i <= gNumbers; i++)
	{
		OutputData(P[i]);
	}
	printf("\n数据输出完成.\n\n");
} 

/*
	查询ID是否已存在 
	i  表示ID存在的下标位置 
	0  表示不存在 
*/
int existID(char *ID)  
{
	int i;
	for (i = 1; i <= gNumbers; i++)
		if (0 == strcmp(P[i].ID, ID))
			return i;
	return 0;  // 不存在 
}

float TAX(float rmb)// 计算税钱的函数 
{
    int n; double tax;
    if (rmb <= 3500)
        n = 0;
    else if (rmb > 3500 && rmb <= 5000)
        n = 1;
    else if (rmb > 5000 && rmb <= 8000)
        n = 2;
    else if (rmb > 8000 && rmb <= 12500)
        n = 3;
    else if (rmb > 12500 && rmb <= 38500)
        n = 4;
    else if (rmb > 38500 && rmb <= 58500)
        n = 5;
    else if (rmb > 58500 && rmb <= 83500)
        n = 6;
    else if (rmb > 83500)
        n = 7;
    switch (n) {
    case 0:
        tax = 0; break;
    case 1:
        tax = (rmb - 3500) * 0.03; break;
    case 2:
        tax = (rmb - 5000) * 0.10 + 45; break;
    case 3:
        tax = (rmb - 8000) * 0.20 + 345; break;
    case 4:
        tax = (rmb - 12500) * 0.25 + 1245; break;
    case 5:
        tax = (rmb - 38500) * 0.30 + 7745; break;
    case 6:
        tax = (rmb - 58500) * 0.35 + 13745; break;
    case 7:
        tax = (rmb - 83500) * 0.45 + 22495; break;
    }
    return (tax);
}

void EnterInput()
{	
	int n, i;
	
	printf("请输入要输进去的信息个数（小于50）：");
	scanf("%d", &n); 
	
	if (n < 0 || n > N)
		return ;
	printf("请严格按照如下格式依次输入数据：\n");
	OutputInputHead();
	
	for (i = 1; i <= n; i++)
	{
		struct Employees e;
		// 输入：职工编号 
		do{
			scanf("%s", e.ID);
			if (existID(e.ID)){
				printf("\n%s重复，请重新输入\n\n", e.ID );
				OutputInputHead();
			}	
			else break;
		}while(1);
		scanf("%s", e.name);// 姓名
		int j;
		for (j = 0; j < M-3; j++)
			scanf("%lf", &e.salary[j]);
		/*依次输入一下工资信息 
		scanf("%lf", &e.salay1);// 基本工资 
		scanf("%lf", &e.salay2);// 职务工资
		scanf("%lf", &e.allowance); //津贴
		scanf("%lf", &e.insurance1);//医疗保险
		scanf("%lf", &e.insurance2);//养老保险
		scanf("%lf", &e.insurance3);//失业保险
		scanf("%lf", &e.money);//公积金
		*/
		
		//计算：应发工资
		e.salary[7] = e.salary[0] + e.salary[1] + e.salary[2];
		//e.money1 = e.salay1 + e.salay2 + e.allowance;  
		
		//计算：个人所得税
		double rmb;
		rmb =  e.salary[7] - e.salary[3] - e.salary[4] - e.salary[5] - e.salary[6];//应该纳税所得金额
		e.salary[8] = TAX(rmb); 
		
		//计算：实发工资
		e.salary[9] = rmb - e.salary[8]; 
		
		//把新输入的数据保存到P数组，总人数加1 
		P[++gNumbers] = e;
		printf("\n成功录入数据：\n");
		OutputHead();
        OutputData(e);
	} 
} 

int compare(struct Employees e1, struct Employees e2, int type)
{
	if (2 == type)
		return strcmp(e1.name, e2.name);// 按姓名排序 
	else if(3 == type)
		return e1.salary[9] - e2.salary[9];  // 按实发工资排序 
	else
		return strcmp(e1.ID, e2.ID);  // 默认按职工编号排序 
}

void EnterSort()
{
    printf("1---职工编号排序\n");
    printf("2---姓名排序\n");
    printf("3---实发工资排序\n");
    printf("请选择排序方式:");
    
    int type;
    scanf("%d", &type);
    
    int i , j;
    for (i = 1; i < gNumbers; i++)
    {
    	for (j = i + 1; j <= gNumbers; j++)
    	{
    		if (compare(P[j], P[i], type) < 0){
    			// 升序排序
				struct Employees tmp = P[j];
				P[j] =  P[i];
				P[i] = tmp;
			}
		}
	}
	EnterOutput(); //排序后显示所有数据 
}

double getMax(int type)
{
	int i;
	double max = P[1].salary[type];
	for (i = 1; i <= gNumbers; i++)
		if (P[i].salary[type] > max)
			max = P[i].salary[type];
	return max;
}
double getMin(int type)
{
	int i;
	double min = P[1].salary[type];
	for (i = 1; i <= gNumbers; i++)
		if (P[i].salary[type] < min)
			min = P[i].salary[type];
	return min;
}
double getAve(int type)
{
	double sum = 0;
	int i;
	for (i = 1; i <= gNumbers; i++)
		sum += P[i].salary[type];
	return sum/gNumbers;
} 
/*
按实发工资统计： 
*/
void countSalary(int *p1, int *p2, int *p3)
{
	int i;
	for (i = 1; i <= gNumbers; i++)
	{
		if (P[i].salary[9] < 5000)
			(*p1)++;
		else if (P[i].salary[9] >= 5000 && P[i].salary[9] < 10000)
			(*p2)++;
		else 
			(*p3)++;
	}
} 

void EnterStats()
{
	// 统计方式：
	char *typeName[11] = {"基本工资", "职务工资", "津    贴", "医疗保险",   "养老保险",
						  "失业保险", "公 积 金", "应发工资", "个人所得税", "实发工资","返回"};		  

	printf("\n\n数据统计功能：\n");					  
	printf("0.基本工资	1.职务工资	2.津    贴	3.医疗保险	4.养老保险\n"); 
	printf("5.失业保险	6.公 积 金	7.应发工资	8.个人所得税	9.实发工资\n\n"); 
	
	printf("请输入统计类别（0~10）：");
	int type;
	scanf("%d", &type);
	

   if (9 == type){
		int c1=0;  //5000以下 
		int c2=0;  //5000-10000 
		int c3=0;   //10000以上 
		countSalary(&c1, &c2, &c3);
		printf("\n%s\t5000以下\t5000~10000\t10000以上\n", typeName[9]);
		printf("%s\t%8d\t%8d\t%8d\n\n", "人    数",c1, c2, c3);
		
		printf("\n%s\t最 大 值\t最 小 值\t平 均 值\n", typeName[type]);
		printf("\t\t%8.2f\t%8.2f\t%8.2f\n\n",getMax(type),getMin(type),getAve(type));
	}
	else if(type >= 0 && type <= 8){
		printf("\n%s\t最 大 值\t最 小 值\t平 均 值\n", typeName[type]);
		printf("\t\t%8.2f\t%8.2f\t%8.2f\n\n",getMax(type),getMin(type),getAve(type));
	}
	else{
		printf("\n统计类型输入错误，请重新输入。\n");
	}
}
void EnterSearch()
{
	printf("\n数据查询：\n");
	printf("  1. 按职工编号查询.\n");
	printf("  2. 按姓名查询.\n");
	printf("  3. 查询实发工资 5000 以下人员.\n");
	printf("  4. 查询实发工资 5000 ~ 10000 之间人员.\n");
	printf("  5. 查询实发工资 10000 之间人员.\n");
	printf("请输入查询指令(1~5)：");
	
	int type;
	scanf("%d", &type);
	
	if (type == 1)
	{
		char tmpID[10];
		printf("请输入职工编号：");
		scanf("%s", tmpID);
		int index = existID(tmpID);
		if (0 == index)
			printf("没有%s职工\n",tmpID);
		else{
			OutputHead(); 
			OutputData(P[index]);
		}
			
	}
	else if(type == 2)
	{
		char tmpName[10];
		printf("请输入职工姓名：");
		scanf("%s", tmpName);
		int i, find = 0;
		for (i = 1; i <= gNumbers; i++)
			if (strcmp(P[i].name, tmpName) == 0)
			{
				OutputHead(); 
				OutputData(P[i]);
				find = 1;
			}
		if (!find){
			printf("没有%s职工\n",tmpName);
		}		
	}
	else if(3 == type)
	{
		int i, find = 0;
		for (i = 1; i <= gNumbers; i++)
			if (P[i].salary[9] < 5000)
			{
				if (0 == find)
					OutputHead();
				OutputData(P[i]);
				find = 1;
			}
		if (!find){
			printf("没有%s职工\n","工资在5000以下");
		}	
	}
	else if(4 == type)
	{
		int i, find = 0;
		for (i = 1; i <= gNumbers; i++)
			if (P[i].salary[9] >= 5000 && P[i].salary[9] < 10000)
			{
				if (0 == find)
					OutputHead();
				OutputData(P[i]);
				find = 1;
			}
		if (!find){
			printf("没有%s职工\n","工资在5000~10000之间的");
		}
	}
	else if(5 == type)
	{
		int i, find = 0;
		for (i = 1; i <= gNumbers; i++)
			if (P[i].salary[9] >= 10000)
			{
				if (0 == find)
					OutputHead();
				OutputData(P[i]);
				find = 1;
			}
		if (!find){
			printf("没有%s职工\n","工资在10000以上的");
		}
	 } 
	 
}
void EnterModify()
{
	printf("\n请输入职工编号进行修改：");
	struct Employees e;
	scanf("%s", e.ID);
	int i, j;
	if (! (i = existID(e.ID)) )
	{
		printf("职工编号%s不存在\n\n", e.ID);
		return ;
	}
	else
	{
		printf("请按如下格式输入数据：\n\n");
		OutputInputHead();
		
		scanf("%s", e.ID);
		scanf("%s", e.name);
		for (j = 0; j < M - 3; j++)
			scanf("%lf", &e.salary[j]);
		
		//计算：应发工资
		e.salary[7] = e.salary[0] + e.salary[1] + e.salary[2];
		//e.money1 = e.salay1 + e.salay2 + e.allowance;  
		
		//计算：个人所得税
		double rmb;
		rmb =  e.salary[7] - e.salary[3] - e.salary[4] - e.salary[5] - e.salary[6];//应该纳税所得金额
		e.salary[8] = TAX(rmb); 
		
		//计算：实发工资
		e.salary[9] = rmb - e.salary[8]; 
		
		// 二次确认是否修改数据
		printf("\n确认修改以上数据吗？(y/n)：");
		char yesorno[10];
		scanf("%s",yesorno);
		if(0==strcmp(yesorno, "y")){
			P[i] = e;
			printf("\n数据修改成功。\n\n");			
		} 
		else{
			printf("\n数据修改已取消。\n\n");
		}

	}
}
void EnterDelete()
{
	printf("\n请输入要删除职工的编号：");
	char tmpID[100];
	scanf("%s", tmpID);
	
	int i = existID(tmpID);
	if(i == 0){
		printf("\n%s职工不存在.\n", tmpID);
		return ;
	}
	else{
		// 二次确认 
		printf("确认删除职工%s的数据? (y/n)： ", tmpID);
		char yesorno[10];
		scanf("%s", yesorno);
		
		if ( 0 == strcmp(yesorno, "y") )
		{
			// 确认删除 
			int j;
			for (j = i + 1; j <= gNumbers; j++)
				P[j-1] = P[j]; 
			gNumbers--; 
			printf("职工%s数据已删除。\n\n",tmpID);
		} 
		else{
			printf("职工%s已取消删除。\n\n",tmpID);
		} 
	}
	
}
