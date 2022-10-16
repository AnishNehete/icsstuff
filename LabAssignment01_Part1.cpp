// A C++ program to illustrate Caesar Cipher Technique
#include <iostream>
using namespace std;

// This function receives text and shift and
// returns the encrypted text
string encrypt(string text, int s)
{
	string result = "";

	
	for (int i=0;i<text.length();i++)
	{
		
		if (isupper(text[i]))
			result += char(int(text[i]+s-65)%26 +65);

	
	else
		result += char(int(text[i]+s-97)%26 +97);
	}

	
	return result;
}

// Driver program to test the above function
int main()
{
	string text;
	cout << "Enter Plaintext: ";
	cin >> text;
	int s = 4;
	cout << "Text : " << text;
	cout << "\nShift: " << s;
	cout << "\nCipher: " << encrypt(text, s);
	string cipherText = encrypt(text, s);
	cout << "\nPlaintext: " << encrypt(cipherText, 26-s);
	return 0;
}
