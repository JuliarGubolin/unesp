%{
    #include <stdio.h>
    #include "fonte.tab.h"
    extern int erros;
    extern int linhas;

	void token_reconhecido(int linhas, char * tipo, char * token){
        printf("Sem erros!");
    }

    void token_nao_reconhecido(int linhas, char * token){
        printf("Erro na linha %d, token: %s\n", linhas, token);
    }
%}

%option yylineno

DIGITO [0-9]
ALFABETO [a-zA-Z]
ID [a-zA-Z_][a-zA-Z0-9_]*
ESPACO " "|"\t"

OPERADORES_ARITMETICOS  "+"|"-"|"*"|"/"|"^"
OPERADORES_LOGICOS  "OU"|"E"
ESPECIAIS "@"|"&"|"$"
PONTO_E_VIRGULA ";"
VIRGULA ","
ATRIBUICAO "="

OPERADORES_RELACIONAIS "=="|">"|"<"|">="|"<="|"!="
ABRE_PARENTESES "("
FECHA_PARENTESES ")"
ABRE_CHAVES "{"
FECHA_CHAVES "}"

IF "if"
ELSE "else"
ELSEIF "elseif"
WHILE "while"
FOR "for"
DO "do"
RETURN "return"
PRINT "printf"
TIPOS_VARIAVEIS "integer"|"boolean"|"double"|"char"
INICIO_PROGRAMA "%INICIO_PROGRAMA%"
FIM_PROGRAMA "%FIM_PROGRAMA%"

QUEBRA_LINHA [\n]

%%

{IF} { return (IF); }
{ELSE} { return (ELSE); }
{ELSEIF} { return (ELSEIF);}
{FOR} { return (FOR);}
{DO} { return (DO);}
{WHILE} { return (WHILE); }
{RETURN} { return (RETURN); }
{PRINT} { return(PRINT);}
{TIPOS_VARIAVEIS} { return (TIPOS_VARIAVEIS); }
{INICIO_PROGRAMA} { return (INICIO_PROGRAMA); }
{FIM_PROGRAMA} { return (FIM_PROGRAMA); }

{DIGITO}+ { return (NUMERO_INTEIRO);}
{DIGITO}+"."{DIGITO}* { return (NUMERO_REAL);}

{OPERADORES_ARITMETICOS} { return (OPERADORES_ARITMETICOS);}
{OPERADORES_RELACIONAIS} { return (OPERADORES_RELACIONAIS);}
{OPERADORES_LOGICOS} { return (OPERADORES_LOGICOS);}

{ALFABETO}+({ALFABETO}|{DIGITO})* { return ID; }

{PONTO_E_VIRGULA} { return (PONTO_E_VIRGULA);}
{VIRGULA} { return (VIRGULA);}
{ABRE_PARENTESES} { return (ABRE_PARENTESES);}
{FECHA_PARENTESES} { return (FECHA_PARENTESES);}
{ABRE_CHAVES} { return (ABRE_CHAVES);}
{FECHA_CHAVES} { return (FECHA_CHAVES);}
{ATRIBUICAO} { return (ATRIBUICAO);}

{QUEBRA_LINHA} {}               
{ESPACO}+ {}

"//".*$ {}

{DIGITO}+{ID} {printf ("Identificador inválido na linha %d\n", yylineno); erros++;}

[\"][^\"]*[\"] {return (STRING);}
