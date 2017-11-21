### Design Doc for Assignment 5
### Dennis Byrd
### byrd.dennis@gmail.com

### Problems to solve ###
The final product must read plain ASCII text files named on command line. These files will only contain lowercase a-z, ' ', and '\n'.
The first n-1 files will be 'training' files from which the program will construct a trigram frequency vector for the text within each file.
The last file will be a 'test' file whose language will be matched to one of the training files by cosine similarity between its trigram frequency vector and the training files.
### Sub-Problems ###
If bad characters are encountered within the body of a file the program must throw STDERR's and produce no output.
A working compile script that serves each executable file in the program must be included.
A git log of the development process will accompany the final product.
The program must not take extraordinary time to run.

	
### My approach ###
I will be heavily cannabilizing Assignment 3's DNA.h and DNA.cpp, along with the class-based strategy used.
	A main.cpp with a main function will be included to parse the command line arguments to DNA.h and DNA.cpp.
My first step will be to make a language document object (Lang) with two immediate string components: title and body.
	Title will be acquired from acquired from the argument vector, while body will be acquired from an the file contents. 
	When body is acquired its contents will be checked for bad characters.
	A second check will determine if the body is 2 or fewer characters, and 'flag' the object accordingly as having an 'empty' body.
	main.cpp will create a lang object for each file named by their argv.
This object will be defined in a Lang.h file, along with other functions that will be programmed in a Lang.cpp file.
	Starter code for these files will be created by using find & replace on DNA.h and DNA.cpp to replace several key terms*.
The test lang object will be made first, as its frequency vector will be needed for computing the cosine similiarity values of the other objects.
Each object will have 4 properties: title, body, empty-body flag, and trigram frequency vector (tri_freq). Each of these will be accessible with a getter function.
Trigrams will be made from the body of each object. Each time a trigram appears that object's trigram frequency vector for that specific trigram will be incremented by 1.
The trigram frequency vector will be a vector of base 10 integers, but the positions of the vector will be represented using a 3-digit, base 27 number to represent each possible trigram.
A '0-Vector' will be procedurally generated for the purposes of incrementation.
Using the function provided in the requirements document the cosine similiarity between a training object and the test object will be calculated.
	If the object was flagged to have an empty body the cosine similarity will automatically be set to 0.
	This function will be abstracted so as to take 2 language objects and return their cosine similiarty.
The training object with the highest cosine similarity value will be our final result. To search for this a cannabilization of the findmax.cpp function provided in lecture will be used.
	This function will be passed a vector of Lang objects created by the main file.
	The cosine similiarity between each object in the vector and the test file will be calculated by calling the cosine similarity function.
	It will be very simple to output the title of the most similar file using a the 'getTitle' function.
My approach will be tested and developed using example ASCII language files and the main function.

*"DNA" with "Lang", "header" with "title", and "sequence" with "body".


### Function Glossary ###

# main.cpp #
/* Command Line Parser: Calls Lang.h/Lang.cpp to work on each file in the command line, then calls max_sim on the all the training files and outputs the result */
	int main(int argc, char *argv[])
	
# Lang.h and Lang.cpp #
/* Default constructor */
	Lang::Lang();
	
/* From-file Constructor: Expects an input file stream to one of the training or test files */
	Lang::Lang(string title, ifstream &infile)
	
/* Getter Methods: Each returns their respective object property */
	string Lang::getBody()
	string Lang::getTitle()
	bool Lang::getEmpty()
	vector<int> Lang::getTri_freq()
	
/* 0-Vector Builder (Helper Function): Generates a vector of all possible trigrams with 0 for each frequency */
	vector<int> Lang::0_vector();
	
/* Trigram Vector Builder: Starts with 0-Vector, but adds frequency to each trigram as it appears */
	vector<int> Lang::trigram_vector(Lang langauge);
	
/* Roman Alphabet to Base 27 Translator (Helper Function): Assigns values as needed to code Roman Alphabet letters and SPACE into base 27 characters */
	translate_27(char letter)
	
/* Cosine Similarity Calculator: After checking if the object was flagged to have an empty body, calculates the similarity between the training object and the test object */
	double Lang::cos_sim(Lang langauge1, Lang langauge2)
	
/* Find Maximum Similiarity: Compares the cosine similarities of each training object and then returns the title of the highest */
	Lang Lang::max_sim(vector<Lang> training_all, Lang test)

	
### Libraries Needed ###

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>

(non-library header items)
#include "Lang.h"
using namespace std;


### Files Needed ###

Lang.h
Lang.cpp
main.cpp
compile   				(will compile Lang.cpp and main.cpp)
README.md


### Considerations ###
I anticipate the most difficulty will arise with the implementation of the base 27 vector and creating the 0-Vector. We have not covered implementing integers other than base 10 in lab, nor procedural generation.
The compile script may also provide challenge, as I have never looked under the hood of one before. Ideally all that would be needed is a cannabalization an existing script with a change to the file targets.
