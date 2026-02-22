class Solution {
public:
       void func(string c, int n , vector<string>& ss , int open , int closed ) {

        if (c.size() == 2 * n) {
            ss.push_back(c);
            return;
        }
     
        if (open < n)
            func(c + "(", n, ss, open + 1, closed);
        if(closed < open)
            func(c + ")", n, ss, open , closed + 1);


    }

    vector<string> generateParenthesis(int n) {

        int open = 0;
        int closed = 0;
        vector<string> ss;

        func("", n, ss, open, closed);
        return ss;
    }
};