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

void print_singly_linked_list(SinglyLinkedListNode* node, string sep, ofstream& fout) {
    while (node) {
        fout << node->data;

        node = node->next;

        if (node) {
            fout << sep;
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



// Complete the compare_lists function below.
bool compare_lists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    if(!head1 && !head2){
	return 1;
    }

    if(!head1 && head2){
	free_singly_linked_list(head2);
	return 0;
    }

     if(head1 && !head2){
	free_singly_linked_list(head1);
	return 0;
    }


    auto tmp1 = head1, tmp2 = head2;
    int count1 = 0, count2 = 0;
    
    while(tmp1){ count1++; tmp1 = tmp1->next;}
    while(tmp2){ count2++; tmp2 = tmp2->next;}

    if(count1 != count2){
	free_singly_linked_list(head1);
	free_singly_linked_list(head2);
	return 0;
    }

    bool is_same = true;
    while(head1){
        if(head1->data != head2->data){
	    is_same = false;
	    break;
	}
        head1 = head1->next;
        head2 = head2->next;
    }

    free_singly_linked_list(head1);
    free_singly_linked_list(head2);

    if(is_same){
	return 1;
    }else{
	return 0;
    }
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int tests;
    cin >> tests;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int tests_itr = 0; tests_itr < tests; tests_itr++) {

	// why is the llist1 pointer not deleted at the end of the program?
        SinglyLinkedList* llist1 = new SinglyLinkedList();

        int llist1_count;
        cin >> llist1_count;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        for (int i = 0; i < llist1_count; i++) {
            int llist1_item;
            cin >> llist1_item;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            llist1->insert_node(llist1_item);
        }
    
	// why is the llist2 pointer not deleted at the end of the program?
      	SinglyLinkedList* llist2 = new SinglyLinkedList();

        int llist2_count;
        cin >> llist2_count;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        for (int i = 0; i < llist2_count; i++) {
            int llist2_item;
            cin >> llist2_item;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            llist2->insert_node(llist2_item);
        }

        bool result = compare_lists(llist1->head, llist2->head);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

