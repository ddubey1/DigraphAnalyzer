#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "digraph_functions.h"


using std::cout;
using std::string;
using std::cin;



int main(int argc, char * argv[]) {

  
  // if number of arguments is not correct, exit with code 1!
  if (argc != 3) {
    cout<<"Invalid arguments";
    return 1;
  }

  // if the "order" argument is not valid, exit with code 1!
  string order(argv[2]);
  if (order != "r" && order != "a" && order != "c") {
    cout<<"Invalid arguments";
    return 1;
  }
  
  // Reading file, storing filename
  string filename = argv[1];
  std::ifstream ifile(filename);

  // reads first line of file into a stringstream
  string firstLine;
  getline(ifile, firstLine);
  std::stringstream ssFirstLine(firstLine);

  // Storing number of digraphs and the digraphs into an int and a vector, respectively
  int numDigraphs;
  ssFirstLine >> numDigraphs;
  std::vector<string> digraphs;
  stringStream_to_vector(ssFirstLine, digraphs);

  // Skip empty line
  string emptyLine;
  getline(ifile, emptyLine);

  // Declaring a map which holds the digraphs as its keys and vectors containing the words as its values
  std::map< string, std::vector<string> > digraph_to_words;
  for(int i = 0; i < numDigraphs; i++) {
    digraph_to_words[digraphs[i]];
  }


  // Reading in the paragraph and filling the map
  string paragraphLine;
  while (getline(ifile, paragraphLine)) {
    std::stringstream ss(paragraphLine);
    string pWord;
    while (ss >> pWord) {
      for(int i = 0; i < numDigraphs; i++) {
        // checks if the digraphs can be found in the word
        if (pWord.find(digraphs[i]) != string::npos) { // if digraph (e.g. digraph[i]) is in pWord, then push pWord back in the map
          digraph_to_words[digraphs[i]].push_back(formattedString(pWord));
        }
      }
    }
  }

  printMap(order, digraph_to_words, digraphs);

  // Take in user queries
  cout << "q?>";
  string command;
  cin >> command;

  // Keeps taking input until exit is entered
  while(command != "exit") {
    command = formattedString(command);
    // If the command is a number
    if (isNumber(command) == 1) {
      std::stringstream s_num(command);
      int num;
      s_num >> num;
      int found = 0;
      for(std::map< string, std::vector<string>>::iterator it = digraph_to_words.begin(); it != digraph_to_words.end(); ++it) {
        if((int)(it->second).size() == num) {
          found++;
          printDigraphWords(it);
        }
      }
      if (found == 0) {
        cout << "None" << std::endl;
      }
    }
    
    // If the command is not a number
    else {
      if(std::count(digraphs.begin(), digraphs.end(), command)) { // check if this digraph exists
        // get an iterator to the digraph
        for(std::map< string, std::vector<string>>::iterator it = digraph_to_words.begin(); it != digraph_to_words.end(); ++it) {
          if(it->first == command) {
            // print out the digraph
            printDigraphWordsWithSize(it);
            break;
          }
        }
      }
      else {
        cout << "No such digraph" << std::endl;
      }
    }
    // Take in next input
    cout << "q?>";
    cin >> command;
    string command;
  }

  return 0;
}