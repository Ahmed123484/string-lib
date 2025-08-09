#include"../header/string.h"
namespace stringFile {
    clsString::clsString(string data):_data(data){

    }
    void clsString::setData(string data){
        this->_data = data ;
    }
    string clsString::getData(){
        return this->_data ;
    }
    void clsString::setWords(vector<string> words){
        this->_words = words ;
    }
    vector<string> clsString::getWords(){
        return this-> _words ;
    }
    int clsString::length(){
        int counter {0};
        while (_data[counter] != '\0'){
            counter++;
        }
        return counter ;
    }
    int clsString::countWords(){
       return _words.size();
    }
    void clsString::UpperFirstLetterOfEachWord(){
        for (int i = 0 ; i < this->length() ; i++){
            if ( i == 0 ){
                if (_isAplha(_data[0]) && _isLowerCharcter (_data[0])){
                    _data[0] = char(int(_data[0])-32) ;
                }
            }
            if (_data[i] == ' '){
                if (_isLowerCharcter (_data[i+1]) && _isAplha(_data[i+1])){
                    _data[i+1] = char(int(_data[i+1])-32) ;
                }
            }
        }
    }
    void clsString::LowerFirstLetterOfEachWord(){
        for (int i = 0 ; i < this->length() ; i++){
            if ( i == 0 ){
                if (_isAplha(_data[0]) && _isUpperCharcter (_data[0])){
                    _data[0] = char(int(_data[0])+32) ;
                }
            }
            if (_data[i] == ' '){
                if (_isUpperCharcter (_data[i+1]) && _isAplha(_data[i+1])){
                    _data[i+1] = char(int(_data[i+1])+32) ;
                }
            }
        }
    }
    void clsString::UpperAllString(){
        for (int i = 0 ; i < this->length() ; i++){
           if (_isAplha(_data[i])){
            if (_isLowerCharcter(_data[i])){
                _data[i] = char(int(_data[i])-32) ;

            }
           }
        }
    }
    void clsString::LowerAllString(){
        for (int i = 0 ; i < this->length() ; i++){
           if (_isAplha(_data[i])){
            if (_isUpperCharcter(_data[i])){
                _data[i] = char(int(_data[i])+32) ;

            }
           }
        }
    }
    void clsString::InvertLetterCase(){
        if (_isAplha(_data[0]) && _isUpperCharcter (_data[0])){
                    _data[0] = char(int(_data[0])+32) ;
                }
        else if (_isAplha(_data[0]) && _isLowerCharcter (_data[0])){
                    _data[0] = char(int(_data[0])-32) ;
                }
            
    }
    void clsString::InvertAllLettersCase(){
        for (int i = 0 ; i < this->length() ; i ++){
        if (_isAplha(_data[i]) && _isUpperCharcter (_data[i])){
                    _data[i] = char(int(_data[i])+32) ;
                }
        else if (_isAplha(_data[i]) && _isLowerCharcter (_data[i])){
                    _data[i] = char(int(_data[i])-32) ;
                }
        }
    }
    int clsString::CountLetters(){
        int counter = 0 ;
          for (int i = 0 ; i < this->length() ; i ++){
        if (_isAplha(_data[i])){
                    counter++ ;
                }
        }
        return counter ;
    }
    int clsString::CountCapitalLetters(){
         int counter = 0 ;
          for (int i = 0 ; i < this->length() ; i ++){
        if (_isAplha(_data[i]) && _isUpperCharcter(_data[i]) ){
                    counter++ ;
                }
        }
        return counter ;
    }
    int clsString::CountSmallLetters(){
          int counter = 0 ;
          for (int i = 0 ; i < this->length() ; i ++){
        if (_isAplha(_data[i]) && _isLowerCharcter(_data[i]) ){
                    counter++ ;
                }
        }
        return counter ;
    }
    int clsString::CountSpecificLetter(char ch){
        int counter = 0 ;
        ch = _toUpperChar(ch);
        for (int i = 0 ; i < this->length() ; i ++){
            if ( _toUpperChar(_data[i]) == ch){
                counter++ ;
                }
            }
        return counter ;
    }
    bool clsString::IsVowel(char ch){
      ch = tolower(ch);
      return ((ch == 'a') || (ch == 'e') || (ch == 'i') || (ch == 'o') || (ch == 'u'));
    }
    int clsString::CountVowels(){
        int counter = 0 ;
        for (int i = 0 ; i < this->length() ; i++){
            if (this->IsVowel(_data[i])){
                counter ++;
            }
        }
        return counter ;
    }
    vector<string> clsString::Split(string Delim ) {
    int length = Delim.length();
    string word = "";
    vector<string> words;

    for (int i = 0; i < this->length(); i++) {
        bool isMatch = true;

        if (_data[i] == Delim[0]) {
            for (int e = 0; e < length; e++) {
                if (_data[i + e] != Delim[e]) {
                    isMatch = false;
                    break;
                }
            }

            if (isMatch) {
                words.push_back(word);
                word = "";
                i += length - 1;
                continue;
            }
        }

        word += _data[i];
    }

    if (word != "") {
        words.push_back(word);
    }

    return words;
}
    void clsString::TrimLeft() {
        int i = 0;

        // continue all space to first char 
        while (i < this->length() && _data[i] == ' ') {
            i++;
        }

        string newData = "";
        for (; i < this->length(); i++) {
            newData += _data[i];
        }

        _data = newData;
        }
    void clsString::TrimRight() {
        int i = this->length()-1;

        // continue all space to first char 
        while (i >= 0 && _data[i] == ' ') {
            i--;
        }

        string newData = "";
        for (int j = 0; j <= i; j++) {
            newData += _data[j];
            }

        _data = newData;
        }
    void clsString::Trim(){
        this->TrimLeft();
        this->TrimRight();
    }
    void clsString::JoinString(string text , string delim){
         _data +=  delim + text ;
    }
    void clsString::ReverseWordsInString(string delim){
        vector<string> words = this->Split(delim);
        string newWord = "";
        for (int i = words.size()-1 ; i >=0 ; i--){
            newWord+= words[i];
            if (i != 0){
                newWord+=delim ;
            }
        }
        _data = newWord ;
    }
    void clsString::ReplaceWord(string newText, string oldText) {
        vector<string> words = this->Split(" "); 
        bool replaced = false;

        for (auto& word : words) {
            if (word == oldText && !replaced) {
                word = newText;
                replaced = true;
            }
        }

        if (!replaced) {
            std::cout << "Word not found!\n";
            return;
        }

        string newSentence = "";
        for (int i = 0; i < words.size(); ++i) {
            newSentence += words[i];
            if (i != words.size() - 1) {
                newSentence += " "; 
            }
        }

        _data = newSentence;
        }
    void clsString::RemovePunctuations(){
        string newWord ="";
        for (auto &s : _data){
            if(_isAplha(s)||s == ' '){
                newWord += s ;
            }
        }
        _data = newWord ;
    }

}
