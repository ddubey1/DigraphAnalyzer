#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include "digraph_functions.h"

using std::cout;
using std::string;

/* Based on user input (a, c, r), printMap prints the contents
   of the map to the console. This function takes in the command,
   a map of digraphs to words, and a vector of the digraphs. */
void printMap(string order, std::map< string, std::vector<string>> digraph_to_words, std::vector<string> digraphs) {
    // printing out the map in ASCII order
    if (order == "a") {
        for(std::map< string, std::vector<string>>::iterator it = digraph_to_words.begin(); it != digraph_to_words.end(); ++it) {
            printDigraphWords(it);
        }
    }
 
    // printing out the map in reverse ASCII order
    if (order == "r") {
        for(std::map< string, std::vector<string>>::reverse_iterator it = digraph_to_words.rbegin(); it != digraph_to_words.rend(); ++it) {
            printDigraphWords(it);
        }
   }

    // printing out the map in order of count (ties broken w/ ASCII)
    if (order == "c") {
        // using selection sort to sort digraphs by count into a vector digraphs
        for(int i = 0; i < ((int) digraphs.size()) - 1; i++) {
            int minIndex = i;
            int minAmount = digraph_to_words[digraphs[i]].size();

            for(int j = i + 1; j < ((int) digraphs.size()); j++) {
                if( ((int) digraph_to_words[digraphs[j]].size()) < minAmount) {
                    minIndex = j;
                    minAmount = digraph_to_words[digraphs[j]].size();
                }
                
                // break ties with ASCII order
                else if ( ((int) digraph_to_words[digraphs[j]].size()) == minAmount) {
                    if(digraphs[j] > digraphs[i]) {
                        minIndex = j;
                        minAmount = (int) digraph_to_words[digraphs[j]].size();
                    }
                }
            }
            string temp = digraphs[i];
            digraphs[i] = digraphs[minIndex];
            digraphs[minIndex] = temp;
        }

        // printing out the words for each digraph in order of count
        for(int i = digraphs.size() - 1; i >= 0; i--) {
            cout << digraphs[i] << ": [";
            for(int j = 0; j < ((int) (digraph_to_words[digraphs[i]]).size()); j++) {
                    cout << (digraph_to_words[digraphs[i]])[j];
                if (j == ((int) ((digraph_to_words[digraphs[i]]).size()) - 1)) {
                    cout << "]";
                }
                else {
                    cout << ", ";
                }
            }
            if(((int) (digraph_to_words[digraphs[i]]).size()) == 0) {
                cout << "]";
            }
            cout << std::endl;
        }
    }


}


/* Takes data from stringstream and puts it into a vector.
   This function takes in a strinigstream and an empty vector 
   to add the digraphs into. */
void stringStream_to_vector(std::stringstream& ss, std::vector<string>& vec) {
  string word;
  while(ss >> word) {
    vec.push_back(word);
  }
}

/* Formats string by converting to lowecase and removing
   punctuation, as necessary. Takes in a string s, and 
   returns the formatted string. */
string formattedString(string s) {
  string output = "";
  for(int i = 0; i < (int) s.length(); i++) {
    if(s.at(i) != ',' && s.at(i) != '!' && s.at(i) != '.' && s.at(i) != '?') {
      output += std::tolower(s.at(i));
    }
  }
  return output;
}

/* Checks if the inputted string is a number.
   Takes in a string command, and returns 0 if
   not a number or 1 if it is a number. */
int isNumber(string command) {
  std::vector<char> numbers = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
  int isNumber = 1;
  for(int i = 0; i < (int) command.length(); i++) {
    // checks if the char of the string is a number in the vector of char numbers
    if(std::count(numbers.begin(), numbers.end(), (char) command[i]) == 0) {
      isNumber = 0;
    }
  }
  // 1 if command is a number
  if(isNumber == 1) {
    return 1;
  }
  // returns 0 otherwise
  else {
    return 0;
  }
}

/* Prints the words corresponding to a specific digraph in the map.
   This function takes an iterator to the specific key of the map
   as input. */
void printDigraphWords(std::map< string, std::vector<string>>::iterator it) {
    cout << it->first << ": [";
    for(int i = 0; i < (int) (it->second).size(); i++) {
        cout << (it->second)[i];
        if (i == ((int) (it->second).size()) - 1) {
            cout << "]";
        }
        else {
            cout << ", ";
        }
    }
    if(((int) (it->second).size()) == 0) {
        cout << "]";
    }
    cout << std::endl;
}

/* Prints the words corresponding to a specific digraph in the map.
   This function takes an iterator to the specific key of the map
   as input. But this function prints the size in the front instead
   of the digraph */
void printDigraphWordsWithSize(std::map< string, std::vector<string>>::iterator it) {
    cout << (int) (it->second).size() << ": [";
    for(int i = 0; i < (int) (it->second).size(); i++) {
        cout << (it->second)[i];
        if (i == ((int) (it->second).size()) - 1) {
            cout << "]";
        }
        else {
            cout << ", ";
        }
    }
    if(((int) (it->second).size()) == 0) {
        cout << "]";
    }
    cout << std::endl;
}

/* Prints the words corresponding to a specific digraph in the map.
   This function takes a reverse iterator to the specific key of the map
   as input. */
void printDigraphWords(std::map< string, std::vector<string>>::reverse_iterator it) {
    cout << it->first << ": [";
    for(int i = 0; i < (int) (it->second).size(); i++) {
        cout << (it->second)[i];
        if (i == ((int) (it->second).size()) - 1) {
            cout << "]";
        }
        else {
            cout << ", ";
        }
    }
    if(((int) (it->second).size()) == 0) {
        cout << "]";
    }
    cout << std::endl;
}
