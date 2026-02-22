class Solution {
public:
    void Generate01StringsHelper(string c, int n , vector<string>& ss ) {

        if (c.size() == n) {
            ss.push_back(c);
            return;
        }

        
        Generate01StringsHelper(c + "1", n, ss);

        
        if (c.empty() || c.back() != '0')
            Generate01StringsHelper(c + "0", n, ss);

    }

    vector<string> validStrings(int n) {

        vector<string> rr;
        int i = 0;
        Generate01StringsHelper("",n, rr);

        return rr;
    }


};