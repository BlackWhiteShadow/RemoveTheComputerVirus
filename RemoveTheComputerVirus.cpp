/* 
RemoveTheComputerVirus.cpp : Your computer might have been infected by a virus! Create a function that finds the viruses in files and removes them from your computer.
                             Bad files will contain "virus" or "malware", but "antivirus" and "notvirus" will not be viruses.
                             Return "PC Files: Empty" if there are no files left on the computer.
*/

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

string removeVirus(string files) 
{
    vector<string> words;
    istringstream ss(files);
    string word, newFiles; 

    while (ss >> word)
    {
        words.push_back(word);
    }

    for (int i = 0; i < words.size(); i++)
    {
        if ((words[i].find("virus") != string::npos) && (words[i].find("antivirus.exe") == string::npos) && (words[i].find("notvirus.exe") == string::npos))
        {
            words.erase(words.begin() + i);
            i--;
        }
        else
            newFiles += words[i] + " ";
    }

    return newFiles;
}

int main()
{
    string files = "PC Files: spotifysetup.exe, virus.exe, dog.jpg";


    cout << removeVirus(files);
}


