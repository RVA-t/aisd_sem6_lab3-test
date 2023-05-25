#include "Huffman.h"

int main()
{
    //string filename = "enwik8t";
    //
    //huf(filename);
    
    string text;
    text = get_text_from_file();

    //ac(text);
    
    
    
    LZ78 lz78;
    string encode78;

    encode78 = lz78.lz78(text, 1);
    put_text_to_file(encode78);

    
    
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