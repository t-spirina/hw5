#include "fillArr.h"

void F5hw::fillArr(int* a, int size)
{//заполнение массива для 2 задания
    for (int i = 0; i < size; i++)
        *(a+i)=1+i*3;
}
