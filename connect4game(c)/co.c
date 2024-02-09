

#include <stdio.h>

#define ROWS    6
#define COLS    7
#define FOUR    4

char scores[ROWS][COLS];
char body[] = "|---|---|---|---|---|---|---|";
int bin = 0;
char disc = 'X';

void instructions();
void score();
void test_scores();
void board();
void choose();
void fill_bin();
int check(char disc);


int main()
{
    printf("******_WELCOME TO CONNECT 4XO_*******\n\n");
   instructions();
    score();
    test_scores();
    board();

    while (1)
    {
        printf("\nPlayer %c, your turn!\n", disc);
        choose();
        printf("\n\n");
        board();
        if (check('X'))
        {
            printf("\n\nPlayer X wins!\n\n");
            break;
        }
        if (check('O'))
        {
            printf("\n\nPlayer O wins!\n\n");
            break;
        }

    }

    return 0;
}

void instructions()
{
   printf("Game instructions:\n");
   printf("-> Two players 'X' and 'O' will be competing against each other.\n");
   printf("-> The scores will be placed from the bottom of the bin.\n");
   printf("-> Each players will get their turn successively.\n");
   printf("-> Players are only allowed to choose numbers from 1 to 7.\n");
   printf("-> Players can win the game by three ways: horizontally, vertically or diagonally, with atleast 4 same score.");
}

void score()
{
    int i, j;

    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            scores[i][j] = ' ';
        }
    }
}

void test_scores()
{
    int i, j;

    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            printf("%c ", scores[i][j]);
        }
        printf("\n");
    }
}

void board()
{
    printf("%s\n", body);

    int i, j;

    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            printf("| %c ", scores[i][j]);
        }
        printf("|\n");
        printf("%s\n", body);
    }
     printf("  1   2   3   4   5   6   7  \n");
}

void choose()
{
    int c;

    while (1)
    {
        printf("\nChoose number: ");
        scanf(" %d", &c);
        switch(c)
        {
            case 1:

                bin = 0;
                break;
            case 2:

                bin = 1;
                break;
            case 3:

                bin = 2;
                break;
            case 4:

                bin = 3;
                break;
            case 5:

                bin = 4;
                break;
            case 6:

                bin = 5;
                break;
            case 7:

                bin = 6;
                break;
            default:
                printf("\nWrong number! Try again.\n\n");
                board();
        }
        if ((bin >= 0 && bin <= 6) && (scores[0][bin] == ' '))
        {
            fill_bin();
            disc = (disc == 'X') ? 'O' : 'X';
            break;
        }
    }
}

void fill_bin()
{

    int level ;

    for (level = ROWS-1; level >= 0; level--)
    {
        if (scores[level][bin] == ' ')
        {
            scores[level][bin] = disc;
            break;
        }
        
            }
}

int check(char disc)
{

    int i, j, k;
    int count;
    int ways = 4; //for rows

    for (i = 0; i < ROWS; ++i)
    {
        for (j = 0; j < ways; ++j)
        {
            count = 0;
            for (k = 0; k < FOUR; ++k)
            {
                if (scores[i][j + k] == disc) count++;
            }
            if (count == FOUR) return 1;
        }
    }



    ways = 3; //for columns

    for (j = 0; j < COLS; ++j)
    {
        for (i = 0; i < ways; ++i)
        {
            count = 0;
            for (k = 0; k < FOUR; ++k)
            {
                if (scores[i + k][j] == disc) count++;
            }
            if (count == FOUR) return 1;
        }
    }

      int ii, jj; //for diagonals
    for (i = 1; i < ROWS-1; i++)
    {
        for (j = 1; j < COLS-1; j++)
        {

            count = 0;
            for (ii = i, jj = j; (ii >= 0) || (jj >= 0); ii--, jj--)
            {
                if (scores[ii][jj] == disc)
                {
                    count++;
                    if (count == FOUR) return 1;
                }
                else
                    break;
            }
            for (ii = i+1, jj = j+1; (ii <= ROWS-1) || (jj <= COLS-1); ii++, jj++)
            {
                if (scores[ii][jj] == disc)
                {
                    count++;
                    if (count == FOUR) return 1;
                }
                else
                    break;
            }

            count = 0;
            for (ii = i, jj = j; (ii <= ROWS-1) || (jj >= 0); ii++, jj--)
            {
                if (scores[ii][jj] == disc)
                {
                    count++;
                    if (count == FOUR) return 1;
                }
                else
                    break;
            }
            for (ii = i-1, jj = j+1; (ii >= 0) || (jj <= COLS-1); ii--, j++)
            {
                if (scores[ii][jj] == disc)
                {
                    count++;
                    if (count == FOUR) return 1;
                }
                else
                    break;
            }

        }
    }

    return 0;
}




