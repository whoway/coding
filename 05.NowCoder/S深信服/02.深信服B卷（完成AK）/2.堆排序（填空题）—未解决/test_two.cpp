#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
static void heap_arrange(int arr[], int cur, int cnt);

static int heap_verify(int arr[], int cnt)
{
    int i;
    for (i = 0; i < cnt / 2; ++i) {
        int lhs = 2 * i + 1;
        int rhs = 2 * i + 2;
        
        if (lhs < cnt && arr[i] > arr[lhs]) {
            fprintf(stderr, "arr[%d]:%d > arr[%d]:%d\n", i, arr[i], lhs, arr[lhs]);
            return -1;
        }
        if (rhs < cnt && arr[i] > arr[rhs]) {
            fprintf(stderr, "arr[%d]:%d > arr[%d]:%d\n", i, arr[i], rhs, arr[rhs]);
            return -1;
        }
    }
    return 0;
}

static void heap_print(int arr[], int cnt)
{
    int layer = 0, num = 0;
    for (layer = 0; num < cnt; ++layer) {
        int i = 0;
        for (i = 0 ; i < (1 << layer) && num < cnt ; ++i)
            printf("%3d ", arr[num++]);
        printf("\n");
    }
}
static void heap_sort(int arr[], int cnt)
{
    int i;

    printf("origin:\n");
    heap_print(arr, cnt);
    //  建堆
    for (i = cnt / 2 - 1; i >= 0; --i) {
        heap_arrange(arr, i, cnt);
    }
    printf("make heap:\n", i);
    heap_print(arr, cnt);
    assert(heap_verify(arr, cnt) == 0);
    for (i = cnt - 1; i > 0; --i) {
        int tmp;
        tmp = arr[0];
        arr[0] = arr[i];
        arr[i] = tmp;
        printf("sort i=%d\n", i);
        heap_print(arr, cnt);
        heap_arrange(arr, 0, i);
        heap_print(arr, cnt);
        assert(heap_verify(arr, i) == 0);
    }
    printf("sorted:\n");
    heap_print(arr, cnt);
}
static int input(int **arr, int *size)
{
    int i;
    int ret;

    ret = fscanf(stdin, "%d\n", size);
    if (ret != 1)
        return -1;
    *arr = (int *)malloc(sizeof(int) * (*size));
    for (i = 0; i < *size; ++i) {
        fscanf(stdin, "%d ", &(*arr)[i]);
    }
    return 0;
}

int main(int argc, char *argv[])
{
    int *arr = NULL;
    int cnt = 0;
    int i;

    if (input(&arr, &cnt) < 0) {
        fprintf(stderr, "input error\n");
        return 0;
    }
    heap_sort(arr, cnt);
    return 0;
}
//  调整为小顶堆
static void heap_arrange(int arr[], int cur, int cnt)  //调整为小顶堆
{
    int heaptop_val = arr[cur]; //堆顶的值
    while (cur < cnt) {
        int left = 2 * cur + 1;
        int right = 2 * cur + 2;
        int min = -1;
        int min_val = heaptop_val;
        if (left < cnt && arr[left] < min_val) { //检查是否比左节点大
            min = left;
            min_val = arr[left];
        }
        if (right < cnt && arr[right] < min_val) {//检查是否比右节点大
            min = right;
        }
        if (min == -1)
            break;
        arr[cur] = arr[min];
        cur = min;
    }
    arr[cur] = heaptop_val;
}
