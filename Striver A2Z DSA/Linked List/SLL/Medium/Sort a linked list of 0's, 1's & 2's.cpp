/*
Problem statement : Given a linked list of N nodes where nodes can contain values 0s, 1s, and 2s only. 
The task is to segregate 0s, 1s, and 2s linked list such that all zeros segregate to head side, 2s at the end of the linked list, 
and 1s in the mid of 0s and 2s.
*/

/*
Approach 1: changing the data

count no of 0's 1's and 2's in the linked list.
Change the data of the nodes and return the list.

*/

//code : 

Node* segregate(Node *head) {
        
        int cnt[3]={0,0,0};
        Node* tmp=head;
        while(tmp!=NULL) {
            cnt[tmp->data]++;
            tmp=tmp->next;
        }
        
        tmp=head;
  
        while(cnt[0]--) {
            tmp->data=0;
            tmp=tmp->next;
        }
        while(cnt[1]--) {
            tmp->data=1;
            tmp=tmp->next;
        }
        while(cnt[2]--) {
            tmp->data=2;
            tmp=tmp->next;
        }
        return head;
    }

//time complexity : O(N)
//space complexity : O(1)

/*
approach 2 : changing the pointers

create six extra pointers zerohead, onehead, twohead, zerotail, onetail, twotail and using them create three lists.
finally merge these three lists.
*/

void insert(Node* &tail, Node* curr){
    tail->next= curr;
    tail = curr;
}

Node* sortList(Node *head){
    Node* zeroHead= new Node(-1);
    Node* zeroTail = zeroHead;
    Node* oneHead= new Node(-1);
    Node* oneTail = oneHead;
    Node* twoHead= new Node(-1);
    Node* twoTail = twoHead;

    Node* curr= head;
    while(curr!=NULL){
        int val= curr->data;

        if(val==0) insert(zeroTail, curr);
        else if(val==1) insert(oneTail, curr);
        else if(val==2) insert(twoTail, curr);

        curr= curr->next;
    }
    if(oneHead -> next != NULL) {
        zeroTail -> next = oneHead -> next;
    } else {
        //1s list -> empty
        zeroTail -> next = twoHead -> next;
    }
    
    oneTail -> next = twoHead -> next;
    twoTail -> next = NULL;
    
	//setup head 
    head = zeroHead -> next;
    
    //delete dummy nodes
    delete zeroHead;
    delete oneHead;
    delete twoHead;
    
    return head;
}

//time complexity : O(N)
//space complexity : O(1)
