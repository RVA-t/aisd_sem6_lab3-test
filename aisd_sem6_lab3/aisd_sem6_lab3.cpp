#include "Huffman.h"

int main()
{
    setlocale(0, "Rus");

    string text;
    text = get_text_from_file();

    cout << "got the text" << endl << endl;




    //cout << "Алгоритм Хаффмата: ";
    //string filename = "C:\\ewnik8tm";
    //
    //huf(filename);
    //
    //cout << "Готов." << endl << endl;

    //cout << "Арифметическое кодирование: ";
    //ac(text);
    //cout << "Готово." << endl << endl;
    
    
    //
    //LZ78 lz78;
    //string encode78, decode78;

    //encode78 = lz78.lz78(text);
    //put_text_to_file(encode78);
    //decode78 = lz78.lz78r(encode78);
    //put_text_to_file(decode78);

    //РАБОТАЕТ не точно
    //BWT bwt;
    //string temp, reverse;
    //temp = bwt.bwt(text);
    //cout << endl << temp << endl;

    ////РАБОТАЕТ
    //vector<int> encoded = mtf_encode(temp);
    //string decoded = mtf_decode(encoded);
    //cout << "Encoded: ";
    //for (int i : encoded) {
    //    cout << i << " ";
    //}
    //cout << endl;
    //cout << "Decoded: " << decoded << endl;


    
    
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