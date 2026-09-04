class Solution {
public:
  
  bool isValidSudoku(vector<vector<char>>& board) {

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {

            if (board[i][j] == '.')
                continue;
            
            for (int k = i + 1; k < 9; k++)
                if (board[i][j] == board[k][j])
                    return false;

            for (int k = j + 1; k < 9; k++) 
                if (board[i][j] == board[i][k])
                    return false;
        }
    }

    for (int i = 0; i < 9; i += 3) {
        for (int j = 0; j < 9; j += 3) {


            vector<bool> seen(10, false);


            for (int r = 0; r < 3; r++) {
                for (int c = 0; c < 3; c++) {
                    char current = board[i + r][j + c];

                    if (current != '.') {
                        int digit = current - '0';


                        if (seen[digit]) {
                            return false;
                        }
                        seen[digit] = true;
                    }
                }
            }

        }
    }



    return true;

}



};