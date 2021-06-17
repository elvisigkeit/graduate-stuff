#include "unionfind.hpp"
#include <vector>
#include <iostream>

void print_separators() {
    for(unsigned i=0; i<30; i++)
        cout << '-';
    cout << endl;
}

int main() {
    std::vector<int> list; 
    for (int i=0; i<5; i++) 
        list.push_back(i);

    QuickFind<int> qf(list);
    QuickUnion<int> qu(list);
    
    qf.join(2, 3);
    print_separators();
    qf.print();
    print_separators();
    
    qf.join(3, 4);
    print_separators();
    qf.print();
    print_separators();
    
    if (qf.find(2, 4))
        cout << "2 and 4 are in the same group!" << endl;
    else
        cout << "The groups of 2 and 4 are different!" << endl;
    
    qu.join(2, 3);
    print_separators();
    qu.print();
    print_separators();
    
    qu.join(3, 4);
    print_separators();
    qu.print();
    print_separators();
    

    qu.join(0, 4);
    print_separators();
    qu.print();
    print_separators();
    

    if (qu.find(2, 4))
        cout << "2 and 4 are in the same group!" << endl;
    else
        cout << "The groups of 2 and 4 are different!" << endl;

    return 0;
}