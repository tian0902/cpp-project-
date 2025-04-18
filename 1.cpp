#include <iostream>
#include <unordered_set>
using namespace std;
int lengthOfLongestSubstring(string s) {
    // 定义一个哈希集合来存储当前窗口中的字符
    unordered_set<char> window;
    
    // left: 窗口的左边界索引
    // max_len: 记录找到的最大无重复子串长度
    int left = 0, max_len = 0;
    
    // 右指针right从0开始遍历整个字符串
    for (int right = 0; right < s.size(); right++) {
        
        // 当当前字符s[right]已经在窗口中存在时
        while (window.count(s[right])) {
            // 从窗口左侧开始移除字符，直到移除掉与s[right]重复的那个字符
            window.erase(s[left]);
            left++;  // 左指针右移
        }
        
        // 将当前字符加入窗口
        window.insert(s[right]);
        
        // 更新最大长度：当前窗口大小(right-left+1)与之前记录的最大值比较
        max_len = max(max_len, right - left + 1);
    }
    
    // 返回找到的最大无重复子串长度
    return max_len;
}
int main(){
    string s="pwwkew";
    cout<<lengthOfLongestSubstring(s)<<endl;
}