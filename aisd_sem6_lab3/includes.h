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

string stringhuf;

void put_text_to_file(string str)
{
    string file;
    cout << "������� �������� ������������ �����: ";
    cin >> file;
    ofstream out;          // ����� ��� ������
    out.open(file);      // ��������� ���� ��� ������
    if (out.is_open())
    {
        out << str << std::endl;
    }
    out.close();
    std::cout << "File has been written" << std::endl;
}