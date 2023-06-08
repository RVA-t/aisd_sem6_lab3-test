#include "RLE.h"


vector<int> mtf_encode(const string& input) {
    vector<int> output;
    vector<int> alphabet(100000); // создаем алфавит из 256 символов
    for (int i = 0; i < 100000; i++) {
        alphabet[i] = i;
    }
    for (char c : input) {
        int index = find(alphabet.begin(), alphabet.end(), c) - alphabet.begin(); // находим индекс символа в алфавите
        output.push_back(index); // добавляем индекс в выходной вектор
        alphabet.erase(alphabet.begin() + index); // удаляем символ из алфавита
        alphabet.insert(alphabet.begin(), c); // добавляем символ в начало алфавита
    }
    return output;
}

string mtf_decode(const vector<int>& input) {
    string output;
    vector<int> alphabet(256); // создаем алфавит из 256 символов
    for (int i = 0; i < 256; i++) {
        alphabet[i] = i;
    }
    for (int index : input) {
        char c = alphabet[index]; // находим символ по индексу в алфавите
        output += c; // добавляем символ в выходную строку
        alphabet.erase(alphabet.begin() + index); // удаляем символ из алфавита
        alphabet.insert(alphabet.begin(), c); // добавляем символ в начало алфавита
    }
    return output;
}