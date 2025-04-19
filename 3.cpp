#include <iostream>
#include <vector>
using namespace std;
class Solution {
    public:
        int maxArea(vector<int>& height) {
            int left = 0;
            int right = height.size() - 1;
            int max_area = 0;  // 初始化最大面积为0
            
            while (left < right) {
                int h = min(height[left], height[right]);
                int current_area = (right - left) * h;
                max_area = max(max_area, current_area);  // 更新最大面积
                
                // 移动高度较小的一侧的指针
                if (height[left] < height[right]) {
                    left++;
                } else {
                    right--;
                }
            }
            
            return max_area;
        }
    };
    int main() {
        Solution s;
        vector<int> height={1,8,6,2,5,4,8,3,7};
        cout<<s.maxArea(height);
        return 0;
    }