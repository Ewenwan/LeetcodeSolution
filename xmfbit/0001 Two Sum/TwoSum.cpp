class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
    	vector<int> tmp(numbers);
        vector<int> res(2);
        sort(numbers.begin(), numbers.end());
        // 在numbers中找到相加和是target的两个数
        int i = 0, j = numbers.size()-1;
        while(i < j && numbers[i] + numbers[j] != target)
        {
            while(i < j && numbers[i] + numbers[j] > target)
                --j;
            while(i < j && numbers[i] + numbers[j] < target)
                ++i;
        }
        int adder1 = numbers[i];
        int adder2 = numbers[j];
        
		// 求取下标
        for(i = 0, j = 0; i < tmp.size(); ++i)
        {
        	if(tmp[i] == adder1 || tmp[i] == adder2)
        		res[j++] = i+1;
        	if(j == 2)     
        		break;
        }
        return res;
    }
};