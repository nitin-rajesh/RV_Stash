whitespace [ \t]*
sl_comment {whitespace}"//".*\n
ml_comment {whitespace}"/*"([^*]*[/]?)*|([*]?[^/]*)*"*/"{whitespace}"\n"?

%{
    #include<stdlib.h>
    int single_line = 0;
    int multi_line = 0;
%}

%%
{sl_comment} {single_line++;}
{ml_comment} {multi_line++;}
%%

int main(int argc, char **argv){
    if(argc != 2){
        printf("usage: %s input [output]\n", argv[0]);
        exit(1);
    }

    yyin = fopen(argv[1], "r");

    argv[1][strlen(argv[1]) - 2] = '\0';
    
    yyout = fopen(strcat(argv[1],"_commentless.c"), "w");

    yylex();
    printf("Single line comments: %d\n",single_line);
    printf("Multi line comments: %d\n",multi_line/2);

}

int yywrap(){
    return 1;
}