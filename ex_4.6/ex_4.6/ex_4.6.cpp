#include <iostream>
#include "List.h"




int main()
{
    List lst1;

    List lst2;

    lst1.push_back(1);
    lst1.push_back(2);
    lst1.push_back(90);
    lst1.push_back(45);
    lst2.push_back(3);
    lst2.push_back(4);
    lst2.push_back(1000);
    lst2.push_back(80);
    lst1.PrintFromHead();
    lst1.output("main.txt");
    lst2.input("hello.txt");
    lst2.PrintFromHead();
    lst1.sort_Head_to_tail();
    lst1.PrintFromHead();
    lst1.sort_Tail_to_head();
    lst1.PrintFromHead();
    return 0;
}

