%{
    #include<stdio.h>

    int pos_nums=0, neg_nums=0;
    int pos_frac=0, negfrac=0;
%}

%%
-[0-9]+[/.][0-9]+ {negfrac++;}
[0-9]+[/.][0-9]+ {pos_frac++;}
-[0-9]+ {neg_nums++;}
[0-9]+ {pos_nums++;}
\n\n {return 0;}
. ;
%%

int main(){
    printf("Enter numbers\n");

    yylex();

    printf("Pos int:%d\nNeg int:%d\nPos frac:%d\nNeg frac:%d\n",pos_nums,neg_nums,pos_frac,negfrac);
}

int yywrap(){
    return 1;
}