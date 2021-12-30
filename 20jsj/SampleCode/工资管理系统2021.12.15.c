#include<stdio.h>
#include<string.h> 
void EnterOutput();//��� 
void EnterInput();//���� 
void EnterSort(); //���� 
void EnterStats();//ͳ��
void EnterSearch();//��ѯ
void EnterModify();//�޸�
void EnterDelete();//ɾ��
void EnterSaveFile(); //�����ļ� 

#define N 50  //�궨�� ������������Ϊ50 
#define M 10  //���������
 
struct Employees
{
	char ID[100];                //ְ����� 
    char name[100];               //����
    double salary[M]; /*���δ������¹��ʣ� 
    double salay1;              //��������
    double salay2;             //ְ����
    double allowance;         //����
    double insurance1;       //ҽ�Ʊ���
    double insurance2;      //���ϱ���
    double insurance3;     //ʧҵ���� 
    double money;         //������ 
    double money1;       //Ӧ������ 
    double tax;        //����˰ 
    double money0;      //ʵ������ 
    */

}P[N] = {
	{},// 0�ŵ�Ԫû�д洢���� 
	{"CSU200501",	"����",	3000,	900,	5000,	50,	100,	20,	560,	8900,	525,	8375},
	{"CSU200612",	"����",	2800,	600,	4000,	45,	80,		19,	550,	7400,	285,	7115},
	{"CSU201208",	"����",	3200,	1000,	5600,	55,	110,	22,	580,	9800,	705,	9095},
	{"CSU201608",	"����",	2900,	800,	4800,	48,	100,	21,	560,	8500,	445,	8055},
	{"CSU201698",	"����",	3100,	900,	5200,	52,	110,	22,	570,	9200,	585,	8615}
};
int gNumbers = 5;		// P������ʵ�����ݸ��� 
char *filename = "data.txt"; // �ļ����� 
 
int main()
{
	int t, quit = 0;
	//system("mode con cols=140 lines=25");
	Menu(); 
	printf("\n\n���������(0-8)��");
	while (!quit && scanf("%d", &t) != EOF)
	{
		switch(t)
		{
			case 0: EnterOutput(); break;  //��ʾ�������� 
			case 1: EnterInput(); break; //���� 
			case 2: EnterSort(); break;  //���� 
			case 3: EnterStats();break; //ͳ��
			case 4: EnterSearch();break; //��ѯ
			case 5: EnterModify();break; //�޸�
			case 6: EnterDelete();break; //ɾ��
			case 7: {	   //�˳�
						printf("ȷ���˳���?(y/n)��");
						char yesorno[10];
						scanf("%s", yesorno);
						if (0 == strcmp(yesorno, "y" || 0 == strcmp(yesorno, "Y"))){
							printf("��лʹ�ñ�ϵͳ,�ټ���");
							quit = 1;
						}
						break;
					}
			default: system("cls"); Menu();
		}
		printf("\n\n���������(0-8)��");
	}
	return 0;
}
void Menu()
{
	printf("*******************************************************************************************************************\n");
	printf("***************************           ��ӭʹ�ù��ʹ���ϵͳ           **********************************************\n");
	printf("*******************************************************************************************************************\n\n");
	printf("  0.��ʾ  1.����  2.����  3.ͳ��  \n");
	printf("  4.��ѯ  5.�޸�  6.ɾ��  7.�˳�  8.����\n\n");	
}

// ����������ͷ 
void OutputHead()
{
	printf("\nְ�����     �� ��  ��������    ְ����   ����   ҽ�Ʊ���   ���ϱ���   ʧҵ����  ������   Ӧ������  ����˰  ʵ������\n");
	printf("-----------------------------------------------------------------------------------------------------------------------\n");
 } 
 void OutputInputHead()
 {
 	printf("\nְ�����     �� ��  ��������    ְ����   ����   ҽ�Ʊ���   ���ϱ���   ʧҵ����  ������\n");
	printf("------------------------------------------------------------------------------------------\n");
 }
 // ������� 
void OutputData(struct Employees e)
{
	printf("%8s  %6s  ",e.ID, e.name);
	int i;
	for (i = 0; i < M; i++)
		printf("%8.0f  ", e.salary[i]);
	printf("\n");
}
// �������������� 
void EnterOutput()
{
	int i, j;
	OutputHead();
	for (i = 1; i <= gNumbers; i++)
	{
		OutputData(P[i]);
	}
	printf("\n����������.\n\n");
} 

/*
	��ѯID�Ƿ��Ѵ��� 
	i  ��ʾID���ڵ��±�λ�� 
	0  ��ʾ������ 
*/
int existID(char *ID)  
{
	int i;
	for (i = 1; i <= gNumbers; i++)
		if (0 == strcmp(P[i].ID, ID))
			return i;
	return 0;  // ������ 
}

float TAX(float rmb)// ����˰Ǯ�ĺ��� 
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
	
	printf("������Ҫ���ȥ����Ϣ������С��50����");
	scanf("%d", &n); 
	
	if (n < 0 || n > N)
		return ;
	printf("���ϸ������¸�ʽ�����������ݣ�\n");
	OutputInputHead();
	
	for (i = 1; i <= n; i++)
	{
		struct Employees e;
		// ���룺ְ����� 
		do{
			scanf("%s", e.ID);
			if (existID(e.ID)){
				printf("\n%s�ظ�������������\n\n", e.ID );
				OutputInputHead();
			}	
			else break;
		}while(1);
		scanf("%s", e.name);// ����
		int j;
		for (j = 0; j < M-3; j++)
			scanf("%lf", &e.salary[j]);
		/*��������һ�¹�����Ϣ 
		scanf("%lf", &e.salay1);// �������� 
		scanf("%lf", &e.salay2);// ְ����
		scanf("%lf", &e.allowance); //����
		scanf("%lf", &e.insurance1);//ҽ�Ʊ���
		scanf("%lf", &e.insurance2);//���ϱ���
		scanf("%lf", &e.insurance3);//ʧҵ����
		scanf("%lf", &e.money);//������
		*/
		
		//���㣺Ӧ������
		e.salary[7] = e.salary[0] + e.salary[1] + e.salary[2];
		//e.money1 = e.salay1 + e.salay2 + e.allowance;  
		
		//���㣺��������˰
		double rmb;
		rmb =  e.salary[7] - e.salary[3] - e.salary[4] - e.salary[5] - e.salary[6];//Ӧ����˰���ý��
		e.salary[8] = TAX(rmb); 
		
		//���㣺ʵ������
		e.salary[9] = rmb - e.salary[8]; 
		
		//������������ݱ��浽P���飬��������1 
		P[++gNumbers] = e;
		printf("\n�ɹ�¼�����ݣ�\n");
		OutputHead();OutputData(e);
	} 
} 

int compare(struct Employees e1, struct Employees e2, int type)
{
	if (2 == type)
		return strcmp(e1.name, e2.name);// ���������� 
	else if(3 == type)
		return e1.salary[9] - e2.salary[9];  // ��ʵ���������� 
	else
		return strcmp(e1.ID, e2.ID);  // Ĭ�ϰ�ְ��������� 
}

void EnterSort()
{
    printf("1---ְ���������\n");
    printf("2---��������\n");
    printf("3---ʵ����������\n");
    printf("��ѡ������ʽ:");
    
    int type;
    scanf("%d", &type);
    
    int i , j;
    for (i = 1; i < gNumbers; i++)
    {
    	for (j = i + 1; j <= gNumbers; j++)
    	{
    		if (compare(P[j], P[i], type) < 0){
    			// ��������
				struct Employees tmp = P[j];
				P[j] =  P[i];
				P[i] = tmp;
			}
		}
	}
	EnterOutput(); //�������ʾ�������� 
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
��ʵ������ͳ�ƣ� 
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
	// ͳ�Ʒ�ʽ��
	char *typeName[11] = {"��������", "ְ����", "��    ��", "ҽ�Ʊ���",   "���ϱ���",
						  "ʧҵ����", "�� �� ��", "Ӧ������", "��������˰", "ʵ������","����"};		  

	printf("\n\n����ͳ�ƹ��ܣ�\n");					  
	printf("0.��������	1.ְ����	2.��    ��	3.ҽ�Ʊ���	4.���ϱ���\n"); 
	printf("5.ʧҵ����	6.�� �� ��	7.Ӧ������	8.��������˰	9.ʵ������\n\n"); 
	
	printf("������ͳ�����0~10����");
	int type;
	scanf("%d", &type);
	

   if (9 == type){
		int c1=0;  //5000���� 
		int c2=0;  //5000-10000 
		int c3=0;   //10000���� 
		countSalary(&c1, &c2, &c3);
		printf("\n%s\t5000����\t5000~10000\t10000����\n", typeName[9]);
		printf("%s\t%8d\t%8d\t%8d\n\n", "��    ��",c1, c2, c3);
		
		printf("\n%s\t�� �� ֵ\t�� С ֵ\tƽ �� ֵ\n", typeName[type]);
		printf("\t\t%8.2f\t%8.2f\t%8.2f\n\n",getMax(type),getMin(type),getAve(type));
	}
	else if(type >= 0 && type <= 8){
		printf("\n%s\t�� �� ֵ\t�� С ֵ\tƽ �� ֵ\n", typeName[type]);
		printf("\t\t%8.2f\t%8.2f\t%8.2f\n\n",getMax(type),getMin(type),getAve(type));
	}
	else{
		printf("\nͳ����������������������롣\n");
	}
}
void EnterSearch()
{
	printf("\n���ݲ�ѯ��\n");
	printf("  1. ��ְ����Ų�ѯ.\n");
	printf("  2. ��������ѯ.\n");
	printf("  3. ��ѯʵ������ 5000 ������Ա.\n");
	printf("  4. ��ѯʵ������ 5000 ~ 10000 ֮����Ա.\n");
	printf("  5. ��ѯʵ������ 10000 ֮����Ա.\n");
	printf("�������ѯָ��(1~5)��");
	
	int type;
	scanf("%d", &type);
	
	if (type == 1)
	{
		char tmpID[10];
		printf("������ְ����ţ�");
		scanf("%s", tmpID);
		int index = existID(tmpID);
		if (0 == index)
			printf("û��%sְ��\n",tmpID);
		else{
			OutputHead(); 
			OutputData(P[index]);
		}
			
	}
	else if(type == 2)
	{
		char tmpName[10];
		printf("������ְ��������");
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
			printf("û��%sְ��\n",tmpName);
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
			printf("û��%sְ��\n","������5000����");
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
			printf("û��%sְ��\n","������5000~10000֮���");
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
			printf("û��%sְ��\n","������10000���ϵ�");
		}
	 } 
	 
}
void EnterModify()
{
	printf("\n������ְ����Ž����޸ģ�");
	struct Employees e;
	scanf("%s", e.ID);
	int i, j;
	if (! (i = existID(e.ID)) )
	{
		printf("ְ�����%s������\n\n", e.ID);
		return ;
	}
	else
	{
		printf("�밴���¸�ʽ�������ݣ�\n\n");
		OutputInputHead();
		
		scanf("%s", e.ID);
		scanf("%s", e.name);
		for (j = 0; j < M - 3; j++)
			scanf("%lf", &e.salary[j]);
		
		//���㣺Ӧ������
		e.salary[7] = e.salary[0] + e.salary[1] + e.salary[2];
		//e.money1 = e.salay1 + e.salay2 + e.allowance;  
		
		//���㣺��������˰
		double rmb;
		rmb =  e.salary[7] - e.salary[3] - e.salary[4] - e.salary[5] - e.salary[6];//Ӧ����˰���ý��
		e.salary[8] = TAX(rmb); 
		
		//���㣺ʵ������
		e.salary[9] = rmb - e.salary[8]; 
		
		// ����ȷ���Ƿ��޸�����
		printf("\nȷ���޸�����������(y/n)��");
		char yesorno[10];
		scanf("%s",yesorno);
		if(0==strcmp(yesorno, "y")){
			P[i] = e;
			printf("\n�����޸ĳɹ���\n\n");			
		} 
		else{
			printf("\n�����޸���ȡ����\n\n");
		}

	}
}
void EnterDelete()
{
	printf("\n������Ҫɾ��ְ���ı�ţ�");
	char tmpID[100];
	scanf("%s", tmpID);
	
	int i = existID(tmpID);
	if(i == 0){
		printf("\n%sְ��������.\n", tmpID);
		return ;
	}
	else{
		// ����ȷ�� 
		printf("ȷ��ɾ��ְ��%s������? (y/n)�� ", tmpID);
		char yesorno[10];
		scanf("%s", yesorno);
		
		if ( 0 == strcmp(yesorno, "y") )
		{
			// ȷ��ɾ�� 
			int j;
			for (j = i + 1; j <= gNumbers; j++)
				P[j-1] = P[j]; 
			gNumbers--; 
			printf("ְ��%s������ɾ����\n\n",tmpID);
		} 
		else{
			printf("ְ��%s��ȡ��ɾ����\n\n",tmpID);
		} 
	}
	
	
}
