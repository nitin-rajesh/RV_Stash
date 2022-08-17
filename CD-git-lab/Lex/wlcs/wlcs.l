wordEx [a-zA-Z]+
lineEx \n
spaceEx [ ]

%{
    #include<stdio.h>
    int words=0, lines=1, chars=0, spaces=0;
%}

%%
\n\n return 0;
{lineEx} {lines++;}
{spaceEx} {spaces++; chars += strlen(yytext);}
{wordEx} {words++; chars += strlen(yytext);}
. chars++;
%%

int main(){
    printf("Enter the strings\n");
    yylex();
    printf("Words:%d\nLines:%d\nSpaces:%d\nChars:%d\n",words,lines,spaces,chars);
}

int yywrap(){
    return 1;
}