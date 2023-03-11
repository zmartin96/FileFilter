#include <string>
#include <iostream>
#include <fstream>
using namespace std;

//abstract base class
class fileFilter
{
protected:
    ifstream inFile;
    ofstream outFile;
public:
    fileFilter(const string& inFileName, const string& outFileName);

    virtual char transform(char ch) const = 0;

    virtual void doFilter() final;
};

//SimpleEncryption class
class SimpleEncryption : public fileFilter
{
private:
    int encryptKey;
    char transform(char ch) const override
    {
        return ch + this->encryptKey;
    }
public:
    SimpleEncryption(const string& inFileName, const string& outFileName,int key)
    : fileFilter(inFileName, outFileName) {this->encryptKey=key;}
    
};

//SimpleDecryption class
class SimpleDecryption : public fileFilter
{
private:
    int encryptKey;
    char transform(char ch) const override
    {
        return ch-this->encryptKey;
    }
public:
    SimpleDecryption(const string& inFileName, const string& outFileName,int key)
    : fileFilter(inFileName, outFileName) {this->encryptKey=key;}
};

//RemoveLineBreaks class
class RemoveLineBreaks : public fileFilter
{
private:
    char transform(char ch) const override
    {
        if (ch=='\n') ch=' ';
        
        return ch;
    }
public:
    RemoveLineBreaks(const string& inFileName, const string& outFileName)
        : fileFilter(inFileName, outFileName) {}
};

//Capitalize class
class Capitalize : public fileFilter
{
private:
    char transform(char ch) const override
    {
        return toupper(ch);
    }
public:
    Capitalize(const string& inFileName, const string& outFileName)
        : fileFilter(inFileName, outFileName) {}
};
