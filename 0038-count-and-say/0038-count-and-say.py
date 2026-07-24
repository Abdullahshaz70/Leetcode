class Solution(object):
        
            
    def count_and_tell(self , s):
        result = ""
        i = 0
        while i < len(s):
            count = 1

            while i+1 < len(s) and s[i+1] == s[i]:
                count+=1
                i+=1

            result+=str(count)
            result+=s[i]
            i+=1

        return result

    def countAndSay(self , n):

        if n==1:
            return "1"

        result = self.countAndSay(n-1)

        s = self.count_and_tell(result)

        return s


            