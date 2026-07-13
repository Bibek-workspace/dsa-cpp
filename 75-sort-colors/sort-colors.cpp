class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int count1 = 0, count2 =0 , count3= 0;

        for(int i=0 ; i<n ; i++){
            if(nums[i]== 0){
                count1++;
            }
            else if(nums[i]== 1){
                    count2++;
                

            }
            else{
                count3++;
            }
        }

        int idx= 0;
        for(int i=0 ; i<count1; i++){
            nums[idx++] = 0;
        }
        for(int i=0 ; i<count2; i++){
            nums[idx ++] = 1;

        }
        for(int i=0 ; i<count3; i++){
            nums[idx ++] = 2;
        }    
    }  
};