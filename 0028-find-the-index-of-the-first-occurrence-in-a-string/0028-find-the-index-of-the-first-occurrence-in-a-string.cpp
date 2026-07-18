class Solution {
public:
   int strStr(string haystack, string needle) {

	int count ;
	for (int i = 0; i < haystack.size(); i++) {
		count=0;
		if (haystack[i] == needle[0]) {

			for (int j = 0; j < needle.size(); j++) {

                if (haystack[i + j] != needle[j])
				break;
                
				if (haystack[i + j] == needle[j])
					count++;
				
			}
		}

		if (count == needle.size())
			return i;

	}

	return -1;
}
};