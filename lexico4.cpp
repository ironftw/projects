/*
 ============================================================================
 Name        : LexicoAAI.c
 Author      : 
              KLEBER FERREIRA
              HUGO DIAS
              LEONARDO MARCIO
              RENATO FIALHO
              PEDRO STEFANO
              EDUARDO
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
*/

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

#define oper "+/-*"
#define igual "="
#define num  "0123456789"
#define letra  "abcdefghijklmnopqrstuvyxwzABCDEFGHIJKLMNOPQRSTUVYXWZ"
#define espaco  " "
#define barra  "/"
#define asterisco  "*"
#define alfabeto  "abcdefghijklmnopqrstuvyxwzABCDEFGHIJKLMNOPQRSTUVYXWZ0123456789=+*/ "

int busk (char a, const char * str)
{
	int j=0, ret=0;
	while (str[j] && !ret)
	{
		ret = (str[j]==a);
		j++;
	}
	return(ret);
}

void reconhece(char *automato) {
     
     FILE *fpou;
     
     fpou = fopen("saida4.txt","a");
     
     if (!fpou)
     {
       printf("Erro na abertura do arquivo arqS.txt");
       getchar();
       exit(1);
     }
     
     
     
	int i=0, state=0, invalida=0;
while ((state!=30) && (i < 60))
	{
		switch(state)
		{
			case 0:
				 while((automato[i]==' ') && (i < 60))i++;
                 if (automato[i]=='/'){
                    state = 1;
                 }else if (busk(automato[i],letra)){
					state = 4;
                 }else{
					state=29;
					invalida = 1;
				}
				i++;
				break;
			case 1:
				if (automato[i]=='*'){
					state = 2;
				}else{
					state=30;
					invalida = 1;
				}
				i++;
                break;
			case 2:
				 while((automato[i]!='*') && (i < 60))i++;
				 if (automato[i]=='*'){
					state=3;
                 }
				 i++;
				 break;
			case 3:
                 while((automato[i]=='*') && (i < 60))i++;
				 if (automato[i]=='/'){
                       state=0;
                 }else {
					state=2;
				 }
				 i++;
				 break;
            case 4:
                 while((busk(automato[i],letra)) && (i < 60))i++;
				 if (busk(automato[i],num)){
					state=5;
				 }else if (automato[i]==' '){
					state=6;
				 }else if (automato[i]=='/'){
					state=7;
				 }else if (automato[i]=='='){
					state=10;
				 }else{
					state=30;
					invalida=1;
				 }
				 i++;
				 break;
            case 5:
				 while((busk(automato[i],num)) && (i < 60)) i++;
				 if (automato[i]==' '){
					state=6;
				 }else if (automato[i]=='/'){
					state=7;
				 }else if (automato[i]=='='){
					state=10;
				 }else{
					state=30;
					invalida=1;
				 }
				i++;
				break;
			case 6:
				while ((automato[i]==' ') && (i < 60)) i++;
				if (automato[i]=='/'){
					state=7;
				 }else if (automato[i]=='='){
					state=10;
				 }else{
					state=30;
					invalida=1;
				 }
                i++;
				break;
			case 7:
				 if (automato[i]=='*'){
					state=8;
				 }else{
                     state=30;
					invalida=1;
                 }
                 i++;
                 break;
			case 8:
				 if (automato[i]=='*'){
					state=9;
				 }else{
                       state = 8;
                 }
                 i++;
                 break;
			case 9:
			     while ((automato[i]=='*') && (i < 60)) i++;
                 if (automato[i]=='/'){
					state=6;
				 }else{
					state=8;
			     }
                 i++;
                 break;
			case 10:
				 while ((automato[i]==' ') && (i < 60)) i++;
				 if (automato[i]=='/'){
					state=11;
				 }else if(busk(automato[i],letra)){
					state=14;
				 }else if (busk(automato[i], num)){
                       state=15;
                 }else{
					state=30;
					invalida=1;
			     }
                 i++;
                 break;
			case 11:
				 if (automato[i]=='*'){
					state=12;
				 }else{
                      state=30;
					invalida=1;
                 }
                 i++;
                 break;
            case 12:
                 while ((automato[i]!='*') && (i < 60)) i++;
				 if (automato[i]=='*'){
					state=13;
				 }
                 i++;
                 break;
            case 13:
                 while ((automato[i]=='*') && (i < 60)) i++;
				 if (automato[i]=='/'){
					state=10;
				 }else {
                      state = 12;
                 }
                 i++;
                 break;
            case 14:
                 while((busk(automato[i],letra)) && (i < 60))i++;
				 if (busk(automato[i],num)){
					state=15;
				 }else if(automato[i]==' '){
                       state=16;
				 }else if(automato[i]=='/'){
                       state=17;
				 }else if(busk(automato[i],oper)){
                       state=20;
				 }else{
                       state=30;
					invalida=1;
                 }
                 i++;
                 break;
            case 15:
                 while((busk(automato[i],num)) && (i < 60))i++;
                 if(automato[i]==' '){
                       state=16;
				 }else if(automato[i]=='/'){
                       state=17;
				 }else if(busk(automato[i],oper)){
                       state=20;
				 }else{
                       state=30;
					invalida=1;
                 }
                 i++;
                 break;
            case 16:
                 while((automato[i]==' ') && (i < 60))i++;
                 if(automato[i]=='/'){
                       state=17;
				 }else if(busk(automato[i],oper)){
                       state=20;
				 }else{
                       state=30;
					invalida=1;
                 }
                 i++;
                 break;
            case 17:
                 if(automato[i]=='/'){
                    state= 21;
                 }
                 else if(automato[i]=='*'){
                       state=18;
				 }
                  else if(automato[i]==' '){
                       state=20;
				 }
                  else if(busk(automato[i],letra)){
                       state=24;
				 }
				 else if(busk(automato[i],num)){
                       state=25;
				 } else{
                       state=30;
					invalida=1;
                 }
                 i++;
                 break;
            case 18:
                 while((automato[i]!='*') && (i < 60))i++;
                 if(automato[i]=='*'){
                       state=19;
				 }
                 i++;
                 break;
            case 19:
                 while((automato[i]=='*') && (i < 60))i++;
                 if (automato[i]=='/'){
					state=16;
				 }else {
                       state=18;
				 }
                 i++;
                 break;
            case 20:
                 while((automato[i]==' ') && (i < 60))i++;
                 if(automato[i]=='/'){
                       state=21;
				 }else if (busk(automato[i],letra)){
                       state=24;
                 }else if (busk(automato[i],num)){
                       state=25;
                 }else{
                     state=30;
					invalida=1;
                 }
                 i++;
                 break;
            case 21:
                 if(automato[i]=='*'){
                       state=22;
				 }else{
                     state=30;
					invalida=1;
                 }
                 i++;
                 break;
            case 22:
                 while((automato[i]!='*') && (i < 60))i++;
                 if(automato[i]=='*'){
                       state=23;
				 }
                 i++;
                 break;
            case 23:
                 while((automato[i]=='*') && (i < 60))i++;
                 if(automato[i]=='/'){
                       state=20;
				 }else {
                       state=22;
				 }
                 i++;
                 break;
            case 24:
                 while((busk(automato[i],letra)) && (i < 60))i++;
                 if(busk(automato[i],oper)){
                       state=20;
				 }else if(busk(automato[i],num)){
                       state=25;
				 }else if (automato[i]==' '){
				       state=26;
				 }else if (automato[i]=='/'){
				       state=27;
				 }else if (automato[i]=='\n'){
				       state=30;
				 }else{
                       state=30;
					invalida=1;
				  }
                 i++;
                 break;
            case 25:
                 while((busk(automato[i],num)) && (i < 60))i++;
                 if (automato[i]==' '){
				       state=26;
				 }else if (automato[i]=='/'){
				       state=27;
				 } else if(busk(automato[i],oper)){
                       state=20;
                 }else if (automato[i]=='\0'){
				       state=30;
				 }else{
                       state=30;
					invalida=1;
				  }
                 i++;
                 break;
            case 26:
                 while((automato[i]==' ') && (i < 60))i++;
                 if (automato[i]=='/'){
				       state=27;
				 }else if(busk(automato[i],oper)){
                       state=20;
                 }else if (automato[i]=='\0'){
				       state=30;
				 }else{
                       state=30;
					invalida=1;
				  }
                 i++;
                 break;
            case 27:
                 if (automato[i]=='*'){
				       state=28;
				 }else if(busk(automato[i],letra)){
                       state=24;
                 }else if(busk(automato[i],num)){
                       state=25;
                 }else if (automato[i]==' '){
				       state=20;
				 }else if (automato[i]=='/'){
				       state=21;
				 }else{
                       state=30;
					invalida=1;
				  }
                 i++;
                 break;
            case 28:
                 while((automato[i]!='*') && (i < 60))i++;
                 if (automato[i]=='*'){
				       state=29;
                 }
                 i++;
                 break;
            case 29:
                 while((automato[i]=='*') && (i < 60))i++;
                 if(automato[i]=='/'){
                       state=26;
				 }else{
                      state=28;
				}
                 i++;
                 break;
		}
	}
	
	if (invalida){
       fputs("String Invalida!\n",fpou);                            
	   printf("String Invalida!\n");
    }else{
        fputs("String Valida!\n",fpou);      
        printf("String valida!\n");
    }
		
}



int main()
{
    char string[60];
	char automato[60];
	char c;
	int i=0, state=0, x = 0;
    FILE *fp;
	printf("\tCompiladores - 6NA \n");
	
	fp = fopen("teste4.txt", "w");

	while (strcmp(string, "99")) {
		printf("Entre com a string a ser gravada no arquivo:");
		gets(string);
		if (strcmp(string, "99") == 0)
			break;

		/* Grava a string, caractere a caractere */
		for (i = 0; string[i]; i++)
			putc(string[i], fp);
		putc('\n', fp);
	}

	fclose(fp);
	
     fp = fopen("teste4.txt","r");

     if (!fp)
     {
       printf("Erro na abertura do arquivo teste4.txt");
       getchar();
       exit(1);
     }

     while ((c = getc(fp)) != EOF)
     {
       if (c != '\n') {
          automato[x] = c;
          x++;
       }else{
    	   reconhece(automato);
    	   x=0;
    	   for(int j=0; j < 60; j++){
               automato[j] = '\0';
    	   }
       }
     }
     
    fclose(fp); 
	getchar();
	return 0;
}
