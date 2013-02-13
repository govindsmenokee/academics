/*

RECURSIVE DESCENT PARSER FOR GRAMMER:

		E->TE'
		E'->+TE'|^
		T-> FT'
		T'-> *FT'|^
		F-> a|(E)

AUTHOR: Govind S Menokee
EMAIL :govindsmenokee@gmail.com
DATE: February 14 2013

*/

#include<stdio.h>
#include<string.h>

char input[30];
int err=0;
int head=0;
// E->TE'
void E()
{
T();
E1();
}
// T-> FT'
void T()
{
F();
T1();
}
// E'->+TE'|^
void E1()
{
if(input[head]=='+'){
head++;
T();
E1();
}
}
// F-> a|(E)
void F()
{
if(input[head]=='s')
head++;
else if(input[head]=='('){
head++;
E();
if(input[head]==')')
head++;
else
err=1;
}
else
err=1;
}
// T'-> *FT'|^
void T1()
{
if(input[head]=='*')
{
head++;
F();
T1();
}
}
//main function
void main()
{
int ch,i;
l1:
err=0;
head=0;
for(i=0;i<30;i++){
input[i]='\0';
}
printf("1.INPUT\n2.EXIT\nEnter your choice!: ");
scanf("%d",&ch);
while(ch>0 && ch<2){
printf("Enter the input string: ");
scanf("%s",input);
E();
if(!err && (head==strlen(input)))
printf("The string is in the language.\n");
else
printf("The string is not accepted!\n");
goto l1;
}}
