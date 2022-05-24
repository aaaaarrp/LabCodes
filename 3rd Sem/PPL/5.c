//GRAMMAR
// <ifstmt> -> if (<boolexpr>) <statement>[else <statement>]
//<boolexpr> -> IDENTIFIER ( > | < ) (INT_LIT | IDENTIFIER)
// <assign_stmt> -> IDENTIFIER = <expr>
//  <expr> -> <term> {(+ | -) <term>}
//  <term> -> <factor> {(* | /) <factor>)}
// <factor> -> IDENTIFIER | INT_LIT | ( <expr >)

#include "stdio.h"
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int TYPE_OF_CHAR;
char LEXEME[200];
char NEXT_CHARACTER = ' ';
int LEXEME_LENGTH;
int NEXT_TOKEN_CODE;
FILE *fp;

void ADD_CHAR_TO_LEXEME();
void DEFINE_CHAR_TYPE();
void GET_NON_EMPTY_CHAR();
int LEX();

#define LETR 0
#define DGT 1
#define INT 2
#define IDENTTFIER 3
#define ASSIGN 4
#define ADD 5
#define SUB 6
#define MULT 7
#define DIV 8
#define LEFTPAREN 9
#define RIGHTPAREN 10
#define UNKNOWN 11
#define eof 12
#define SEMICOLON 13
#define KEYWORD 14
#define IF_CODE 15
#define ELSE_CODE 16
#define GREATERTHAN 17
#define LESSTHAN 18
#define RELATIONAL 19

char WORD[21][20] = {"LETTER", "DIGIT", "INT_LIT", "IDENT", "ASSIGN_OP", "ADD_OP",
                     "SUB_OP", "MULT_OP", "DIV_OP", "LEFT_PAREN", "RIGHT_PAREN", "UNKNOWN", "EOF", "SEMICOLON",
                     "KEYWORD", "IF_CODE", "ELSE_CODE", "GREATERTHAN", "LESSTHAN", "RELATIONAL"};

char keywords[32][10] = {"auto", "break", "case", "char", "const", "continue", "default",
                         "do", "double", "else", "enum", "extern", "float", "for", "goto",
                         "if", "int", "long", "register", "return", "short", "signed",
                         "sizeof", "static", "struct", "switch", "typedef", "union",
                         "unsigned", "void", "volatile", "while"};

int main()
{
    printf("\n");
    void ifstmt();
    if ((fp = fopen("input5.txt", "r")) == NULL)
        printf("ERROR - CANNOT OPEN THE FILE \n");
    else
    {

        LEX();
        ifstmt();
        printf("\n\n");
    }
}

int CHECK_OPERATOR(char ch)
{
    switch (ch)
    {
    case '(':
        ADD_CHAR_TO_LEXEME();
        NEXT_TOKEN_CODE = LEFTPAREN;
        break;
    case ')':
        ADD_CHAR_TO_LEXEME();
        NEXT_TOKEN_CODE = RIGHTPAREN;
        break;
    case '+':
        ADD_CHAR_TO_LEXEME();
        NEXT_TOKEN_CODE = ADD;
        break;
    case '-':
        ADD_CHAR_TO_LEXEME();
        NEXT_TOKEN_CODE = SUB;
        break;
    case '*':
        ADD_CHAR_TO_LEXEME();
        NEXT_TOKEN_CODE = MULT;
        break;
    case '/':
        ADD_CHAR_TO_LEXEME();
        NEXT_TOKEN_CODE = DIV;
        break;
    case '=':
        ADD_CHAR_TO_LEXEME();
        NEXT_TOKEN_CODE = ASSIGN;
        break;
    case ';':
        ADD_CHAR_TO_LEXEME();
        NEXT_TOKEN_CODE = SEMICOLON;
        break;

    default:
        ADD_CHAR_TO_LEXEME();
        NEXT_TOKEN_CODE = eof;
        break;
    }
    return NEXT_TOKEN_CODE;
}

void boolexpr()
{

    printf("Enter boolexpr\n");
    LEX();
    if (NEXT_TOKEN_CODE == IDENTTFIER)
    {
        LEX();
        int t = NEXT_TOKEN_CODE;
        if (t == GREATERTHAN || t == LESSTHAN)
        {
            LEX();
            if (NEXT_TOKEN_CODE == IDENTTFIER || NEXT_TOKEN_CODE == INT)
                LEX();
            else
                printf("Error in boolexpr1");
        }
        else
            printf("Error in boolexpr2");
    }
    else
        printf("Error in boolexpr3");
    printf("Exit boolexpr\n");
}

void ADD_CHAR_TO_LEXEME()
{
    LEXEME[LEXEME_LENGTH] = NEXT_CHARACTER;
    LEXEME_LENGTH++;
    LEXEME[LEXEME_LENGTH] = '\0';
}

void expr()

{
    printf("Enter <expr>\n");
    void term();
    term();

    while (NEXT_TOKEN_CODE == ADD || NEXT_TOKEN_CODE == SUB)
    {
        LEX();
        term();
    }
    printf("Exit <expr>\n");
}

void factor()
{
    printf("Enter <factor>\n");
    if (NEXT_TOKEN_CODE == IDENTTFIER || NEXT_TOKEN_CODE == INT)
    {
        LEX();
    }

    else
    {

        if (NEXT_TOKEN_CODE == LEFTPAREN)
        {
            LEX();
            expr();
        }
        else if (NEXT_TOKEN_CODE == RIGHTPAREN)
            LEX();
        else
            printf("Error in fact\n");
    }
    printf("Exit <factor>\n");
}

void term()
{
    printf("Enter <term>\n");
    void factor();
    factor();

    while (NEXT_TOKEN_CODE == MULT || NEXT_TOKEN_CODE == DIV)
    {
        LEX();
        factor();
    }
    printf("Exit <term>\n");
}

void assignStmt()
{

    printf("Enter assignStmt\n");
    LEX();
    if (NEXT_TOKEN_CODE != IDENTTFIER)
        printf("Error in assignStmt\n");
    else
    {
        LEX();
        if (NEXT_TOKEN_CODE != ASSIGN)
            printf("Error in assignStmt\n");
        else
        {
            LEX();
            expr();
            if (NEXT_TOKEN_CODE != SEMICOLON)
                printf("Missing Semicolon\n");
        }
    }
    printf("Exit Statement\n");
}

void ifstmt()
{
    if (NEXT_TOKEN_CODE != IF_CODE)
        printf("Error in ifstmt1\n");
    else
    {
        LEX();
        if (NEXT_TOKEN_CODE != LEFTPAREN)
            printf("Error in ifstmt2\n");
        else
        {
            boolexpr();
            if (NEXT_TOKEN_CODE != RIGHTPAREN)
                printf("Error in ifstmt3\n");
            else
            {
                assignStmt();
                LEX();
                if (NEXT_TOKEN_CODE == ELSE_CODE)
                {
                    assignStmt();
                }
                else
                    printf("No Else part");
            }
        }
    }
}

void DEFINE_CHAR_TYPE()
{

    if ((NEXT_CHARACTER = fgetc(fp)) != EOF)
    {
        if (isalpha(NEXT_CHARACTER))
            TYPE_OF_CHAR = LETR;
        else if (NEXT_CHARACTER == '<' || NEXT_CHARACTER == '>')
            TYPE_OF_CHAR = RELATIONAL;
        else if (isdigit(NEXT_CHARACTER))
            TYPE_OF_CHAR = DGT;

        else
            TYPE_OF_CHAR = UNKNOWN;
    }

    else
        TYPE_OF_CHAR = eof;
}

void GET_NON_EMPTY_CHAR()
{
    while (isspace(NEXT_CHARACTER))
        DEFINE_CHAR_TYPE();
}

int LEX()
{
    LEXEME_LENGTH = 0;
    GET_NON_EMPTY_CHAR();
    switch (TYPE_OF_CHAR)
    {
    case LETR:
        ADD_CHAR_TO_LEXEME();
        DEFINE_CHAR_TYPE();
        while (TYPE_OF_CHAR == LETR || TYPE_OF_CHAR == DGT)
        {
            ADD_CHAR_TO_LEXEME();
            DEFINE_CHAR_TYPE();
        }
        for (int i = 0; i < 32; i++)
            if (strcmp(LEXEME, "if") == 0)
                NEXT_TOKEN_CODE = IF_CODE;
            else if (strcmp(LEXEME, "else") == 0)
                NEXT_TOKEN_CODE = ELSE_CODE;
            else
                NEXT_TOKEN_CODE = IDENTTFIER;

        break;
    case RELATIONAL:
        ADD_CHAR_TO_LEXEME();
        DEFINE_CHAR_TYPE();
        for (int i = 0; i < 32; i++)
            if (strcmp(LEXEME, "<") == 0)
                NEXT_TOKEN_CODE = LESSTHAN;
            else if (strcmp(LEXEME, ">") == 0)
                NEXT_TOKEN_CODE = GREATERTHAN;
        break;

    case DGT:
        ADD_CHAR_TO_LEXEME();
        DEFINE_CHAR_TYPE();
        while (TYPE_OF_CHAR == DGT)
        {
            ADD_CHAR_TO_LEXEME();
            DEFINE_CHAR_TYPE();
        }
        NEXT_TOKEN_CODE = INT;
        break;

    case UNKNOWN:
        CHECK_OPERATOR(NEXT_CHARACTER);
        DEFINE_CHAR_TYPE();
        break;

    case eof:
        NEXT_TOKEN_CODE = eof;
        LEXEME[0] = 'E';
        LEXEME[1] = 'O';
        LEXEME[2] = 'F';
        LEXEME[3] = '\0';
        break;
    }
    printf("Token: %s,\t Lexeme: %s \n",
           WORD[NEXT_TOKEN_CODE], LEXEME);
    return NEXT_TOKEN_CODE;
}