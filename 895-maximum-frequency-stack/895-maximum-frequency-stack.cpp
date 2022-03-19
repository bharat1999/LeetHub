class FreqStack {
public:
    unordered_map<int,int> frequency;
    //This maps the elements which have same count
    //But the element that come last will come first of same count
    unordered_map<int,stack<int>> group_stack;
    int max_frequency=0;
    FreqStack() {
        
    }
    void push(int val) {
        //Increment the count
        frequency[val]++;
        max_frequency=max(max_frequency,frequency[val]);
        //Add element to the group of elements with same frequency
        group_stack[frequency[val]].push(val);
    }
    
    int pop() {
        //Find the max occurence element
        int top_max_frequency=group_stack[max_frequency].top();
        //Remove it from stack
        group_stack[max_frequency].pop();
        //Decrement its count
        frequency[top_max_frequency]--;
        //If there is no element left of curretn max frequency decrement max frequency
        if(group_stack[max_frequency].size()==0)
            max_frequency--;
        return top_max_frequency;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */