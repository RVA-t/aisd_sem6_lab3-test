#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
#include <vector>
#include <sstream>
#include <map>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include "windows.h"

using namespace std;
pair<string, int> BWT(string);
string DecodeBWT(pair<string, int>);
string LShift(string, int);
bool Test();

//string stringhuf;

string get_text_from_file()
{
    const string path = "C:\\enwik8tm";
    ifstream input_file(path);
    if (!input_file.is_open()) {
        cerr << "Could not open the file - '"
            << path << "'" << endl;
        exit(EXIT_FAILURE);
    }

    return string((istreambuf_iterator<char>(input_file)), istreambuf_iterator<char>());
}

void put_text_to_file(string str)
{
    string file;
    cout << "¬ведите название сохран€емого файла: ";
    cin >> file;
    ofstream out;          // поток дл€ записи
    out.open(file);      // открываем файл дл€ записи
    if (out.is_open())
    {
        out << str << std::endl;
    }
    out.close();
    std::cout << "File has been written" << std::endl;
}