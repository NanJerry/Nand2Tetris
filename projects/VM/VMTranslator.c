#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<io.h>

int k = 0;
int l = 0;
char name[100];
void parser(FILE* fp, FILE* Newfp);
void Hascomment(char* s);
void Codeini(FILE* Newfp);
void CodeWriter(char* com,char* ar1, char* ar2, FILE* Newfp);
int Typejudge(char* com);
void wirteArithmetic(char* com, FILE* Newfp);
void writePushPop(char* com,char* ar1, char* ar2, FILE* Newfp);
void writeLabel(char* ar,FILE* Newfp);
void writeGoto(char* ar1,FILE* Newfp);
void writeifGoto(char* ar1,FILE* Newfp);
void writeCall(char* ar1,char* ar2,FILE* Newfp);
void writeReturn(FILE* Newfp);
void writeFuction(char* ar1,char* ar2,FILE* Newfp);


int main(int argc, char* argv[])
{   
    FILE* Newfp = NULL; 
    FILE* fp = NULL;
    struct _finddata_t fileDir;
    long lfDir;
    char dire[100];
    char* a = NULL;
    int is_folder = 0;
    int in_folder = 0;
    // Part I, generate files.
    memset(dire,0,100);
    memset(name,0,100);            
    strcpy(dire,argv[1]);
    
    a = strrchr(dire,'/');
    if(a != NULL)
    in_folder = 1;
    if(in_folder == 0)
    {   
        strcpy(name,argv[1]);
    }
    else
    {
        a++;
        strcpy(name,a);
    }
    
    
    a = strstr(dire,".vm");
    if(a == NULL)
    {
        is_folder = 1;
        in_folder = 1;
        memset(dire,0,100);
        strcat(dire,"./");
        strcat(dire,argv[1]);
        strcat(dire,"/*.vm");
    }
    else
    {
        memset(dire,0,100);
        strcat(dire,"./");
        strcat(dire,argv[1]);
    }

    if(is_folder)
    {
        strcat(name,".asm");
    }
    else
    {
        a = strrchr(name,'.');
        a++;
        *a = '\0';
        strcat(name,"asm");
    }

    Newfp = fopen(name,"w");
    a = strrchr(name,'.');
    *a = '\0';
    if((lfDir = _findfirst(dire,&fileDir)) == -1)
    {    
        printf("No file is found!\n");
        return 0;
    }
    else
    {
        do
        {
            printf("%d",strcmp(fileDir.name,"Sys.vm"));
            if(!strcmp(fileDir.name,"Sys.vm"))
            Codeini(Newfp);
        } while (_findnext( lfDir, &fileDir ) == 0);     
    }
    _findclose(lfDir);
    // Part II 
    lfDir = _findfirst(dire,&fileDir);
    do
    {
        if(in_folder == 1)
        {
            a = strrchr(dire,'/');
            a++;
            *a = '\0';
            strcat(dire,fileDir.name);
        }
    fp = fopen(dire,"r+");
    parser(fp,Newfp);
    fclose(fp);
    }while( _findnext( lfDir, &fileDir ) == 0 );
    
    _findclose(lfDir);
    fclose(Newfp);
    return 0;
}



// Parser 部分的代码

void parser(FILE* fp, FILE* Newfp)
{
    char readBuf[1024];
    char comtype[16];
    char arg1[100];
    char arg2[100];
    int i = 0;
    while(!feof(fp))
    {   
        i = 0;
        memset(readBuf,0,1024);
        memset(comtype,0,16);
        memset(arg1,0,100);
        memset(arg2,0,100);
        fgets(readBuf,1024,fp);
        Hascomment(readBuf);
        while(readBuf[i] == ' ')
        i++;

        if(readBuf[i] == '\n' || readBuf[i] == '\0')
        continue;

        sscanf(&readBuf[i],"%s %s %s",comtype, arg1, arg2);
        CodeWriter(comtype,arg1,arg2,Newfp);
    }

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

// CodeWriter Part III

void Codeini(FILE* Newfp)
{
    fprintf(Newfp,"@256\nD=A\n@SP\nM=D\n");
    // fprintf(Newfp,"@call$sys.init\nD=A\n@SP\nM=M+1\nA=M-1\nM=D\n@LCL\nD=M\n@SP\nM=M+1\nA=M-1\nM=D\n@ARG\nD=M\n@SP\nM=M+1\nA=M-1\nM=D\n@THIS\nD=M\n@SP\nM=M+1\nA=M-1\nM=D\n@THAT\nD=M\n@SP\nM=M+1\nA=M-1\nM=D\n@5\nD=A\n");
    // fprintf(Newfp,"@SP\nD=M-D\n@ARG\nM=D\n@SP\nD=M\n@LCL\nM=D\n@Sys.init\n0;JMP\n(@call$sys.init)\n");
    fprintf(Newfp,"@Sys.init\n0;JMP\n");
}

void CodeWriter(char* com,char* ar1, char* ar2, FILE* Newfp)
{
    int k = 0;
    k = Typejudge(com);
    if(k == 0)
    {
        printf("syntax error!\n");
        exit(-1);
    }
    if(k == 1)
    wirteArithmetic(com,Newfp);
    if(k == 2)
    writePushPop(com,ar1,ar2,Newfp);
    if(k == 3)
    writeLabel(ar1,Newfp);
    if(k == 4)
    writeGoto(ar1,Newfp);
    if(k == 5)
    writeifGoto(ar1,Newfp);
    if(k == 6)
    writeCall(ar1,ar2,Newfp);
    if(k == 7)
    writeReturn(Newfp);
    if(k == 8)
    writeFuction(ar1,ar2,Newfp);
}


int Typejudge(char* com)
{
    if(strcmp(com,"add") == 0 || strcmp(com,"sub") == 0 || strcmp(com,"neg") == 0 || strcmp(com,"eq") == 0 || strcmp(com,"gt") == 0 || strcmp(com,"lt") == 0 || strcmp(com,"and") == 0 || strcmp(com,"or") == 0 || strcmp(com,"not") == 0)
    return 1;
    if(strcmp(com,"push") == 0 || strcmp(com,"pop") == 0)
    return 2;
    if(strcmp(com,"label") == 0)
    return 3;
    if(strcmp(com,"goto") == 0)
    return 4;
    if(strcmp(com,"if-goto") == 0)
    return 5;
    if(strcmp(com,"call") == 0)
    return 6;
    if(strcmp(com,"return") == 0)
    return 7;
    if(strcmp(com,"function") == 0)
    return 8;

    return 0;
}


void wirteArithmetic(char* com, FILE* Newfp)
{   
    if(strcmp(com,"neg") == 0 || strcmp(com,"not") == 0)
    {
        
        fputs("@SP\nA=M-1\n",Newfp);
        if(strcmp(com,"neg") == 0)
        fputs("M=-M\n",Newfp);

        if(strcmp(com,"not") == 0)
        fputs("M=!M\n",Newfp);
    }
    else
    {
        fputs("@SP\nM=M-1\nA=M\nD=M\n@SP\nA=M-1\n",Newfp);

        if(strcmp(com,"add") == 0)
        fputs("M=M+D\n",Newfp);

        if(strcmp(com,"sub") == 0)
        fputs("M=M-D\n",Newfp);

        if(strcmp(com,"eq") == 0)
        {
            fprintf(Newfp,"D=M-D\n@RET_TRUE%d\nD;JEQ\nD=0\n@CONTINUE%d\n0;JMP\n(RET_TRUE%d)\nD=-1\n(CONTINUE%d)\n@SP\nA=M-1\nM=D\n",k,k,k,k);
            k++;
        }

        if(strcmp(com,"gt") == 0)
        {
            fprintf(Newfp,"D=M-D\n@RET_TRUE%d\nD;JGT\nD=0\n@CONTINUE%d\n0;JMP\n(RET_TRUE%d)\nD=-1\n(CONTINUE%d)\n@SP\nA=M-1\nM=D\n",k,k,k,k);
            k++;
        }

        if(strcmp(com,"lt") == 0)
        {
            fprintf(Newfp,"D=M-D\n@RET_TRUE%d\nD;JLT\nD=0\n@CONTINUE%d\n0;JMP\n(RET_TRUE%d)\nD=-1\n(CONTINUE%d)\n@SP\nA=M-1\nM=D\n",k,k,k,k);
            k++;
        }

        if(strcmp(com,"and") == 0)
        fputs("M=D&M\n",Newfp);

        if(strcmp(com,"or") == 0)
        fputs("M=D|M\n",Newfp);        
        
    }
}
void writePushPop(char* com,char* ar1, char* ar2, FILE* Newfp)
{
    long arg2 = atol(ar2);
    if(strcmp(com,"push") == 0)
    {
        if(strcmp(ar1,"argument") == 0)
        fprintf(Newfp,"@ARG\nD=M\n@%d\nA=D+A\nD=M\n@SP\nM=M+1\nA=M-1\nM=D\n",arg2);

        if(strcmp(ar1,"constant") == 0)
        fprintf(Newfp,"@%d\nD=A\n@SP\nM=M+1\nA=M-1\nM=D\n",arg2);

        if(strcmp(ar1,"local") == 0)
        fprintf(Newfp,"@%d\nD=A\n@LCL\nA=M+D\nD=M\n@SP\nM=M+1\nA=M-1\nM=D\n",arg2);

        if(strcmp(ar1,"pointer") == 0)
        {
            if(arg2 == 0)
            fprintf(Newfp,"@THIS\n");

            if(arg2 == 1)
            fprintf(Newfp,"@THAT\n");

            fprintf(Newfp,"D=M\n@SP\nM=M+1\nA=M-1\nM=D\n");
        }

        if(strcmp(ar1,"this") == 0)
        fprintf(Newfp,"@%d\nD=A\n@THIS\nA=M+D\nD=M\n@SP\nM=M+1\nA=M-1\nM=D\n",arg2);

        if(strcmp(ar1,"that") == 0)
        fprintf(Newfp,"@%d\nD=A\n@THAT\nA=M+D\nD=M\n@SP\nM=M+1\nA=M-1\nM=D\n",arg2);

        if(strcmp(ar1,"temp") == 0)
        fprintf(Newfp,"@%d\nD=A\n@R5\nA=A+D\nD=M\n@SP\nM=M+1\nA=M-1\nM=D\n",arg2); // what if arg2 > 7

        if(strcmp(ar1,"static") == 0)
        fprintf(Newfp,"@%s.%d\nD=M\n@SP\nM=M+1\nA=M-1\nM=D\n",name,arg2);
    }
    // Pop use general purpose register.
    if(strcmp(com,"pop") == 0)
    {
        if(strcmp(ar1,"argument") == 0)
        fprintf(Newfp,"@%d\nD=A\n@ARG\nD=M+D\n@R13\nM=D\n@SP\nM=M-1\nA=M\nD=M\n@R13\nA=M\nM=D\n",arg2);

        if(strcmp(ar1,"local") == 0)
        fprintf(Newfp,"@%d\nD=A\n@LCL\nD=M+D\n@R13\nM=D\n@SP\nM=M-1\nA=M\nD=M\n@R13\nA=M\nM=D\n",arg2);

        if(strcmp(ar1,"pointer") == 0)
        {
            fprintf(Newfp,"@SP\nM=M-1\nA=M\nD=M\n");

            if(arg2 == 0)
            fprintf(Newfp,"@THIS\n");

            if(arg2 == 1)
            fprintf(Newfp,"@THAT\n");

            fprintf(Newfp,"M=D\n");            
        }

        if(strcmp(ar1,"this") == 0)
        fprintf(Newfp,"@%d\nD=A\n@THIS\nD=M+D\n@R13\nM=D\n@SP\nM=M-1\nA=M\nD=M\n@R13\nA=M\nM=D\n",arg2);

        if(strcmp(ar1,"that") == 0)
        fprintf(Newfp,"@%d\nD=A\n@THAT\nD=M+D\n@R13\nM=D\n@SP\nM=M-1\nA=M\nD=M\n@R13\nA=M\nM=D\n",arg2);

        if(strcmp(ar1,"temp") == 0)
        fprintf(Newfp,"@%d\nD=A\n@R5\nD=A+D\n@R13\nM=D\n@SP\nM=M-1\nA=M\nD=M\n@R13\nA=M\nM=D\n",arg2); // what if arg2 > 7

        if(strcmp(ar1,"static") == 0)
        fprintf(Newfp,"@SP\nM=M-1\nA=M\nD=M\n@%s.%d\nM=D\n",name,arg2);
    }  
}


void writeLabel(char* ar,FILE* Newfp)
{
    fprintf(Newfp,"(%s)\n",ar);
}

void writeGoto(char* ar1,FILE* Newfp)
{
    fprintf(Newfp,"@%s\n0;JMP\n",ar1);
}

void writeifGoto(char* ar1,FILE* Newfp)
{
    fprintf(Newfp,"@SP\nM=M-1\nA=M\nD=M\n@%s\nD;JGT\n",ar1);   
}

void writeCall(char* ar1,char* ar2,FILE* Newfp)
{
    long arg2 = atol(ar2);
    fprintf(Newfp,"@RETURN%d\nD=A\n@SP\nM=M+1\nA=M-1\nM=D\n@LCL\nD=M\n@SP\nM=M+1\nA=M-1\nM=D\n@ARG\nD=M\n@SP\nM=M+1\nA=M-1\nM=D\n@THIS\nD=M\n@SP\nM=M+1\nA=M-1\nM=D\n@THAT\nD=M\n@SP\nM=M+1\nA=M-1\nM=D\n@5\nD=A\n",l);
    fprintf(Newfp,"@%d\nD=A+D\n@SP\nD=M-D\n@ARG\nM=D\n@SP\nD=M\n@LCL\nM=D\n@%s\n0;JMP\n(RETURN%d)\n",arg2,ar1,l);   
    l++;
}

void writeReturn(FILE* Newfp)
{
    fprintf(Newfp,"@5\nD=A\n@LCL\nA=M-D\nD=M\n@R13\nM=D\n@SP\nA=M-1\nD=M\n@ARG\nA=M\nM=D\n");
    fprintf(Newfp,"@ARG\nD=M\n@SP\nM=D+1\n@LCL\nA=M-1\nD=M\n@THAT\nM=D\n");
    fprintf(Newfp,"@2\nD=A\n@LCL\nA=M-D\nD=M\n@THIS\nM=D\n@3\nD=A\n@LCL\nA=M-D\nD=M\n@ARG\nM=D\n@4\nD=A\n@LCL\nA=M-D\nD=M\n@LCL\nM=D\n@R13\nA=M\n0;JMP\n");
}
    
void writeFuction(char* ar1,char* ar2,FILE* Newfp)
{   
    long arg2 = atol(ar2);
    fprintf(Newfp,"(%s)\n@%d\nD=A\n@SP\nM=M+D\n@func$%d$%s\nD;JEQ\n(func$%s$%d)\nD=D-1\n@LCL\nA=M+D\nM=0\n@func$%s$%d\nD;JGT\n(func$%d$%s)\n",ar1,arg2,arg2,ar1,ar1,arg2,ar1,arg2,arg2,ar1);
}