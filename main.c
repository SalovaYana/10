#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <windows.h>
#define size 80

int main()
{
    setlocale(LC_ALL,"Rus");

    char *str, *istr, *last, *str_copy, *str_copy_2, *str_copy_3, *str_copy_4, *even_n;

    int i;

    str_copy=(char*)malloc(sizeof(char)*size);
    last=(char*)malloc(sizeof(char)*size);
    str=(char*)malloc(sizeof(char)*size);
    str_copy_2=(char*)malloc(sizeof(char)*size);
    str_copy_3=(char*)malloc(sizeof(char)*size);
    str_copy_4=(char*)malloc(sizeof(char)*size);
    even_n=(char*)malloc(sizeof(char)*size);



    printf("Please, enter the string:\n");
    printf("\n");

    FILE *f;

    f=fopen("doc.txt","w");

    fgets(str,size,stdin);
    fputs(str,f);

    fclose(f);


    f=fopen("doc.txt", "r");
    fscanf(f,"%[^\n]",str);

    strcpy(str_copy, str);
    strcpy(str_copy_2, str);
    strcpy(str_copy_3, str);
    strcpy(str_copy_4, str);
    fclose(f);
    printf("Check the results in the doc\n");


    f=fopen("doc.txt", "w");
    fclose(f);

    f=fopen("doc.txt", "a");

    fputs("\nВведенная строка:\n",f);
    fputs(str,f);
    fputs("\n",f);
    /*printf("\nСтрока без лишних пробелов:\n");*/
    fputs("\nСтрока без лишних пробелов:\n",f);

    /*printf("\n");*/

    istr=strtok(str," ");

    while (istr!= NULL)
    {
        fputs(istr, f);

        istr=strtok (NULL, " ");
        if (istr!=NULL && strcmp(".",istr)!=0)
        {
            /*printf(" ");*/
            fputs("  ",f);
        }

    }
    fputs("\n", f);
    /*printf("\n");*/

    /*printf("\nСтрока без последнего слова и слов, совпадающих с ним\n");*/

    fputs("\nСтрока без последнего слова и слов, совпадающих с ним\n", f);

    /*printf("\n");*/
    char *a=strtok(str_copy_2," .");
    while (a!=NULL)
    {
        last=a;
        a=strtok (NULL," .");
    }


    char *p=strtok(str_copy_3," .");
    int h=0;
    while (p!=NULL)
    {

        if (strcmp(p,last)!=0)
        {
            /*fprintf(stdout,"%s ",p);*/
            fputs(p,f);
            for(int i=0; i<strlen(p); i++)
            {
                str_copy_4[h]=p[i];
                h++;
            }
            str_copy_4[h]=' ';
            fputs(" ",f);
            h++;
        }
        p=strtok(NULL," .");
    }
    str_copy_4[h]='\0';

    /*printf("\n");*/

    /*printf("\nИндивидульное задание - если в слове четное кол-во букв, то посавить первую букву в середину слова: \n");


    printf("\n");*/

    int k=0;
    char *c=strtok(str_copy_4," .");
    while (c!= NULL)
    {
        char first = c[0];

        if (strlen(c)%2 == 0)
        {
            for(i=0; i<strlen(c)/2+1; i++)
            {
                even_n[k]=c[i];
                k++;
            }

            even_n[k] = first;
            k++;

            for(i=strlen(c)/2 +1; i<strlen(c); i++)
            {
                even_n[k]=c[i];
                k++;
            }

        }

        else
        {
            for(i=0; i<strlen(c); i++)
            {
                even_n[k]=c[i];
                k++;
            }
        }

        even_n[k] =' ';
        k+=1;
        c=strtok (NULL, " .");

    }

    even_n[k]='\0';

    /*fprintf(stdout,"%s",even_n);*/
    /*printf("\n");*/

    fclose(f);

    f=fopen("doc.txt", "a");

    fputs("\n",f);
    fputs("\nИндивидульное задание - если четное количество букв в слове,то поставить первую букву слова в его середину :",f);
    fputs("\n",f);
    fputs(even_n,f);

    fclose(f);


    return 0;

}

