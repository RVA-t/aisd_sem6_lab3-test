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
#include <chrono>
#include <set>
#include <conio.h>
#include <ctype.h>
#include "windows.h"

using namespace std;

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
    cout << "������� �������� ������������ �����: ";
    cin >> file;
    ofstream out;          // ����� ��� ������
    out.open("D:\\" + file);      // ��������� ���� ��� ������
    if (out.is_open())
    {
        out << str << std::endl;
    }
    out.close();
    std::cout << "File has been written" << std::endl;
}