class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n=board.size();
        for(int i=0;i<n;i++){
            unordered_set<char> st;
            for(int j=0;j<n;j++){
                char c=board[i][j];
                if(c=='.') continue;
                if(st.count(c)) return false;
                st.insert(c);
            }
        }
        for(int i=0;i<n;i++){
            unordered_set<char> st;
            for(int j=0;j<n;j++){
                char c=board[j][i];
                if(c=='.') continue;
                if(st.count(c)) return false;
                st.insert(c);
            }
        }
        for(int i=0;i<n;i+=3){
            for(int j=0;j<n;j+=3){
                if(!valid(i,j,board)) return false;
            }
        }
        return true;
    }

    bool valid(int x, int y, vector<vector<char>>& board){
        unordered_set<char> st;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                char c=board[x+i][y+j];
                if(c=='.') continue;
                if(st.count(c)) return false;
                st.insert(c);
            }
        }
        return true;
    }
};