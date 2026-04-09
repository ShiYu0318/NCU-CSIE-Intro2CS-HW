// Assignment A15-1
// Name: 黃士育
// Student Number: 114502540
// Course 2025-CE1003A-資工1A

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

// return true if and only if hugeInt1 == hugeInt2
bool equal(int *hugeInt1, int *hugeInt2, int size1, int size2);

// returns true if and only if hugeInt1 < hugeInt2
bool less(int *hugeInt1, int *hugeInt2, int size1, int size2);

// print HugeInt
void printHugeInt(int *hugeInt, int size);

// multiplicand *= multiplier
void multiAssign(int *&multiplicand, int *multiplier, int &multiplicandSize, int multiplierSize);

// hugeInt1 = hugeInt2; assignment
void assign(int *&hugeInt1, int *hugeInt2, int &size1, int size2);

int main()
{
   int d, t, a, b;
   while (cin >> d >> t >> a >> b && d != -1)
   {
      int *number1 = new int[1](); // d^a
      int *number2 = new int[1](); // t^b
      int number1Size = 1;
      int number2Size = 1;

      // put all digits of d into base1(d)
      // 取出每一個位數並反轉
      int *base1 = new int[10]();
      int base1Size = 0;
      for (int i = d; i > 0; i /= 10)
         base1[base1Size++] = i % 10;

      // put all digits of t into base2(t)
      int *base2 = new int[10]();
      int base2Size = 0;
      for (int i = t; i > 0; i /= 10)
         base2[base2Size++] = i % 10;

      number1[0] = 1;
      // put all digits of d^a into number1
      // Hint:for loop + multiAssign
      // write code
      for (int i = 0; i < a; i++)
         multiAssign(number1, base1, number1Size, base1Size);

      number2[0] = 1;
      // put all digits of t^b into number2
      // Hint:for loop + multiAssign
      // write code
      for (int i = 0; i < b; i++)
         multiAssign(number2, base2, number2Size, base2Size);

      printHugeInt(number1, number1Size);
      
      if (less(number1, number2, number1Size, number2Size))
         cout << "<";
      else if (equal(number1, number2, number1Size, number2Size))
         cout << "=";
      else
         cout << ">";
      printHugeInt(number2, number2Size);
      cout << endl;

      delete[] number1;
      delete[] number2;
      delete[] base1;
      delete[] base2;
   }
}

// return true if and only if hugeInt1 == hugeInt2
bool equal(int *hugeInt1, int *hugeInt2, int size1, int size2)
{
   // write code
   if (size1 != size2)  // 長度不同
      return false;
   
   // 比較每個位數
   for (int i = 0; i < size1; i++)  
      if (hugeInt1[i] != hugeInt2[i])
            return false;
   return true;
}

// returns true if and only if hugeInt1 < hugeInt2
bool less(int *hugeInt1, int *hugeInt2, int size1, int size2)
{
   // write code
   if (size1 != size2)  // 長度不同
      return size1 < size2;

   // 由高到低比較每個位數
   for (int i = size1 - 1; i >= 0; i--)
   {
      if (hugeInt1[i] < hugeInt2[i]) return true;  
      if (hugeInt1[i] > hugeInt2[i]) return false;
   }
   return false;
}

void printHugeInt(int *hugeInt, int size)
{
   // write code
   for (int i = size-1; i >= 0; i--)   // 由高到低印出數字
      cout << hugeInt[i];
}

// multiplicand *= multiplier
void multiAssign(int *&multiplicand, int *multiplier, int &multiplicandSize, int multiplierSize)
{
   int productSize = multiplicandSize + multiplierSize;
   int *product = new int[productSize]();

   // write code
   // 逐位相乘
   for (int i = 0; i < multiplicandSize; i++)
      for (int j = 0; j < multiplierSize; j++)
         product[i + j] += multiplicand[i] * multiplier[j];

   // 處理進位
   for (int k = 0; k < productSize - 1; k++)
   {
      if (product[k] >= 10)
      {
         product[k + 1] += product[k] / 10;
         product[k] %= 10;
      }
   }

   // 刪掉前綴 0
   while (productSize > 1 && product[productSize - 1] == 0)
      productSize--;

   if (productSize > 1 && product[productSize - 1] == 0)
      cout << "product has a leading zero!\n";

   assign(multiplicand, product, multiplicandSize, productSize); // multiplicand = product

   delete[] product;
}

// hugeInt1 = hugeInt2; assignment
void assign(int *&hugeInt1, int *hugeInt2, int &size1, int size2)
{
   // write code
   delete[] hugeInt1;
   hugeInt1 = new int[size2];
   for (int i = 0; i < size2; i++)
      hugeInt1[i] = hugeInt2[i];
   size1 = size2;
}