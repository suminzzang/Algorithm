#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;


set<char> specialChar = { '-','_','.' };

string solution1(string new_id)
{
	for (int a = 0; a < new_id.size(); a++)
	{
		if (new_id[a] >= 65 && new_id[a] <= 90)
		{
			new_id[a] += 32;
		}
	}

	return new_id;
}

string solution2(string new_id)
{
	for (int a = new_id.size() - 1; a >= 0; a--)
	{
		bool charToDelete = true;
		if ((new_id[a] >= 97 && new_id[a] <= 122) ||(new_id[a]>=48 && new_id[a]<=57)|| (specialChar.find(new_id[a]) != specialChar.end()))
		{
			charToDelete = false;
		}

		if (charToDelete)
		{
			new_id.erase(a,1);
		}
	}
	return new_id;
}

string solution3(string new_id)
{
	bool checkDot = false;
	int deleteCharNum = 0;
	for (int a = new_id.size() - 1; a >= 0; a--)
	{
		if (new_id[a] == '.')
		{
			if (checkDot == false)
			{
				checkDot = true;
			}
			deleteCharNum++;
		}
		else
		{
			if (checkDot && deleteCharNum >= 2)
			{
				new_id.erase(a+1, deleteCharNum-1);
				checkDot = false;
				deleteCharNum = 0;
			}
			else
			{
				checkDot = false;
				deleteCharNum = 0;
			}
		}
	}

	if (checkDot && deleteCharNum >= 2)
	{
		new_id.erase(0, deleteCharNum - 1);
	}
	return new_id;
}

string solution4(string new_id)
{
	if (new_id.size() == 0)
	{
		return new_id;

	}
	if (new_id[0] == '.')
	{
		new_id.erase(0, 1);
	}
	if (new_id[new_id.size() - 1] == '.')
	{
		new_id.erase(new_id.end() - 1);
	}
	return new_id;
}

string solution5(string new_id)
{
	if (new_id.size() == 0)
	{
		new_id.push_back('a');
	}
	return new_id;
}


string solution6(string new_id)
{
	if (new_id.size() >=16)
	{
		new_id.erase(new_id.begin()+15,new_id.end());
	}
	if (*(new_id.end() - 1) == '.')
	{
		new_id.erase(new_id.end() - 1);
	}
	return new_id;
}

string solution7(string new_id)
{
	if (new_id.size() <=2)
	{
		while (new_id.size() <= 2)
		{
			new_id.push_back(*(new_id.end() - 1));
		}
	}
	return new_id;
}

string solution(string new_id)
{
	string answer = "";

	answer = solution1(new_id);
	cout << "solution1 : " << answer << endl;
	answer = solution2(answer);
	cout << "solution2 : " << answer << endl;
	answer = solution3(answer);
	cout << "solution3 : " << answer << endl;
	answer = solution4(answer);
	cout << "solution4 : " << answer << endl;
	answer = solution5(answer);
	cout << "solution5 : " << answer << endl;
	answer = solution6(answer);
	cout << "solution6 : " << answer << endl;
	answer = solution7(answer);
	cout << "solution7 : " << answer << endl;

	cout << 'A' - 0 << " " << 'Z' - 0 << " " << char('A' + 32) << " " << '0' - 0 << " " << '9' - 0 << endl;

	return answer;
}

int main()
{
	string new_id1 = "...!@BaT#*..y.abcdefghijklm";
	string new_id2 = "z-+.^.";
	string new_id3 = "=.=";
	string new_id4 = "123_.def";
	string new_id5 = "abcdefghijklmn.p";

	solution(new_id1);

}