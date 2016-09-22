// Lexical Analizer
/* TO IMPLEMENT LEXICAL ANALIZER IN C */

#include< conio.h>
#include< string.h>

void main()
{
int i,j,lc;
char *a[9][4]={"PRG","START" ," " ," ",
" " ,"USING" ,"*" ,"15",
" ","L","1","FIVE",
" ","A","1","FOUR",
" ","ST","1","TEMP",
"FOUR ","DC","F","4",
"FIVE","DC","F","5",
"TEMP","DS","1","F",
" " ,"END"," "," ", };
clrscr();
printf("\n \t\t LEXICAL ANALIZER \n");

for(i=0;i< 9;i++)
{ for(j=0;j< 4;j++)
{ if(isalpha(*a[i][j]))
printf("\n STRING : %s",a[i][j]);
if(isdigit(*a[i][j]))
printf("\n DIGIT : %s",a[i][j]);
}
printf("\n");
}

getch();
}
