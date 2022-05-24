#include <stdio.h>
#include <ctype.h>

// Global variable declarations 
int charClass;
char lexeme[99];
char nextChar;
int lexLen;
int token;
int nextToken;
FILE *in_fp, *fopen();

// Declarations of functions
void addChar();
void getChar();
void getNonBlank();
int lex();

// Character classes declaration
#define LETTER 0
#define DIGIT 1
#define UNKNOWN 99

// Token codes declaration
#define INT_LIT 10
#define IDENT 11
#define ASSIGN_OP 20
#define ADD_OP 21
#define SUB_OP 22
#define MULT_OP 23
#define DIV_OP 24
#define LEFT_PAREN 25
#define RIGHT_PAREN 26

// main function
int main()
{
    printf("\n");
    if ((in_fp = fopen("inputLEX.in", "r")) == NULL) // Open the input file inputLEX.in 
        printf("Unable to open inputLEX.in \n");
    else
    {
        getChar();
        do
        {
            lex();
        } while (nextToken != EOF);
    }
    printf("\n");
}
// Function to lookup operators and parentheses 
int lookup(char ch)
{
    if ( ch == '(' )
    {
        addChar();
        nextToken = LEFT_PAREN;
    }
    else if ( ch == ')' )
    {
        addChar();
        nextToken = RIGHT_PAREN;
    }
    else if ( ch == '+' )
    {
        addChar();
        nextToken = ADD_OP;
    }
    else if ( ch == '-' )
    {
        addChar();
        nextToken = SUB_OP;
    }
    else if ( ch == '*' )
    {
        addChar();
        nextToken = MULT_OP;
    }
    else if ( ch == '/' )
    {
        addChar();
        nextToken = DIV_OP;
    }
    else
    {
        addChar();
        nextToken = EOF;
    }
    return nextToken;
}
// Function to add nextChar to lexeme 
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
// Function to get the next character of input 
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
// Function to call getChar until it returns a non-whitespace character
void getNonBlank()
{
    while (isspace(nextChar))
        getChar();
}
// Lexical analyzer
int lex()
{
    lexLen = 0;
    getNonBlank();
    if ( charClass == LETTER )
    {
        addChar();
        getChar();
        while (charClass == LETTER || charClass == DIGIT)
        {
            addChar();
            getChar();
        }
        nextToken = IDENT;
    }
    else if (charClass == DIGIT)
    {
        addChar();
        getChar();
        while (charClass == DIGIT)
        {
            addChar();
            getChar();
        }
        nextToken = INT_LIT;
    }
    else if (charClass == UNKNOWN)
    {
        lookup(nextChar);
        getChar();
    }
    else if (charClass == EOF)
    {
        nextToken = EOF;
        lexeme[0] = 'E';
        lexeme[1] = 'O';
        lexeme[2] = 'F';
        lexeme[3] = 0;
    }
    printf("Next token is: %d, Next lexeme is %s\n", nextToken, lexeme);
    return nextToken;
}
