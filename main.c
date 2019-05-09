#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main() {
    Backpack backpack = initialBackpack();

    //Initializing items
    Item items[QTD_ITEMS];
    initialItems(items);
    bubbleSort(items, QTD_ITEMS);
    printItems(items);

    //main algorithm
    branchAndBound(&backpack, items, 0, backpack, backpack.itemCounter);
    printBackpack(backpack, backpack.itemCounter);
    return 0;
}
