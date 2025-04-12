// Link: https://leetcode.cn/problems/encrypt-and-decrypt-strings/
// Level: Hard
// Date: 2025-04-12

class Encrypter {
    private:
        unordered_map<char, string> enc;
        unordered_map<string, int> dec_cnt;
    public:
        Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dictionary) {
            int n = keys.size();
            for (int i = 0; i < n; ++i) {
                enc[keys[i]] = values[i];
            }

            for (const string& word: dictionary) {
                string result = encrypt(word);
                if (result != "") {
                    ++dec_cnt[result];
                }
            }
        }

        string encrypt(string word1) {
            string result;
            for (char ch : word1) {
                if (enc.count(ch)) {
                    result += enc[ch];
                } else {
                    return "";
                }
            }
            return result;
        }

        int decrypt(string word2) {
            return dec_count.count(word2) ? dec_count[word2] : 0;
        }
};

/**
 * Your Encrypter object will be instantiated and called as such:
 * Encrypter* obj = new Encrypter(keys, values, dictionary);
 * string param_1 = obj->encrypt(word1);
 * int param_2 = obj->decrypt(word2);
 */