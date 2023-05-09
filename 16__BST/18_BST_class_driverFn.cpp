#include <iostream>
using namespace std;
#include "..\15__Binary_Tree\00__Binary_Tree.h"
#include <queue>
#include "..\15__Binary_Tree\03_input.h"
#include "15_BST_class.h"

int main(){
    BST b;
    b.insert(10);
    b.insert(5);
    b.insert(20);
    b.insert(7);
    b.insert(3);
    b.insert(15);
    b.printTree();
    cout << endl;

    b.deleteData(10);
    b.deleteData(100);
    b.printTree();
return 0;
}