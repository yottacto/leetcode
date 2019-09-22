#include <string>
#include <stack>

struct Solution
{

    bool is_left(char ch)
    {
        return ch == '('
            || ch == '['
            || ch == '{';
    }

    bool is_right(char ch)
    {
        return ch == ')'
            || ch == ']'
            || ch == '}';
    }

    bool match(char l, char r)
    {
        return (l == '(' && r == ')')
            || (l == '[' && r == ']')
            || (l == '{' && r == '}');
    }

    bool isValid(std::string s)
    {
        std::stack<char> st;
        for (auto ch : s) {
            if (is_left(ch)) {
                st.emplace(ch);
            } else {
                if (st.empty() || !match(st.top(), ch))
                    return false;
                st.pop();
            }
        }
        return true;
    }
};

