# wordCount

## Purpose

To count the occurences of a specified string in a simple text file using a C++ program.

## Repo Contents

* CountWords.cpp

  * Main CPP file containing all code for the program
    
## Description

Program divided into main function, a counting function, and print function. A template is also used, according to the package <map>. No GUI include with program, simply uses console for user input.
  
* int main()
  * Main function
  * Takes file name from user and words to look for (up to 10)
  * Runs another function to count occurences of target words
  
* int countWords()
  * Streams contents of specified file into memory
  * From list of target words, checks contents of file for number of occurences
  * Saves number of occurences for each word into map template

* void printMap()
  * Prints out map template, which contains target word and number of occurences
