// LIS.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;


void LISDP(vector<int>& input)
{
    vector<int> LIS(input.size(), 1);

    for (int a = 0; a < input.size(); a++)
    {
        for (int b = 0; b < a; b++)
        {
            if (input[a] > input[b])
            {
                LIS[a] = max(LIS[a], LIS[b] + 1);
            }
        }
    }

    for (auto& a : LIS)
    {
        cout << a << " ";
    }
    cout << endl;

}

void LISBinarySearch(vector<int>& input)
{
    vector<int> LIS;

    for (auto& a : input)
    {
        auto it = lower_bound(LIS.begin(), LIS.end(), a);

        if (it == LIS.end())
        {
            LIS.push_back(a);
        }
        else
        {
            LIS[it - LIS.begin()] = a;
            //*it = a;
        }
    }

    cout << LIS.size() << endl;
}

vector<int> LISBSReturnVector(vector<int>& input)
{
    vector<int> LIS;
    vector<int> realIndex(input.size(),0);

    int index = 0;
    for (auto& a : input)
    {
        auto it = lower_bound(LIS.begin(), LIS.end(), a);

        if (it == LIS.end())
        {
            realIndex[index] = LIS.size();
            LIS.push_back(a);
        }
        else
        {
            realIndex[index] = it - LIS.begin();
            LIS[it - LIS.begin()] = a;
            //*it = a;
        }
        index++;
    }
    vector<int> LISVector(LIS.size(), 0);

    int LISSize = LIS.size()-1;

    for (int a = realIndex.size() - 1; a >= 0; a--)
    {

        if (realIndex[a] == LISSize)
        {
            LISVector[LISSize] = input[a];
            LISSize--;
        }
    }

    cout << LIS.size() << endl;

    return LISVector;
}

int main()
{
    vector<int> input = { 1,5,4,2,3,8,6,7,8,3,4,5 };
    LISDP(input);
    LISBinarySearch(input);
    vector<int> LISVector = LISBSReturnVector(input);

    for (int a : LISVector)
    {
        cout << a << " ";
    }
    cout << endl;

    list<int> test = { 1,2,3 };
    auto it = test.begin();
    test.erase(it);


}