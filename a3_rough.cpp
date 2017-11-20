
//Part "B/C" The reader

DNA(std::ifstream &infile);

ifstream infile(filename);
if (!infile.fail()){
string line;
char ch;
string sequence;


getline(infile, line#1)
header = line;
if (header[0] != '>'){return std::runtime_error("Invalid/no header")}

while (getline(infile, line#2)) {
if ch == '/n')
	{ch = ''}
if (ch!='A' || ch!='T' || ch!='C' || ch!='G' || ch!='N')
	{return std::runtime_error("Invalid sequence")}
sequence += ch;
}
infile.close();
} else 
	{return std::runtime_error("Could not read file")}
}


//fiel opender socntructor thing srah
DNA::DNA(ifstream & info)

//LAB 3 for Part C
ifstream infile(filename);
	string header;



	vector<string> long_o;
	vector<string> final_o;
	if (!infile.fail()){
		string line;

		getline(infile, line);
		if (header[0] != '>'){return std::runtime_error("invalid/no header")}

			while(getline(infile, line)){
				string rev = revcomp(line);
				
			long_o.push_back(rev);
			}
			infile.close();
		}else{
			cerr << "could not open file" << filename << endl;
			exit(EXIT_FAILURE);
		}

		for(int i = long_o.size()-1; i>=0; i--){
			final_o.push_back(long_o[i]);
		} 
for(int i = 0; i <= (int)(final_o.size())-1; i++){
	cout<<final_o[i]<<endl;
}

}

infile.open(read);
	char ch;
	while (infile.get(ch)) {
	DNA_Prime += ch;
}
	infile.close();
	std::ofstream outfile(write);
	if (!outfile.fail()){
		outfile << result;
		outfile.close();
	}
	else {
		std::cerr << "Could not open file" << std::endl;
		exit(EXIT_FAILURE);
}
	

//Sequence Checker


//"QUERY SEARCHER"
size_t find(std::string query, size_t start){
size_t pos = seq.find(query, start);											// Uses the find function on the original sequence
size_t pos_rv = (baby_revcomp(seq)).find(query, start);							// Does the same with the reverse of said sequence, found through a revcomp helper (below)
if (pos <= pos_rv)
	{return pot}
if (pos > pos_rv)
	{return pos_rv}																// Returns whichever position is lower
}

//"ToFASTA"
string toFasta(int columns=80){
string row;																		// Declarations
string wrap_sequence;
for (int i=0; i< (int) sequence.length+1; i++){									// This a complex and unique implementation, bear with me...
	row += sequence[i];															// I count nucleotide-by-nucleotide through the sequence, 
	if (line.length == columns)													// adding them to a string called row until I reach the set length, then clears row.
		{wrap_sequence += (row+'/n');											// I then re-add this sequence, with an endline, to a new output sequence
		row = "";}																// When the original for-loop counter reaches the end of the sequence, I add
	if (i == (int) sequence.length)												// whatever is currently stored in row, which would be any remainder
		{wrap_sequence += (row+'/n')
		break}
}
return wrap_sequence;															// I return the new sequence which contains endlines every 80 characters
}

//"REVCOMP"																	<<<<<<<<<<<<<<<< needs work
string revcomp(string seq) {													// Copy-pasted from one of the labs with a few edits to make it work with DNA input
	vector<string> revcomp_output;
	revcomp_output.push_back(header);											// Adds the header to a vector<string> output
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
	revcomp_output.push_back(result);											// Adds the rev.-comp. of the sequence
	return revcomp_output;
	}
	
//"TRANSLATE" 
vector<string> translate(string seq){
vector<string> 6_seqs = 6_split(seq);   //need to do a nested loop? or i & j?	// Calls a helper function to generate 6 sequences from the sequence entered
string codon;																	// Declarations and resets
string amino_string;
amino_string = "";																
for (i=0; i< (int) ((sub_seq).length/3)*3); i=(i+3)){							// Cuts the sequence into 3-nucleotide strings stored as 'codon'
	codon = sub_seq[i]+sub_seq[i+1]+sub_seq[i+2];
	amino = amino_translate(codon);												// Calls an Codon Reader Helper Function on 'codon' (below)
	if (amino.compare("stop")==0)											// Breaks the loop if a stop codon is reached
		{break}
	amino_string += amino;														// Adds any aminos to string of aminos for that sequence
	}
vector_output.push_back(amino_string);											// Builds a vector<string> of the aminos collected
}
return vector_output;     														// >>>>>>>>>>>>Will this give back the correct vector?
}

//"EQUALITY OPERATOR"														
friend bool operator==(DNA d1, DNA d2){
get.sequence(d1);																// Uses the get.sequence operation on both DNA files & compares the sequence strings
get.sequence(d2);
return (d1.compare(d2));														// Returns the bool result
}

//Make 6 Sequences Helper Function for "TRANSLATE"
vector<string> 6_split(string seq){												// Cuts a substring from original string without the first character
	string seq_1 = seq.substring(size_t 1, size_t seq.length-1);				// Does the same thing again, effcetively subtrating 2 from the front of the original sequence
	string seq_2 = seq_1.substring(size_t 1, size_t seq_1.length-1);
	string seq_rv = baby_revcomp(seq);											// Does the same to the the reverse compliment of the sequence, using a revcomp helper function (below)
	string seq_rv_1 = seq_rv_1.substring(size_t 1, size_t seq_rv.length-1);
	string seq_rv_2 = seq_rv_2.substring(size_t 1, size_t seq_rv_1.length-1);

vector<string> 6_seqs;															// Builds a vector<string> of the original sequence and the 5 new ones made
	6_seqs.push_back(seq);
	6_seqs.push_back(seq_1);
	6_seqs.push_back(seq_2);
	6_seqs.push_back(seq_rv);
	6_seqs.push_back(seq_rv_1);
	6_seqs.push_back(seq_rv_2);

	return 6_seqs;
}

//Revcomp Helper Function for "TRANSLATE" and "QUERY"
string baby_revcomp(string seq) {												// 'baby'/helper function version of the provided revcomp code
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
string amino_translate(string codon){											// Code based on email Dr.Daniels sent out
if (codon == "TAG" || codon == "TAA" || codon == "TGA") {						// Returns STOP or amino acid letters based on codon input
    return("STOP"); 
    continue;}
if (codon == "TTT" || codon == "TTC") {
    return(F);
    continue;}
if (codon == "TTA" || codon == "TTG" || codon == "CTT" || codon == "CTC" || codon == "CTA" || codon == "CTG") {
    return(L);
    continue;}
if (codon == "ATT" || codon == "ATC" || codon == "ATA"){
	return(I);
    continue;}
if (codon == "GTT" || codon == "GTC" || codon == "GTG" || codon == "GTG"){
	return(V);
    continue;}
if (codon == "TCT" || codon == "TCC" || codon == "TCA" || codon == "TCG"){
	return(S);
    continue;}
if (codon == "CCT" || codon == "CCC" || codon == "CCA" || codon == "CCG"){
	return(P);
    continue;}
if (codon == "ACT" || codon == "ACC" || codon == "ACA" || codon == "ACG"){
	return(T);
    continue;}
if (codon == "GCT" || codon == "GCC" || codon == "GCA" || codon == "GCG"){
	return(T);
    continue;}
if (codon == "GTT" || codon == "TAT" || codon == "TAC"){
	return(A);
    continue;}
if (codon == "TAT" || codon == "TAC"){
	return(Y);
    continue;}
if (codon == "CAT" || codon == "CAC"){
	return(H);
    continue;}
if (codon == "CAA" || codon == "CAG"){
	return(Q);
    continue;}
if (codon == "AAT" || codon == "AAC"){
	return(N);
    continue;}
if (codon == "AAA" || codon == "AAG"){
	return(K);
    continue;}
if (codon == "GAT" || codon == "GAC"){
	return(D);
    continue;}
if (codon == "GAA" || codon == "GAG"){
	return(E);
    continue;}
if (codon == "TGT" || codon == "TGC"){
	return(C);
    continue;}	
if (codon == "TGG"){
	return(W);
    continue;}
if (codon == "CGT" || codon == "CGC" || codon == "CGA" || codon == "CGG" || codon == "AGA" || codon == "AGG"){
	return(R);
    continue;}
if (codon == "AGT" || codon == "AGC"){
	return(S);
    continue;}
if (codon == "GGT" || codon == "GGC" || codon == "GGA" || codon == "GGG"){
	return(G);
	}
}
