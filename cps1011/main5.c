#include <stdio.h>

void view_stack_frame(int array[], size_t length)
{
    printf("Value:\tAddress:\n");
    for(int i = 0; i < length; i++)
    {
        printf("%d\t%p\n", array[i], &array[i]);
    }
}

int main(){

    int numbers[] = {36, 864, 42, 619, 583};
    size_t numbersSize = sizeof(numbers)/sizeof(int);
    view_stack_frame(numbers, numbersSize);

    return 0;
}