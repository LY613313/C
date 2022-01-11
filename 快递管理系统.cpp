#include<stdio.h> 
#include<string.h>
#include<stdlib.h>
#include<windows.h>


    char c[20];
    char b[20];
    char a[20];
    int g=3;

    void caozuo();
    void read();
    void read_file();
    void read_file1();
    void qujian();
    void yonhu();
    void write_file();
    void guanlizhe();
    void zhuce();
    void yanzheng1();
    void yanzheng2();
    void caozuo();
 
void read()
{
    FILE *fp;
    fp=fopen("data.txt","r"); 
    fscanf(fp,"%s %s %s",&a,&b,&c); 
    while(!feof(fp)) 
    {
	    printf("                            %s %s %s\n",a,b,c);
        fscanf(fp,"%s %s %s",&a,&b,&c);
    }
    fclose(fp);
}

void read_file1(){
	FILE *fp;  int i=0;
    char str[20];
    printf("                            请输入电话号码："); 
    scanf("%s",str); 
    fp=fopen("data.txt","r");
    fscanf(fp,"%s %s %s",&a,&b,&c);
    while(!feof(fp))
    {  
        
        if((strcmp(c,str))==0)
		{
			printf("                                        包裹个数 姓名   取件码 状态    \n");
			printf("                            查到此快递：");
            printf("包裹%-5d%-7s%-4s   未取件\n",i+1,a,b);
            i++;
        }
        fscanf(fp,"%s %s %s",&a,&b,&c);
    }
    fclose(fp);
    if(i==0)
    {
 	    printf("                            |*-----------------^_^查无此快递^_^------------------*|\n");
    }
}
void read_file() 
{
    FILE *fp;  int i=0;
    char str[20];
    printf("                            请输入电话号码："); 
    scanf("%s",str); 
    fp=fopen("data.txt","r");
    fscanf(fp,"%s %s %s",&a,&b,&c);
    while(!feof(fp))
    {  
        
        if((strcmp(c,str))==0)
		{
			printf("                                        包裹个数 姓名   号码     状态    \n");
			printf("                            查到此快递：");
            printf("包裹%-5d%-7s%-4s   未取件\n",i+1,a,c);
            i++;
        }
        fscanf(fp,"%s %s %s",&a,&b,&c);
    }
    fclose(fp);
    if(i==0)
    {
 	    printf("                            |*-----------------^_^查无此快递^_^------------------*|\n");
    }
}

void qujian()
{
	FILE *fp,*ff;
	char name[15];
	char phone[20];
	int i=0; 
	printf("                            请输入姓名、取件码：");
	scanf("%s %s",name,phone);
	fp=fopen("data.txt","r");
	if(fp==NULL)
	{
		printf("                                            文件为空\n");
		yonhu();
	}
	ff=fopen("text.txt","w");
	fscanf(fp,"%s %s %s",&a,&b,&c);
	while(!feof(fp))
	{
		if(strcmp(a,name)!=0||strcmp(b,phone)!=0){
	    	fprintf(ff,"%s %s %s\n",&a,&b,&c);
	    }
	    else
	       i++;
		fscanf(fp,"%s %s %s",&a,&b,&c);
	}
	fclose(ff);
	fclose(fp);
	fp=fopen("data.txt","w");
	ff=fopen("text.txt","r");
	char d;
	while((d=fgetc(ff))!=EOF)
	{
		fputc(d,fp);
	}
	fclose(ff);
	fclose(fp);
	if(i==1)
	{
		printf("                            |*-----------------<^_^>取件成功<^_^>---------------*|\n");
	}
	else
	{
		printf("                            |*-----------------<^_^>取件错误<^_^>---------------*|\n");
	}
}

void yonhu()
{ 
	printf("                            |*------------------欢迎进入用户操作界面------------*|\n");
	printf("                            |*------------------------取件（1)------------------*|\n");
	printf("                            |*------------------------查件（2)------------------*|\n");
	printf("                            |*------------------------退出（3）-----------------*|\n");
	int i;
	int n=1;
	char k;
	while(n)
	{
		printf("                            请输入你的操作内容：");
		scanf("%d",&i);
		switch(i)
		{
		case 1:
			qujian();
			printf("\n");
			break;
		case 2:
			read_file();
			printf("\n");
			break;
		case 3:
		    printf("                            是否返回登录页面(y/n)：");
 	      	scanf("%s",&k);
 	      	if(k=='y')
 	      	{
 	      		caozuo();
			   }
			if(k=='n'){
 	      	    n=0; 
 	      	    printf("                            |*-------------------欢迎下次再来-------------------*|\n");
 	        }
 	      	break;
 	      default:printf("                            |*----------------无此操作，请从新输入---------------*|\n");
	   }
	}
}

void write_file()
{
    FILE *fp;
    fp=fopen("data.txt","a") ; 
    scanf("%s %s %s",&a,&b,&c);
    fprintf(fp,"%s %s %s\n",a,b,c);  
    fclose(fp);
}

void guanlizhe()
{
	printf("                            |*--------------------管理者操作内容-----------------*|\n");
	printf("                            |*--------------------输出所有单号(1)----------------*|\n");
	printf("                            |*--------------------录入单号信息(2)----------------*|\n");
	printf("                            |*--------------------查询单号信息(3)----------------*|\n");
	printf("                            |*----------------------退出登录(4)------------------*|\n"); 
    int i;
    int n=1;
    char k;
    while(n)
   {
   	    printf("                            请输入你的操作内容："); 
   	   scanf("%d",&i);
 	   switch(i)
	   {
	      case 1:
	        printf("                            输出所有快递单号:\n");
 	        read();
 	        printf("\n");
 	        break;
          case 2:
          	printf("                            信息录入\n");
 	        printf("                            请输入姓名、取件码、手机号码：");
 	        write_file();
 	        printf("\n");
            break;
 	      case 3:
 	        read_file1();
 	        printf("\n");
 	        break;
 	      case 4:
 	      	printf("                            是否返回登录页面(y/n)：");
 	      	scanf("%s",&k);
 	      	if(k=='y')
 	      	{
 	      		caozuo();
			   }
			if(k=='n'){
 	      	    n=0; 
 	      	    printf("                            |*-------------------欢迎下次再来--------------------*|");
 	        }
 	      	break;
 	      default:printf("                            |*----------------无此操作，请从新输入---------------*|\n");
 	    }
    }
}

void yanzheng2()
{
	FILE *fp;
	int i=0;
	char str[20];
	char str1[20];
	char n;
	printf("                            请输入你的账号：");
	scanf("%s",str);
	printf("                            请输入你的密码: ");
	scanf("%s",str1);
    fp=fopen("data1.txt","r"); 
    fscanf(fp,"%s %s %s",&a,&b,&c);  
    while(!feof(fp)) 
   {  
    if((strcmp(b,str))==0&&(strcmp(c,str1))==0)
	{
		printf("                            |*-------------<^_^>登录成功（用户)<^_^>------------*|\n");
		printf("\n");
		printf("                                       用户名：%s             账号：%s\n",a,b);
		printf("\n");
		yonhu();
		i++;
	 } 
    fscanf(fp,"%s %s %s",&a,&b,&c);
   }
    fclose(fp);
    if(i==0)
    {
    printf("                            |*------------密码或账户错误，或者没有注册----------*|\n");
    printf("                            |*--------------------返回登录(a)-------------------*|\n");
    printf("                            |*--------------------注册账号(b)-------------------*|\n");
    printf("\n");
    printf("                            请输入你的选择：");
    scanf("%s",&n);
	if(n=='a'){
		if(g!=0){
		printf("                            |*--------------重新登录(你还有%d次机会)-------------*|\n",g);
		g--;
        yanzheng2();
        }
        else
        {
        	printf("\n");
        	printf("                            |*--------------------屌你妈！滚--------------------*|\n");
		}
	}
	if(n=='b'){
		zhuce();
	}
    }
}

void zhuce()
{
	FILE *fp;
	FILE *ff;
	char str1[20];
	char str2[20];
	char str3[20];
	int i=0; 
	printf("\n"); 
    printf("                            输入名字: ");
    scanf("%s",&str1);
    printf("                            创建账号："); 
    scanf("%s",&str2);
    ff=fopen("data1.txt","r");
    fscanf(ff,"%s %s %s",&a,&b,&c);
    while(!feof(ff))
    {  
        
        if((strcmp(b,str2))==0)
		{
            i++;
        }
        fscanf(ff,"%s %s %s",&a,&b,&c);
    }
    fclose(ff);
    if(i!=0)
    {
    	printf("                            |*------------------该账号已被注册------------------*|\n");
    	printf("                            |*------------------请重新注册账号------------------*|\n");
    	zhuce();
	}
    printf("                            创建密码: ");
    scanf("%s",&str3);
	fp=fopen("data1.txt","a") ; 
    fprintf(fp,"%s %s %s\n",str1,str2,str3);  
    printf("                            |*--------------------注册成功----------------------*|\n");
    fclose(fp);
    yanzheng2();
}

void yanzheng1()
{
	char str[20];
	char str1[20];
	char str2[]="admire";
	char mi[]="123456";
	printf("                            请输入账号：");
	scanf("%s",str);
	printf("                            请输入密码：");
	scanf("%s",str1);
	if((strcmp(str2,str))==0&&(strcmp(str1,mi))==0)
	{
		printf("\n");
		printf("                                            <^_^>登录成功<^_^>\n");
		printf("\n");
		guanlizhe();
	}
	else{
		if(g!=0)
		{
			printf("                            请重新登录(你还有%d次机会)\n",g);
			g--;
			yanzheng1();
		}
		else
	     {
	     	printf("\n");
        	printf("                            |*--------------------屌你妈！滚--------------------*|\n");
		 }
	 }
}


void caozuo()
{
	int n;
	int k;
	printf("\n");
	printf("                            |*--------------------  锐宝驿站--------------------*|\n");
	printf("                            |*-------------如有问题请联系后台管理者-------------*|\n");
	printf("                            |*-------------电话1：15820337316（宋健兴）---------*|\n");
	printf("                            |*-------------电话2：15975815629（吴旭）-----------*|\n");
	printf("                            |*--------------------管理端登录（1）---------------*|\n");
	printf("                            |*--------------------用户端登录（2）---------------*|\n");
	printf("\n");
	printf("                            请选择你的登录方式："); 
	scanf("%d",&n);
	if(n==1)
	{
	   printf("                            |*--------------欢迎进入登录页面(管理端)------------*|\n");
	   yanzheng1();
    }
	if(n==2)
	{
	   printf("                            |*---------------欢迎进入登录页面(用户端)-----------*|\n"); 
	   printf("                            |*---------------------登录(1)----------------------*|\n");
	   printf("                            |*---------------------注册(2)----------------------*|\n");
	   printf("                            请输入你的操作：");
	   scanf("%d",&k);
	   if(k==1)
	   {
	       yanzheng2();
	   }
	   if(k==2)
	   {
	       zhuce();
	   }
	   if(k!=1&&k!=2)
	   {
	 	printf("                            |*----------------无此操作，请从新输入---------------*|\n");
		 caozuo(); 
	   }
	 }
	if(n!=1&&n!=2){
	 	printf("                            |*----------------无此操作，请从新输入---------------*|\n"); 
	 	caozuo();
	} 
}

int main()
{
	SetConsoleTitle("快递管理系统"); 
	system("color f5");
	caozuo();
 } 
 
 
 

