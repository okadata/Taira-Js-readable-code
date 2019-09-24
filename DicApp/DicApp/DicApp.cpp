// DicApp.cpp : アプリケーションのエントリ ポイントを定義します。
//

// macOSでは存在しないヘッダがincludeされて、ビルドできないためコメントアウト
//#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

typedef std::string String;

class word_info {
public:
    word_info( int aID, const std::string& aWord )
    :mID(aID), mWord(aWord)
    {
    }
    
    const String get_string_expression() const
    {
        std::stringstream xStream;
        xStream << mID << ": " << mWord;
        return xStream.str();
    }
    
    std::string mWord; // 表記
    int mID; // ID（1始まりの数値）
};

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
    output_line(aWord.get_string_expression());
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
    int xID = 1;
    while (xfs.getline(xWord, kReadBufSize - 1)) {
        word_info xWordInfo( xID, xWord );
        xWords.push_back(xWordInfo);
        ++xID;
    }

    return xWords;
}


int main()
{
    Words xWords = load_dictionary_data();
    for (auto xIter = xWords.begin(); xIter != xWords.end(); ++xIter) {
        output_word( *xIter );
    }
 
    return 0;
}

