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
    printf("                            ������绰���룺"); 
    scanf("%s",str); 
    fp=fopen("data.txt","r");
    fscanf(fp,"%s %s %s",&a,&b,&c);
    while(!feof(fp))
    {  
        
        if((strcmp(c,str))==0)
		{
			printf("                                        �������� ����   ȡ���� ״̬    \n");
			printf("                            �鵽�˿�ݣ�");
            printf("����%-5d%-7s%-4s   δȡ��\n",i+1,a,b);
            i++;
        }
        fscanf(fp,"%s %s %s",&a,&b,&c);
    }
    fclose(fp);
    if(i==0)
    {
 	    printf("                            |*-----------------^_^���޴˿��^_^------------------*|\n");
    }
}
void read_file() 
{
    FILE *fp;  int i=0;
    char str[20];
    printf("                            ������绰���룺"); 
    scanf("%s",str); 
    fp=fopen("data.txt","r");
    fscanf(fp,"%s %s %s",&a,&b,&c);
    while(!feof(fp))
    {  
        
        if((strcmp(c,str))==0)
		{
			printf("                                        �������� ����   ����     ״̬    \n");
			printf("                            �鵽�˿�ݣ�");
            printf("����%-5d%-7s%-4s   δȡ��\n",i+1,a,c);
            i++;
        }
        fscanf(fp,"%s %s %s",&a,&b,&c);
    }
    fclose(fp);
    if(i==0)
    {
 	    printf("                            |*-----------------^_^���޴˿��^_^------------------*|\n");
    }
}

void qujian()
{
	FILE *fp,*ff;
	char name[15];
	char phone[20];
	int i=0; 
	printf("                            ������������ȡ���룺");
	scanf("%s %s",name,phone);
	fp=fopen("data.txt","r");
	if(fp==NULL)
	{
		printf("                                            �ļ�Ϊ��\n");
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
		printf("                            |*-----------------<^_^>ȡ���ɹ�<^_^>---------------*|\n");
	}
	else
	{
		printf("                            |*-----------------<^_^>ȡ������<^_^>---------------*|\n");
	}
}

void yonhu()
{ 
	printf("                            |*------------------��ӭ�����û���������------------*|\n");
	printf("                            |*------------------------ȡ����1)------------------*|\n");
	printf("                            |*------------------------�����2)------------------*|\n");
	printf("                            |*------------------------�˳���3��-----------------*|\n");
	int i;
	int n=1;
	char k;
	while(n)
	{
		printf("                            ��������Ĳ������ݣ�");
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
		    printf("                            �Ƿ񷵻ص�¼ҳ��(y/n)��");
 	      	scanf("%s",&k);
 	      	if(k=='y')
 	      	{
 	      		caozuo();
			   }
			if(k=='n'){
 	      	    n=0; 
 	      	    printf("                            |*-------------------��ӭ�´�����-------------------*|\n");
 	        }
 	      	break;
 	      default:printf("                            |*----------------�޴˲��������������---------------*|\n");
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
	printf("                            |*--------------------�����߲�������-----------------*|\n");
	printf("                            |*--------------------������е���(1)----------------*|\n");
	printf("                            |*--------------------¼�뵥����Ϣ(2)----------------*|\n");
	printf("                            |*--------------------��ѯ������Ϣ(3)----------------*|\n");
	printf("                            |*----------------------�˳���¼(4)------------------*|\n"); 
    int i;
    int n=1;
    char k;
    while(n)
   {
   	    printf("                            ��������Ĳ������ݣ�"); 
   	   scanf("%d",&i);
 	   switch(i)
	   {
	      case 1:
	        printf("                            ������п�ݵ���:\n");
 	        read();
 	        printf("\n");
 	        break;
          case 2:
          	printf("                            ��Ϣ¼��\n");
 	        printf("                            ������������ȡ���롢�ֻ����룺");
 	        write_file();
 	        printf("\n");
            break;
 	      case 3:
 	        read_file1();
 	        printf("\n");
 	        break;
 	      case 4:
 	      	printf("                            �Ƿ񷵻ص�¼ҳ��(y/n)��");
 	      	scanf("%s",&k);
 	      	if(k=='y')
 	      	{
 	      		caozuo();
			   }
			if(k=='n'){
 	      	    n=0; 
 	      	    printf("                            |*-------------------��ӭ�´�����--------------------*|");
 	        }
 	      	break;
 	      default:printf("                            |*----------------�޴˲��������������---------------*|\n");
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
	printf("                            ����������˺ţ�");
	scanf("%s",str);
	printf("                            �������������: ");
	scanf("%s",str1);
    fp=fopen("data1.txt","r"); 
    fscanf(fp,"%s %s %s",&a,&b,&c);  
    while(!feof(fp)) 
   {  
    if((strcmp(b,str))==0&&(strcmp(c,str1))==0)
	{
		printf("                            |*-------------<^_^>��¼�ɹ����û�)<^_^>------------*|\n");
		printf("\n");
		printf("                                       �û�����%s             �˺ţ�%s\n",a,b);
		printf("\n");
		yonhu();
		i++;
	 } 
    fscanf(fp,"%s %s %s",&a,&b,&c);
   }
    fclose(fp);
    if(i==0)
    {
    printf("                            |*------------������˻����󣬻���û��ע��----------*|\n");
    printf("                            |*--------------------���ص�¼(a)-------------------*|\n");
    printf("                            |*--------------------ע���˺�(b)-------------------*|\n");
    printf("\n");
    printf("                            ���������ѡ��");
    scanf("%s",&n);
	if(n=='a'){
		if(g!=0){
		printf("                            |*--------------���µ�¼(�㻹��%d�λ���)-------------*|\n",g);
		g--;
        yanzheng2();
        }
        else
        {
        	printf("\n");
        	printf("                            |*--------------------�����裡��--------------------*|\n");
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
    printf("                            ��������: ");
    scanf("%s",&str1);
    printf("                            �����˺ţ�"); 
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
    	printf("                            |*------------------���˺��ѱ�ע��------------------*|\n");
    	printf("                            |*------------------������ע���˺�------------------*|\n");
    	zhuce();
	}
    printf("                            ��������: ");
    scanf("%s",&str3);
	fp=fopen("data1.txt","a") ; 
    fprintf(fp,"%s %s %s\n",str1,str2,str3);  
    printf("                            |*--------------------ע��ɹ�----------------------*|\n");
    fclose(fp);
    yanzheng2();
}

void yanzheng1()
{
	char str[20];
	char str1[20];
	char str2[]="admire";
	char mi[]="123456";
	printf("                            �������˺ţ�");
	scanf("%s",str);
	printf("                            ���������룺");
	scanf("%s",str1);
	if((strcmp(str2,str))==0&&(strcmp(str1,mi))==0)
	{
		printf("\n");
		printf("                                            <^_^>��¼�ɹ�<^_^>\n");
		printf("\n");
		guanlizhe();
	}
	else{
		if(g!=0)
		{
			printf("                            �����µ�¼(�㻹��%d�λ���)\n",g);
			g--;
			yanzheng1();
		}
		else
	     {
	     	printf("\n");
        	printf("                            |*--------------------�����裡��--------------------*|\n");
		 }
	 }
}


void caozuo()
{
	int n;
	int k;
	printf("\n");
	printf("                            |*--------------------  ����վ--------------------*|\n");
	printf("                            |*-------------������������ϵ��̨������-------------*|\n");
	printf("                            |*-------------�绰1��15820337316���ν��ˣ�---------*|\n");
	printf("                            |*-------------�绰2��15975815629������-----------*|\n");
	printf("                            |*--------------------����˵�¼��1��---------------*|\n");
	printf("                            |*--------------------�û��˵�¼��2��---------------*|\n");
	printf("\n");
	printf("                            ��ѡ����ĵ�¼��ʽ��"); 
	scanf("%d",&n);
	if(n==1)
	{
	   printf("                            |*--------------��ӭ�����¼ҳ��(�����)------------*|\n");
	   yanzheng1();
    }
	if(n==2)
	{
	   printf("                            |*---------------��ӭ�����¼ҳ��(�û���)-----------*|\n"); 
	   printf("                            |*---------------------��¼(1)----------------------*|\n");
	   printf("                            |*---------------------ע��(2)----------------------*|\n");
	   printf("                            ��������Ĳ�����");
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
	 	printf("                            |*----------------�޴˲��������������---------------*|\n");
		 caozuo(); 
	   }
	 }
	if(n!=1&&n!=2){
	 	printf("                            |*----------------�޴˲��������������---------------*|\n"); 
	 	caozuo();
	} 
}

int main()
{
	SetConsoleTitle("��ݹ���ϵͳ"); 
	system("color f5");
	caozuo();
 } 
 
 
 

