// Assignment A15-2
// Name: 黃士育
// Student Number: 114502540
// Course 2025-CE1003A-資工1A

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

void reverseCString(char *s)
{
   if (s == nullptr)
      return;
   char *left = s;
   char *right = s;

   // write code
   // 平移到字串結尾
   while (*right != '\0') right++;
   right--;

   // 對稱交換 往內收縮 直到相遇
   while (left < right)
   {
      // swap left character and right character
      // write code
      char temp = *left;
      *left = *right;
      *right = temp;

      left++;
      right--;
   }
}

int main()
{
   char str[100];
   while (cin.getline(str, 100))
   {
      reverseCString(str);
      cout << str << endl;
   }
   return 0;
}