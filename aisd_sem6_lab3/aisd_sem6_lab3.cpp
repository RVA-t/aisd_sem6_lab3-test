#include "Huffman.h"

int main()
{
    setlocale(0, "Rus");

    string text;
    text = get_text_from_file();

    cout << "got the text" << endl << endl;

    const int lenght = text.length();

    //// �������� � �������������� �������.

    cout << "�������� ��������: ";
    string filename = "C:\\enwik8tm";
    
    auto begin1 = std::chrono::steady_clock::now();
    huf("D:\\huf.txt");
    auto end1 = std::chrono::steady_clock::now();
    auto elapsed_ms1 = std::chrono::duration_cast<std::chrono::milliseconds>(end1 - begin1);
    std::cout << "�����: " << elapsed_ms1.count() << " � �� \n";
    cout << "�����." << endl << endl;



    //// �������� �� �������� (��� ����������� ��� ������� ������ �� �������)
    cout << "�������������� �����������: ";
    auto begin2 = std::chrono::steady_clock::now();
    ac(text);
    auto end2 = std::chrono::steady_clock::now();
    auto elapsed_ms2 = std::chrono::duration_cast<std::chrono::milliseconds>(end2 - begin2);
    std::cout << "�����: " << elapsed_ms2.count() << " � �� \n";
    cout << "������." << endl << endl;

 
    //
    //
    //// LZ78 ��������

    LZ78 lz78;
    string encode78, decode78;
    cout << "�������� LZ78: ";
    auto begin3 = std::chrono::steady_clock::now();
    encode78 = lz78.lz78(text, 1);
    auto end3 = std::chrono::steady_clock::now();
    auto elapsed_ms3 = std::chrono::duration_cast<std::chrono::milliseconds>(end3 - begin3);
    std::cout << "�����: " << elapsed_ms3.count() << " � �� \n";
    cout << "�����." << endl << endl;
    put_text_to_file(encode78);




    //// 4 �����
    ////��������

    cout << "4 ����� BWT->MTF->HUF: " << endl;
    auto begin4 = std::chrono::steady_clock::now();
    string bwt_result = bwt_encode(text);
    vector<int> encoded = mtf_encode(bwt_result);
    string decoded = mtf_decode(encoded);
    std::ofstream out;          // ����� ��� ������
    out.open("tempmtf4");      // ��������� ���� ��� ������
    if (out.is_open()) {
        for (int i : encoded) {
            out << i << " ";
        }
    }
    out.close();

    huf("D:\\bwtmtfhuf.txt");
    auto end4 = std::chrono::steady_clock::now();
    auto elapsed_ms4 = std::chrono::duration_cast<std::chrono::milliseconds>(end4 - begin4);
    std::cout << "�����: " << elapsed_ms4.count() << " � �� \n";
 

    cout << "�������� RLE: ";
    auto begin5 = std::chrono::steady_clock::now();
    string rle = rle_encode(text);
    auto end5 = std::chrono::steady_clock::now();
    auto elapsed_ms5 = std::chrono::duration_cast<std::chrono::milliseconds>(end5 - begin5);
    std::cout << "�����: " << elapsed_ms5.count() << " � �� \n";
    put_text_to_file(rle);

    cout << "�����.";

    return 0;
}