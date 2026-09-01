class Solution {
    
    int operate(int a, int b, string token) {
        
        if(token == "+") {
            return a + b;
        }
        
        if(token == "-") {
            return a - b;
        }
        
        if(token == "*") {
            return a * b;
        }
        
        if(token == "/") {
            return a / b;
        }
        
        return 0;
    }
    
public:
    int evalRPN(vector<string>& tokens) {
        
        stack<int> st;
        
        for(int i = 0; i < tokens.size(); i++) {
            
            if(tokens[i] == "+" || tokens[i] == "-" ||
               tokens[i] == "*" || tokens[i] == "/") {
                
                int b = st.top();
                st.pop();
                
                int a = st.top();
                st.pop();
                
                int result = operate(a, b, tokens[i]);
                
                st.push(result);
            }
            
            else {
                st.push(stoi(tokens[i]));
            }
        }
        
        return st.top();
    }
};