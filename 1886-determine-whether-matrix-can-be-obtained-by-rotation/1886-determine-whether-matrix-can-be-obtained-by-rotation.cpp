class Solution {
public:
    void transpose(vector<vector<int>>& mat) {

	int rows = mat.size();
	int cols = mat[0].size();

	vector<vector<int>> copy(rows, vector<int>(cols, -1));

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			copy[j][i] = mat[i][j];
		}
	}

	mat = copy;

}

void reverseRows(vector<vector<int>>& mat) {
	int rows = mat.size();
	for (int i = 0; i < rows; i++)
		reverse(mat[i].begin(), mat[i].end());
}

bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {

	int i = 4;

	while (i--) {
		if (mat == target)
			return true;


		transpose(mat);
		reverseRows(mat);
	}


		

	return false;

}

};