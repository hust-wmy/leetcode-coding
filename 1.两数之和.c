
/*
 * @lc app=leetcode.cn id=1 lang=c
 *
 * [1] 两数之和
 */
struct node
{
    int val;
    int index;
};

int comp(const void *a, const void *b)
{
    if(((struct node*)a)->val > ((struct node*)b)->val)
    {
        return 1;
    }
    else if(((struct node*)a)->val < ((struct node*)b)->val )
    {
        return -1;
    }
    else
    {
        return 0;
    }
    
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int n = numsSize;
    int i = 0, sum = 0;
    int begin = 0, end = n-1;
    int *result = NULL;
    struct node *nodes = (struct node*)malloc(sizeof(struct node)*n);

    for (i = 0; i < n; i++)
    {
        nodes[i].val = nums[i];
        nodes[i].index = i;
    }

    qsort(nodes, n, sizeof(struct node), comp);
    
    while (begin < end)
    {
        sum = nodes[begin].val + nodes[end].val;
        if(sum == target)
        {
            result = (int*)malloc(sizeof(int)*2);
            result[0] = nodes[begin].index;
            result[1] = nodes[end].index;
            *returnSize = 2;
            free(nodes);
            return result;
        }
        else if(sum < target)
        {
            begin++;
        }
        else
        {
            end--;
        }
        
    }
    
    free(nodes);
    *returnSize = 0;
    return NULL;
}


