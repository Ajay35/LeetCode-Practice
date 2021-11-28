class Solution {
public:
    string intToRoman(int n) {
        string num = to_string(n);
        int sz = num.size();
        map<int, string> numeral;
        numeral[1] = "I";
        numeral[5] = "V";
        numeral[4] = "IV";
        numeral[10] = "X";
        numeral[9] = "IX";
        numeral[40] = "XL";
        numeral[50] = "L";
        numeral[90] = "XC";
        numeral[100] = "C";
        numeral[400] = "CD";
        numeral[500] = "D";
        numeral[900] = "CM";
        numeral[1000] = "M";
        vector<int> nums = {1,5,10,50,100,500,1000};
        vector<char> num_char = {'I','V','X','L','C','D','M'};
        string ans = "";
        for(int i = 0; i < num.size(); i++)
        {
            int place = pow(10,num.size() - i - 1) ;
            
            int digit = num[i] - '0';
            int cur_num = digit * place;
            if(digit == 4 or digit == 9)
            {
                ans += numeral[cur_num];
            }
            else
            {
                for(int i = 6; i >= 0 and cur_num > 0;)
                {
                    if(nums[i] <= cur_num)
                    {
                        ans += num_char[i];
                        cur_num -= nums[i];
                    }
                    else
                        i--;
                }
            }
        }
        return ans;
    }
};