
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <conio.h> // For getch()
#include <chrono>  // For measuring time

using namespace std;
using namespace chrono;

// Trie Node Structure
struct TrieNode {
    TrieNode* children[26];
    bool isEndOfWord;

    TrieNode() {
        isEndOfWord = false;
        fill(begin(children), end(children), nullptr);
    }
};

// Trie Class
class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            int index = c - 'a';
            if (node->children[index] == nullptr) {
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
        }
        node->isEndOfWord = true;
    }

    vector<string> getSuggestions(const string& prefix) {
        TrieNode* node = root;
        for (char c : prefix) {
            int index = c - 'a';
            if (node->children[index] == nullptr) {
                return {};
            }
            node = node->children[index];
        }

        vector<string> suggestions;
        findSuggestions(node, prefix, suggestions);
        return suggestions;
    }

    void findSuggestions(TrieNode* node, string prefix, vector<string>& suggestions) {
        if (node->isEndOfWord) {
            suggestions.push_back(prefix);
        }
        for (int i = 0; i < 26; ++i) {
            if (node->children[i]) {
                findSuggestions(node->children[i], prefix + char('a' + i), suggestions);
            }
        }
    }

    string autoComplete(const string& prefix) {
        vector<string> suggestions = getSuggestions(prefix);
        if (!suggestions.empty()) {
            return suggestions[0];
        }
        return prefix;
    }
};

// Load dictionary from file
void loadDictionary(Trie& trie, const string& filename) {
    ifstream file(filename);
    string word;
    while (file >> word) {
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        trie.insert(word);
    }
    file.close();
}

// Display suggestions and handle user selection
string displaySuggestions(Trie& trie, const string& currentWord) {
    // Start measuring time
    auto start = high_resolution_clock::now();

    vector<string> suggestions = trie.getSuggestions(currentWord);

    // End measuring time
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start); // Measure in microseconds

    // Output the time taken to find suggestions
    cout << "\nTime taken to find suggestions: " << duration.count() << " microseconds.\n";

    if (suggestions.empty()) {
        cout << "\nNo suggestions found.\n";
        return currentWord;
    }

    cout << "\nSuggestions:\n";
    for (size_t i = 0; i < min(suggestions.size(), size_t(5)); ++i) {
        cout << i + 1 << ". " << suggestions[i] << "\n";
    }

    cout << "Choose a suggestion (1-5) or press any other key to cancel: ";
    char choice = _getch();
    if (choice >= '1' && choice <= '5') {
        int index = choice - '1';
        if (index < suggestions.size()) {
            return suggestions[index];
        }
    }
    cout << "\n";
    return currentWord;
}

// Main real-time input processing
void realTimeAutoComplete(Trie& trie) {
    string sentence = "";
    string currentWord = "";
    cout << "Start typing your sentence (Press '/' to auto-complete the current word, '\\' for suggestions, and 'Enter' to finish):" << endl;
    cout << "> ";

    while (true) {
        char ch = _getch(); // Read single character without waiting for Enter key

        if (ch == '\r') { // Enter key
            cout << endl << "Final sentence: " << sentence + currentWord << endl;
            break;
        }
        else if (ch == ' ') { // Space key
            // Add current word to sentence
            sentence += currentWord + " ";
            cout << " ";
            currentWord = "";
        }
        else if (ch == '/') { // Auto-complete key
            // Complete the current word and replace it
            string completedWord = trie.autoComplete(currentWord);
            for (int i = 0; i < currentWord.size(); i++) {
                cout << "\b \b"; // Remove incomplete word from console
            }
            cout << completedWord; // Display completed word
            currentWord = completedWord;
        }
        else if (ch == '\\') { // Suggestion key
            // Display suggestions and handle user choice
            string chosenWord = displaySuggestions(trie, currentWord);
            for (int i = 0; i < currentWord.size(); i++) {
                cout << "\b \b"; // Remove incomplete word from console
            }
            cout << chosenWord; // Display selected word
            currentWord = chosenWord;
            cout << "\n" << sentence << currentWord; // Display current progress again
            cout << "\n> ";
        }
        else if (ch == '\b') { // Backspace key
            // Handle backspace for current word and console display
            if (!currentWord.empty()) {
                currentWord.pop_back();
                cout << "\b \b"; // Remove last character from console
            }
        }
        else {
            // Append character to current word and display it
            currentWord += ch;
            cout << ch;
        }
    }
}

int main() {
    Trie trie;
    string filename = "C:\\Users\\Hashmi\\Desktop\\DSA\\DSA Project\\words_alpha.txt";
    loadDictionary(trie, filename);

    realTimeAutoComplete(trie);

    return 0;
}