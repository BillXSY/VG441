#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <list>
#include <fstream>

using namespace std;

int main(){

	int demand[8] = {0, 220, 155, 105, 90, 170, 210, 290};
	int theta[9];
	int s[9];
	theta[8] = 0;
	//s[53] = 10000000;
	for(int t = 7; t >= 1; t--){
		int min = 1000000;
		int flag = 0;
		for(int s = t + 1; s < 9; s++){
			int sum = 1000;
			for(int j = t; j < s; j++){
				sum += 1.2 * (j - t) * demand[j];
			}
			cout << "from " << t << " to " << s << " is " << sum << endl;
			sum += theta[s];
			if( sum < min){ 
				min = sum;
				flag = s;
			}
		}
		theta[t] = min;
		s[t] = flag;
	}
	for(int i = 1; i < 9; i++){
		cout << theta[i] << "  " << s[i] << endl;
	}
	int path = 1;
	cout << "the period that purchase happens " << path;
	while(path < 8){
		path = s[path];
		if (path < 8)
			cout << " -> " << path;
	}

	return 0;
}





