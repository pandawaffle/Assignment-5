#ifndef _Lang_h
#define _Lang_h

#include <iostream>
#include <string>
#include <vector>

/*
A class to represent Lang Bodys, related to the FASTA format.
A Lang object has two member fields: a Title, which is a Body of characters beginning with the `>` character,
and a Body, which is a Body of characters containing only A, C, T, G, and N.
*/

class Lang {

public:

	/*
	Default constructor
	*/
	Lang();

	/*
	Constructor with separate arguments for Title and Body
	If `Body` contains invalid characters, throws a std::runtime_error
	*/
	Lang(std::string Title, std::string Body);

	/*
	Constructor that expects an input file stream to a FASTA-formatted file
	If the first line is not a valid Title (does not begin with a `>`)
	or if the Body part of the file contains invalid characters 
	(other than newlines, which are removed),
	throws a std::runtime_error
	*/
	Lang(std::ifstream &infile);

	/*
	Getter methods
	*/
	std::string getBody();
	std::string getTitle();

	/*
	Produces FASTA-formatted output as a string, 
	with the Body wrapped to `columns` number of characters (default 80)
	*/
	std::string toFasta(int columns=80);

	/* 
	Returns a new Lang object whose `Title` is the same as this object's,
	and whose underlying `Body` is the reverse complement as this object's.
	*/
	Lang revcomp();

	/*
	Searches the Body for `query`, a string, AND its reverse complement.
	Returns the index of the first instance of `query` or its reverse complement, 
	or `string::npos` if not found.
	*/
	size_t find(std::string query, size_t start);

	/*
	Generates all six possible amino acid Bodys from this Body.
	Returns them as a vector of strings, in unspecified order.
	*/
	std::vector<std::string> translate();

private:

	/*
	the equality operator does not test full equality.
	It returns true if and only if d1 and d2 have the same Body 
	(even if their Titles differ), and false otherwise.
	*/
	friend bool operator==(Lang d1, Lang d2);

	/* instance variables */
	std::string seq;
	std::string hdr;

};


#endif