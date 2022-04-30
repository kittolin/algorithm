/*
* 名称：建立升序链表并输出
* 来源：华中科技大学复试上机题
* 链接：http://985.so/k71x
* 难度：较难
*/

#include <cstdio>
#include <queue>
#include <vector>
#include <cstdlib>

using namespace std;

struct ListNode {
    int data;
    ListNode* next;
    ListNode(): next(nullptr) {}
    ListNode(int d): data(d), next(nullptr) {}
};

struct Comparator {
    bool operator()(ListNode* x, ListNode* y) {
        return x->data < y->data;   // 值越大优先级越大，因为采用的是头插法
    }
};

// 头插法
ListNode* BuildList(int n) {
    ListNode* head = new ListNode();
    while (n --) {
        int number;
        scanf("%d", &number);
        ListNode* cur = new ListNode(number);
        cur->next = head->next;
        head->next= cur;
    }
    return head;
}

void HeapSortList(ListNode* head) {
    priority_queue<ListNode*, vector<ListNode*>, Comparator> pq;
    ListNode* cur = head->next;
    while (cur) {
        pq.push(cur);
        cur = cur->next;
    }

    head->next = nullptr;
    while (!pq.empty()) {
        cur = pq.top();
        pq.pop();
        cur->next = head->next;
        head->next = cur;
    }
}

void OutputList(ListNode* head) {
    ListNode* cur = head->next;
    while (cur) {
        printf("%d ", cur->data);
        cur = cur->next;
    }
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        ListNode* head = BuildList(n);
        HeapSortList(head);
        OutputList(head);
    }
    return 0;
}
