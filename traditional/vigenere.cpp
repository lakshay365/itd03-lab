#include <iostream>
using namespace std;

string encrypt(string s, string k)
{
	for (int i = 0, j = 0; i < s.length(); i++)
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
		{
			s[i] = (s[i] - 'A' + k[j % k.length()] - 'a') % 26 + 'A';
			j++;
		}
		else if (s[i] >= 'a' && s[i] <= 'z')
		{
			s[i] = (s[i] - 'a' + k[j % k.length()] - 'a') % 26 + 'a';
			j++;
		}
	}

	return s;
}

string decrypt(string s, string k)
{
	for (int i = 0, j = 0; i < s.length(); i++)
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
		{
			s[i] = (s[i] - 'A' - k[j % k.length()] + 'a' + 26) % 26 + 'A';
			j++;
		}
		else if (s[i] >= 'a' && s[i] <= 'z')
		{
			s[i] = (s[i] - 'a' - k[j % k.length()] + 'a' + 26) % 26 + 'a';
			j++;
		}
	}

	return s;
}

int main()
{
	cout << "\n";
	cout << "1. Encrypt\n";
	cout << "2. Decrypt\n";
	cout << "Choice: ";
	string ch;	cin >> ch;

	cin.ignore();

	cout << "Enter text: ";
	string s;	getline(cin, s);

	cout << "Enter key: ";
	string k;	cin >> k;

	for (int i = 0; i < k.length(); i++)
	{
		if (k[i] < 'a' || k[i] > 'z')
		{
			cout << "Invalid Key\n";
			return 1;
		}
	}

	if (ch == "1")
		cout << "Encrypted text: " << encrypt(s, k) << "\n";
	else if (ch == "2")
		cout << "Decrypted text: " << decrypt(s, k) << "\n";

	return 0;
}