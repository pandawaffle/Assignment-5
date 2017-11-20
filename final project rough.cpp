Okay design document rough ducklings

How do:

Set up a smaller base example (10) before testing with 27
Set up base 27

throw errors for non-input chars;
big ol' check system like in DNA, looking for a-z, ' ', and '\n'
	else throw runtime error 'bad char'
	
0 vector is not angle of 0, its length of 0; define as special case

implement similarity

for(i=0; i=(n-1); i++){
	sum_AB += (A[i])*(B[i]);
	sum_A^2 += (A[i])*(A[i]);
	sum_B^2 += (B[i])*(B[i]);
}
cos_sim = (sum_AB / (sqroot(sum_A^2)*sqroot(sum_B^2)));
return cos_sim;                                         // ???

get_cos_sim;


if ((abs_value(get_cos_sim.lang_target)-abs_value(get_cos_sim.lang_pool)) < guess_cos_diff){   // How to absolute value
	guess_cos_diff = (abs_value(get_cos_sim.lang_target)-abs_value(get_cos_sim.lang_pool));
	lang_guess = lang_pool;
}



Lang::Lang(std::ifstream &infile){	
string body_rough;
while (getline(infile, line)) {												
		body_rough += line;
}


for (argv