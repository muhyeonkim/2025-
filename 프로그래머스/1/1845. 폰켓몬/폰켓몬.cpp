#include <vector>


using namespace std;

int arr[200001];

int solution(vector<int> nums)
{
    int cnt=0;
    for (int i=0;i<nums.size();i++){
        if (arr[nums[i]]==0) cnt++; // 해당 포켓몬이 처음 등록되는 경우
        arr[nums[i]]++;
    }
    if(nums.size()/2>cnt) return cnt;
    else return nums.size()/2;
}
