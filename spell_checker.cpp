/**
 * To create a Word Spell Checker in C++ using a Command Line Interface (CLI), you'll need:
 * 1. A dictionary file (e.g., a text file) containing valid words.
 * 2. An algorithm to check if a word is in the dictionary.
 * 3. Optionally, an algorithm to suggest corrections.
 */
#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>
#include <algorithm>
#include <vector>

using namespace std;

unordered_set<string> loadDictionary(const string& fileName)
{
    unordered_set<string> dictionary;
    ifstream file(fileName);
    string word;

    if (file.is_open())
    {
        while(getline(file, word))
        {
            transform(word.begin(), word.end(), word.begin(), ::tolower);
            dictionary.insert(word);
        }
        file.close();
    }
    else
    {
        cerr << "Couldn't open the dictionary file." << endl;
    }

    return dictionary;
}

bool checkSpelling(const unordered_set<string>& dictionary, const string& word)
{
    return dictionary.find(word) != dictionary.end();
}

vector<string> suggestCorrections(const unordered_set<string>& dictionary, const string& word)
{
    vector<string> suggestions;
    string alphabet = "abcdefghijklmnopqrstuvwxyz";

    for (size_t i = 0; i < word.length(); i++)
    {
        string modifiedWord = word;
        
        for (char c : alphabet)
        {
            modifiedWord[i] = c;
            
            if (dictionary.find(modifiedWord) != dictionary.end() && modifiedWord != word)
            {
                suggestions.push_back(modifiedWord);
            }
        }
    }

    return suggestions;
}

int main()
{
    string dictionaryPath = "/home/josemanuel/Documents/Personal/Learning/C++/Word Spell Checker/dictionary.txt";
    unordered_set<string> dictionary = loadDictionary(dictionaryPath);

    if (dictionary.empty())
    {
        cerr << "Error: The dictionary is empty or couldn't be loaded correctly." << endl;
        return 1;
    }
    
    string inputWord;
    cout << "Enter the word to check its spelling: ";
    cin >> inputWord;

    transform(inputWord.begin(), inputWord.end(), inputWord.begin(), ::tolower);

    if (checkSpelling(dictionary, inputWord))
    {
        cout << "'" << inputWord << "' is spelled correctly." << endl;
    }
    else
    {
        cout << "'" << inputWord << "' is not spelled correctly." << endl;

        vector<string> suggestions = suggestCorrections(dictionary, inputWord);

        if (!suggestions.empty())
        {
            cout << "Did you mean: ";
            for (const string& suggestion : suggestions)
            {
                cout << suggestion << " ";
            }
            cout << endl;
        }
        else
        {
            cout << "No suggestions found." << endl;
        }
    }

    return 0;
}
