//counting number of nodes

int countNodes(Node* head){
    Node* temp = head;
    int count = 0;
    while(temp != nullptr){
     count++;
     temp = temp->next;
    }
    return count;
}

//finding position of an element
int findPosition(Node* head, int key) {
 Node* temp = head;
 int position = 1;
 while(temp != nullptr){
  if(temp -> data == key){
    return position;
  }
  temp = temp -> next;
  position++;
 }
 return -1;
}

//find lastnode value

int getLastNode(Node* head) {
if (head == nullptr) {
return -1;
}
Node* temp = head;
while (temp->next != nullptr) {
  temp = temp->next;
}
return temp->data;
}

//reverse a linked list
Node* Reverselist (Node* head){
  Node* prev = nullptr;
  Node* curr = head;
  Node* next = nullptr;

  while(curr != nullptr){
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  return prev;
}

//middle of a linked list problem

Node* findMiddle(Node* head) {
Node* slow = head;
Node* fast = head;
while(fast != nullptr && fast->next != nullptr){
  slow = slow -> next;
  fast = fast -> next -> next;
}
return slow;
}

//does it have a cycle in the linkedlist

bool hasCycle(Node* head) {
    Node* slow = head;
    Node* fast = head;
    while (fast != nullptr && fast-> next != nullptr) {
        slow = slow -> next;
        fast = fast -> next -> next;
        if(slow == fast){
          return true;
        }
    }
    return false;
}

//detect where cycle starts 

ListNode* detectCycle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    // Phase 1: Detect the cycle
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            // Phase 2: Find cycle starting point
            slow = head;

            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }

            return slow;
        }
    }

    return nullptr;
}

//remove a cycle 
void removeCycle(ListNode* head) {
    ListNode* entry = detectCycle(head);
    if (entry == nullptr) return;
    ListNode* temp = entry;
    while (temp->next != entry) {
    temp = temp->next;
    }
    temp->next = nullptr;
}


//merging two sorted linkedlist

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;

        ListNode* temp1 = list1;
        ListNode* temp2 = list2;
        
        while(temp1 != nullptr && temp2 != nullptr){
            if(temp1 -> val < temp2->val){
                tail->next = temp1;
                temp1 = temp1 -> next;
            }
            else{
                tail->next = temp2;
                temp2 = temp2 -> next;
            }
            tail = tail->next;
        }
        tail->next = (temp1 != nullptr) ? temp1 : temp2;

        ListNode* newHead = dummy -> next;
        delete dummy;

        return newHead;
    }
};


//remove nth node from end

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* slow = dummy;
        ListNode* fast = dummy;

        // Move fast ahead by n + 1 steps
        for (int i = 0; i <= n; i++) {
            fast = fast->next;
        }

        // Move both pointers together
        while (fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }

        // Delete the target node
        ListNode* delNode = slow->next;
        slow->next = slow->next->next;
        delete delNode;

        ListNode* newHead = dummy->next;
        delete dummy;

        return newHead;
    }
};