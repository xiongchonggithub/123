

#include"../inc/account.h"

int key[9]={0};

int x = 3;


#define MAX_USERS 100

char id1[3][10]={"zzz","xxx","ccc"};   
char id2[MAX_USERS][10]={"aaa","sss","ddd"};
char id3[3][10]={"qqq","www","eee"};

char password1[3][10]={"111","222","333"};
char password2[MAX_USERS][10]={"444","555","666"};
char password3[3][10]={"777","888","999"};
	



void ymd();
int xing_dis(int x);
void zimu_out(int x,int c);
int x_dis(int x,int y);
void display();


/* 
函数功能    ：系统注册
函数参数    ：
函数返回值  ：
 */
void acc_create()
{
	char A[10],B[10],C[10];
	char *login_id=A;
	char *login_password=B;
	char *login_password1=C;
	char d;
	printf("欢迎注册!\n");
	while(1)
	{
		
		printf("请输入新用户名:");
		scanf("%s", login_id);
		printf("请输入新的密码:");
		scanf("%s", login_password);
		printf("请再次输入密码:");
		scanf("%s", login_password1);
		if(strcmp(login_password,login_password1)==0)
		{
			strncpy(id2[x],login_id,10);
			strncpy(password2[x],login_password,10);
			x++;
			printf("=========================================\n");
			printf("============注册成功返回主菜单===========\n");
			return ;
		}
		else
		{
			printf("两次密码输入不一致\n");
			printf("==================\n1、输入q退出\n2、任意键继续\n");
			getchar();
			scanf("%c",&d);
			if(d=='q')
			{
				break;
			}
			else
			{
				printf("===================\n");
			}
			
		}
	}
}

void acc_delete()
{
	if(x<=3)
	{
		printf("=====================当前无用户注册======================\n");
		printf("=====================正在返回主菜单======================\n");
		
	}
	if(x>3)
	{
		strncpy(password2[x],"",10);
		strncpy(id2[x],"",10);
		x--;
	}
}

void look()
{
	int i;
	printf("会员用户名如下\n");
	for(i=0;i<3;i++)
	{
		printf("系统初始用户%d %s\n",i+1,id2[i]);
	}
	for(i;i<x;i++)
	{
		printf("新注册用户%d   %s\n",i-2,id2[i]);
	}
		
}

void system_acc()
{
	printf("当前登录的账户如下\n");
	for(int i=0;i<6+x;i++)
	{
		if(key[i]==1&&i<3)		
			printf("%s\n",id1[i]);
		if(key[i]==1&&i<6)
			printf("%s\n",id2[i]);
		if(key[i]==1&&i>6)
			printf("%s\n",id3[i]);
		
	}
}

void nor()
{
	char control;
	printf("====================================================\n");
	printf("进入普通用户系统\n1.输入1进入系统\n2.q键退出\n");
	while(1)
	{
		scanf("%c",&control);
		if(control=='1')
		{
			printf("=================账户密码正确=======================\n");
			printf("=================正在进入系统=======================\n");
			printf("1、*号菱形\n2、*金字塔\n3、字母金字塔\n4、q退出\n");
			display();
			printf("1、*号菱形\n2、*金字塔\n3、字母金字塔\n4、q退出\n");
		}
		if(control=='q')
		{
			printf("==================正在退出账户======================\n\n\n");
			break;
		}
	}
	
}

void vip()
{
	char control;
	printf("=================账户密码正确=======================\n");
	printf("====================================================\n");
	printf("进入会员用户系统\n1.输入1进入系统\n2.q键退出\n");
	while(1)
	{
		scanf("%c",&control);
		if(control=='1')
		{
			printf("===================正在进入系统==================\n");
			ymd();	
		}
		if(control=='q')
		{
			printf("===================正在退出账户==================\n\n\n\n");
			break;
		}
	}
}

void admin()
{
	char control;
	printf("=================账户密码正确=======================\n");
	printf("====================================================\n");
	printf("进入管理员用户系统\n1.输入1进入系统\n2.q键退出\n");
	while(1)
	{	
		scanf("%c",&control);
		if(control=='1')
		{
			printf("=================正在进入系统=======================\n");
			system_acc();	
		}
		if(control=='q')
		{
			printf("==================正在退出账户=================\n\n\n\n");
			break;
		}
		
	}	
}

int system_sw(int ret)
{
	switch(ret)
	{
		case 1:
				nor();break;
		case 2:
				vip();break;
		case 3:
				admin();break;
		case 0:
				printf("输入出错请重新输入\n");break;
		default :
				printf("输入出错请重新输入\n");break;
	}
}


int compare(char *login_id,char *login_password)
{
	int i,j=0,k[6]={0},q[100]={0};
	for(i=0;i<3;i++)
	{
		k[i]=(strcmp(login_id,id1[i])==0)&&(strcmp(login_password,password1[i])==0);
		k[i+3]=(strcmp(login_id,id3[i])==0)&&(strcmp(login_password,password3[i])==0);
	}
	for(i=0;i<x;i++)
	{
		q[i]=(strcmp(login_id,id2[i])==0)&&(strcmp(login_password,password2[i])==0);
	}
	for(j=0;j<6+x;j++)
	{
		
		if(j<3&&k[j]==1)
		{
			key[j]=1;
			k[j]=0;
			return 1;
		}
		else if(j<6&&k[j]==1)
		{
			key[j]=1;
			k[j]=0;
			return 3;
		}
		else if(q[j]==1)
		{
			key[j]=1;
			k[j]=0;
			return 2;
		}
		
		else if(k[j]==0&&q[j])
		{return 0;}
		
	}
	
}

void system_login()
{
	char a[10],b[10];
	char *login_id=a,*login_password=b;
	printf("请输入您的用户名");
	scanf("%s",login_id);
	printf("请输入您的密码");
	scanf("%s",login_password);
	system_sw(compare(login_id,login_password));
}

void mune()
{
	printf(" ________________________________________________________\n");
	printf("|                                                        |\n");	
	printf("|                   ***正在导入系统***                   |\n");
	printf("|                        _|  |_                          |\n");	
	printf("|                        \\    /                          |\n");	
	printf("|                         \\  /                           |\n");
	printf("|                          \\/                            |\n");		
	printf("|                    1.任意键继续                        |\n");
	printf("|                    2.q 退出                            |\n");
	printf("|________________________________________________________|\n");	
}

void mune1()
{
	printf(" ________________________________________________________\n");
	printf("|                                                        |\n");
	printf("|                     1:开户                             |\n");
	printf("|                     2:账户登录                         |\n");
	printf("|                     3:账户注销                         |\n");
	printf("|                     4:退出                             |\n");
	printf("|                     5:查看会员信息                     |\n");
	printf("|________________________________________________________|\n");
	
	
	
}

void acc_enter()
{
	char x;
	while(1)
	{
		mune();
		scanf(" %c",&x);
		if(x=='q')
			return ;
		else
			system_login();
	}
}

int system()
{
	int x;
	while(1)
	{
		mune1();
		scanf("%d",&x);
		switch(x)
		{
			case 1:	
					acc_create();
					break;
			case 2:
					acc_enter();
					break;
			case 3:
					acc_delete();
					break;
			case 4:
					return 0;
					break;
			case 5:	
					look();
					break;
		}
	}
}




