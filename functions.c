#include "functions.h"

Backpack initialBackpack() {
    Backpack backpack;
    backpack.availableWeight = MAX_WEIGHT;
    backpack.totalCost = 0;
    backpack.itemCounter = 0;

    return backpack;
}

void initialItems(Item items[]) {
    char id[QTD_ITEMS] = {'A', 'B', 'C', 'D', 'E'};
    int cost[QTD_ITEMS] = {40, 50, 100, 95, 30};
    float weight[QTD_ITEMS] = {2, 3.14, 1.98, 5, 3};

    for(int i = 0; i < QTD_ITEMS; i++) {
        items[i].id = id[i];
        items[i].cost = cost[i];
        items[i].weight = weight[i];
        items[i].rate = weight[i] / cost[i];
    }
}

void printItems(Item items[]) {
    printLine();
    printf("\n|\t ITEMS\t\t\|\n");
    printLine();
    printf("\n| ID\t Weight\t Cost\t\|\n");
    printLine();
    for(int i = 0; i < QTD_ITEMS; i++)
        printf("\n| %c\t %.2f\t $%d\t\|", items[i].id, items[i].weight, items[i].cost);
    printf("\n");
    printLine();
    printf("\n\n");
}

void branchAndBound(Backpack *globalBackpack, Item items[], int index, Backpack backpack, int count) {
    if(index < QTD_ITEMS - 1) {
        branchAndBound(globalBackpack, items, ++index, backpack, count);

        if(backpack.availableWeight >= items[index].weight) {
            backpack.availableWeight -= items[index].weight;
            backpack.totalCost += items[index].cost;
            backpack.items[backpack.itemCounter++] = items[index];
            branchAndBound(globalBackpack, items, index, backpack, count);
        }
    }
    else if(globalBackpack -> totalCost < backpack.totalCost) {
        *globalBackpack = backpack;
    }
}

void printBackpack(Backpack backpack, int count) {
    printLine();
    printf("\n|\t BACKPACK\t\|\n");
    printLine();
    printf("\n| Item\t Weight\t Cost\t\|\n");
    printLine();
    for(int i = 0; i < count; i++)
        printf("\n| %c\t %.2f\t $%d\t\|", backpack.items[i].id, backpack.items[i].weight, backpack.items[i].cost);
    printf("\n");
    printLine();
    printf("\n| %Total\t %.2f\t $%d\t|\n", 10 - backpack.availableWeight, backpack.totalCost);
    printLine();
}

void swap(Item *xp, Item *yp) {
    Item temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(Item arr[], int n) {
   int i, j;
   for(i = 0; i < n-1; i++)

       // Last i elements are already in place
       for(j = 0; j < n-i-1; j++)
           if(arr[j].rate < arr[j+1].rate)
              swap(&arr[j], &arr[j+1]);
}

void printLine() {
    for(int i = 0; i < 25; i++)
        printf("-");
}
