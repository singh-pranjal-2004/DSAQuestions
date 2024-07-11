class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        int rows = matrix.size(), cols = matrix[0].size(), col0 = -1;

        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;

                    if(j==0) col0 = 0;
                    else matrix[0][j] = 0;
                }
            }
        }

        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }


        for(int i = matrix.size() - 1; i > 0; i--){
            for(int j = matrix[0].size() - 1; j > 0; j--){
                if(matrix[0][j] == 0 || matrix[i][0] == 0){
                    matrix[i][j] = 0;
                }
            }
        }

        for(int i = cols-1; i >= 0; i--){
            if(matrix[0][0] == 0) matrix[0][i] = 0;
        }

        for(int i = rows-1; i >= 0; i--){
            if(col0 == 0) matrix[i][0] = 0;
        }

        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
    }
};