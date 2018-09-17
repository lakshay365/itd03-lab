#include <iostream>
using namespace std;

string encrypt(string s, int key)
{
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] >= 'a' and s[i] <= 'z')
			s[i] = 'a' + (s[i] - 'a' + key) % 26;
		else if (s[i] >= 'A' && s[i] <= 'Z')
			s[i] = 'A' + (s[i] - 'A' + key) % 26;
	}

	return s;
}

string decrypt(string s, int key)
{
	return encrypt(s, 26 - key % 26);
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
	int key;	cin >> key;

	if (ch == "1")
		cout << "Encrypted text: " << encrypt(s, key) << "\n";
	else if (ch == "2")
		cout << "Decrypted text: " << decrypt(s, key) << "\n";

	return 0;
}