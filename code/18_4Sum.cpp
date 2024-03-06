#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <algorithm> // 包含 sort 算法
#include <utility>
#include <list>
#include <chrono>
#include <random>

using namespace std;

// 代码随想录参考答案
class Solution2 {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for (int k = 0; k < nums.size(); k++) {

            // 剪枝处理
            if (nums[k] > target && nums[k] >= 0) {
            	break; // 这里使用break，统一通过最后的return返回
            }

            // 对nums[k]去重
            if (k > 0 && nums[k] == nums[k - 1]) {
                continue;
            }
            for (int i = k + 1; i < nums.size(); i++) {

                // 2级剪枝处理
                if (nums[k] + nums[i] > target && nums[k] + nums[i] >= 0) {
                    break;
                }

                // 对nums[i]去重
                if (i > k + 1 && nums[i] == nums[i - 1]) {
                    continue;
                }
                int left = i + 1;
                int right = nums.size() - 1;
                while (right > left) {
                    // nums[k] + nums[i] + nums[left] + nums[right] > target 会溢出
                    if ((long) nums[k] + nums[i] + nums[left] + nums[right] > target) {
                        right--;
                    // nums[k] + nums[i] + nums[left] + nums[right] < target 会溢出
                    } else if ((long) nums[k] + nums[i] + nums[left] + nums[right]  < target) {
                        left++;
                    } else {
                        result.push_back(vector<int>{nums[k], nums[i], nums[left], nums[right]});
                        // 对nums[left]和nums[right]去重
                        while (right > left && nums[right] == nums[right - 1]) right--;
                        while (right > left && nums[left] == nums[left + 1]) left++;

                        // 找到答案时，双指针同时收缩
                        right--;
                        left++;
                    }
                }

            }
        }
        return result;
    }
};

//哈希表实现
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        // 创建结果vector
        vector<vector<int>> result;

        // ordered map: 同时排序和统计数值的出现次数，复杂度O(nlogn)
        map<int,int> num_count;
        for (int num : nums) num_count[num]++;
        vector<pair<int,int>> num_unique(num_count.begin(),num_count.end());

        // 边搜边加，相当于用哈希表替代两个夹逼的指针
        unordered_map<long, list<pair<int,int>>> hash_pair;
        for (auto iter = num_unique.begin(); iter != num_unique.end(); iter++){
            
            // 指针b在不同位置
            
            for(int i = 1; i <= iter->second; i++) {
                
                // b 只检索倒数第2和第1个位置，防止相同的(a,b)多次检索哈希表导致result重复
                if (i >= iter->second - 1){

                    // 遍历a，查找合适的pair
                    for(auto iter1 = iter; iter1 != num_unique.end(); iter1++) {
                        
                        // b 在倒数第二，a只能在倒数第一
                        // b 在倒数第一，a只能选后面的数
                        if(i == iter->second - 1 && iter1 != iter || i == iter->second && iter1 == iter) continue;
                        else {
                            // 从哈希表返回可能的匹配
                            const auto& pair_list = hash_pair[long(target) - iter1->first - iter->first];

                            // 加入result
                            for (const auto& pair : pair_list) result.push_back(vector<int>{pair.second, pair.first, iter->first, iter1->first});
                        }

                    }
                }

                // 扩充哈希表
                if(i == 1) {
                    for(auto iter_pair = num_unique.begin(); iter_pair != iter; iter_pair++){
                        hash_pair[iter->first + iter_pair->first].push_back(pair(iter->first, iter_pair->first));
                        // cout << iter->first + iter_pair->first << "," << iter->first << "," << iter_pair->first << endl;
                    }
                }
                else if (i == 2){
                    hash_pair[iter->first + iter->first].push_back(pair(iter->first, iter->first));
                }

            }

        }

        return result;
    }
};

// testing
int main() {
    // vector<int> nums = {1,0,-1,0,-2,2};
    // vector<int> nums = {1000000000,1000000000,1000000000,1000000000};
    // vector<int> nums = {91277418,66271374,38763793,4092006,11415077,60468277,1122637,72398035,-62267800,22082642,60359529,-16540633,92671879,-64462734,-55855043,-40899846,88007957,-57387813,-49552230,-96789394,18318594,-3246760,-44346548,-21370279,42493875,25185969,83216261,-70078020,-53687927,-76072023,-65863359,-61708176,-29175835,85675811,-80575807,-92211746,44755622,-23368379,23619674,-749263,-40707953,-68966953,72694581,-52328726,-78618474,40958224,-2921736,-55902268,-74278762,63342010,29076029,58781716,56045007,-67966567,-79405127,-45778231,-47167435,1586413,-58822903,-51277270,87348634,-86955956,-47418266,74884315,-36952674,-29067969,-98812826,-44893101,-22516153,-34522513,34091871,-79583480,47562301,6154068,87601405,-48859327,-2183204,17736781,31189878,-23814871,-35880166,39204002,93248899,-42067196,-49473145,-75235452,-61923200,64824322,-88505198,20903451,-80926102,56089387,-58094433,37743524,-71480010,-14975982,19473982,47085913,-90793462,-33520678,70775566,-76347995,-16091435,94700640,17183454,85735982,90399615,-86251609,-68167910,-95327478,90586275,-99524469,16999817,27815883,-88279865,53092631,75125438,44270568,-23129316,-846252,-59608044,90938699,80923976,3534451,6218186,41256179,-9165388,-11897463,92423776,-38991231,-6082654,92275443,74040861,77457712,-80549965,-42515693,69918944,-95198414,15677446,-52451179,-50111167,-23732840,39520751,-90474508,-27860023,65164540,26582346,-20183515,99018741,-2826130,-28461563,-24759460,-83828963,-1739800,71207113,26434787,52931083,-33111208,38314304,-29429107,-5567826,-5149750,9582750,85289753,75490866,-93202942,-85974081,7365682,-42953023,21825824,68329208,-87994788,3460985,18744871,-49724457,-12982362,-47800372,39958829,-95981751,-71017359,-18397211,27941418,-34699076,74174334,96928957,44328607,49293516,-39034828,5945763,-47046163,10986423,63478877,30677010,-21202664,-86235407,3164123,8956697,-9003909,-18929014,-73824245};
    
    // int target = 0;
    // int target = -294967296;
    // int target = -236727523;

    // 500  & 1000: solu:4200ms solu2:4100 ms 
    int k = 500; // 设定范围为 -k,k
    int n = 1000;  // 生成 n 个随机数

    // 固定种子为 0
    seed_seq seed{0}; 
    mt19937 gen(seed);
    uniform_int_distribution<int> dis(-k, k); // 指定整数的范围

    vector<int> randomNumbers;

    for (int i = 0; i < n; ++i) {
        int randomNumber = dis(gen);
        randomNumbers.push_back(randomNumber);
    }

    auto& nums = randomNumbers;
    int target = 0;

    // // 输出生成的随机数
    // for (int num : randomNumbers) {
    //     std::cout << num << " ";
    // }
    // std::cout << std::endl;
    
    auto start = chrono::high_resolution_clock::now();
    auto result = Solution().fourSum(nums, target);
    // auto result = Solution2().fourSum(nums, target);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end - start;
    cout << "Elapsed time: " << elapsed.count() * 1000 << " ms " << endl;

    
    // 输出结果
    // for (vector<int> num_vec : result) {
    //     for (int num : num_vec) cout << num << " " ;
    //     cout << endl;
    // }
    
}