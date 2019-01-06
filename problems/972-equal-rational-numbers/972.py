from fractions import Fraction

class Solution:
    def calc(self, s):
        l = len(s) - 4
        mid = s[3:-1]
        return Fraction(int(mid), 10**l-1)

    def get_fract(self, s):
        if '(' not in s:
            return Fraction(s)
        l = s.find('(')
        p = s.find('.')
        power = l - p - 1
        a = 10 ** power
        left = s[:l]
        b = round(float(left) * a)
        x = self.calc('0.' + s[l:])
        return (x + b) / a

    def isRationalEqual(self, S, T):
        return self.get_fract(S) == self.get_fract(T)


s = Solution()
print(s.get_fract('1.001(01)'))
print(s.get_fract('1.00(10)'))

