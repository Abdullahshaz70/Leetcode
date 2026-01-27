class Solution {
public:
    string addBinary(string a, string b) {

	string result;

	int aSize = a.size();
	int bSize = b.size();

	int size = max(a.size(), b.size());
	int carry = 0;

	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());

	if (aSize != size) {
		int d = abs(aSize - size);
		while (d--)
			a += "0";
	}

	if (bSize != size) {
		int d = abs(bSize - size);
		while (d--)
			b += "0";
	}

	for (int i = 0; i < size; i++) {

		int sum = (a[i] - '0') + (b[i] - '0') + carry;

		if (sum == 3) {
			carry = 1;
			result += "1";
		}
		else if (sum == 2) {
			carry = 1;
			result += "0";
		}
		else if(sum==1){
			carry = 0;
			result += "1";
		}
		else {
			carry = 0;
			result += "0";
		}

	}

    if(carry!=0)
	    result += to_string(carry);

	reverse(result.begin(), result.end());
	
	
	
	return result;

}

};