#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

FILE *in = 0;

const int Columns = 13;

void copy (char* pathetic_parody, 
                  const char* unique_original, int Max_char_to_copy); //На одном тесте сработало
void read_in_array (char *arr);
void erase_evidence (char* arr,int size);

int main (void)

{
    
    char first_str[Columns] = {};
    char second_str[Columns] = "Meow";

    read_in_array (first_str);

    copy (second_str, first_str, 13);
    

}
void copy (char* pathetic_parody,
                  const char* unique_original, int Max_char_to_copy)
{
    int count = 0;
    int i = 0;
    int sh = 0;
    int ch = 0;
    int flag = 1;


    for (; unique_original[count*sizeof(long)] != '\0' && count*sizeof(long) + i*4 + sh*2+ ch < Max_char_to_copy  && flag != 0; )
    {   
        flag = 0;
        if ((count+1)*sizeof(long) < Max_char_to_copy )
        {
            *(((long*)pathetic_parody) + count) = *(((long*)unique_original) + count);
            printf ("Итерация номер %d\n", count);
            count++;
            flag = 1;
        }
        
        else
        {   if ((count)*sizeof(long) + 2*sh + ch + 4*i + sizeof(int) < Max_char_to_copy )
            {
                *(((int*)pathetic_parody) + (2*count )) = *(((int*)unique_original) + (2*count));
                printf ("Зашел в инты\n");
                i++;
                flag = 1;
            }
            if (count*sizeof(long) + 4*i + sizeof(short) + 2*sh + ch < Max_char_to_copy)
            {
                *(((short*)pathetic_parody) + 4*count + 2*i) = *(((short*)unique_original) + 4*count + 2*i);
                printf ("Зашел в шорты\n");
                sh++;
                flag = 1;
            }
            printf("Иду дальше\n");
            if ((count)*sizeof(long) + 4*i + 2*sh + sizeof(char) < Max_char_to_copy )
            {
                *(((char*)pathetic_parody) + 8*count + 4*i + 2*sh) = *(((char*)unique_original) + 8*count + 4*i + 2*sh);
                printf ("Зашел в чары\n");
                ch++;
                flag = 1;
            }
            
        }
        

        
    }
    pathetic_parody[Max_char_to_copy-1] = '\0'; 

    printf ("%d\n", count);

    erase_evidence (pathetic_parody, (count) *sizeof(long)+i*4+sh*2+ch);


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