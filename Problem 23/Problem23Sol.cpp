class Solution {
public:
    struct compList{
        bool operator()(ListNode* a, ListNode* b){
            return a->val > b->val;
        }
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        std::priority_queue<ListNode*, std::vector<ListNode*>, compList> priority;
        for(unsigned int i = 0 ; i < lists.size() ; ++i){
            if(lists[i] != nullptr){
                priority.push(lists[i]); //a list cannot start with nullptr, priority queue will have a runtime error using a nullptr
            }
        }
        ListNode* output = new ListNode(NULL); //need something to intialize with
        if(priority.empty()){
            return nullptr;
        }
        output = priority.top();
        priority.pop();
        ListNode* curr = output;
        if(output->next != nullptr){
            priority.push(output->next);  
        }
        while(!priority.empty()){
            curr->next = priority.top();
            priority.pop();
            curr = curr->next;
            if(curr->next != NULL){
                priority.push(curr->next);  
            }
        }
        return output;
    }
};