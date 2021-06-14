#include <stdio.h>
#include <stdlib.h>




typedef struct stack {
  char *array;
  int top;
} Array;

void initArray(Array *a, int initialSize){                      //to initialize stack
    a->array = (char*)malloc(initialSize * sizeof(char));
    a->top = 0;
}

void insertArray (Array *a, char elem){                         //to insert an element
    a->array[a->top] = elem;
    a->top++;
}

void deleteArray(Array *a){                                     //to delete an element
    a->top--;
    a->array[a->top] = NULL;
}






int main(int argc, char *argv[])
{
Array a;
int len;
char c;
    FILE *finput;
    finput = fopen(argv[1] , "r");                                                     //argv[1] - input.txt


    while((c = fgetc(finput)) != EOF )  {
         if (c == ')' || c == ']' || c =='}' || c == '(' || c == '[' || c =='{')
        len++;
    };

initArray(&a, len);

fseek( finput , 0 , SEEK_SET );

while((c = fgetc(finput)) != EOF )  {
    if (c == '(' || c == '[' || c =='{')
    insertArray (&a, c);

    if (c == ')' && a.array[a.top-1] != '(') {
        insertArray (&a, c);
        break;
    }
    if (c == ']' && a.array[a.top-1] != '['){
        insertArray (&a, c);
        break;
    }
    if (c == '}' && a.array[a.top-1] != '{'){
        insertArray (&a, c);
        break;
    }

    if (c == '"' && a.array[a.top-1] != '"'){
        insertArray (&a, c);
      while  ((c = fgetc(finput)) != '"' )
            fseek(finput , 0.5 , SEEK_CUR );
    };

    if (c == '"' && a.array[a.top-1] == '"'){
        deleteArray(&a);
    };

    if (c == ')' && a.array[a.top-1] == '(')
        deleteArray(&a);
    if (c == ']' && a.array[a.top-1] == '[')
        deleteArray(&a);
    if (c == '}' && a.array[a.top-1] == '{')
        deleteArray(&a);

    };

if (a.array[0] != NULL)
    printf("ERROR\n");

if (a.array[0] == NULL)
    printf("OK\n");

fclose(finput);

    return 0;
}
