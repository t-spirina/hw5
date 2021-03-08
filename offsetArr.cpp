#include "offsetArr.h"

void F5hw::offsetArr(int* a, int size, int pos)
{//cдвиг массива
    int tmp;
     if (pos > 0) // будет сдвиг по часовой стрелке (из начала в конец)
        while (pos!=0)
        {
            tmp=*(a); //запомнить 0 элемент
            for (int i = 0; i < size; i++)
                *(a+i)=*(a+i+1); //  сдвинуть все элементы влево
            *(a+(size-1))=tmp; //записать 0 элемент в конец
            pos--;
        }
    else
       while (pos!=0)
        { //из конца в начало
            tmp=*(a+(size-1)); //запомнить последний эменет
            for (int i =  size - 1 ; i >0; i--)
                *(a+i)= *(a+i-1); //подвинуть все вправо
            *(a)=tmp; // записать хвост в голову
            pos++;
        }
}
