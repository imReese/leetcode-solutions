# Link: https://leetcode.cn/problems/encrypt-and-decrypt-strings/
# Level: Hard
# Date: 2025-04-12

class Encrypter:

    def __init__(self, keys: List[str], values: List[str], dictionary: List[str]):
        self.enc = {key : value for key, value in zip(keys, values)}
        self.dec_cnt = Counter()
        for word in dictionary:
            # := python3.8 新加的语法 用于在表达式中赋值
            # 此处用于将self.encrypt(word)的结果赋值于result并将result与""比较
            if (result := self.encrypt(word)) != "":
                self.dec_cnt[result] += 1

    def encrypt(self, word1: str) -> str:
        result = list()
        for ch in word1:
            if ch in self.enc:
                result.append(self.enc[ch])
            else:
                return ""
        return "".join(result)

    def decrypt(self, word2: str) -> int:
        return self.dec_cnt[word2] if word2 in self.dec_cnt else 0



# Your Encrypter object will be instantiated and called as such:
# obj = Encrypter(keys, values, dictionary)
# param_1 = obj.encrypt(word1)
# param_2 = obj.decrypt(word2)