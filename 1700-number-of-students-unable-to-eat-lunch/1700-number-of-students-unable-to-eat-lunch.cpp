class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {

	int result = 0;

	int size = students.size();

	int i = 0;

	while (i<students.size()) {


		if (students.front() == sandwiches.front()) {
			students.erase(students.begin());
			sandwiches.erase(sandwiches.begin());
			i = 0;
		}
		else {
			int n = students.front();
			students.erase(students.begin());
			students.push_back(n);
			i++;
		}
	
	}


	return students.size();
}

};