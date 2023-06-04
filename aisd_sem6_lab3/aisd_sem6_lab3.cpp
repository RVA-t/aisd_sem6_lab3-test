#include "Huffman.h"

int main()
{
    setlocale(0, "Rus");

    string text;
    text = get_text_from_file();

    cout << "got the text" << endl << endl;


    // хаффмана и арифметическое работют.

    cout << "Алгоритм Хаффмата: ";
    string filename = "enwik8";
    
    huf(filename);
    
    cout << "Готов." << endl << endl;

    //cout << "Арифметическое кодирование: ";
    //ac(text);
    //cout << "Готово." << endl << endl;
     
    //
    
    
    // LZ78 надо доделать !!!

   /* LZ78 lz78;
    string encode78, decode78;

    lz78.lz78(text);
    put_text_to_file(encode78);
    decode78 = lz78.lz78r(encode78);
    put_text_to_file(decode78);*/



    // 4 пункт
    //РАБОТАЕТ
    //pair<string, int> result = BWT(text);
    //cout << endl << "BWT code is: (\"" << result.first << "\", " << result.second << ")" << endl;
    //string decoded = DecodeBWT(result);
    //cout << decoded;

    //РАБОТАЕТ
    //cout << "mtf: ";
    //vector<int> encoded = mtf_encode(text);
    //string decoded = mtf_decode(encoded);
    //std::ofstream out;          // поток для записи
    //out.open("tempmtf4");      // открываем файл для записи
    //if (out.is_open()) {
    //    for (int i : encoded) {
    //        out << i << " ";
    //    }
    //}
    //out.close();
    //cout << "Готово." << endl << endl;

    //MTF mtf;
    //string a;
    //a = mtf.encode(text);
    //cout << a;



    //cout << "Huffman: ";
    //huf("tempmtf4", "resultcoding4");
    //cout << "Готово." << endl << endl;
    
    
    //string text, encodetext;
    //text = get_text_from_file();


    ////put_text_to_file(text);

    //int Hchoice = 0;

    //Huffman huffman;

    //huffman.buildHuffmanTree(text);

    //cout << "------------------------------------------------------------------------------------" << endl << endl << endl;
    //cout << stringhuf;
    //put_text_to_file(stringhuf);
    //cout << endl;

    //RKE rke;
    //cout << rke.RKEencode(text);;


    //LZ78 lz78;
    //string encodeLZ78;

    //encodeLZ78 = lz78.lz78(text, 1);;
    //cout << endl << lz78.lz78(text, 1);;

    //cout << endl << lz78.lz78(encodeLZ78, 2);;

    //// BWT

    //int* suffix_arr = computeSuffixArray(text, len_text);;

    //char* bwt_arr = findLastChar(text, suffix_arr, len_text);;

    //printf("Input text : %s\n", text);;

    //printf("Burrows - Wheeler Transform : %s\n", bwt_arr);;

    //// 

    //MTF mtf;
    //string a;

    //a = text;
    //cout << endl << "encoded = ";
    //a = mtf.encode(a);;
    //cout << a << "; decoded = " << mtf.decode(a); << endl;





    return 0;
}