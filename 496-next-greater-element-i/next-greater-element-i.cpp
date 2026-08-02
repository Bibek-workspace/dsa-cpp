class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>nextGreaterElement(nums2.size(),-1);
        stack<int>st;

        for(int i=nums2.size()-1 ; i>=0; i--){
            int element = nums2[i];
            while(!st.empty() && st.top()<=element){
                st.pop();
            }
            if(!st.empty()){
                nextGreaterElement[i]=st.top();

            }
            st.push(element);
        } 

        vector<int>ans;
        for(int i =0; i<nums1.size(); i++){
            for(int j =0 ; j<nums2.size(); j++){
                if(nums1[i]==nums2[j]){
                    ans.push_back(nextGreaterElement[j]);
                    break;
                }
            }
        }
        return ans;       
    }
};