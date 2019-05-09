#define MAX_WEIGHT 10.00
#define QTD_ITEMS 5

typedef struct I {
    char id;
    int cost;
    float weight;
    float rate;
} Item;

typedef struct B {
    float availableWeight;
    int totalCost;
    Item items[5];
    int itemCounter;
} Backpack;

Backpack initialBackpack();
void initialItems(Item items[]);
void printItems(Item items[]);
void branchAndBound(Backpack *globalBackpack, Item items[], int index, Backpack backpack, int count);
void printBackpack(Backpack backpack, int count);
