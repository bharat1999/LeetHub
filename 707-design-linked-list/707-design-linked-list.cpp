class node{
    public:
        int val;
        node *next;
        node(int val)
        {
            this->val = val;
            this->next = NULL;
        }
};
class MyLinkedList {
    node *head=NULL,*tail=NULL;
    int count;
public:
    MyLinkedList() {
        count =0;
    }
    
    int get(int index) {
        if(index>=count)
            return -1;
        node *tmp = head;
        for(int i=0;i<index;i++)
            tmp = tmp->next;
        return tmp->val;
    }
    
    void addAtHead(int val) {
        node *tmp = new node(val);
        if(!head)
        {
            head = tmp;
            tail = head;
        }
        else
        {
            tmp ->next = head;
            head = tmp;
        }
        count++;
    }
    
    void addAtTail(int val) {
        node *tmp = new node(val);
        if(!tail)
        {
            tail = tmp;
            head = tail;
        }
        else
        {
            tail->next = tmp;
            tail = tmp;
        }
        count++;
    }
    
    void addAtIndex(int index, int val) {
        if(index>count)
            return;
        if(index == count)
        {
            addAtTail(val);
            return;
        }
            
        if(index == 0)
        {
            addAtHead(val);
            return;
        }
        node *prev = NULL;
        node *cur = head;
        node* tmp = new node(val);
        for(int i=0;i<index;i++)
        {
            prev = cur;
            cur = cur->next;
        }
        prev->next = tmp;
        tmp->next = cur;
        count++;
    }
    
    void deleteAtIndex(int index) {
        if(index==0)
        {
            count--;
            head = head->next;
            return;
        }
        if(index == count-1)
        {
            count--;
            node *tmp = head;
            for(int i=0;i<count-1;i++)
                tmp = tmp->next;
            tmp->next = NULL;
            tail = tmp;
            return;
        }
        if(index>=count)
            return;
        node *prev = NULL;
        node *cur = head;
        for(int i=0;i<index;i++)
        {
            prev = cur;
            cur = cur->next;
        }
        cur = cur ->next;
        prev->next = cur;
        count--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */