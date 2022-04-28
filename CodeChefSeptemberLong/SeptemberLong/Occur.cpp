// C++ program to count the number
// of occurrence of a word in
// the given string given string
#include <bits/stdc++.h>
using namespace std;

int NumberOccurrencesWord(char *str,
					char* word)
{
    if(str == " " or word==" ")
    {
        return -1;
    }
    if(strlen(str) < strlen(word))
    {
        return -1;
    }

	char *p;

	vector<string> a;

	p = strtok(str, " ");
	while (p != NULL)
	{
		a.push_back(p);
		p = strtok(NULL, " ");
	}

	int c = 0;
	for (int i = 0; i < a.size(); i++)

		// if match found increase count
		if (word == a[i])
			c++;
	return c;
}

int main()
{
    char str[100000];
    cin.getline(str, 100000);
    char word[100000];
    cin.getline(word,100000);
    cout << countNumberOfOccurrences(str, word);
	return 0;
}

