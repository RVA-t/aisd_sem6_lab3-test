#include "includes.h"
//
//
//vector<int> mtf_encode(const string& input) {
//    vector<int> output;
//    vector<int> alphabet(100000); // создаем алфавит из 256 символов
//    for (int i = 0; i < 100000; i++) {
//        alphabet[i] = i;
//    }
//    for (char c : input) {
//        int index = find(alphabet.begin(), alphabet.end(), c) - alphabet.begin(); // находим индекс символа в алфавите
//        output.push_back(index); // добавляем индекс в выходной вектор
//        alphabet.erase(alphabet.begin() + index); // удаляем символ из алфавита
//        alphabet.insert(alphabet.begin(), c); // добавляем символ в начало алфавита
//    }
//    return output;
//}
//
//string mtf_decode(const vector<int>& input) {
//    string output;
//    vector<int> alphabet(256); // создаем алфавит из 256 символов
//    for (int i = 0; i < 256; i++) {
//        alphabet[i] = i;
//    }
//    for (int index : input) {
//        char c = alphabet[index]; // находим символ по индексу в алфавите
//        output += c; // добавляем символ в выходную строку
//        alphabet.erase(alphabet.begin() + index); // удаляем символ из алфавита
//        alphabet.insert(alphabet.begin(), c); // добавляем символ в начало алфавита
//    }
//    return output;
//}

using namespace std;

class MTF
{
public:
	string encode(string str)
	{
		fillSymbolTable();
		vector<int> output;
		for (string::iterator it = str.begin(); it != str.end(); it++)
		{
			for (int i = 0; i < 26; i++)
			{
				if (*it == symbolTable[i])
				{
					output.push_back(i);
					moveToFront(i);
					break;
				}
			}
		}
		string r;
		for (vector<int>::iterator it = output.begin(); it != output.end(); it++)
		{
			ostringstream ss;
			ss << *it;
			r += ss.str() + " ";
		}
		return r;
	}

	string decode(string str)
	{
		fillSymbolTable();
		istringstream iss(str); vector<int> output;
		copy(istream_iterator<int>(iss), istream_iterator<int>(), back_inserter<vector<int> >(output));
		string r;
		for (vector<int>::iterator it = output.begin(); it != output.end(); it++)
		{
			r.append(1, symbolTable[*it]);
			moveToFront(*it);
		}
		return r;
	}

private:
	void moveToFront(int i)
	{
		char t = symbolTable[i];
		for (int z = i - 1; z >= 0; z--)
			symbolTable[z + 1] = symbolTable[z];

		symbolTable[0] = t;
	}

	void fillSymbolTable()
	{
		for (int x = 0; x < 26; x++)
			symbolTable[x] = x + 'a';
	}

	char symbolTable[26];
};