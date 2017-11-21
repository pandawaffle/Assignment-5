#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include "Lang.h"
using namespace std;

string amino_translate(string codon);
string baby_revcomp(string seq);
vector<string> six_split(string seq);

//"Lang CONSTRUCTOR"
Lang::Lang(){																			
	empty_title = "";
	empty_body = "";
}

//"READER, CONSTRUCTOR, AND CHECKER"
Lang::Lang(string name, std::ifstream &infile){												
		string title;
		string title = name;
		string line;
		string body; 									
		char ch;
	while (getline(infile, line)) {												
		body += line;	
	} 	
	for (int i = 0; i < (int) body.length(); i++){
		ch = body[i];
		if (ch=='a' || ch=='b' || ch=='c' || ch=='d' || ch=='e' || ch=='f' || ch=='g' || ch=='h' || ch=='i' || ch=='j' ||
			ch=='k' || ch=='l' || ch=='m' || ch=='n' || ch=='o' || ch=='p' || ch=='q' || ch=='r' || ch=='s' || ch=='t' ||
			ch=='u' || ch=='v' || ch=='w' || ch=='x' || ch=='y' || ch=='z' || ch==' '){
			continue;
		}
	else {throw std::runtime_error("Bad characters in body")};
	bool empty_body = (body.length <= 2);
	infile.close();																
}
	

//"GETTER METHODS"																	// Basically a copy of the point.cpp on Sakai
string Lang::getBody(){
	return body;
}
string Lang::getTitle(){
	return title;
}
bool Lang::getEmpty_body(){
	return empty_body;
}	
vector<int> Lang::getTri_freq(){
	return tri_freq;
}

/* 
	0-Vector Builder: Generates a vector of all possible trigrams with 0 for each frequency 
*/
vector<int> 0_vec(19682);


// vector<int> 0_vec();
	// for (int i=0; i<=19682; i++;){							// 19683 - 1
		// 0_vec.pushback(0);
	// }

// int freq_array_0 [19682] = 0; ***



//"TRANSLATE 27"
int translate_27(char letter){
	int base27;
	switch letter{
		case ' ': base27 = 0 ; break;
		case 'a': base27 = 1 ; break;
		case 'b': base27 = 2 ; break;
		case 'c': base27 = 3 ; break;
		case 'd': base27 = 4 ; break;
		case 'e': base27 = 5 ; break;
		case 'f': base27 = 6 ; break;
		case 'g': base27 = 7 ; break;
		case 'h': base27 = 8 ; break;
		case 'i': base27 = 9 ; break;
		case 'j': base27 = 10 ; break;
		case 'k': base27 = 11 ; break;
		case 'l': base27 = 12 ; break;
		case 'm': base27 = 13 ; break;
		case 'n': base27 = 14 ; break;
		case 'o': base27 = 15 ; break;
		case 'p': base27 = 16 ; break;
		case 'q': base27 = 17 ; break;
		case 'r': base27 = 18 ; break;
		case 's': base27 = 19 ; break;
		case 't': base27 = 20 ; break;
		case 'u': base27 = 21 ; break;
		case 'v': base27 = 22 ; break;
		case 'w': base27 = 23 ; break;
		case 'x': base27 = 24 ; break;
		case 'y': base27 = 25 ; break;
		case 'z': base27 = 26 ; break;
		default: break;
	}
	return base27;
}

/* 
	Trigram Vector Builder: Starts with 0-Vector, but adds frequency to each trigram as it appears 
*/
vector<int> Lang::trigram_vector(Lang langauge){
	vector<int> tri_vec = 0_vec;
																														// int tri_freq = freq_array_0; ***
	string body = language.getBody;
	int vec_pos;
	for (int i = 0; i < (int) (body.length()/3)*3 ; i++){
		vec_pos = translate_27(body[i])*(27^2)+translate_27(body[i+1])*(27^1)+translate_27(body[i+2])*(27^0);
		tri_freq[vec_pos] += 1;
	}
}

/* 
	Cosine Similarity Calculator: After checking if the object was flagged to have an empty body, calculates the similarity between the training object and the test object 
*/
double Lang::cosine_similarity(Lang training, Lang test){
	vector<int> training_vec = training.getTri_vec();
	vector<int> test_vec = test.getTri_vec();
																			//int training_vec = ...  ***
	double cos_sim;
	if training.getEmpty_body()=0){
		cos_sim = 0.0;
		return cos_sim;														//will this work to end prgm
	}
	if test.getEmpty_body()=0){
		cos_sim = 0.0;
		return cos_sim;														//will this work to end prgm
	}
	for (i=0; i=19682; i++){
		sum_AB += (training_vec_vec[i])*(test_vec[i]);
		sum_A^2 += (training_vec[i])*(training_vec[i]);
		sum_B^2 += (test_vec[i])*(test_vec[i]);
	}
	cos_sim = (sum_AB / (sqrt(sum_A^2)*sqrt(sum_B^2)));
	return cos_sim; 
}

/* 
	Find Maximum Similiarity: Compares the cosine similarities of each training object and then returns the title of the highest 
*/
string Lang::max_sim(vector<Lang> all_training, Lang test){
	string most_sim;
	Lang guess = all_training[0];
	for(int i=0; i < all_training.size; i++){
		Lang candidate = all_training[i];
		if(cosine_similarity(candidate, test) > cosine_similarity(guess, test)){
		guess = candidate;
		}
	}
	most_sim = guess.getTitle();
	return most_sim;
}














//GetMax (inspiration for max sim)

int main(int argc, char* argv[])
{int guess = atoi(argv[1]) // guess is something we made up for the program (hence int preceding it)
						// atoi = ascii to integer : turns a string that contains numbers into an integer
						// so now, "10" is the # ten
for(int i=2; i<argc; i++){   					// for(1st item; 2nd item; 3rd item) {}   <--- abstract for loop format
int candidate = atoi(argv[i]);					// 1st item: happens once @ start of loop
if (candidate > guess) guess = candidate;		// 2nd item: happens before each iteration & if it evaluates to true it goes through that iteration
												// 3rd item: happens after each iteration	
}
std:: cout << guess;		//print out guess | cout = print   LOOK UP SYNTAX REGARDNG THIS. What're the ::'s for? why does the << need to be there?
std:: cout << std::endl;	//print out new line | endl = endline
return 0;					//ends the program. the main function can tell teh computer if the application was sucessful, "return 0;" signals this
}







// //"SEPERATE ARGUMENT CONSTRUCTOR"
// Lang::Lang(string title, string body){											// Declarations
	// seq = body;
	// hdr = title;
	// char ch;
		// if (title[0] != '>'){														// Checks if title's first char is >
		// throw std::runtime_error("Invalid/no title");}
	// for (int i = 0; i < (int) body.length(); i++){							
		// ch = body[i];
		// if (ch=='A' || ch=='T' || ch=='C' || ch=='G' || ch=='N'){					// Reads body by character, error-checking if they are A,C,T,G,N
			// continue;
		// }
		// else {throw std::runtime_error("Invalid body");}
	// }
// }



//"QUERY SEARCHER"
size_t Lang::find(string query, size_t start){
	size_t pos = seq.find(query, start);											// Uses the find function on the original body
	size_t pos_rv = (baby_revcomp(seq)).find(query, start);							// Does the same with the reverse of said body, found through a revcomp helper (below)
	if (pos <= pos_rv)
		{return pos;}
	if (pos > pos_rv)
		{return pos_rv;}															// Returns whichever position is lower, or npos if neither are found
	else {return string::npos;}
	}

//"ToFASTA"
string Lang::toFasta(int columns){
	string title;
	title = gettitle();
	string row;																		// Declarations
	string wrap_body;
	wrap_body += title;
	wrap_body += '\n';
	for (int i=0; i< (int) seq.length()+1; i++){									// This a complex and unique implementation, bear with me...
		row += seq[i];																// I count nucleotide-by-nucleotide through the body, 
		if ( (int) row.length() == columns){										// adding them to a string called row until I reach the set length
			wrap_body += row;													// I then re-add this body, with an endline, to a new output body, then clears row.
			wrap_body += '\n';
			row = "";}																// When the original for-loop counter reaches the end of the body, I add
		if (i == (int) seq.length()){												// whatever is currently stored in row, which would be any remainder
			wrap_body += row;											
			wrap_body += '\n';
			break;}
	}
	return wrap_body;															// I return the new body which contains endlines every 80 characters
}

//"REVCOMP"																		
Lang Lang::revcomp(){																	// Copy-pasted from one of the labs with a few edits to make it work with Lang input <<<<<<<<<<<<<<<<<<<<<<<<<<<<<
	string body = Lang::getbody();
	string title = Lang::gettitle();
	
																					// Adds the title to a vector<string> output. THIS SHOULD WORK BY USING LOCAL DATA
	string result;
	for (int i=seq.length()-1; i >= 0; i--) {
		switch (seq[i]) {
			case 'A': result += 'T'; break;
			case 'T': result += 'A'; break;
			case 'C': result += 'G'; break;
			case 'G': result += 'C'; break;
			case 'N': result += 'N'; break;
			default: break;
		}
	}														
	Lang Lang_RV = Lang(title, result);												// Constructs new Lang file with its local title and the reversed string (result)
	return Lang_RV;
}
	
//"TRANSLATE" 
vector<string> Lang::translate(){													// I use 3 helper functions to accomplish translate
	vector<string> six_seqs = six_split(seq);   									// 1st I call a helper function to generate all possible untranslated 6 bodys in a vector from the body entered (see six_split below
	string codon;																	// Declarations and resets
	string amino_string;
	string amino;
	string stop_amino = "STOP";
	vector<string> vector_output;
	for (int seqi=0;  seqi< (int) six_seqs.size(); seqi++){							// Nested for-loops; the first reads through the vector, the 2nd reads through each string
		amino_string = "";
		for (int i=0; i< (int) (((six_seqs[seqi]).length()/3)*3); i=(i+3)){			// Cuts the body into 3-nucleotide strings stored as 'codon'
			codon = six_seqs[seqi].substr(i, 3);
			amino = amino_translate(codon);											// Calls an Codon Reader Helper Function on 'codon' (below)
			if( amino ==  stop_amino){												// End the minor/string loop if a stop codon is reached, but not the major/vector loop
			break;}
			amino_string += amino;													// Adds any aminos to a string of aminos for that body
		}
		vector_output.push_back(amino_string);										// Builds a vector<string> of the amino strings collected
	}
	
	return vector_output;     														// returns the vector output
}

//"EQUALITY OPERATOR"														
bool operator==(Lang d1, Lang d2){
																					// Uses the get.body operation on both Lang files & compares the body strings
	return (d1.getbody()==d2.getbody());									// Apparently == is overloaded for strings I am being told
}

//Make 6 bodys Helper Function for "TRANSLATE"
vector<string> six_split(string seq){												// Cuts a substring from original string without the first character
	string seq_1 = seq.substr(1, seq.length()-1);									// Does the same thing again, effcetively subtrating 2 from the front of the original body
	string seq_2 = seq_1.substr(1, seq_1.length()-1);
	string seq_rv = baby_revcomp(seq);												// Does the same to the the reverse compliment of the body, using a revcomp helper function (below)
	string seq_rv_1 = seq_rv.substr(1, seq_rv.length()-1);
	string seq_rv_2 = seq_rv_1.substr(1, seq_rv_1.length()-1);
vector<string> six_seqs;															// Builds a vector<string> of the original body and the 5 new ones made
	six_seqs.push_back(seq);
	six_seqs.push_back(seq_1);
	six_seqs.push_back(seq_2);
	six_seqs.push_back(seq_rv);
	six_seqs.push_back(seq_rv_1);
	six_seqs.push_back(seq_rv_2);
	return six_seqs;
}

//Revcomp Helper Function for "TRANSLATE" and "QUERY"
string baby_revcomp(string seq) {													// 'baby'/helper function version of the provided revcomp code
	string result;
	for (int i=seq.length()-1; i >= 0; i--) {
		switch (seq[i]) {
			case 'A': result += 'T'; break;
			case 'T': result += 'A'; break;
			case 'C': result += 'G'; break;
			case 'G': result += 'C'; break;
			case 'N': result += 'N'; break;
			default: return "";
		}
	}
	return result;
}

//Codon Reader Helper Function for "TRANSLATE"
string amino_translate(string codon){												// Code based on email Dr.Daniels sent out
if (codon == "TAG" || codon == "TAA" || codon == "TGA") {							// Returns STOP or amino acid letters based on codon input
    return("STOP");
	}
if (codon == "TTT" || codon == "TTC") {
    return("F");
    }
if (codon == "TTA" || codon == "TTG" || codon == "CTT" || codon == "CTC" || codon == "CTA" || codon == "CTG") {
    return("L");
    }
if (codon == "ATT" || codon == "ATC" || codon == "ATA"){
	return("I");
    }
if (codon == "ATG"){
	return("M");
    }
if (codon == "GTT" || codon == "GTC" || codon == "GTA" || codon == "GTG"){
	return("V");
    }
if (codon == "TCT" || codon == "TCC" || codon == "TCA" || codon == "TCG"){
	return("S");
    }
if (codon == "CCT" || codon == "CCC" || codon == "CCA" || codon == "CCG"){
	return("P");
    }
if (codon == "ACT" || codon == "ACC" || codon == "ACA" || codon == "ACG"){
	return("T");
    }
if (codon == "GCT" || codon == "GCC" || codon == "GCA" || codon == "GCG"){
	return("A");
    }
if (codon == "TAT" || codon == "TAC"){
	return("Y");
    }
if (codon == "CAT" || codon == "CAC"){
	return("H");
    }
if (codon == "CAA" || codon == "CAG"){
	return("Q");
    }
if (codon == "AAT" || codon == "AAC"){
	return("N");
    }
if (codon == "AAA" || codon == "AAG"){
	return("K");
    }
if (codon == "GAT" || codon == "GAC"){
	return("D");
    }
if (codon == "GAA" || codon == "GAG"){
	return("E");
    }
if (codon == "TGT" || codon == "TGC"){
	return("C");
    }	
if (codon == "TGG"){
	return("W");
    }
if (codon == "CGT" || codon == "CGC" || codon == "CGA" || codon == "CGG" || codon == "AGA" || codon == "AGG"){
	return("R");
    }
if (codon == "AGT" || codon == "AGC"){
	return("S");
    }
if (codon == "GGT" || codon == "GGC" || codon == "GGA" || codon == "GGG"){
	return("G");}																		// Otherwise returns nothing, just in case
else return "";}