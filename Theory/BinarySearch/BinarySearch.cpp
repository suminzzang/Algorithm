// BinarySearch.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int num, int value)
{
    return num > value;
}

void binarySearch(vector<int> input, int numToFind)
{
    auto it = lower_bound(input.begin(), input.end(), numToFind);
    cout << "using Library " << it-input.begin() << endl;

    int start = 0;
    int end = input.size() - 1; // 끝 인덱스는 size() - 1

    while (start <= end) // <=로 변경
    {
        int mid = (start + end) / 2;
        if (input[mid] == numToFind)
        {
            cout << "Not Using Library " << mid << endl;
            break;
        }
        else if (input[mid] > numToFind)
        {
            end = mid - 1; // end를 mid - 1로 이동
        }
        else
        {
            start = mid + 1; // start를 mid + 1로 이동
        }
    }


    reverse(input.begin(), input.end());
    it = lower_bound(input.begin(), input.end(), numToFind,compare);
    it = lower_bound(input.begin(), input.end(), numToFind, greater<int>());

    cout << "using Library " << it - input.begin() << endl;


}

int main()
{
    vector<int> input = { 1,2,4,7,8,11,15,20 };
    binarySearch(input, 8);

}

