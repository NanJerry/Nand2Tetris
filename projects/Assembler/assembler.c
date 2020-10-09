#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

void Hascomment(char* s);
void first_pass(FILE *fp);
void secend_pass(FILE *fp,FILE* fp1);
void parser(char* b, FILE *fp1);
void binary1(long a,char z[]);


struct Symbol1{
char k1[256];
long  k2;	
};

typedef struct Symbol1 sym;
sym t[2048]={{"SP",0},{"LCL",1},{"ARG",2},{"THIS",3},{"THAT",4},{"R0",0},{"R1",1},{"R2",2},{"R3",3},{"R4",4},{"R5",5},{"R6",6},{"R7",7},{"R8",8},{"R9",9},{"R10",10},{"R11",11},{"R12",12},{"R13",13},{"R14",14},{"R15",15},{"SCREEN",16384},{"KBD",24576}};
int p0 = 23;
int n0 = 16;
int n1 = 0;  //n1 lines,


int main(int argc, char *argv[])
{
FILE *fp0;
FILE *fp1;

if(argc!=2)
	{
	printf("We need one file.");
	exit(0);
	}

int a=0;


a = strlen(argv[1]);
char chr[a+2];
memset(chr,0,a+2);
strcpy(chr,argv[1]);

if(!(strcmp(chr+a-4,".asm")))
	{
	strcpy(chr+a-4,".hack");
	}
else
	{
	printf("error!");
	exit(0);
	}


	
fp0 = fopen(argv[1],"r");
fp1 = fopen(chr,"w");		

first_pass(fp0);

fseek(fp0,0L,SEEK_SET);
secend_pass(fp0,fp1); //'已经完成了symboltable 的构建
fclose(fp0);
fclose(fp1);

	
}

void Hascomment(char* s)
{
    char* a = NULL;
    if((a = strstr(s,"//")) == NULL)
    return;
    else
    {
        *a = '\n';
    }
    
}

void first_pass(FILE *fp)
{
    char readBuf[1024];
    char name[128];
    char* a = NULL;
    int i = 0;
    while(!feof(fp))
    {
        i = 0;
        memset(name,0,128);
        memset(readBuf,0,1024);
        fgets(readBuf,1024,fp);
        Hascomment(readBuf);

        while(readBuf[i] == ' ')
        i++;

        if(readBuf[i] == '\n' || readBuf[i] == '\0')
        continue;
        if(readBuf[i] == '(')
        {
            sscanf(&readBuf[i],"(%[^)]",name);            
            int w=1;
		    for(int j=0; j < p0; j++)
			{
		    	if(!(strcmp(t[j].k1,name)))
				{
			        w=0;
		    	    break;
		    	}
			}
			if(w==0)
			{
                printf("error!label name already exits!\n");
                exit(-1);
			}
            else
            {
                strcpy(t[p0].k1,name);
                t[p0].k2 = n1;
				p0++;
            }			
            
        }
        else
        {
            n1++;
        }
        
    }
}


void secend_pass(FILE *fp,FILE* fp1)
{
    char readBuf[1024];
    char name[128];
    char* a = NULL;
    int i = 0;
    while(!feof(fp))
    {
		
        i = 0;
        memset(name,0,128);
        memset(readBuf,0,1024);
        fgets(readBuf,1024,fp);
        Hascomment(readBuf);
		
        while(readBuf[i] == ' ')
        i++;

        if(readBuf[i] == '\n' || readBuf[i] == '\0')
        continue;
		
        if(readBuf[i] == '(')
        continue;
		
        if(readBuf[i] == '@')
        {
            
            sscanf(&readBuf[i],"@%s",name);
            int w=1;
			if(isdigit(name[0]))
			w = 0;
            int j;
		    for(j=0; j < p0; j++)
			{
		    	if(!(strcmp(t[j].k1,name)))
				{
			        w=0;
		    	    break;
		    	}
			}
			if(w==1)
            {
                strcpy(t[p0].k1,name);
                t[p0].k2 = n0;
                p0++;
                n0++;
            }
            char index[10];
            memset(index,0,10);
            int bitc = 0;
            int s = 0;
			if(isdigit(name[0]))
			s = atol(name);
			else
			{
				s = t[j].k2;
			}
            while((s / 10) != 0)
            {
                s = s/10;
                bitc++;
            }
            if(isdigit(name[0]))
			s = atol(name);
			else
			{
				s = t[j].k2;
			}
            for(int k = bitc;k >= 0;k--)
            {
                index[k] = (s%10)+48;
                s = s/10;
            }
            readBuf[i+1] = '\0';
            strcat(&readBuf[i],index);
        }
        parser(&readBuf[i],fp1);
    }
}


void parser(char *b, FILE *fp1)
{
    char a;
    char nk1[4];
    char nk3[4];
	int nk4=0;
	int nk0 = 0;
    int CI =0;
    int RI =0;
    char ci[17]="1110000000000000";
    int i = 0;
	
	if(b[i]=='@')
	{
    	long c = atoi(&b[i+1]);	
	    char c0[20];
		memset(c0,0,20);
        binary1(c,c0);	
		fprintf(fp1,"0%s\n",c0);
		return;
	}   //实现A型指令

	
    if(b[i]=='1')
 	{
		ci[4]='1';
		ci[5]='1';
		ci[6]='1';
    	ci[7]='1';
    	ci[8]='1';
    	ci[9]='1';
	}

    if(b[i]=='0')
	{
    	ci[4]='1';
    	ci[5]='0';
		ci[6]='1';
	    ci[7]='0';
		ci[8]='1';
		ci[9]='0';
	}		
		
    if(b[i]=='A')
	{
		ci[4]='1';
		ci[5]='1';
    	ci[6]='0';
    	ci[7]='0';
    	ci[8]='0';
    	ci[9]='0';
	}	
		
    if(b[i]=='M')
	{
		ci[3]='1';
		ci[4]='1';
		ci[5]='1';
		ci[6]='0';
		ci[7]='0';
		ci[8]='0';
		ci[9]='0';
	}		
		
    if(b[i]=='D')
	{
		ci[4]='0';
		ci[5]='0';
    	ci[6]='1';
    	ci[7]='1';
    	ci[8]='0';
		ci[9]='0';
	}		
	
		
    while(b[i]!=';' && b[i]!='=')
	{
		if(b[i]=='A' || b[i]=='M' || b[i]=='D')
		{
	    	nk1[nk0] = b[i];
	    	nk0++;
	    	i++;
	    	continue;
		}
		i++;
		
	}
	nk1[nk0]='\0';
	
    if(b[i]==';')
	{	
	    i++;
	    while(b[i]==' ')
	    {
	        i++;
		}
		char nk2[4]="000\0";
		nk2[0]=b[i];
		i++;
		nk2[1]=b[i];
		i++;		
		nk2[2]=b[i];
		i++;	
	
	    if(!strcmp(nk2,"JGT"))
	    {
	        ci[15] = '1';
		}	
    	if(!strcmp(nk2,"JEQ"))
    	{	
   	    ci[14] = '1';
		}
    
		if(!strcmp(nk2,"JGE"))
		{
	       	ci[14] = '1';
	    	ci[15] = '1';
	    }			
		
	    if(!strcmp(nk2,"JLT"))
	    {
	    	ci[13] = '1';	
	    }			
		
		if(!strcmp(nk2,"JNE"))
		{
	       	ci[13] = '1';	
	    	ci[15] = '1';
    	}			
		
		if(!strcmp(nk2,"JLE"))
		{
	    	ci[13] = '1';	
	    	ci[14] = '1';
		}			
		
    	if(!strcmp(nk2,"JMP"))
    	{
    		ci[13] = '1';	
         	ci[14] = '1';
	        ci[15] = '1';
	    }
        fprintf(fp1,"%s\n",ci);
        return;
	}
		
    if(b[i]=='=')
	{
		if(!strcmp(nk1,"M"))
		{
			ci[12] = '1';	
		}			

		if(!strcmp(nk1,"D"))
		{
			ci[11] = '1';
		}

		if(!strcmp(nk1,"MD"))
		{
			ci[11] = '1';
			ci[12] = '1';
		}
			
		if(!strcmp(nk1,"A"))
		{
			ci[10] = '1';	
	    }
			
		if(!strcmp(nk1,"AM"))
		{
			ci[10] = '1';	
			ci[12] = '1';
	    }
			
		if(!strcmp(nk1,"AD"))
		{
			ci[10] = '1';	
			ci[11] = '1';
		}
		
		if(!strcmp(nk1,"AMD"))
		{
			ci[10] = '1';	
			ci[11] = '1';
			ci[12] = '1';	
		}		
	}
	i++;
	while(b[i]==' ')
	i++;
	
	
	nk3[4]='\0';
	while(b[i]!='\0')
    {
        if(b[i]==' ')
		{
			i++;
        	continue;
		}
        nk3[nk4] = b[i];
        nk4++;
        i++;
    }
	
	if(nk3[1]=='|')
	{
		if(nk3[0]=='M' || nk3[2]=='M' )
		{
			ci[3]='1';	
		}
		ci[4]='0';
		ci[5]='1';
		ci[6]='0';
		ci[7]='1';
		ci[8]='0';
		ci[9]='1';
        fprintf(fp1,"%s\n",ci);
        return;
	}
		
	if(nk3[1]=='&')
	{
		if(nk3[0]=='M' || nk3[2]=='M' )
		{
			ci[3]='1';	
		}
		ci[4]='0';
		ci[5]='0';
		ci[6]='0';
		ci[7]='0';
		ci[8]='0';
		ci[9]='0';
        fprintf(fp1,"%s\n",ci);
        return;
	}
		
	if(nk3[1]=='+')
	{
		ci[8]='1';
		if(nk3[0]=='1' || nk3[2]=='1' )
		{
			ci[9]='1';	
			if(nk3[0]=='D' || nk3[2]=='D' )
			{
				ci[3]='0';
				ci[4]='0';	
				ci[5]='1';
				ci[6]='1';
				ci[7]='1';
                fprintf(fp1,"%s\n",ci);
                return;
			}
			if(nk3[0]=='M' || nk3[2]=='M')
			{
				ci[3]='1';
			}
			else
			{
				ci[3]='0';
			}
			ci[4]='1';	
			ci[5]='1';
			ci[6]='0';
			ci[7]='1';
            fprintf(fp1,"%s\n",ci);
            return;
		    
        }
		if(nk3[0]=='M' || nk3[2]=='M')
		{
			ci[3]='1';	
		}
		else
		{
			ci[3]='0';
		}			
		ci[4]='0';	
		ci[5]='0';
		ci[6]='0';
		ci[7]='0';			
		ci[9]='0';
        fprintf(fp1,"%s\n",ci);
        return;
	}		
		
	if(nk3[1]=='-')
	{
		ci[8]='1';
		if(nk3[2]=='1')
		{
			ci[9]='0';	
			if(nk3[0]=='D' || nk3[2]=='D' )
			{
				ci[3]='0';
				ci[4]='0';	
				ci[5]='0';
				ci[6]='1';
				ci[7]='1';
				fprintf(fp1,"%s\n",ci);
                return;
			}
			if(nk3[0]=='M')
			{
				ci[3]='1';	
			}
			else
			{
				ci[3]='0';
			}
			ci[4]='1';	
			ci[5]='1';
			ci[6]='0';
			ci[7]='0';
			fprintf(fp1,"%s\n",ci);
            return;
		}
		ci[9]='1';	
		if(nk3[0]=='M' || nk3[2]=='M')
		{
			ci[3]='1';	
		}
		else
		{
			ci[3]='0';
		}
		
		if(nk3[0]=='D')
		{
	    	ci[4]='0';	
		    ci[5]='1';
    		ci[6]='0';
    		ci[7]='0';	
    		fprintf(fp1,"%s\n",ci);
            return;
		}
			
		ci[4]='0';	
		ci[5]='0';
		ci[6]='0';
		ci[7]='1';				
		fprintf(fp1,"%s\n",ci);
        return;
	}		

	if(nk3[1]=='D')
	{
		ci[3]='0';
		ci[4]='0';
		ci[5]='0';
		ci[6]='1';
		ci[7]='1';
		ci[9]='1';	
		if(nk3[0]=='!')
		{
			ci[8]='0';	
		}
		else
		{
			ci[8]='1';
		}
		fprintf(fp1,"%s\n",ci);
        return;	
	}	

	if(nk3[1]=='A' || nk3[1]=='M')
	{
		if(nk3[1]=='M')
		{
			ci[3]='1';	
		}
		else
		{
			ci[3]='0';
		}
		ci[4]='1';
		ci[5]='1';
		ci[6]='0';
		ci[7]='0';
		ci[9]='1';	
		if(nk3[0]=='!')
		{
			ci[8]='0';	
		}
		else
		{
			ci[8]='1';
		}
		fprintf(fp1,"%s\n",ci);
        return;	
	}			
	
	if(nk3[1]=='1')
	{
		ci[3]='0';
		ci[4]='1';
		ci[5]='1';
		ci[6]='1';
		ci[7]='0';
		ci[8]='1';
		ci[9]='0';	
		fprintf(fp1,"%s\n",ci);
        return;
	}

	if(nk3[0]=='1')
	{
		ci[3]='0';
		ci[4]='1';
		ci[5]='1';
		ci[6]='1';
		ci[7]='1';
		ci[8]='1';
		ci[9]='1';	
		fprintf(fp1,"%s\n",ci);
        return;
	}
		
	if(nk3[0]=='0')
	{
		ci[3]='0';
		ci[4]='1';
		ci[5]='0';
		ci[6]='1';
		ci[7]='0';
		ci[8]='1';
		ci[9]='0';	
		fprintf(fp1,"%s\n",ci);
        return;
	}		
		
	if(nk3[0]=='D')
	{
		ci[3]='0';
		ci[4]='0';
		ci[5]='0';
		ci[6]='1';
		ci[7]='1';
		ci[8]='0';
		ci[9]='0';	
		fprintf(fp1,"%s\n",ci);
        return;
	}		

	if(nk3[0]=='A' || nk3[0]=='M')
	{
		if(nk3[0]=='M')
		{
			ci[3]='1';				
		}
		else
		{
			ci[3]='0';
		}
		
		ci[4]='1';
		ci[5]='1';
		ci[6]='0';
		ci[7]='0';
		ci[8]='0';
		ci[9]='0';	
		fprintf(fp1,"%s\n",ci);
        return;
	}			    
}	

void binary1(long a,char z[])
{
    long x = a;
    long y = 14;

    while(x>0 && y>=0)
    {
        if(x % 2 == 1)
	    {
	        *(z+y)='1';	
	    }
        else
	    {
    	    *(z+y)='0';	
	    }
        x = x / 2;
        y--;	
    }	
    while(y>=0)
	{
	    *(z+y)=	'0';
	    y--;
	}
}