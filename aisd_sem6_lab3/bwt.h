#include "MTF.h"

class BWT {
public:
    string bwt(string s) {
        s += "$"; // ��������� ������ ����� ������

        int n = s.size(); // ����� ������

        // ������� ������ ���������
        string* suffixes = new string[n];
        for (int i = 0; i < n; i++)
            suffixes[i] = s.substr(i, n - i);

        // ��������� ������ ���������
        sort(suffixes, suffixes + n);

        // ������� ������ ��������
        int* indexes= new int[n];
        for (int i = 0; i < n; i++)
            indexes[i] = n - suffixes[i].size();

        // ������� ��������������� ������
        string transformed_string;
        for (int i = 0; i < n; i++)
            transformed_string += s[(indexes[i] - 1 + n) % n];

        return transformed_string;
    }

    // ������� ��� ���������� ������
    string bwtr(string s) {
        int n = s.size(); // ����� ������

        // ������� ������� ������ ��������
        int freq[256] = { 0 };
        for (int i = 0; i < n; i++)
            freq[s[i]]++;

        // ������� ������� �������� ������� ��������� �������
        int first_index[256] = { 0 };
        int sum = 0;
        for (int i = 0; i < 256; i++) {
            first_index[i] = sum;
            sum += freq[i];
        }

        // ������� ������� �������� ���������� �������
        int* next_index = new int[n];
        for (int i = 0; i < n; i++) {
            next_index[first_index[s[i]]] = i;
            first_index[s[i]]++;
        }

        // ������� �������� ������
        string original_string;
        int current_index = 0;
        for (int i = 0; i < n; i++) {
            original_string += s[current_index];
            current_index = next_index[current_index];
        }

        // ������� ������ ����� ������
        original_string.erase(original_string.size() - 1);

        return original_string;
    }

};