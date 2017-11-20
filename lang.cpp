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
Lang::Lang(){																			// Basic constructor setting default values
	hdr = ">";
	seq = "";
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

//"READER, CONSTRUCTOR, AND CHECKER"
Lang::Lang(string name, std::ifstream &infile){												
		string title;
		string title = name;
		string line;
		string body; body = "";		// need to define again?									
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
	else {throw std::runtime_error("Bad characters in body");
	bool empty = (body.length <= 2);
	infile.close();																
}
	

//"GETTER METHODS"																	// Basically a copy of the point.cpp on Sakai
string Lang::getBody(){
	return body;
}
string Lang::getTitle(){
	return title;
}

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