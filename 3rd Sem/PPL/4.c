#include <stdio.h>
#include <ctype.h>
/* Global declarations */
/* Variables */
int charClass;
char lexeme[100];
char nextChar;
int lexLen;
int token;
int nextToken;
FILE *in_fp, *fopen();
void addChar();
void getChar();
void getNonBlank();
int lex();
void term();
void error();
/* Character classes */
#define LETTER 0
#define DIGIT 1
#define UNKNOWN 99
/* Token codes */
#define INT_LIT 10
#define IDENT 11
#define ASSIGN_OP 20
#define ADD_OP 21
#define SUB_OP 22
#define MULT_OP 23
#define DIV_OP 24
#define LEFT_PAREN 25
#define RIGHT_PAREN 26


void expr()
{
    printf("Enter <expr>\n");
    /* Parse the first term */
    term();
    /* As long as the next token is + or -, get
 the next token and parse the next term */
    while (nextToken == ADD_OP || nextToken == SUB_OP)
    {
        lex();
        term();
    }
    printf("Exit <expr>\n");
}

void factor()
{
    printf("Enter <factor>\n");
    /* Determine which RHS */
    if (nextToken == IDENT || nextToken == INT_LIT)
        lex();
    /* If the RHS is ( <expr>), call lex to pass over the
 left parenthesis, call expr, and check for the right
 parenthesis */
    else
    {
        if (nextToken == LEFT_PAREN)
        {
            lex();
            expr();
            if (nextToken == RIGHT_PAREN)
                lex();
            else
                error();
        } /* End of if (nextToken == ... */
          /* It was not an id, an integer literal, or a left
 parenthesis */
        else
            error();
    } /* End of else */
    printf("Exit <factor>\n");
    ;
}

void term()
{
    printf("Enter <term>\n");
    /* Parse the first factor */
    factor();
    /* As long as the next token is * or /, get the
 next token and parse the next factor */
    while (nextToken == MULT_OP || nextToken == DIV_OP)
    {
        lex();
        factor();
    }
    printf("Exit <term>\n");
}



void error()
{
    printf("\nError");
}

/* main driver */
int main()
{
    /* Open the input data file and process its contents */
    if ((in_fp = fopen("input.txt", "r")) == NULL)
        printf("ERROR - cannot open file \n");
    else
    {
        getChar();
        do
        {
            lex();
            expr();
        } while (nextToken != EOF);
    }
}
int lookup(char ch)
{
    switch (ch)
    {
    case '(':
        addChar();
        nextToken = LEFT_PAREN;
        break;
    case ')':
        addChar();
        nextToken = RIGHT_PAREN;
        break;
    case '+':
        addChar();
        nextToken = ADD_OP;
        break;
    case '-':
        addChar();
        nextToken = SUB_OP;
        break;
    case '*':
        addChar();
        nextToken = MULT_OP;
        break;
    case '/':
        addChar();
        nextToken = DIV_OP;
        break;

    default:
        addChar();
        nextToken = EOF;
        break;
    }
    return nextToken;
}

void addChar()
{
    if (lexLen <= 98)
    {
        lexeme[lexLen++] = nextChar;
        lexeme[lexLen] = 0;
    }
    else
        printf("Error - lexeme is too long \n");
}

void getChar()
{
    if ((nextChar = getc(in_fp)) != EOF)
    {
        if (isalpha(nextChar))
            charClass = LETTER;
        else if (isdigit(nextChar))
            charClass = DIGIT;
        else
            charClass = UNKNOWN;
    }
    else
        charClass = EOF;
}

void getNonBlank()
{
    while (isspace(nextChar))
        getChar();
}

int lex()
{
    lexLen = 0;
    getNonBlank();
    switch (charClass)
    {
        /* Parse identifiers */
    case LETTER:
        addChar();
        getChar();
        while (charClass == LETTER || charClass == DIGIT)
        {
            addChar();
            getChar();
        }
        nextToken = IDENT;
        break;
        /* Parse integer literals */
    case DIGIT:
        addChar();
        getChar();
        while (charClass == DIGIT)
        {
            addChar();
            getChar();
        }
        nextToken = INT_LIT;
        break;
        /* Parentheses and operators */
    case UNKNOWN:
        lookup(nextChar);
        getChar();
        break;
        /* EOF */
    case EOF:
        nextToken = EOF;
        lexeme[0] = 'E';
        lexeme[1] = 'O';
        lexeme[2] = 'F';
        lexeme[3] = 0;
        break;
    } /* End of switch */
    printf("\n");
    printf("Next token is: %d, Next lexeme is %s\n",
           nextToken, lexeme);
    return nextToken;
}