// DicApp.cpp : アプリケーションのエントリ ポイントを定義します。
//

// macOSでは存在しないヘッダがincludeされて、ビルドできないためコメントアウト
//#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

typedef std::string String;


typedef std::string     word_info;
typedef std::vector<word_info> Words;
const size_t kReadBufSize = 256;

// 指定した文字列を1行コンソールに出力する
void output_line(const String& aString)
{
    std::cout << aString.c_str() << std::endl;
}

// 単語を１つコンソールに出力する
void output_word(const word_info& aWord)
{
    output_line(aWord);
}


Words load_dictionary_data()
{
    Words xWords;
    
    // macOSでの動作のために、ファイルセパレータを\\から/に変更
    std::ifstream xfs("./dictionary_data.txt");
    if (xfs.fail()) {
        return xWords;
    }

    char xWord[kReadBufSize] = { 0 };
    while (xfs.getline(xWord, kReadBufSize - 1)) {

        xWords.push_back(xWord);
    }

    return xWords;
}


int main()
{
    Words xWords = load_dictionary_data();
    for (auto xIter = xWords.begin(); xIter != xWords.end(); ++xIter) {

        std::cout << xIter->c_str() << std::endl;
    }
 
    return 0;
}

