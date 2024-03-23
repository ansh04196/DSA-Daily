class Solution {
public:
    stack<int> insertAtBottom(std::stack<int> S, int N) {
        std::stack<int> temp;

        // Iterate until S becomes empty
        while (!S.empty()) {
            // Push the top element of S into the stack temp
            temp.push(S.top());

            // Pop the top element of S
            S.pop();
        }

        // Push N into the stack S
        S.push(N);

        // Iterate until temp becomes empty
        while (!temp.empty()) {
            // Push the top element of temp into the stack S
            S.push(temp.top());

            // Pop the top element of temp
            temp.pop();
        }

        // Return the stack S
        return S;
    }
};
