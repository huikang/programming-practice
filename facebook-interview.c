// sqrt of a number output * output +/- 0.01 of in
// For all numbers > 0
double candidate_sqrt(double in, int * iterations) {
	int low_thr = (in < 1) ? 1:0;
	double sqrt = 0;
	double middle = in / 2.0;
	double min = 0;
	double max = (low_thr) ? 1.0 : in; // this fixes the cases of less than 1		
	while (1) {
		sqrt = middle;
		double tmp = sqrt * sqrt;

		if (fabs(tmp - in) < 0.00001) { // this wasn't working
			return sqrt;
                }

		if (tmp < in) {
			min = middle;
			middle = (min + max) / 2.0;
		} else if (tmp > in) {
			max = middle;
			middle = (min + max) / 2.0;
		}
		
               *iterations = *iterations + 1;
                if (*iterations > 10000) {
                  printf("guess = %f\n", sqrt);
                }
                if (*iterations > 10002) {
                  return sqrt;
		}
	}
}

Candidate Solution below
sqrt(0.000000) = 0.000000 == 0.000000 your answer			iter = 0
sqrt(0.002500) = 0.050000 == 0.050017 your answer			iter = 9
sqrt(0.250000) = 0.500000 == 0.500002 your answer			iter = 16
sqrt(0.090000) = 0.300000 == 0.300013 your answer			iter = 14
sqrt(1.000000) = 1.000000 == 0.999996 your answer			iter = 17
sqrt(1.200000) = 1.095400 == 1.095447 your answer			iter = 14
sqrt(3.900000) = 1.974800 == 1.974841 your answer			iter = 19
sqrt(4.000000) = 2.000000 == 2.000000 your answer			iter = 0
sqrt(16.000000) = 4.000000 == 4.000000 your answer			iter = 1
sqrt(24.500000) = 4.949747 == 4.949748 your answer			iter = 22
