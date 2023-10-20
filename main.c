#include "Tokens.h"
#include <stdio.h>

#ifdef EOF
#undef EOF
#endif

#define EOF 0

extern int yylex(void);
extern char *yytext;
extern int tokenCount;
extern FILE *yyin;

char *getTokenLabel(int tokenCode);

/*Para un correcto uso, una vez compilado, se llama al ejecutable en la terminal seguido de
el nombre del archivo por ejemplo: ./main Caso_De_Prueba_Programa_de_MiniP.txt  */
int main(int argc, char *argv[])
{
    /*Esta logica es solo para que el programa pueda leer
    el contenido del archivo utilizando lel puntero propio
    que genera lex llamada "*yyin" */

    FILE *file = fopen(argv[1], "r");
    printf("El archivo a analizarse es: %s\n", argv[1]);
    if (file == NULL)
    {
        perror("Error al abrir el archivo");
        return 1;
    }

    yyin = file;
    int tokenCode;
    char *tokenName;

    tokenCode = yylex();
    tokenName = getTokenLabel(tokenCode);

    while (tokenCode != EOF)
    {
        // Para ver todos los lexemas al momento de correr el analisis de mini P,  por favor quitar el comentario del codigo siguiente:
        // if (tokenCode != 72)
        // {
        //     printf("El lexema detectado '%s' pertence al token %s\n", yytext, tokenName);
        // }
        tokenCode = yylex();
        tokenName = getTokenLabel(tokenCode);
    }

    printf("No se encontro ningun error sintactico\n");
    printf("Se detectaron un total de %d lexemas\n", tokenCount);
    fclose(file);
    return 0;
}

char *getTokenLabel(int tokenCode)
{
    switch (tokenCode)
    {
    case _ID:
        return "ID";
        break;

    case _ICONST:
        return "ICONST";
        break;

    case _RCONST:
        return "RCONST";
        break;

    case _ECONST:
        return "ECONST";
        break;

    case _LITERAL:
        return "LITERAL";
        break;
    case _COMENTARIO:
        return "COMENTARIO";
        break;
    case _LBRACK:
        return "LBRACK";
        break;

    case _RBRACK:
        return "RBRACK";
        break;

    case _LPAREN:
        return "LPAREN";
        break;

    case _RPAREN:
        return "RPAREN";
        break;

    case _SEMI:
        return "SEMI";
        break;

    case _COLON:
        return "COLON";
        break;

    case _COMMA:
        return "COMMA";
        break;

    case _ASSING:
        return "ASSING";
        break;

    case _PLUS:
        return "PLUS";
        break;

    case _MINUS:
        return "MINUS";
        break;

    case _MULT:
        return "MULT";
        break;

    case _DIVIDE:
        return "DIVIDE";
        break;

    case _EQL:
        return "EQL";
        break;

    case _LESS:
        return "LESS";
        break;

    case _GTR:
        return "GTR";
        break;

    case _LEQ:
        return "LEQ";
        break;

    case _GEQ:
        return "GEQ";
        break;

    case _NEQ:
        return "NEQ";
        break;

    case _PROGRAM:
        return "PROGRAM";
        break;

    case _ENDVARS:
        return "ENDVARS";
        break;

    case _ENDPROCS:
        return "ENDPROCS";
        break;

    case _VARS:
        return "VARS";
        break;

    case _NOVARS:
        return "NOVARS";
        break;

    case _INTEGER:
        return "INTEGER";
        break;

    case _REAL:
        return "REAL";
        break;

    case _STRING:
        return "STRING";
        break;

    case _PROCS:
        return "PROCS";
        break;

    case _BEGIN:
        return "BEGIN";
        break;

    case _PROC:
        return "PROC";
        break;

    case _END:
        return "END";
        break;

    case _FOR:
        return "FOR";
        break;

    case _TO:
        return "TO";
        break;

    case _DO:
        return "DO";
        break;

    case _IF:
        return "IF";
        break;

    case _THEN:
        return "THEN";
        break;

    case _ELSE:
        return "ELSE";
        break;

    case _READ:
        return "READ";
        break;

    case _WRITE:
        return "WRITE";
        break;

    default:
        return "false";
        break;
    }
}