class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord)) return 0;

        queue<string> q;
        q.push(beginWord);

        unordered_map<string, bool> visited;
        visited[beginWord] = true;

        int level = 1;

        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                string word = q.front();
                q.pop();

                if (word == endWord) return level;

                for (int i = 0; i < word.size(); i++) {
                    char original = word[i];
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == original) continue;
                        word[i] = c;

                        if (dict.count(word) && !visited[word]) {
                            visited[word] = true;
                            q.push(word);
                        }
                    }
                    word[i] = original;
                }
            }
            level++;
        }
        return 0;
    }
};
