#include <bits/stdc++.h>
using namespace std;

class MinStack {
public:
    stack<int> st;
    stack<int>minst;

    MinStack() {
        
        
    }
    
    void push(int val) {
        st.push(val);

        if(minst.empty()){
            minst.push(val);
        }
        else{
            minst.push(min(val,minst.top()));
        }
        
    }
    
    void pop() {
        st.pop();
        minst.pop();

        
    }
    
    int top() {
        int x=st.top();
        return x;
        
    }
    
    int getMin() {
        int p=minst.top();
        return p;
        
    }
};
