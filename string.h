#pragma once 
#include<iostream>
#include <vector> 
#include <functional>
#include<cctype>

using namespace std ;
namespace stringFile {
    class clsString {
        private :
            string _data ;
            vector<string> _words = _word();
            bool _isAplha(char alpha){
                if ((int(alpha) >=65 && int(alpha)<=90) ||
                (int(alpha) >=97 && int(alpha)<=122)){
                    return true ;
                }
                    return false ;
                }
            vector <string> _word (){
                vector <string> words ;
                string word ;
                    for (int i  = 0 ; i < this->length() ; i++){
                        if (this->_isAplha(_data[i])){
                                word += _data [i];
                        }
                        else if (_data[i] == ' '){
                            if (_isAplha(word[0])){
                                words.push_back(word);
                            }
                            word = "";
                        }
                    }
                    if (!word.empty() && this->_isAplha(word[0])){
                            words.push_back(word);
                            word = "";
                    }
                    return words ;
                    }
            bool _isUpperCharcter (char alpha){
                if ((int(alpha) >=65 && int(alpha)<=90) ){
                    return true ;
                }
                return false ;
            }
            bool _isLowerCharcter (char alpha){
                if ((int(alpha) >=97 && int(alpha)<=122) ){
                    return true ;
                }
                return false ;
            }
            char _toUpperChar (char ch){
                if (_isLowerCharcter(ch)){
                    ch = char(int(ch)-32);
                }
                return ch ;
            }
            char _toLowerChar (char ch){
                if (_isUpperCharcter(ch)){
                    ch = char(int(ch)+32);
                }
                return ch ;
            }
            void _applyTransformation(bool toUpper, std::function<bool(int)> shouldProcess) {
                for (int i = 0; i < this->length(); i++) {
                    if (shouldProcess(i)) {
                        _convertCharacterCase(_data[i], toUpper);
                    }
                }
            }
            char _convertCharacterCase(char& ch, bool toUpper) {
                if (_isAplha(ch)) {
                    if (toUpper && _isLowerCharcter(ch)) {
                        return char(int(ch) - 32);
                    }
                    else if (!toUpper && _isUpperCharcter(ch)) {
                        return char(int(ch) + 32);
                    }
                }
                return ' ';
    }

        public :
            clsString (string data) ;
            void setData (string data);
            string getData ();
            void setWords (vector<string> words);
            vector<string> getWords() ;
            int length () ;
            int countWords ();
            void  UpperFirstLetterOfEachWord () ;
            void  LowerFirstLetterOfEachWord () ;
            void  UpperAllString ();
            void  LowerAllString () ;
            void  InvertLetterCase() ;
            void  InvertAllLettersCase() ;
            int  CountLetters() ;
            int  CountCapitalLetters() ;
            int  CountSmallLetters() ;
            int  CountSpecificLetter(char a) ;
            static bool  IsVowel(char) ;
            int  CountVowels() ;
            vector <string> Split(string Delim ) ;
            void  TrimLeft ();
            void  TrimRight();
            void  Trim();
            void  JoinString (string text , string delim);
            void  ReverseWordsInString(string delim);
            void  ReplaceWord(string newText , string oldText);
            void  RemovePunctuations();
    };
}
