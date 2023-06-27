%{
    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    int yylex();
    int yyparse();

    extern FILE * yyin;
    extern int yylineno;
    int erros = 0;

    void yyerror (const char *s) {
        printf("Erro encontrado na linha %d: %s \n", yylineno, s);
        erros++;
    }

    int main(int argc, char *argv[]) {
        FILE * arq;
        
		if(argc > 0){
			arq = fopen(argv[1], "r");
		}else{
			printf("Erro ao abrir o arquivo!\n");
			exit(0);
		}
        yyin = arq;
        do {
            yyparse();
        } while (!feof(yyin));

        if (erros == 0) {
            printf("\nSucesso! Nenhum erro encontrado.\n\n");
            exit(0);
        }
        else {
            printf("\nEncontrado(s) %d erro(s).\n", erros);
            exit(1);
        }
    }
%}
/*Declaração dos tokens*/
%token INICIO_PROGRAMA
%token FIM_PROGRAMA

%token IF
%token FOR
%token DO
%token ELSE
%token ELSEIF
%token WHILE
%token RETURN

%token TIPOS_VARIAVEIS
%token NUMERO_INTEIRO
%token NUMERO_REAL

%token ID
%token OPERADORES_ARITMETICOS
%token OPERADORES_RELACIONAIS
%token OPERADORES_LOGICOS

%token PONTO_E_VIRGULA
%token VIRGULA
%token ABRE_PARENTESES
%token FECHA_PARENTESES
%token ABRE_CHAVES
%token FECHA_CHAVES
%token ATRIBUICAO
%token STRING
%token PRINT

%define parse.error verbose

%start Programa_principal

%%

/* ESTRUTURA GERAL*/
Programa_principal: INICIO_PROGRAMA comandos FIM_PROGRAMA;

/* Possíveis comandos que podem estar no arquivo teste de entrada */
comandos: decl_var comandos 
	| ID atribuicao PONTO_E_VIRGULA comandos 
	| condicional comandos 
	| loop comandos 
	| printar comandos
	| %empty;

/*Possíveis números*/
var_num: ID 
    | NUMERO_REAL 
    | NUMERO_INTEIRO;

/* Estrutura de declaração das variáveis */
decl_var: TIPOS_VARIAVEIS ID PONTO_E_VIRGULA
	| TIPOS_VARIAVEIS ID atribuicao PONTO_E_VIRGULA;

/* Estrutura de atribuição */
atribuicao: ATRIBUICAO expressao_arit 
    | ATRIBUICAO ID cont_parametros 
	| var_num;

cont_parametros: VIRGULA TIPOS_VARIAVEIS ID cont_parametros
    | VIRGULA ID cont_parametros
    | ID cont_parametros
    | %empty;

/* Regras das expressões aritméticas */
expressao_arit: arit1 arit2 ;
arit1: ABRE_PARENTESES expressao_arit FECHA_PARENTESES arit2 
     | var_num arit2;
arit2: OPERADORES_ARITMETICOS arit1 
     | %empty;

/* Regras das expressões lógicas */
expressao_logica: expressao_arit log1 ;
log1: OPERADORES_RELACIONAIS expressao_arit log2 
    | %empty;
log2: OPERADORES_LOGICOS expressao_logica 
    | %empty;

bloco_comando: ABRE_CHAVES comandos FECHA_CHAVES;

/* Estruturas condicionais: IF, ELSE */
condicional: IF ABRE_PARENTESES expressao_logica FECHA_PARENTESES bloco_comando cond2 cond1;
cond1: ELSE bloco_comando 
    | %empty;
cond2: ELSEIF bloco_comando
	| %empty;

/* Estruturas de repetição: FOR, WHILE E DO WHILE */
loop: FOR ABRE_PARENTESES decl_var expressao_logica PONTO_E_VIRGULA ID atribuicao FECHA_PARENTESES bloco_comando
    | WHILE ABRE_PARENTESES expressao_logica FECHA_PARENTESES bloco_comando;
	| DO ABRE_CHAVES expressao_logica FECHA_CHAVES WHILE ABRE_PARENTESES expressao_logica FECHA_PARENTESES bloco_comando;

printar: PRINT ABRE_PARENTESES comandos FECHA_PARENTESES PONTO_E_VIRGULA;

%%