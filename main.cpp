int main(int argc, char* argv[]){
	vector<Lang> all_training;
	string filename;
	string test;
	test = argv[argc-1];
	Lang test = Lang(test, argv[argc-1]);
	for (int i=0; i<argc-1; i++){
		filename = argv[i];
		Lang filename = Lang(filname, argv[i]);
		all_training.push_back(filename);
	}
	cout << max_sim(all_training, test) << endl;
	return 0;
}