#include <stdio.h>
#include <malloc.h>
#define SIZE 10
#define T char
#define SiZe 1000
#define true 1 == 1
#define false 1 != 1

typedef int boolean;
int cursor = -1;
T Stack[SiZe];

boolean pushStack(T data){
    if(cursor<SiZe){
        Stack[++cursor] = data;
        return true;
    } else{
        printf("%s \n", "Stack overflow");
        return false;
    }
}

T popStack(){
    if(cursor != -1){
        return Stack[cursor--];
    }else{
        printf("%s \n", "Stack is empty");
        return -1;
    }
}

void ToBin(int n) {
    while(n >= 1){
        pushStack(n % 2);
        n /= 2;
    }
}

typedef struct{
    int pri;
    int dat;
} Node;

Node* arr[SIZE];
int head;
int tail;
int items;

void init (){
    for (int i = 0;i < SIZE; ++i){
        arr[i]= NULL;
    }
    head =0;
    tail =0;
    items =0;
}

void ins(int pri,int dat){
    Node *node = (Node*) malloc(sizeof(Node));
    node ->dat = dat;
    node ->pri = pri;
    int flagvst;

    if (items ==0){
        arr[tail++] = node;
        items++;
    }else if (items == SIZE){
        printf("%s \n","Queue is full");
    }else {
        int i = 0;
        int ind = 0;
        Node *tmp;
        for (i = head; i < tail; ++i){
            ind = i % SIZE;
            if (arr[ind] ->pri > pri)
                break;
            else
                ind++;
        }
        flagvst =ind % SIZE;
        i++;
        while(i<=tail){
            ind= i % SIZE;
            tmp=arr[ind];
            arr[ind]=arr[flagvst];
            arr[flagvst]=tmp;
            i++;
        }
        arr[flagvst]=node;
        items++;
        tail++;
    }
}

Node* rem(){
    if (items==0){
        return NULL;
    } else{
        int ind = head++ % SIZE;
        Node *tmp = arr[ind];
        arr[ind]=NULL;
        items--;
        return tmp;
    }
}

void printQueue(){
    printf("[ ");
    for (int i = 0; i < SIZE; ++i) {
        if (arr[i] ==NULL)
            printf("[*, *] ");
        else
            printf("[%d, %d] ",arr[i]->pri, arr[i]->dat);
    }
    printf(" ]\n");
}

int main() {
    //lesens9
    init();
    ins(7,175);
    ins(10,17);
    ins(9,75);
    ins(6,15);
    ins(5,5);
    ins(1,11);
    ins(8,7);
    ins(3,1);
    ins(4,2);
    ins(2,145);
    printQueue();
    for(int i=0;i < 6;++i){
        Node* n= rem();
        printf("pri=%d,dat=%d \n", n -> pri, n -> dat);
    }
    ins(3,145);
    ins(2,15);
    ins(2,15);
    printQueue();

// lesens10
// wariant1
int n;
printf("Enter integer\n");
scanf("%d",&n);
while(n)
{
    printf("%d",n%2);
    n=n/2;
}
printf("\n");
// wariant2
printf("16: ");
ToBin(16);
int count = cursor;
    for (int i = 0; i <= count; ++i) {
        printf("%d", popStack());
    }

printf("\n7: ");
ToBin(7);
count = cursor;
    for (int i = 0; i <= count; ++i) {
        printf("%d", popStack());
    }
    return 0;
}
