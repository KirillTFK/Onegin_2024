#include <stdio.h>
#include <string.h>


int stupid_compare (char* first_str, char* second_str);
void stupid_copy (char* pathetic_parody, 
                  const char* unique_original); //На одном тесте сработало

void stupid_sort (char Onegin[][40]);

const int Colums = 50;//Знаю что опечатка, но это тупая версия
const int Max_row = 40;

int main ()
{
    char Onegin[Colums][Max_row] = {"My uncle, what a worthy man,",
                                    "Falling ill like that, and dying;",
                                    "It summons up respect, one can",
                                    "Admire it, as if he were trying.",
                                    "Let us all follow his example!",
                                    "But, God, what tedium to sample",
                                    "That sitting by the bed all day,",
                                    "All night, barely a foot away!",
                                    "And the hypocrisy, demeaning,",
                                    "Of cosseting one who\'s half alive;",
                                    "Puffing the pillows, you contrive",
                                    "To bring his medicine unsmiling,",
                                    "Thinking with a mournful sigh,",
                                    "“Why the devil can\'t you die?”’"
                                                            };

    
    stupid_sort (Onegin);

    for (int i = 0; i < 14; i++)
    {
        printf ("%s\n", Onegin[i]);
    }
    

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
    for (; count < 40; count++)
    {
        pathetic_parody[count] = '\0';
    }
}

int stupid_compare (char* first_str, char* second_str)
{
    int i = 0;
    for (; first_str[i] !='\0' && second_str[i] == first_str[i];i++)
    {
        continue;
    }
    //printf ("Значение int i в stupid_compare: %d\n", i);
    return ( first_str[i] - second_str[i]); 

}

void stupid_sort (char Onegin[][40])
{
    char intermediary[40] = {};
    
    for (int c = 14; c > 0; c--)
    {   
        char challanger[40] = {};
        stupid_copy (challanger, Onegin[0]);
        for (int i = 0; i < c-1; i++)
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
        if (stupid_compare (Onegin[c-1], challanger) > 0)
        {    
            stupid_copy (Onegin[0], challanger );
        }

        else
        {
            stupid_copy (Onegin[0], Onegin[c-1]);
            stupid_copy (Onegin[c-1], challanger);
        }
    }

    
}