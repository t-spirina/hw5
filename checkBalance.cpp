#include "checkBalance.h"

bool F5hw::checkBalance(int* a, int size)
{ //функция возвращает истину если в массиве есть место, в котором сумма левой и правой части массива равны
    int leftSum, rightSum, i;
    leftSum = 0;
    rightSum = 0;
    //сумма элементов расположенных справа от границы - сумма всех элементов
    //сначала граница перед нулевым элементом
    for (i=0;i<size;i++)
        rightSum+=*(a+i);
    for (i=0;i<size;i++)
    {
        //двигаю границу на 1 элемент влево
        leftSum+= *(a+i);
        rightSum -= *(a+i);
        //если баланс нашелся - выход
        if (leftSum == rightSum)
            return true;
    }
    return  false;
}
