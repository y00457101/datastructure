#include<stdio.h>
#include<stdlib.h>

#define HASHSIZE 12
#define NULLKEY -32768

typedef struct {
    int *elem;
    int count;
} HashTable;

int m=0;

//初始化散列表
int InitHashTable(HashTable *H)
{
    int i;
    m = HASHSIZE;
    H->count = m;
    H->elem = (int*)malloc(m*sizeof(int));
    for (i = 0; i < m; i++) {
        H->elem[i]=NULLKEY;
    }
    return 1;
}

//散列函数
int Hash(int key)
{
    return key % m;
}

//插入关键字进散列表 {42, 67, 56, 16, 25, *37*, 22, 29, 15, 47, 48, *34*};
void InsertHash(HashTable *H,int key)
{
    int addr = Hash(key);
    while(H->elem[addr] != NULLKEY) {
    addr = (addr + 1) % m;
    }
    H->elem[addr] = key;
}

//查找指定元素
int SearchHash(HashTable H, int key)
{
    int addr = Hash(key);
    while (H.elem[addr] != key) {
        addr=(addr + 1) % m;
        if (H.elem[addr] == NULLKEY || addr == Hash(key)) {
            return -1;
        }
    }
    return addr;
}

int main()
{
    HashTable H;
    int i;
    int a[12] = {42, 67, 56, 16, 25, 37, 22, 29, 15, 47, 48, 34};

    InitHashTable(&H);

    for (i = 0; i < m; i++) {
        InsertHash(&H, a[i]);
    }

    printf("插入之后的哈希表为：\n");
    for (i = 0; i < m; i++) {
        printf("%d,", H.elem[i]);
    }

    int j;
    int serchKey = 34;
    j = SearchHash(H, serchKey);
    if (j != -1) {
        printf("\n搜索到 %d 的地址是：%d", serchKey, j);
    } else {
        printf("\n在哈希表中没有搜索到 %d", serchKey);
    }

    return 0;
}
