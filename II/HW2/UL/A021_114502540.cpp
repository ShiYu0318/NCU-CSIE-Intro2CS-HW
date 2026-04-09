#include <iostream>
#include <stdlib.h>
using namespace std;
class IntegerSet
{
    bool arr[100];
    public:

//  Default constructor to initialize set
    IntegerSet()
    {
        for(int i=0; i<100; ++i) arr[i] = false;
    }

//  Method to set values of a set
    void setValues(int val[], int size)
    {
        for(int i=0; i<size; ++i) arr[val[i]] = true;
    }

//  Method to implement union between two sets
    IntegerSet unionOfSets(IntegerSet s)
    {
        IntegerSet ss;
        for(int i=0; i<100; ++i)
        {
            if(arr[i] || s.arr[i]) ss.arr[i] = true;
        }
        return ss;
    }

//  Method to implement intersection between two sets
    IntegerSet intersectionOfSets(IntegerSet s)
    {
        IntegerSet ss;
        for(int i=0; i<100; ++i)
        {
            if(arr[i] && s.arr[i]) ss.arr[i] = true;
        }
        return ss;
    }

//  Method to insert element in set
    void insertElement(int k)
    {
        arr[k] = true;
    }

//  Method to print set values
    void printSet()
    {
        for(int i=0; i<100; ++i)
        {
            if(arr[i]) cout << i << " \n"[i == 99];
        }
    }
};
int main()
{
    int a1[30], a2[30];
    int i;
    IntegerSet s1, s2, s3, s4;

// Initialize two sets a1 and a2
    for (int i = 0; i < 20; i++) {
        cin >> a1[i];
    }
    s1.setValues(a1, 20);

    for (int i = 0; i < 20; i++) {
        cin >> a2[i];
    }
    s2.setValues(a2, 20);

    s1.insertElement(2);
    s2.insertElement(2);

    s3 = s1.unionOfSets(s2);
    s4 = s1.intersectionOfSets(s2);

    cout << "After insert element in s1: " << endl;
    s1.printSet();
    cout << endl;
    cout << "After insert element in s2: " << endl;
    s2.printSet();
    cout << endl;
    cout << "union of s1 s2: " << endl;
    s3.printSet();
    cout << endl;
    cout << "intersection of s1 s2: " << endl;
    s4.printSet();
    cout << endl;

    return 0;
}
