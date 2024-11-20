/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* sortList(struct ListNode* head);
//  a = 5 -> 6 -> 9 -> NULL
//  b = 4 -> 8 -> NULL
struct ListNode* mergeSort(struct ListNode* a, struct ListNode* b) {
    a = sortList(a);
    b = sortList(b);
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* tmp = head;
    while (a || b) {
        if (a == NULL) {
            tmp->next = b;
            break;
        }
        else if (b == NULL) {
            tmp->next = a;
            break;
        }
        else if (a->val < b->val) {
            tmp->next = a;
            a = a->next;
        }
        else {
            tmp->next = b;
            b = b->next;
        }
        tmp = tmp->next;
        tmp->next = NULL;
    }
    return head->next;
}

struct ListNode* sortList(struct ListNode* head) {
    if (head == NULL) {
        return NULL;
    }
    else if (head->next == NULL) {
        return head;
    }
    // head -> ... -> prev -> slow -> ... -> NULL
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    struct ListNode* prev = NULL;
    while (fast && slow) {
        prev = slow;
        slow = slow->next;
        fast = fast->next;
        if (fast)
            fast = fast->next;
    }
    prev->next = NULL;
    return mergeSort(head, slow);
}
