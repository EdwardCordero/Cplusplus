#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include "..\HelperFunctions\helperfunctions.h"
#include "..\DataStructures\linkedList.h"
#include "..\DataStructures\binaryTree.h"

using namespace std;

#pragma region Day1Signatures
vector<int> twoSum(vector<int>& nums, int target);
void runTwoSums();

bool containsDuplicate(vector<int>& nums);
void runContainsDuplicate();

bool isAnagram(string s, string t);
void runIsAnagram();
#pragma endregion

#pragma region Day2Signatures
vector<int> recap_twoSum(vector<int>& nums, int target);
vector<int> intersection(vector<int>& nums1, vector<int>& nums2);
void runIntersect();
vector<int> topKFrequent(vector<int>& nums, int k);
void runTopKFrequent();
vector<int> productExceptSelf(vector<int>& nums);
void runProductExceptSelf();
#pragma endregion

#pragma region Day3Signatures
void runRecapTopKFrequent();
vector<int> recap_topKFrequent(vector<int>& nums, int k);
void runIsPalidrome();
bool isPalindrome(string s);
void runTowSumV2();
vector<int> twoSumV2(vector<int>& numbers, int target);
void runMaxArea();
int maxArea(vector<int>& height);
#pragma endregion

#pragma region Day4Signatures
int recap_maxArea(vector<int>& height);
bool recap_isPalindrome(string s);
void runMaxProfit();
int maxProfit(vector<int>& prices);
void runLengthOfLongestSubstring();
int lengthOfLongestSubstring(string s);
void runFindMaxAverage();
double findMaxAverage(vector<int>& nums, int k);
#pragma endregion

#pragma region Day5Signatures
int recap_lengthOfLongestSubstring(string s);
bool isValidParentheses(string s);
// MinStack Class in functions below
int evalRPN(vector<string>& tokens);
#pragma endregion

#pragma region Day6Signatures
bool recap_isValidParentheses(string s);
Node<int>* reverseList(Node<int>* head);
Node<int>* mergeTwoLists(Node<int>* head1, Node<int>* head2);
bool hasCycle(Node<int>* head);
#pragma endregion

#pragma region Day7Signatures
Node<int>* recap_reverseList(Node<int>* head);
Node<int>* middleNode(Node<int>* head);
Node<int>* removeNthFromEnd(Node<int>* head, int n);
bool isPalindrome(Node<char>* head);
#pragma endregion

#pragma region Day8Signatures
Node<int>* recap_removeNthFromEnd(Node<int>* head, int n);
int search(vector<int>& nums, int target);
int searchInsert(vector<int>& nums, int target);
int search_rotated(vector<int>& nums, int target);
#pragma endregion

int main(int argsc, char** argsv)
{
    vector<int> nums = {1,3,5,6};
    int target = 5;
    searchInsert(nums, target);
}

#pragma region Day1Functions
#pragma region Two Sums
void runTwoSums()
{
    vector<int> nums = {1, 2, 3, 4};
    int target = 7;
    vector<int> is = twoSum(nums, target);

    for(int i = 0; i < is.size(); i++)
    {
        cout << "index: " << is[i] << endl;
    }
    cout << "Sums to target: " << target << endl;
}

vector<int> twoSum(vector<int>& nums, int target)
{
    unordered_map<int, int> map; // value -> index

    for(int i = 0; i < nums.size(); i++)
    {
        int num = nums[i];
        int complement = target - num;

        if(map.count(complement))
        {
            return { map[complement], i };
        }
        map[num] = i;
    }
    return {};
}
#pragma endregion

#pragma region Contains Duplicate
void runContainsDuplicate()
{
    vector<int> nums = {1, 2, 3, 4, 8, 5, 6};
    bool result = containsDuplicate(nums);

    if(result)
    {
        cout << "Found duplicate" << endl;
    }
    else{
        cout << "No duplicate found" << endl;
    }
}

bool containsDuplicate(vector<int>& nums)
{
    unordered_set<int> set;
    for(int i = 0; i < nums.size(); i++)
    {
        int num = nums[i];
        if(set.count(num))
        {
            return true;
        }

        set.emplace(num);
    }

    return false;
}
#pragma endregion

#pragma region Valid Anagram
void runIsAnagram()
{
    std::string s = "Cinema";
    std::string t = "Icemasn";
    if(isAnagram(s, t))
    {
        cout << s << " & " << t << " are anagrams" << endl; 
    }
    else{
        cout << s << " & " << t << " are NOT anagrams" << endl; 
    }
}
bool isAnagram(string s, string t)
{
    if(s.size() != t.size())
    {
        return false;
    }

    unordered_map<char, int> map;

    for(int i = 0; i < s.size(); i++)
    {
        char c = s[i];
        map[(char)std::tolower(c)] += 1;
    }

    for(int i = 0; i < t.size(); i++)
    {
        char c = t[i];
        map[(char)std::tolower(c)] -= 1;
        if(map[(char)std::tolower(c)] < 0)
        {
            return false;
        }
    }

    return true;
}
#pragma endregion
#pragma endregion

#pragma region Day2Functions
#pragma region recap_twoSum
vector<int> recap_twoSum(vector<int>& nums, int target)
{
    unordered_map<int, int> map;
    for(int i = 0; i < nums.size(); i++)
    {
        int num = nums[i];
        int complement = target - num;
        if(map.count(complement))
        {
            return { map[complement], i };
        }
        map[num] = i;
    }
    return {};
}
#pragma endregion
#pragma region intersection
void runIntersect()
{
    vector<int> nums1 = {1,2,3,4,5,6,10};
    vector<int> nums2 = {1,4,10,11,23,2,3};
    vector<int> intersect = intersection(nums1, nums2);

    cout << "Unique nums: " << endl;
    for(int i : intersect)
    {
        cout << i << ", ";
    }
    cout << endl;
}
vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
{
    vector<int> intersect;
    unordered_set<int> seen(nums1.begin(), nums1.end());
    for(int i = 0; i < nums2.size(); i++)
    {
        if(seen.count(nums2[i]))
        {
            intersect.push_back(nums2[i]);
            seen.erase(nums2[i]);
        }
    }
    return intersect;
}
#pragma endregion
#pragma region topKFrequent
void runTopKFrequent()
{
    vector<int> nums = {1,1,1,2,2,3};
    int k = 2;
    vector<int> results = topKFrequent(nums, k);
    for(int i : results)
    {
        cout << i << endl;
    }
}
vector<int> topKFrequent(vector<int>& nums, int k)
{
    // key = num, val = count
    unordered_map<int, int> leaderboard;
    for(int num : nums)
    {
        leaderboard[num] += 1;
    }
    vector<vector<int>> bucket(nums.size() + 1);
    vector<int> results;
    for(auto& pair : leaderboard)
    {
        int num = pair.first;
        int count = pair.second;
        bucket[count].push_back(num);
    }

    for(int count = bucket.size() - 1; count >= 0 && results.size() < k; count--)
    {
        for(int nums : bucket[count])
        {
            results.push_back(nums);
            if(results.size() == k)
            {
                return results;
            }
        }
    }

    return results;
}
#pragma endregion
#pragma region productExceptSelf
void runProductExceptSelf()
{
    vector<int> nums = {1, 10, 15, 5, 2};
    vector<int> results = productExceptSelf(nums);
}
vector<int> productExceptSelf(vector<int>& nums)
{
    vector<int> results(nums.size(), 1);

    int prefix = 1;
    for(int i = 0; i < nums.size(); i++)
    {
        results[i] = prefix;
        prefix *= nums[i];
    }
    int sufix = 1;
    for(int i = nums.size() - 1; i >= 0; i--)
    {
        results[i] *= sufix;
        sufix *= nums[i];
    }

    return results;
}
#pragma endregion
#pragma endregion

#pragma region Day3Functions
#pragma region recap_topKFrequent
void runRecapTopKFrequent()
{

}
vector<int> recap_topKFrequent(vector<int>& nums, int k)
{
    vector<int> results;
    unordered_map<int, int> leaderboard;
    vector<vector<int>> bucket(nums.size() + 1);
    for(int num : nums)
    {
        leaderboard[num] += 1;
    }

    for(auto& pair : leaderboard)
    {
        int num = pair.first;
        int count = pair.second;
        bucket[count].push_back(num);
    }

    for(int i = bucket.size() - 1; i >= 0 && results.size() < k; i--)
    {
        for(auto& n: bucket[i])
        {
            results.push_back(n);
            if(results.size() == k)
            {
                return results;
            }
        }
    }

    return results;
}
#pragma endregion

#pragma region isPalindrome
void runIsPalidrome()
{
    isPalindrome("ababa");
}
bool isPalindrome(string s)
{
    int left = 0;
    int right = s.size() - 1;

    while (left < right)
    {
        // skip non-alphanumeric
        while (left < right && !isalnum(s[left]))
            left++;

        while (left < right && !isalnum(s[right]))
            right--;

        // compare lowercase
        if (tolower(s[left]) != tolower(s[right]))
            return false;

        left++;
        right--;
    }

    return true;
}
#pragma endregion

#pragma region twoSumV2
void runTowSumV2()
{

}
// Arry is sorted now
vector<int> twoSumV2(vector<int>& numbers, int target)
{
    int n = numbers.size();
    if(n < 2)
    {
        return {};
    }

    int endptr = n - 1;
    int startptr = 0;
    while(startptr < endptr)
    {
        int sum = numbers[startptr] + numbers[endptr];

        if(sum == target)
        {
            return {startptr, endptr};
        }

        // Need to decrease endptr
        if(sum > target)
        {
            endptr--;
        }
        // else need to increase startptr since we need the value to increase
        else{
            startptr++;
        }
    }

    return {};
}
#pragma endregion

#pragma region maxArea
void runMaxArea();
int maxArea(vector<int>& heights)
{
    int startptr = 0;
    int endptr = heights.size() - 1;
    int maxArea = 0;
    while(startptr < endptr)
    {
        int leftVal = heights[startptr];
        int rightVal = heights[endptr];
        int height = min(leftVal, rightVal);
        int width = endptr - startptr;
        int area = width * height;

        maxArea = max(maxArea, area);

        if(leftVal < rightVal)
        {
            startptr++;
        }
        else{
            endptr--;
        }
    }

    return maxArea;
}   
#pragma endregion

#pragma endregion

#pragma region Day4Functions
int recap_maxArea(vector<int>& heights)
{
    int maxArea = 0;
    int n = heights.size() - 1;
    int startPtr = 0;
    int endPtr = n;

    while(startPtr < endPtr)
    {
        int height = min(heights[startPtr], heights[endPtr]);
        int width = endPtr - startPtr;
        int area = width * height;
        maxArea = max(maxArea, area);

        if(heights[startPtr] < heights[endPtr])
        {
            startPtr++;
        }
        else{
            endPtr--;
        }
    }

    return maxArea;
}
bool recap_isPalindrome(string s)
{
    int startPtr = 0;
    int endPtr = s.size() - 1;

    while(startPtr < endPtr)
    {
        while(!isalnum(s[startPtr]) && startPtr < endPtr)
        {
            startPtr++;
        }
        while(!isalnum(s[endPtr]) && endPtr > startPtr)
        {
            endPtr--;
        }

        if(tolower(s[startPtr]) != tolower(s[endPtr]))
        {
            return false;
        }
        startPtr++;
        endPtr--;
    }

    return true;
}

void runMaxProfit()
{

}
int maxProfit(vector<int>& prices)
{
    int minIndex = 0;
    int maxProfit = 0;

    for(int sellIn = 1; sellIn < prices.size(); sellIn++)
    {
        int profit = prices[sellIn] - prices[minIndex];
        maxProfit = max(maxProfit, profit);
        if(prices[sellIn] < prices[minIndex])
        {
            minIndex = sellIn;
        }
    }

    return maxProfit;
}

void runLengthOfLongestSubstring()
{

}
int lengthOfLongestSubstring(string s)
{
    unordered_set<char> maxUniqueStr;
    int left = 0;
    int maxLength = 0;
    for(int right = 0; right < s.size(); right++)
    {
        char newChar = s[right];
        while(maxUniqueStr.count(newChar))
        {
            maxUniqueStr.erase(s[left]);
            left++;
        }
        maxUniqueStr.insert(newChar);
        maxLength = max(int(maxUniqueStr.size()), maxLength);
    }

    return maxLength;
}

void runFindMaxAverage()
{

}
double findMaxAverage(vector<int>& nums, int k)
{
    int sum = 0;
    for(int i = 0; i < k; i++)
    {
        sum += nums[i];
    }
    int maxSum = sum;

    for(int right = k; right < nums.size(); right++)
    {
        sum += nums[right];
        sum -= nums[right - k];

        maxSum = max(maxSum, sum);
    }

    return (double) maxSum/k;
}
#pragma endregion

#pragma region QuickRecapWeek1
// vector<int> twoSum(vector<int>& nums, int target)
// {
//     unordered_map<int, int> seen;
//     for(int i = 0; i < nums.size(); i++)
//     {
//         int num = nums[i];
//         int comp = target - num;
//         if(seen.count(comp))
//         {
//             return {seen[comp], i};
//         }
//         seen[num] = i;
//     }

//     return {};
// }

// bool isAnagram(string s, string t)
// {
//     if(s.size() != t.size()) return false;

//     unordered_map<char, int> tally;
//     for(char c : s)
//     {
//         tally[c] += 1;
//     }

//     for(char c : t)
//     {
//         if(tally.count(c) <= 0)
//         {
//             return false;
//         }
//         else{
//             tally[c] -= 1;
//         }
//     }
//     return true;
// }

// vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
// {
//     unordered_set<int> uniqueInts;
//     vector<int> results;

//     for(int i : nums1)
//     {
//         uniqueInts.insert(i);
//     }

//     for(int n : nums2)
//     {
//         if(uniqueInts.count(n))
//         {
//             results.push_back(n);
//         }
//     }

//     return results;
// }

// vector<int> topKFrequent(vector<int>& nums, int k)
// {
//     unordered_map<int, int> leaderboard;
//     vector<vector<int>> bucket(nums.size() + 1);
//     vector<int> results;
//     for(int n : nums)
//     {
//         leaderboard[n] += 1;
//     }

//     for(auto& pair : leaderboard)
//     {
//         int num = pair.first;
//         int count = pair.second;
//         bucket[count].push_back(num);
//     }

//     for(int i = nums.size() - 1; i >= 0 && results.size() != k; i--)
//     {
//         for(auto& num : bucket[i])
//         {
//             results.push_back(num);
//             if(results.size() == k)
//             {
//                 return results;
//             }
//         }
//     }

//     return results;
// }

// vector<int> productExceptSelf(vector<int>& nums)
// {
//     vector<int> products;
//     int prefix = 1;
//     for(int i : nums)
//     {
//         products.push_back(prefix);
//         prefix *= i;
//     }

//     int suffix = 1;
//     for(int j = nums.size() - 1; j >= 0; j--)
//     {
//         products[j] *= suffix;
//         suffix *= nums[j];
//     }

//     return products;
// }


#pragma endregion

#pragma region Day5Functions
// abbcde
int recap_lengthOfLongestSubstring(string s)
{
    int left = 0;
    int maxLength = 0;
    unordered_set<char> longestStr;
    for(int right = 0; right < s.size(); right++)
    {
        while(longestStr.count(s[right]))
        {
            longestStr.erase(s[left]);
            left++;
        }
        longestStr.insert(s[right]);
        maxLength = max(maxLength, right - left + 1);
    }

    return maxLength;
}

// ((())) = valid     ((()(())) = invalid
bool isValidParentheses(string s)
{
    stack<char> pStack;
    for(int i = 0; i < s.size(); i++)
    {
        char p = s[i];
        if(p == '(')
        {
            pStack.push(p);
        }
        else{
            if(pStack.empty()) return false;
            pStack.pop();
        }
    }

    return pStack.empty();
}
class MinStack {
    private: 
        stack<int> minStack;
        stack<int> origStack;
    public:
        MinStack(){};
        void push(int val)
        {
            origStack.push(val);
            if(minStack.empty())
            {
                minStack.push(val);
            }
            else{
                minStack.push(min(val, minStack.top()));
            }
        }
        void pop()
        {
            if(origStack.empty()) return;

            origStack.pop();
            minStack.pop();
        }
        int top()
        {
            return origStack.top();
        }
        int getMin()
        {
            return minStack.top();
        }
};
int evalRPN(vector<string>& tokens) {
    stack<int> nums;
    for(int i = 0; i < tokens.size(); i++)
    {
        string t = tokens[i];
        if(t == "+")
        {
            int num1 = nums.top();
            nums.pop();
            int num2 = nums.top();
            nums.pop();

            nums.push(num2 + num1);
        }
        else if(t == "-")
        {
            int num1 = nums.top();
            nums.pop();
            int num2 = nums.top();
            nums.pop();

            nums.push(num2 - num1);
        }
        else if(t == "/")
        {
            int num1 = nums.top();
            nums.pop();
            int num2 = nums.top();
            nums.pop();

            nums.push(num2 / num1);
        }
        else if(t == "*")
        {
            int num1 = nums.top();
            nums.pop();
            int num2 = nums.top();
            nums.pop();
            
            nums.push(num2 * num1);
        }
        else
        {
            // assuming its a num
            int sign = 1;
            int num = 0;
            for(char c : t)
            {
                if(c == '-') 
                { 
                    sign = -1;
                    continue;
                };
                num = (c - '0') + (num * 10);
            }

            nums.push(num * sign);
        }
    }

    return nums.top();
}
#pragma endregion

#pragma region Day6Functions
bool recap_isValidParentheses(string s)
{
    stack<char> pStack;
    for(char c : s)
    {
        if(c == '(')
        {
            pStack.push(c);
        }
        else{
            if(pStack.empty())
            {
                return false;
            }
            pStack.pop();
        }
    }

    return pStack.empty();
}

Node<int>* reverseList(Node<int>* head)
{
    if(head == nullptr || head->next == nullptr) return head;

    Node<int>* newHead = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;
    
    return newHead;
}

// Assuming they are sorted
Node<int>* mergeTwoLists(Node<int>* head1, Node<int>* head2)
{
    Node<int> mergedHead;
    Node<int>* currentNode = &mergedHead;

    while(head1 != nullptr && head2 != nullptr)
    {
        if(head1->value <= head2->value)
        {
            currentNode->next = head1;
            head1 = head1->next;
        }
        else{
            currentNode->next = head2;
            head2 = head2->next;
        }
        currentNode = currentNode->next;
    }

    if(head1 != nullptr)
    {
        currentNode->next = head1;
    }
    else{
        currentNode->next = head2;
    }

    return mergedHead.next;
}

bool hasCycle(Node<int>* head)
{
    Node<int>* slow = head;
    Node<int>* fast = head;

    while(fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
        {
            return true;
        }
    }

    return false;
}

#pragma endregion

#pragma region Day7Functions
Node<int>* recap_reverseList(Node<int>* head)
{
    if(head == nullptr || head->next == nullptr) return head;

    Node<int>* newHead = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;
    
    return newHead;
}

Node<int>* middleNode(Node<int>* head)
{
    Node<int>* slow = head;
    Node<int>* fast = head;

    // for 1st middle (fast->next != nullptr && fast->next->next != nullptr)
    while(fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

Node<int>* removeNthFromEnd(Node<int>* head, int n)
{
    Node<int> temp;
    temp.next = head;
    Node<int>* slow = &temp;
    Node<int>* fast = &temp;

    for(int i = 0; i < n; i++)
    {
        if(fast->next == nullptr) return head;

        fast = fast->next;
    }

    while(fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next;
    }

    Node<int>* nodeToRemove = slow->next;
    slow->next = slow->next->next;

    delete nodeToRemove;

    return temp.next;
}

bool isPalindrome(Node<char>* head)
{
    int len = 0;
    Node<char>* tail = head;
    stack<char> letters;
    while(tail != nullptr)
    {
        len++;
        letters.push(tail->value);
        tail = tail->next;
    }

    for(int i = len / 2; i > 0; i--)
    {
        if(letters.top() != head->value)
        {
            return false;
        }
        head = head->next;
        letters.pop();
    }

    return true;
}
#pragma endregion

#pragma region Day8Functions
Node<int>* recap_removeNthFromEnd(Node<int>* head, int n)
{
    Node<int> temp;
    temp.next = head;

    Node<int>* slow = &temp;
    Node<int>* fast = &temp;

    for(int i = 0; i > n; i++)
    {
        if(fast->next == nullptr) return head;
        fast = fast->next;
    }


    while(fast != nullptr)
    {
        slow = slow->next;
        fast = fast->next;
    }

    Node<int>* nodeToRemove = slow->next;
    slow->next = slow->next->next;
    delete nodeToRemove;

    return temp.next;
}

// divide and conquer in sorted array 
int search(vector<int>& nums, int target)
{
    int left = 0;
    int right = nums.size() - 1;

    while(left <= right)
    {
        int mid = left + (right - left)/2;
        if(nums[mid] > target)
        {
            right = mid - 1;
        }
        else if(nums[mid] < target)
        {
            left = mid + 1;
        }
        else if(nums[mid] == target)
        {
            return mid;
        }
    }

    return -1;
}
// array is sorted, return index target should get inserted to retain sorted
int searchInsert(vector<int>& nums, int target)
{
    int left = 0;
    int right = nums.size();

    while(left < right)
    {
        int mid = left + (right - left)/2;
        if(nums[mid] < target)
        {
            left = mid + 1;
        }
        else{
            right = mid;
        }
    }

    return left;
}
// divide and conquer in sorted array, but array is rotated 
int search_rotated(vector<int>& nums, int target)
{
    int left = 0;
    int right = nums.size() - 1;

    while(left <= right)
    {
        int mid = left + (right - left)/2;
        if(nums[mid] == target)
        {
            return mid;
        }

        if(nums[left] <= nums[mid])
        {
            if(target >= nums[left] && target < nums[mid])
            {
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        else
        {
            if(target > nums[mid] && target <= nums[right])
            {
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
    }
    return -1;
}

#pragma endregion

#pragma region Day9Functions
//Recap
int recap_binarySearch(vector<int>& nums, int target)
{
    int left = 0;
    int right = nums.size() - 1;
    while(left <= right)
    {
        int mid = left + (right - left) / 2;
        if(nums[mid] == target)
        {
            return mid;
        }

        if(target < nums[mid])
        {
            right = mid - 1;
        }
        else{
            left =  mid + 1;
        }
    }
    return -1;
}

int maxDepth(node<int>* root)
{
    node<int>* currNode = root;
    int depth = 0;
    while(currNode != nullptr)
    {
        depth++;
        currNode = root->right;
    }
    return depth;
}

node<int>* invertTree(node<int>* root)
{

}

bool isSameTree(node<int>* p, node<int>* q)
{

}
#pragma endregion



