class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int words_cnt = words.size();
        vector<int> letters_cnt(26, 0);
        for (char ch : letters) {
            ++letters_cnt[ch - 'a'];
        }
        vector<int> words_score(words_cnt, 0);
        for (int i = 0; i < words_cnt; ++i) {
            for (char ch : words[i]) {
                words_score[i] += score[ch - 'a'];
            }
        }
        int max_score = 0;
        for (int choice = 1; choice < (1 << words_cnt); ++choice) {
            int _score = 0;
            auto _letters_cnt = letters_cnt;
            bool valid = true;
            for (int i = 0; i < words_cnt; ++i) {
                if (choice & (1 << i)) {
                    for (char ch : words[i]) {
                        int idx = ch - 'a';
                        if (--_letters_cnt[idx] < 0) {
                            valid = false;
                            break;
                        }
                    }
                    if (!valid)
                        break;
                    _score += words_score[i];
                }
            }
            if (valid) {
                max_score = max(max_score, _score);
            }
        }
        return max_score;
    }
};