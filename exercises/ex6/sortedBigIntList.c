#include <stdio.h>
#include <string.h>
#include "/share/ex_data/ex6/bigInt.h"
#include "/share/ex_data/ex6/virtualHeap.h"
#include "/share/ex_data/ex6/genericLinkedList.h"
#include "/share/ex_data/ex6/sortedBigIntList.h"

struct ListNode_st{
    BigInt *data;
    ListNode *next;
};

struct SortedBigIntList_st
{
    int list_type;
    ListNode *head;
};

SortedBigIntList newSortedBigIntList(int listType){
    if (listType == INC){
        SortedBigIntList list = ourMalloc(sizeof(struct SortedBigIntList_st));
        if (!list) return NULL; 
        list->list_type = INC;
        list->head = NULL;
        return list;
    } 
    else if (listType == DEC)
    {
        SortedBigIntList list = ourMalloc(sizeof(struct SortedBigIntList_st));
        if (!list) return NULL;
        list->list_type = DEC;
        list->head = NULL;
        return list;
    }
    return NULL;
}






int addBigIntToSortedList(SortedBigIntList list, BigInt bigInt){
    ListNode new_node = newListNode(bigInt);
    if (!new_node) return 0;

    if (!(list->head)){
        list->head = new_node;
    } 
    else
    {
        ListNode cur = list->head;
        BigInt cur_val = cur->data;
        ListNode prev = NULL;
        BigInt prev_val = NULL;
       
        while (cur){
            // Comparing int with inserted
            int compare_res = compareBigInt(bigInt,cur_val); 
            
            // dealing with increasing
            if (list->list_type == INC){
                if (compare_res == -1 || compare_res == 0){
                    if(list->head == cur){
                        listConcat(new_node,list->head);
                        list->head = new_node;
                        return 1;
                    }
                    else
                    {
                        listNodeInsert(prev,new_node);
                        return 1;
                    }
                }
                
                prev = cur;
                cur = cur->next;
                if (!cur){
                    listConcat(prev,new_node);
                    return 1;
                }
                cur_val = cur->data;
            }

            // dealing with increasing
            else if (list->list_type == DEC)
            {
                if (compare_res == 1 || compare_res == 0){
                    if(list->head == cur){
                        listConcat(new_node,list->head);
                        return 1;
                    }
                    else
                    {
                        listNodeInsert(prev,new_node);
                        return 1;
                    }
                }
                prev = cur;
                cur = cur->next;
                if (!cur){
                    listConcat(prev,new_node);
                    return 1;
                }
                cur_val = cur->data;
            }

            // illegal list type
            else
            {
                return 0;
            } 
        }
    }
}


void printSortedBigIntList(SortedBigIntList list, int precision){
    ListNode cur = list->head;
    while (cur){
        BigInt cur_val = cur->data;
        printBigInt(cur_val,precision);
        cur = cur->next;
        printf("\n");
    }
}

void freeListAndBigIntData(ListNode head){
    if (head->next){
        freeListAndBigIntData(head->next);
    }
    freeBigInt(head->data);
    ourFree(head);
}

void freeSortedBigIntList(SortedBigIntList list){
    if (!(list->head)){
        ourFree(list);
    }
    else
    {
        freeListAndBigIntData(list->head);
        ourFree(list);
    }
}

