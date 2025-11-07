#include<iostream>
#include<stack>
#include<cstring>
#include<string>
#include<vector>


using namespace std;

int calPoints(vector<string>& operations) {
    
    stack<int> s;
    int sum = 0;

    for(int i = 0 ; i < operations.size() ; i++){

        if(operations[i] == "C")
            s.pop();
        
        else if(operations[i]=="D"){
            int n = s.top();
            s.push(n*2);
        }
        else if( operations[i]=="+") {
            if(s.size() > 1){
                stack<int> temp = s;
                int a = temp.top();temp.pop();
                int b = temp.top();temp.pop();
                s.push(a+b);
            }

        }
        else{
                s.push(stoi(operations[i]));
            }

    }

    while(!s.empty()){
        int n = s.top();
        sum+=n;
        s.pop();
    }

    return sum;
}

int main(){

    // vector<string> operations = {"5","2","C","D","+"};
    // vector<string> operations = {"5","-2","4","C","D","9","+","+"};
    vector<string> operations = {"1","C"};

    cout<<"The sum will be: "<<calPoints(operations)<<endl;




    return 0;

} 


