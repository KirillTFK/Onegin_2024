#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/stat.h>

const int ver_width = 10;
const int Columns = 100;
const int Max_row = 8000;
struct  stat onegin_stat = {};

FILE *in = 0, *out = 0;


void ZOV (FILE *text, char agitation[]);
int  stupid_compare (const char* biba, const char* boba);
void stupid_sort (char *adres[], int size);
void check_open  (FILE **ptr, const char *name, const char *mode);
int  read_file   (FILE *manuscript, char compuscript[][Columns]);
void print_file  (FILE *encyclopedia, char *adres[]);
int  sep_grain_from_chaff (const char *harvest);
void litter (char *rubbish);
void copy (char* pathetic_parody, 
                  const char* unique_original, int Max_char_to_copy); //На одном тесте сработало
void read_in_array (char *arr);
void erase_evidence (char* arr,int size);
int  div_in_lines (char *adres[], char *Onegin);


int main (int argc, char* argv[])
{
    //char Huge[100000] = {};

    stat (argv[1], &onegin_stat);
    //char Onegin [Max_row][Columns] = {};
    if (argc < 3)
    {
        printf ("Не обноружины названия файлов ввода и вывода\n");
        exit (EXIT_FAILURE);
    }
    
    check_open (&in,  argv[1], "rb");
    check_open (&out, argv[2], "wb");

    int size = 0;
    char *Onegin = 0;

    Onegin = (char*) calloc (sizeof(char), onegin_stat.st_size + 1);

    if (Onegin == NULL)
    {
        printf ("Calloc не смог выделить необходимую память\n");
        exit (EXIT_FAILURE);
    }

    size = fread (Onegin, sizeof(char), (onegin_stat.st_size), in);

    char *adres[Max_row] = {};
    int am_of_lines = 0;
    am_of_lines = div_in_lines (adres, Onegin);

/*
    int i = 0;
    for (; adres[i+1] != NULL; i++)
    {
        fputs (adres[i], out);
        fprintf (out, "\n");
        
    }
    fputs (adres[i], out);
*/
    //size = read_file (in, Onegin);
    /*
    for (int c = 0; c < 3; c++)
    { 
        for (int i = 0; i < Columns; i++ )
        {
            printf ("%d", Onegin[size-1+c][i]);
        }
        printf (" ");   
    }
    */


    printf ("Прочитал файл\n");

    stupid_sort (adres, am_of_lines);

    printf ("Отсортировал файл\n"); //Реально отсортировал, вроде все правильно

/*  int i = 0;
    for (; adres[i+1] != NULL; i++)
    {
        fputs (adres[i], out);
        fprintf (out, "\n");
        
    }
    fputs (adres[i], out);
*/
    print_file  (out, adres); //Могу попробовать реализовать подругому


    fclose (in);
    fclose (out);

    free (Onegin);

    return (0);
    
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

int stupid_compare (const char* biba, const char* boba)
{
    int i = 0;
    int o = 0;
    for (; biba[i] != '\0';)
    {
        if (!(isalpha(biba[i])))
        {
            i++;
            continue;
        }

        if (!(isalpha(boba[o])))
        {
            o++;
            continue;
        }

        if (biba[i] !=  boba[o])
        {
            //printf ("Значение int i в stupid_compare: %d\n", i);
            return ( tolower(biba[i]) - tolower(boba[o]));
        }
        i++;
        o++;
    }
    
    return ( tolower(biba[i]) - tolower(boba[o]));

}

void stupid_sort (char *adres[], int size)
{
    char *intermediary = NULL;
    
    for (; size > 0; size--)
    {   
        char *challanger = NULL;
        challanger = adres[0];
        for (int i = 0; i < size; i++)
        {
            
            if (stupid_compare (adres[i], challanger) > 0)
            {
                //printf ("Зашел в if\n");
                intermediary = adres[i];
                adres[i] = challanger;
                challanger = intermediary;
            }
            //printf ("challanger: %s, intermedia: %s, Onegin[%d]:%s\n", challanger, 
                   //  intermediary, i, Onegin[i]);
        }
        if (stupid_compare (adres[size], challanger) > 0)
        {    
            adres[0] = challanger;
            intermediary = NULL;
        }

        else
        {
            adres[0] = adres[size];
            adres[size] = challanger;
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
    char buf[Columns] = {};
    int i = 0;
    int ch = 0; 
    int flag;
    for (; (ch = getc(manuscript))!= EOF; i++)
    {
            ungetc (ch, manuscript);
            fgets (buf, Columns, manuscript);
            flag = sep_grain_from_chaff (buf);

            if (flag == 0)
            {
                continue;
            }
            copy (compuscript[i], buf, Columns);
            litter (buf);
            //fputs (compuscript[i], stdout);
    }
    //while (compuscript[i-1] )
    copy (compuscript[i], "END_OF_TEXT", Columns);
    return (i - 1);
}

void print_file (FILE *encyclopedia, char *adres[])
{
    int i = 0;
    for (; adres[i+1] != NULL; i++)
    {
        fputs (adres[i], out);
        fprintf (out, "\n");
        
    }
    fputs (adres[i], out);
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

int sep_grain_from_chaff(const char *harvest)
{

    char reference[2] = {' ', ' '};
    if (*((short*)harvest) == *((short*)reference))
    {
        return (0);
    }
    
    for (int i = 0; i < ver_width; i++)
    {
        
        if (isalpha(harvest[i]))
        {
            return (1);
        }

        if (harvest[i] == '\n' || harvest[i] == '')
        {
            return (0);
        }
    }
    return (0);
}

void litter (char *dump)
{
    for (int i = 0; i < ver_width; i++ )
    {
        dump[i] = '\0';
    }
}

void copy (char* pathetic_parody,
                  const char* unique_original, int Max_char_to_copy)
{
    int count = 0;
    int i = 0;
    int sh = 0;
    int ch = 0;
    int flag = 1;


    for (; unique_original[count*8 + i*4 + sh*2 + ch] != '\0' && count*sizeof(long) + i*4 + sh*2+ ch < Max_char_to_copy  && flag != 0; )
    {   
        flag = 0;
        if ((count+1)*sizeof(long) < Max_char_to_copy )
        {
            *(((long*)pathetic_parody) + count) = *(((long*)unique_original) + count);
            //printf ("Итерация номер %d\n", count);
            count++;
            flag = 1;
        }
        
        else
        {   if ((count)*sizeof(long) + 2*sh + ch + 4*i + sizeof(int) < Max_char_to_copy )
            {
                *(((int*)pathetic_parody) + (2*count )) = *(((int*)unique_original) + (2*count));
                //printf ("Зашел в инты\n");
                i++;
                flag = 1;
            }
            if (count*sizeof(long) + 4*i + sizeof(short) + 2*sh + ch < Max_char_to_copy)
            {
                *(((short*)pathetic_parody) + 4*count + 2*i) = *(((short*)unique_original) + 4*count + 2*i);
                //printf ("Зашел в шорты\n");
                sh++;
                flag = 1;
            }
            //printf("Иду дальше\n");
            if ((count)*sizeof(long) + 4*i + 2*sh + sizeof(char) < Max_char_to_copy )
            {
                *(((char*)pathetic_parody) + 8*count + 4*i + 2*sh) = *(((char*)unique_original) + 8*count + 4*i + 2*sh);
                //printf ("Зашел в чары\n");
                ch++;
                flag = 1;
            }
            
        }
        

        
    }
    pathetic_parody[Max_char_to_copy-1] = '\0'; 

    //printf ("%d\n", count);

    erase_evidence (pathetic_parody, (count) *sizeof(long)+i*4+sh*2+ch);

/*
    printf ("Жалкая пародия:        ");
    for (int i = 0; i < Columns; i++)
    {
        printf ("%c", pathetic_parody[i]);
    }
    putchar ('\n');
    printf ("Неповторимый оригинал: ");  
    for (int i = 0; i < Columns; i++)
    {
        printf ("%c", unique_original[i]);
    }
    putchar ('\n');
    */


}

void read_in_array (char *arr)
{
    char ch = 0;
    for (int i = 0; (ch = getchar()) != '\n'; i ++ )
    {
        arr[i] = ch;
    }
}

void erase_evidence(char *arr, int size)
{
    for (int i = size; i < Columns; i++)
    {
        arr[i] = '\0';
    }
}

int div_in_lines (char *adres[], char *Onegin) // Тут я надеюсь на ненулевую массив
{
    adres[0] = Onegin;//Говорю что нет пустых строк
    int j = 1;
    for (int i = 0; Onegin[i] != '\0'; i++)
    {
        if (Onegin[i] == '\r')
        {
            Onegin[i] = '\0';
            continue;
        }

        if (Onegin[i] == '\n')
        {
            Onegin[i] = '\0';
            adres[j] = (Onegin + (++i));
            j++;
        }
    }
    return (j-2);
}
