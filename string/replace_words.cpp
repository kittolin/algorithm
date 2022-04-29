/*
* 名称：单词替换
* 来源：北京大学复试上机题
* 链接：http://985.so/kshk
* 难度：困难
* 分析：只有匹配到单词才替换，例如：text = " CCCCABC...", oldWord = "CCC"，不能替换
*/

#include <iostream>
#include <string>

using namespace std;

string ReplaceWord1(string text, string oldWord, string newWord) {
    string prefix, suffix;
    int index = text.find(oldWord);
    while (index >= 0) {
        // 如果不是第一个单词，则要判断该单词前面是否有空格；如果不是最好一个单词，则要判断该单词后面是否有空格
        if ((index == 0 || text[index - 1] == ' ') && (index + oldWord.size() == text.size() || text[index + oldWord.size()] == ' ')) {
            prefix = text.substr(0, index);               // 要替换的单词的前缀部分
            suffix = text.substr(index + oldWord.size()); // 要替换的单词的后缀部分
            text = prefix + newWord + suffix;             // 拼接成新的字符串
        }
        index = text.find(oldWord, index + 1);            // 下一次从 index+1 开始匹配，避免一直在同一位置匹配从而死循环
    }
    return text;
}

string ReplaceWord2(string text, string oldWord, string newWord) {
    text = " " + text + " ";
    oldWord = " " + oldWord + " ";
    newWord = " " + newWord + " ";
    int index = text.find(oldWord);
    while (index >= 0) {
        text = text.replace(index, oldWord.size(), newWord);
        index = text.find(oldWord);
    }
    return text.substr(1, text.size() - 2);  // 去掉前后空格
}

int main() {
    string text, oldWord, newWord;
    while (getline(cin, text)) {
        cin >> oldWord >> newWord;
        cout << ReplaceWord2(text, oldWord, newWord) << endl;
    }
    return 0;
}
