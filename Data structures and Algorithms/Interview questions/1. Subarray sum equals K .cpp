/*
    Link : https://leetcode.com/problems/subarray-sum-equals-k/

    Naive Approach : 
        For all index check how many subarrays are possible with given sum:

        O(N^2) Time And 
        int subarraySum(vector<int>& arr, int k) {
            int n = arr.size();
            int ans = 0;
            for(int i = 0; i < n; i++){
                int sum = arr[i];
                if(sum == k){
                    ans++;
                }
                for(int j = i + 1; j < n; j++) {
                    sum += arr[j];
                    if(sum == k){
                        ans++;
                    }
                }
            }
        }

    
    Efficient Approach : 
        While traversing store all preSums in a map and check if currentSum-k value is present or not.
        If current sum till now is 15 , k is 8 and we had a preSum of 7 it means that there is a subarray
        with given sum. So we will add all previous calculated counts and store in a result.*/

        int subarraySum(vector<int>& nums, int k) {
            unordered_map<int,int>mp;
            int sum = 0;
            int count=0;
            for(int i = 0;i<nums.size();i++){
                sum+=nums[i];
                if(sum==k){
                    count++;
                }
                if(mp.find(sum-k)!=mp.end()){
                    count+=mp[sum-k];
                }
                mp[sum]+=1;
            }
            return count;
        }







