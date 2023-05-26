#include "bwt.h"

using namespace std;

//class LZ78 {
//public:
//	struct Node {
//		int index;
//		string data;
//		Node* next;
//	};
//
//	void st_Node(Node* head, int index, string data) {
//		head->index = index;
//		head->data = data;
//		head->next = NULL;
//	}
//
//	void insert_Node(Node* head, int index, string data) {
//		Node* new_Node = new Node;
//		new_Node->index = index;
//		new_Node->data = data;
//		new_Node->next = NULL;
//
//		Node* curr = head;
//		while (curr != NULL)
//		{
//			if (curr->next == NULL)
//			{
//				curr->next = new_Node;
//				return;
//			}
//			curr = curr->next;
//		}
//	}
//
//	Node* search_Node(Node* head, string data)
//	{
//		Node* curr = head;
//		while (curr != NULL)
//		{
//			if (data.compare(curr->data) == 0)
//				return curr;
//			else
//				curr = curr->next;
//		}
//		return NULL;
//	}
//
//	Node* search_Node(Node* head, int index)
//	{
//		Node* curr = head;
//		while (curr != NULL)
//		{
//			if (index == curr->index)
//				return curr;
//			else
//				curr = curr->next;
//		}
//		return NULL;
//	}
//
//	bool delete_Node(Node* head, Node* to_delete) {
//		if (to_delete == NULL)
//			return false;
//		else if (to_delete == head)
//		{
//			head = to_delete->next;
//			delete to_delete;
//			return true;
//		}
//		else {
//			Node* curr = head;
//			while (curr)
//			{
//				if (curr->next == to_delete)
//				{
//					curr->next = to_delete->next;
//					delete to_delete;
//					return true;
//				}
//				curr = curr->next;
//			}
//			return false;
//		}
//	}
//
//	vector <string> split(string str, char delimiter) {
//		vector<string> internal;
//		stringstream ss(str); // Turn the string into a stream.
//		string tok;
//
//		while (getline(ss, tok, delimiter)) {
//			internal.push_back(tok);
//		}
//
//		return internal;
//	}
//
//	//string LZ78(string input, int option);
//
//	//int main()
//	//{
//	//	string input, result, method_text;
//	//	int method, option, option2;
//	//
//	//
//	//
//	//	return 0;
//	//}
//
//	string lz78(string input, int option)
//	{
//		if (option == 1)
//		{
//			Node* dictionary = new Node;
//			string word, result;
//			int length, last_seen, index = 1;
//
//			length = (int)input.length();
//			word = input[0];
//			st_Node(dictionary, 1, word);
//			result += "0," + word;
//
//			for (int i = 1; i < length; i++)
//			{
//				string data;
//				data = input[i];
//
//			re_check:
//				Node* search = search_Node(dictionary, data);
//
//				if (search)
//				{
//					i++;
//					data += input[i];
//					last_seen = search->index;
//					goto re_check;
//				}
//				else
//				{
//					char zero;
//					if (input[i] == ' ')
//						zero = '0';
//					else
//						zero = input[i];
//
//					if ((int)data.length() < 2)
//						result += " " + to_string(0) + "," + zero;
//					else
//						result += " " + to_string(last_seen) + "," + zero;
//
//					index++;
//					if (i != length)
//						insert_Node(dictionary, index, data);
//				} 
//			}
//
//			return result;
//		}
//		if (option == 2)
//		{
//			Node* dictionary = new Node;
//			string result;
//
//			vector <string> s_input = split(input, ' ');
//			int zz = 2;
//			for (int i = 0; i < s_input.size(); i++)
//			{
//				vector <string> ss_input = split(s_input[i], ',');
//
//				if (i == 0)
//				{
//					st_Node(dictionary, 1, ss_input[1]);
//					result += ss_input[1];
//				}
//				else
//				{
//					Node* serched;
//					string get_search = ss_input[1];
//					serched = search_Node(dictionary, stoi(ss_input[0]));
//					if (serched)
//					{
//						result += serched->data + get_search;
//						get_search = serched->data + split(s_input[i], ',')[1];
//						insert_Node(dictionary, zz, get_search);
//					}
//					else
//					{
//						if (stoi(ss_input[0]) == 0)
//							insert_Node(dictionary, zz, get_search);
//						else
//							insert_Node(dictionary, zz, get_search);
//
//						result += get_search;
//					}
//					zz++;
//				}
//			}
//
//			if (result[(int)result.length() - 1] == '0')
//				result = result.substr(0, result.size() - 1);
//
//			return result;
//		}
//	}
//};

class LZ78 {
public:
    string lz78(string s) {
        map<string, int> dictionary; // �������
        int next_code = 1; // ��������� ���

        string compressed_string; // ������ ������

        int n = s.size(); // ����� ������
        string current_string; // ������� ������
        for (int i = 0; i < n; i++) {
            current_string += s[i]; // ��������� ������ � ������� ������

            // ���� ������� ������ �� ���������� � �������, ��������� �� � ��� 0
            if (dictionary.find(current_string) == dictionary.end()) {
                dictionary[current_string] = next_code++;
                compressed_string += "0" + current_string.back();
                current_string = "";
            }
            // ���� ������� ������ ���������� � �������, ���������� ��������� �������
            else if (i == n - 1) {
                compressed_string += to_string(dictionary[current_string]);
            }
        }

        return compressed_string;
    }

    // ������� ��� ���������� ������
    string lz78r(string s) {
        map<int, string> dictionary; // �������
        int next_code = 1; // ��������� ���

        string decompressed_string; // ������������� ������

        int n = s.size(); // ����� ������
        for (int i = 0; i < n; i += 2) {
            int code = s[i] - '0'; // �������� ���

            // ���� ��� ����� 0, ��������� ����� ������ � �������
            if (code == 0) {
                string character = string(1, s[i + 1]);
                dictionary[next_code++] = character;
                decompressed_string += character;
            }
            // ���� ��� �� ����� 0, ��������� ������� �� ��������������� ������ � �������
            else {
                string previous_string = dictionary[code];
                previous_string += s[i + 1];
                dictionary[next_code++] = previous_string;
                decompressed_string += previous_string;
            }
        }

        return decompressed_string;
    }
};