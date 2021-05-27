#include <bits/stdc++.h>

using namespace std;

class DoublyLinkedListNode {
    public:
        int data;
        DoublyLinkedListNode *next;
        DoublyLinkedListNode *prev;

        DoublyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
            this->prev = nullptr;
        }
};

class DoublyLinkedList {
    public:
        DoublyLinkedListNode *head;
        DoublyLinkedListNode *tail;

        DoublyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }

        void insert_node(int node_data) {
            DoublyLinkedListNode* node = new DoublyLinkedListNode(node_data);

            if (!this->head) {
                this->head = node;
            } else {
                this->tail->next = node;
                node->prev = this->tail;
            }

            this->tail = node;
        }
};

void print_doubly_linked_list(DoublyLinkedListNode* node, string sep, ofstream& fout) {
    while (node) {
        fout << node->data;

        node = node->next;

        if (node) {
            fout << sep;
        }
    }
}

void free_doubly_linked_list(DoublyLinkedListNode* node) {
    while (node) {
        DoublyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}

/* Complete the 'reverse' function below. */

DoublyLinkedListNode* reverse(DoublyLinkedListNode* head) {
    if(!head){
        return nullptr;
    }
    
    if(head->next == nullptr){
        return head;
    }
    
    if(head->next->next == nullptr){
        auto temp = head->next;
        temp->next = head;
        temp->prev = nullptr;
        
        head->prev = temp;
        head->next = nullptr;
        return temp;
    }
    
    auto next_node = head->next;
    auto new_node = next_node->next;
    DoublyLinkedListNode* left_node = nullptr;
    
    while(new_node){
        next_node->next = head;
        head->prev = next_node;
        
        head->next = left_node;
        if(left_node){
            left_node->prev = head;
        }
        
        left_node = head;
        head = next_node;
        
        next_node = new_node;
        new_node = new_node->next;
    }
    
    next_node->next = head;
    head->prev = next_node;
    next_node->prev = nullptr;  
    
    return next_node;
    

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {

	// why the llist pointer doesn't delete at the end of the loop or program?    
        DoublyLinkedList* llist = new DoublyLinkedList();

        int llist_count;
        cin >> llist_count;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        for (int i = 0; i < llist_count; i++) {
            int llist_item;
            cin >> llist_item;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            llist->insert_node(llist_item);
        }

        DoublyLinkedListNode* llist1 = reverse(llist->head);

        print_doubly_linked_list(llist1, " ", fout);
        fout << "\n";

        free_doubly_linked_list(llist1);
    }

    fout.close();

    return 0;
}

