#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> threesum(vector<int>&nums){
    int n=nums.size();
    vector<vector<int>>ans;
    sort(nums.begin(),nums.end());
    for(int first=0;first<n;first++){
        if(first>1&&nums[first]==nums[first-1]){
            continue;
        }
        for(int second=first+1;second<n;second++){
            if(second>first+1&&nums[second]+nums[second-1]==0){
                continue;
            }
            int third=n-1;
            int target=-nums[first];
            while(second<third&&nums[second]+nums[third]>target){
                
                third--;
            }
            if(second==third){
                break;
            }
            if(nums[second]+nums[third]==target){
                ans.push_back({nums[first],nums[second],nums[third]});
            }
        }
    }
    return ans;
}
int main(){
    vector<int>nums={-1,0,1,2,-1,-4};
    vector<vector<int>>ans=threesum(nums);
    for(auto i:ans){
        cout<<i[0]<<" "<<i[1]<<" "<<i[2]<<endl;
    }
    return 0;
}