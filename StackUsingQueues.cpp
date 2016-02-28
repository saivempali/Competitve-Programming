class Stack {
public:
    // Push element x onto stack.
    queue<int> q1,q2;
    void push(int x) {
        
        q1.push(x);
       
    }

    // Removes the element on top of the stack.
    void pop() {
        
        if(q1.size() == 1)
        {
            q1.pop();
        }
        else{
            while(q1.size() != 1)
            {
                q2.push(q1.front());
                q1.pop();
            }
        
            q1.pop();
        
            while(!q2.empty())
            {
                q1.push(q2.front());
                q2.pop();
            }
        }
        
    }

    // Get the top element.
    int top() {
        
        
         while(q1.size() != 1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        
        int x = q1.front();
        q2.push(q1.front());
        q1.pop();
        
        while(!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
        return x;
    }

    // Return whether the stack is empty.
    bool empty() {
        
        if(q1.empty())
            return true;
            
        return false;
    
    }
};