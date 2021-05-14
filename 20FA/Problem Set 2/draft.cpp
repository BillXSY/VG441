#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <list>
#include <fstream>

using namespace std;

int main(){

	int demand[53];
	fstream file;
	file.open("data.txt", ios::in);
	int i = 1;
	while(!file.eof()){
		file >> demand[i];
		i++;
	}
	file.close();

	int theta[54];
	int s[54];
	theta[53] = 0;
	//s[53] = 10000000;
	for(int t = 52; t >= 1; t--){
		int min = 1000000;
		int flag = 0;
		for(int s = t + 1; s < 54; s++){
			int sum = 1100;
			for(int j = t; j < s; j++){
				sum += 2.4 * (j - t) * demand[j];
			}
			sum += theta[s];
			if( sum < min){ 
				min = sum;
				flag = s;
			}
		}
		theta[t] = min;
		s[t] = flag;
	}
	for(i = 1; i < 54; i++){
		cout << theta[i] << "  " << s[i] << endl;
	}
	int path = 1;
	cout << "the period that purchase happens " << path;
	while(path < 53){
		path = s[path];
		if (path < 53)
			cout << " -> " << path;
	}

	return 0;
}





