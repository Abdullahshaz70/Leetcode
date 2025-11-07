#include<iostream>
#include<stack>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>


using namespace std;

string removeDuplicates(string s) {
    
    if(s.empty())
        return "";

    string result;

    stack<char> st;

    
    for(int i = 0 ; i < s.size() ; i++){


        if(st.empty()){
            st.push(s[i]);
            continue;
        }

        else if(st.top() == s[i]){
            st.pop();

        }
        else
            st.push(s[i]);

    }

    while(!st.empty()){
        result+=st.top();
        st.pop();
    }
    
    reverse(result.begin() , result.end());
    return result;
}

int main(){

    string s = "abbaca";

    s = removeDuplicates(s);
    
    cout<<"The string will be: "<<s<<endl;




    return 0;

} 


