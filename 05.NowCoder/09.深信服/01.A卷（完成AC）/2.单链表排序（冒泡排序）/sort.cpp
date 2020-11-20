#include <stdio.h>
#include <malloc.h>

struct node {
    int val;
    struct node *next;
};

static void list_sort(struct node *head);

struct node *list_create(int arr[], int size)
{
    struct node *head = NULL;
    int i;
    for (i = size - 1; i >= 0; --i) {
        struct node *p = (struct node *)malloc(sizeof(struct node));

        p->val = arr[i];
        p->next = head;
        head = p;
    }
    return head;
}
static void list_print(struct node *head)
{
    for (; head; head = head->next) {
        printf("%d", head->val);
        if (head->next)
            printf(" ");
    }
    printf("\n");
}
static void list_free(struct node *head)
{
    struct node *next;
    while (head) {
        next = head->next;
        free(head);
        head = next;
    }
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
    struct node *head;
    int *arr = NULL;
    int size = 0;

    if (input(&arr, &size) < 0) {
        fprintf(stderr, "input error\n");
        return 0;
    }
//     printf("OK\n");
    head = list_create(arr, size);
   
    list_sort(head);
    list_print(head);
    list_free(head);
    free(arr);
    return 0;
}

static void list_sort(struct node *head)
{
    //TODO:
     if (head == NULL)//无节点 
        return;

    struct node* tail = NULL;
    while (tail != head->next)//不满足则1个节点，否则>1个节点 
    {
        struct node* cur = head ;  

        while (cur->next != tail)
        {
            if (cur->val>cur->next->val)
            {   //交换节点
            
                cur->val = (cur->val)^(cur->next->val);
                cur->next->val = (cur->val)^(cur->next->val);
				cur->val = (cur->val)^(cur->next->val);
            }  
            
            cur = cur->next;
            
        }//#end while
        
        tail = cur;//前移 
       
    }//#end 最外层 while

    
}


    
	

