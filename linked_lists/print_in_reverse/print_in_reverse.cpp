#include <bits/stdc++.h>

using namespace std;

class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};

class SinglyLinkedList {
    public:
        SinglyLinkedListNode *head;
        SinglyLinkedListNode *tail;

        SinglyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }

        void insert_node(int node_data) {
            SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

            if (!this->head) {
                this->head = node;
            } else {
                this->tail->next = node;
            }

            this->tail = node;
        }
};

void print_singly_linked_list(SinglyLinkedListNode* node, string sep) {
    while (node) {
        cout << node->data;

        node = node->next;

        if (node) {
            cout << sep;
        }
    }
}

void free_singly_linked_list(SinglyLinkedListNode* node) {
    while (node) {
        SinglyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}

/* Complete the 'reversePrint' function below. */
void reversePrint(SinglyLinkedListNode* head) {
    if(!head){ return; }
    
    if(head->next == nullptr){
        cout << head->data;
        return;
    }
    
    if(head->next->next == nullptr){
        cout << head->next->data << "\n";
        cout << head->data;
        return;
    }
    
    // input   1 -> 2 -> 3 -> 4
    // result  4 -> 3 -> 2 -> 1
    SinglyLinkedListNode* left_node = nullptr;
    SinglyLinkedListNode* next_node = head->next; // 2
    SinglyLinkedListNode* new_node = next_node->next; // 3
    
    
    while(new_node){
        next_node->next = head; // 2 -> 1 | 3 -> 2
        head->next = left_node; // 1 -> nullptr | 2 -> 1 
        
        left_node = head; // 1 | 2
        head = next_node; // 2 | 3
        
        next_node = new_node; // 3 | 4
        new_node = new_node->next; // 4 | nulptr
    }
    
    next_node->next = head; // 4 -> 3   
    while(next_node){
        cout << next_node->data << "\n";
        next_node = next_node->next;
    }
    
    delete head;
    delete left_node;
}

int main()
{
    int tests;
    cin >> tests;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int tests_itr = 0; tests_itr < tests; tests_itr++) {
        SinglyLinkedList* llist = new SinglyLinkedList();

        int llist_count;
        cin >> llist_count;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        for (int i = 0; i < llist_count; i++) {
            int llist_item;
            cin >> llist_item;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            llist->insert_node(llist_item);
        }

        reversePrint(llist->head);
    }

    return 0;
}

