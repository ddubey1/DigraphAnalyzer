#ifndef DIGRAPH_FUNCTIONS_H
#define DIGRAPH_FUNCTIONS_H

#include <string>
#include <map>
#include <vector>

// Takes data from stringstream and puts it into a vector
void stringStream_to_vector(std::stringstream& ss, std::vector<std::string>& vec);

// Formats strings (converting to lowercase and removing punctuation)
std::string formattedString(std::string s);

// prints out the map based on the user's input (a, c, r)
void printMap(std::string order, std::map< std::string, std::vector<std::string>> digraph_to_words, std::vector<std::string> digraphs);

// checks if the string is a number (returns 1 if true, 0 if false)
int isNumber(std::string command);

// prints the words corresponding to a specific digraph in the map (taking in an interator to that digraph)
void printDigraphWords(std::map< std::string, std::vector<std::string>>::iterator it);

// prints the words corresponding to a specific digraph in the map (taking in an interator to that digraph), and prints the size of the vector at the front instead of the digraph
void printDigraphWordsWithSize(std::map< std::string, std::vector<std::string>>::iterator it);

// prints the words corresponding to a specific digraph in the map (taking in a reverse interator to that digraph)
void printDigraphWords(std::map< std::string, std::vector<std::string>>::reverse_iterator it);


#endif // DIGRAPH_FUNCTIONS_H