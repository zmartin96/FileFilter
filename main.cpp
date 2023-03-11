#include "FileFilter.hpp"

int main()
{
    try
    {
        string location="/Users/zacharymartin/Documents/XCode Projects/FileFilter/FileFilter/",
        baseFile, upperFile, lineFile, encryptFile, decryptFile;
        
        int key;
        cout << "Enter name of the base file to manipulate: ";
        cin >> baseFile;
        cout << "Enter name of file to receive the encrypted text: ";
        cin >> encryptFile;
        cout<<"Enter an integer encryption key between one and ten: ";
        cin>>key;
        while (key<1||key>10)
        {
            cout<<"Enter an integer between one and ten: ";
            cin>>key;
        }
        SimpleEncryption e(location+baseFile, location+encryptFile,key);
        e.doFilter();
        cout << "Encrypted Successfully.\n\n"
             << "Enter name of file to receive the decrypted text: ";
        cin >> decryptFile;
        
            
        cout<<"Enter an integer decryption key between one and ten: ";
        cin>>key;
        while (key<1||key>10)
        {
            cout<<"Enter an integer between one and ten: ";
            cin>>key;
        }
        
        SimpleDecryption d(location+encryptFile, location+decryptFile,key);
        d.doFilter();
        cout << "Decrypted Successfully.\n\n"
             << "Enter name of file to receive the capitalized text: ";
        cin >> upperFile;
        Capitalize c(location+baseFile, location+upperFile);
        c.doFilter();
        d.doFilter();
        cout << "Capitalized Successfully.\n\n"
             << "Enter name of file to receive the text with line breaks removed: ";
        cin >> lineFile;
        RemoveLineBreaks r(location+baseFile, location+lineFile);
        r.doFilter();
        cout << "Line Breaks Removed Successfully.\n\n";
    }
    
    catch (string s)
    {
        cout<<"The file \""<<s<<"\" could not be opened!\n\n";
        exit(-1);
    }
    
    return 0;
}
