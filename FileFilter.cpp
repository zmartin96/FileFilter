#include "FileFilter.hpp"

fileFilter::fileFilter(const string& inFileName, const string& outFileName)
{
    inFile.open(inFileName);
    outFile.open(outFileName);
    
    if (!inFile) throw string(inFileName);
    if (!outFile) throw string(outFileName);
    
}

void fileFilter::doFilter()
{
    char ch;
    char transCh;
    //ch = inFile.get();
    inFile.get(ch);
    while (!inFile.fail())
    {
        transCh = transform(ch);
        outFile.put(transCh);
        inFile.get(ch);
    }
    
    inFile.close();
    outFile.close();
}

