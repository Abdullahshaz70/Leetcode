#include<iostream>
#include<vector>
#include<stack>
using namespace std;

bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {

    stack<int> s;

    int size = pushed.size();

    int pop_index=0;

    for(int i = 0 ; i < size ; i++){

        s.push(pushed[i]);

        if(s.size() >0 && s.top() == popped[pop_index]){

            while(pop_index < popped.size() && s.size()>0 && s.top() == popped[pop_index]){
                s.pop();
                pop_index++;
            }
        }

    }

    return s.size()==0;

}

int main(){

    vector<int> pushed = {1,0};
    vector<int> popped = {1,0};
    // vector<int> popped = {4,3,5,1,2};
    // vector<int> popped = {4,3,5,1,2};
    // vector<int> popped = {4,5,3,2,1};

    if(validateStackSequences(pushed , popped))
        cout<<"Yes"<<endl;
    else
        cout<<"False"<<endl;



    return 0;
}



