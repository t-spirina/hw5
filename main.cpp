#include <iostream>
#include <stdarg.h>
#include "checkBalance.h"
#include "viceversa.h"
#include "fillArr.h"
#include "offsetArr.h"

void printArr(int* a, int size);
void viceVersa(int* a, int size);   //меняет 1 на 0 и наоборот
void viseVersa (int number, ...);   // второй вариант для функции с переменым числом параметров
void fillArr(int* a, int size);     //заполнение массива для 2 задания
void offsetArr(int* a, int size, int pos); //cдвиг массива
bool checkBalance(int* a, int size); //функция возвращает истину если в массиве есть место, в котором сумма левой и правой части массива равны

int main()
{
    //1. Задать целочисленный массив, состоящий из элементов 0 и 1. Например: [ 1, 1, 0, 0, 1, 0, 1, 1, 0, 0 ].
    //Написать функцию, заменяющую в принятом массиве 0 на 1, 1 на 0 (** без применения if-else, switch, () ? :);
    const int sizeArr = 10;
    int a[sizeArr] = { 1, 1, 0, 0, 1, 0, 1, 1, 0, 0 };
    std::cout<<"1. Инверсия значений элементов массива "<<std::endl;
    printArr(a, sizeArr);
    viceVersa(a, sizeArr);
    printArr(a, sizeArr);

     //2. Задать пустой целочисленный массив размером 8. Написать функцию, которая с помощью цикла заполнит его значениями 1 4 7 10 13 16 19 22;
    const int sizeEight = 8;
    std::cout << "2. Заполнение массива " << std::endl;
    int a2[sizeEight] = {0};
    fillArr(a2, sizeEight);
    printArr(a2, sizeEight);

    //3* Написать функцию, в которую передается не пустой одномерный целочисленный массив, функция должна вернуть истину
    //если в массиве есть место, в котором сумма левой и правой части массива равны. Примеры: checkBalance([1, 1, 1, || 2, 1]) → true,
    //checkBalance ([2, 1, 1, 2, 1]) → false, checkBalance ([10, || 1, 2, 3, 4]) → true.
    //Абстрактная граница показана символами ||, эти символы в массив не входят.
    const int sizeB = 6;
    int aB[sizeB] = {1, 1, 2, 2, 1, 3};
    if (checkBalance(aB, sizeB))
        std::cout << " true " << std::endl;
    else
        std::cout << " false " << std::endl;
    //4* Написать функцию, которой на вход подаётся одномерный массив и число n (может быть положительным, или отрицательным),
    //при этом функция должна циклически сместить все элементы массива на n позиций.
    std::cout<<"4. Смещение массива"<<std::endl;
    const int sizeC = 6;
    int aC[sizeC] = {0, 1, 2, 3, 4, 5};
    printArr(aC, sizeC);
    offsetArr(aC, sizeC,2);
    printArr(aC, sizeC);

    //5** Написать функцию из первого задания так, чтобы она работала с аргументом переменной длины.
    std::cout<<"5. Инверсия значений переменного списка аргументов "<<std::endl;
    const int sizeD = 6;
    int aD[sizeD] = { 1, 1, 0, 0, 1, 0 };
    printArr(aD, sizeD);
   //наверняка можно сделать лучше и прямее
    viseVersa(sizeD, &aD[0], &aD[1], &aD[2], &aD[3], &aD[4], &aD[5]);
    printArr(aD, sizeD);


    //6** Написать все функции в отдельных файлах в одном пространстве имён, вызвать их на исполнение в основном файле программы
    //используя указатели на функции.
    std::cout << " 6 часть " << std::endl;
    const int colF = 2;
    void (*func[colF])(int* , int);
    void (*funcVv)(int, ...);
    bool (*funcBool)(int* , int);
    void (*funcOffset)(int* , int, int);
    const int arrSize = 8;
    int arrS[arrSize];

    func[0] = F5hw::fillArr;
    func[1] = F5hw::viceVersa;
    funcVv = F5hw::viseVersa;
    funcBool = F5hw::checkBalance;
    funcOffset = F5hw::offsetArr;

     (*func[0])(arrS, arrSize);
     std::cout << "заполение массива:" << std::endl;
     printArr(arrS, arrSize);

     (*funcOffset)(arrS, arrSize, 3);
     std::cout << "после сдвига на 3 влево: " << std::endl;
     printArr(arrS, arrSize);

     for (int i = 0; i < arrSize ; i++)
         arrS[i] = arrS[i] % 2;

     std::cout << "исходный  массив:" << std::endl;
     printArr(arrS, arrSize);
     (*func[1])(arrS, arrSize);
     std::cout << "инвертированный: " << std::endl;

     printArr(arrS, arrSize);
     std::cout << "для функции с переменным числом параметров: " << std::endl;
     (*funcVv)(arrSize, &arrS[0], &arrS[1], &arrS[2], &arrS[3], &arrS[4], &arrS[5], &arrS[6], &arrS[7]);
     printArr(arrS, arrSize);

     if ((*funcBool)(arrS, arrSize))
         std::cout << "checkBalance true " << std::endl;
     else
         std::cout << "checkBalance false " << std::endl;

     return 0;
}

void printArr(int* a, int size)
{//вывод массива на печать
    for (int i = 0; i < size; i++)
        std::cout <<  *(a+i) << " ";
    std::cout << std::endl;;
}

void viceVersa(int* a, int size)
{//меняет 1 на 0 и наоборот
    for (int i = 0; i < size; i++)
        *(a+i)=!(*(a+i));
}

void viseVersa (int number, ...)
{// второй вариант для функции с переменым числом параметров
    va_list arr;
    va_start(arr,number);
    for (int i = 0; i < number; i++)
    *(va_arg(arr,int*))^=1;
    va_end(arr);
}

void fillArr(int* a, int size)
{//заполнение массива для 2 задания
    for (int i = 0; i < size; i++)
        *(a+i)=1+i*3;
}

void offsetArr(int* a, int size, int pos)
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
bool checkBalance(int* a, int size)
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
