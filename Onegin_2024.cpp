#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


const int Columns = 100;
const int Max_row = 8000;
FILE *in = 0, *out = 0;


void ZOV (FILE *text, char agitation[]);
int stupid_compare (const char* first_str, const char* second_str);
void stupid_copy (char* pathetic_parody, 
                  const char* unique_original); //На одном тесте сработало

void stupid_sort (char Onegin[][Columns], int size);
void check_open  (FILE **ptr, const char *name, const char *mode);
int  read_file   (FILE *manuscript, char compuscript[][Columns]);
void print_file  (FILE *encyclopedia, char compuscript[][Columns]);




int main (int argc, char* argv[])
{
    //char Huge[100000] = {};
    char Onegin [Max_row][Columns] = {};
    if (argc < 3)
    {
        printf ("Не обноружины названия файлов ввода и вывода\n");
        exit (EXIT_FAILURE);
    }
    
    check_open (&in,  argv[1], "r");
    check_open (&out, argv[2], "w");

    int size = 0;
    size = read_file (in, Onegin);

    /*for (int c = 0; c < 3; c++)
    { 
        for (int i = 0; i < Columns; i++ )
        {
            printf ("%d", Onegin[size-1+c][i]);
        }
        printf (" ");   
    }
    */

    printf ("Прочитал файл\n");

    stupid_sort (Onegin, size);

    printf ("Отсортировал файл\n");
    print_file  (out, Onegin);
    
}

void stupid_copy (char* pathetic_parody,
                  const char* unique_original)
{
    int count = 0;
    for (; unique_original[count] != '\0'; 
         count++ )
    {
        pathetic_parody[count] = unique_original[count];
    }
    for (; count < Columns; count++)
    {
        pathetic_parody[count] = '\0';
    }
}

int stupid_compare (const char* first_str, const char* second_str)
{
    int i = 0;
    for (;second_str[i] == first_str[i] && first_str[i] != '\0';i++)
    {
        continue;
    }
    //printf ("Значение int i в stupid_compare: %d\n", i);
    return ( first_str[i] - second_str[i]); 

}

void stupid_sort (char Onegin[][Columns], int size)
{
    char intermediary[Columns] = {};
    
    for (; size > 0; size--)
    {   
        char challanger[Columns] = {};
        stupid_copy (challanger, Onegin[0]);
        for (int i = 0; i < size-1; i++)
        {
            
            if (stupid_compare (Onegin[i], challanger) > 0)
            {
                //printf ("Зашел в if\n");
                stupid_copy (intermediary, challanger);
                stupid_copy (challanger, Onegin[i]);
                stupid_copy (Onegin[i], intermediary);
            }
            //printf ("challanger: %s, intermedia: %s, Onegin[%d]:%s\n", challanger, 
                    //intermediary, i, Onegin[i]);
        }
        if (stupid_compare (Onegin[size-1], challanger) > 0)
        {    
            stupid_copy (Onegin[0], challanger );
        }

        else
        {
            stupid_copy (Onegin[0], Onegin[size-1]);
            stupid_copy (Onegin[size-1], challanger);
        }
    }

    
}

void check_open (FILE** ptr, const char *name, const char *mode)
{
    if ((*ptr = fopen(name, mode)) == 0)
    {
        printf ("Не удалось открыть файл\n");

        exit (EXIT_FAILURE);
    }

    return;
}

int read_file (FILE *manuscript, char compuscript[][Columns])
{
    int i = 0;
    for (;feof (manuscript) == 0; i++)
    {
            fgets (compuscript [i], Columns, manuscript);
            //fputs (compuscript[i], stdout);

    }
    stupid_copy (compuscript[i], "END_OF_TEXT");
    return (i - 1);
}

void print_file (FILE *encyclopedia, char compuscript[][Columns])
{
    const size_t length = strlen("END_OF_TEXT") + 1;
    for (int i = 0; strncmp (compuscript[i], "END_OF_TEXT", length ) != 0;i++)
    {
        fputs (compuscript[i], encyclopedia);
    }
}

void ZOV (FILE *text, char agitation[])
{
    int ch = 0;
    int i = 0;

    for (; (ch = getc(text)) != EOF;)
    {
        
        if ( ch == 'Z' || ch == 'z' || ch == 'O' || ch == 'o' || ch == 'V'
            || ch == 'v' || ch == '\n' || ch == ' ')
        {
            agitation[i] = ch;
            i++;    
        }
        //printf ("%c\n", ch);

    }
}