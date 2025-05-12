// Link: https://leetcode.cn/problems/remove-invalid-parentheses/
// Level: Hard
// Date: 2025-05-12

class Solution {
private:
    bool isValid(const string& s) {
        int count = 0;
        for (char c : s) {
            if (c == '(') {
                count++;
            } else if (c == ')') {
                if (count == 0) {
                    return false;
                }
                count--;
            }
        }
        return count == 0;
    }

public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        queue<string> q;
        unordered_set<string> visited;
        q.push(s);
        visited.insert(s);
        bool found = false;


        while (!q.empty()) {
            int levelSize = q.size();
            unordered_set<string> currentLevel;
            
            for (int i = 0; i < levelSize; i++) {
                string current = q.front();
                q.pop();

                if (isValid(current)) {
                    res.push_back(current);
                    found = true;
                }

                if (!found) {
                    for (int j = 0; j < current.size(); j++) {
                        if (current[j] != '(' && current[j] != ')') {
                            continue;
                        }
                        string newStr = current.substr(0, j) + current.substr(j + 1);
                        if (visited.find(newStr) == visited.end()) {
                            currentLevel.insert(newStr);
                            visited.insert(newStr);
                        }
                    }
                }
            }

            if (found) {
                break;
            }
            for (const string& str : currentLevel) {
                q.push(str);
            }
        }
        return res;
    }
};
