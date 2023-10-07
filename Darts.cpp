#include <iostream>
#include <cmath>
#include <stdlib.h>

int Randcoord(int c) {
	srand(time(NULL));
	int x = rand();
	int y = rand();
	if (c < 5) {
		c += x % 5;
	}
	else {
		c -= x % 5;
	}
	return c;
}

int main() {
	int Field[9][9];
	int cini1, cinj1, cini2 ,cinj2;
	
	std::cout << "you see Darts pole, best result 5, for stop write !, for play else char\n";
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if ((5 - sqrt(pow((4-i),2)+pow((4-j), 2))) < 0) {
				Field[i][j] = 0;
			}
			else {
				Field[i][j] = 5 - sqrt(pow((4 - i), 2) + pow((4 - j), 2));
			}
		}
	}
	char play;
	int sum1 = 0;
	int sum2 = 0;
	std::cin >> play;
	while (play != '!') {
		std::cout << "1st plaer \n";
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				std::cout << Field[i][j];
			}
			std::cout << "\n";
		}
		std::cout << "enter sample coordinates due to spreat you'll know your result\n";
		std::cout << "put here 2 nombers from 1 to 8 \n";
		std::cin >> cini1 >> cinj1;
		int it = Randcoord(cini1);
		int jt = Randcoord(cinj1);
		std::cout <<"result:"<<  Field[it][jt] << "\n";
		sum1 += Field[it][jt];

		
		std::cout << "2nd plaer \n";
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				std::cout << Field[i][j];
			}
			std::cout << "\n";
		}
		std::cout << "enter sample coordinates due to spreat you'll know your result\n";
		std::cout << "put here 2 nombers from 1 to 8 \n";
		std::cin >> cini2 >> cinj2;
		int ik = Randcoord(cini2);
		int jk = Randcoord(cinj2);
		std::cout << "result:" << Field[ik][jk] << "\n";
		sum2 += Field[ik][jk];


		std::cout << "Finish, put ! for stop, put else char for play\n";
		std::cin >> play;
	}
	std::cout << "score: \n";
	std::cout << "1st plaer:" << sum1 << "\n";
	std::cout << "2nd plaer:" << sum2 << "\n";
	return 0;
}
