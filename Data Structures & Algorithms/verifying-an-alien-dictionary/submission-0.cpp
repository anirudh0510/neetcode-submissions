class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {

        // Store the rank of every character
        vector<int> rank(26);

        for (int i = 0; i < 26; i++) {
            rank[order[i] - 'a'] = i;
        }

        // Compare every adjacent pair of words
        for (int i = 0; i < words.size() - 1; i++) {

            string word1 = words[i];
            string word2 = words[i + 1];

            int len = min(word1.size(), word2.size());
            bool foundDifference = false;

            for (int j = 0; j < len; j++) {

                if (word1[j] != word2[j]) {

                    // Wrong order
                    if (rank[word1[j] - 'a'] > rank[word2[j] - 'a'])
                        return false;

                    // Correct order
                    foundDifference = true;
                    break;
                }
            }

            // Prefix case
            if (!foundDifference && word1.size() > word2.size())
                return false;
        }

        return true;
    }
};