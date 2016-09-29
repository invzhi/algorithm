class Solution {
public:
    string intToRoman(int num) {
    	char str[20] = "";
    	char* symbol[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    	int value[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    	for (int i = 0; num; i++) {
    		while (num >= value[i]) {
    			num -= value[i];
    			strcat(str, symbol[i]);
    		}
    	}
    	return str;
    }
};