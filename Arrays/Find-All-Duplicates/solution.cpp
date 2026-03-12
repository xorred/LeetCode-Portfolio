class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {

        // unordered_map <int, int> mpp;
        // for(int x: nums){
        //     mpp[x]++;
        // }
        // vector<int>ans;
        // for(auto it: mpp){
        //     if(it.second>=2){
        //         ans.push_back(it.first);
        //     }
        // }
        // return ans;


        vector<int>ans;
        for(int i=0; i<nums.size();i++){
            int index = abs(nums[i]) - 1;

            if(nums[index] <0){
                ans.push_back(index+1);
            }
            else{
                nums[index] = - nums[index];
            }


        }
        return ans;
     
    }
};
