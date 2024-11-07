// CombPerm.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <stack>
#include <tuple>


using namespace std;

vector<int> input = { 2,4,5,7,9,11 };

void combDupl(int cnt, int num, int start,vector<int>& result)
{
    if (cnt == num)
    {
        for (int a = 0; a < num; a++)
        {
            cout << result[a] << " ";
        }
        cout << endl;

        return;
    }

    for (int a = start; a < input.size(); a++)
    {
        result[cnt] = input[a];
        combDupl(cnt + 1, num, a, result);
    }
}

void permDupl(int cnt, int num, vector<int>& result)
{
    if (cnt == num)
    {
        for (int a = 0; a < num; a++)
        {
            cout << result[a] << " ";
        }
        cout << endl;

        return;
    }

    for (int a = 0; a < input.size(); a++)
    {
        result[cnt] = input[a];
        permDupl(cnt + 1, num, result);
    }
}

void comb(int cnt, int num, int start, vector<int>& result)
{
    if (cnt == num)
    {
        for (int a = 0; a < num; a++)
        {
            cout << result[a] << " ";
        }
        cout << endl;

        return;
    }

    for (int a = start; a < input.size(); a++)
    {
        result[cnt] = input[a];
        comb(cnt + 1, num, a+1, result);
    }
}

void perm(int cnt, int num, vector<int>& result, vector<int>& visited)
{
    if (cnt == num)
    {
        for (int a = 0; a < num; a++)
        {
            cout << result[a] << " ";
        }
        cout << endl;

        return;
    }

    for (int a = 0; a < input.size(); a++)
    {
        if (visited[a] == 1) continue;
        result[cnt] = input[a];
        visited[a] = 1;
        perm(cnt + 1, num, result, visited);
        visited[a] = 0;
    }
}


int main()
{
    int num = 4;
    vector<int> result(num);
    vector<int> visited(input.size());
    //combDupl(0, num, 0,result);
    //permDupl(0, num, result);
    //comb(0, num, 0, result);
    //perm(0, num, result,visited);
}