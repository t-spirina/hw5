#include "viceversa.h"

namespace F5hw {
    void viceVersa(int* a, int size)
    {//меняет 1 на 0 и наоборот
        for (int i = 0; i < size; i++)
            *(a+i)=!(*(a+i));
    }

    void  viseVersa (int number, ...)
    {// второй вариант для функции с переменым числом параметров
        va_list arr;
        va_start(arr,number);
        for (int i = 0; i < number; i++)
        *(va_arg(arr,int*))^=1;
        va_end(arr);
    }
}
