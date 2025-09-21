#include <iostream>
#include <vector>


int main(void) {
	std::vector<int> ratings = {1, 2, 2};

	// std::vector<int> ratings;
	// for (int i = 20000; i >= 0; i--)
	// 	ratings.push_back(i);

	int size = ratings.size();
	int amount = 0;

	std::vector<int> candies(size, 1);

	for (int i = 0; i < size; i++) {
		if (i - 1 >= 0 && ratings[i] > ratings[i - 1])
			candies[i] = candies[i - 1] + 1;
	}
	for (int i = size; i >= 0; i--) {
		if (i + 1 < size && ratings[i] > ratings[i + 1])
			candies[i] = std::max(candies[i], candies[i + 1] + 1);
	}

	std::cout << "Candies: ";
	for (int i = 0; i < size; i++)
		std::cout << candies[i] << " ";
	std::cout << std::endl;

	while (--size >= 0)
		amount += candies[size];

	std::cout << "Amount : " << amount << std::endl;
}







// int main(void) {
// 	std::vector<int> ratings;

// 	for (int i = 20000; i >= 0; i--)
// 		ratings.push_back(i);

// 	int size = ratings.size();
// 	int amount = size;
// 	std::vector<int> candies(size, 1);

// 	for (int i = 0; i < size; i++)
// 		candies.push_back(1);

// 	bool done = false;

// 	while (!done) {
// 		bool adjusted = false;
// 		for (int i = 0; i < size; i++) {
// 			if (i == 0 && i < size - 1) {
// 				if (ratings[i] > ratings[i + 1] && candies[i] <= candies[i + 1]) {
// 					candies[i]++;
// 					amount++;
// 					adjusted = true;
// 				}
// 			}
// 			else if (i > 0 && i < size - 1) {
// 				if (ratings[i] > ratings[i + 1] && candies[i] <= candies[i + 1]) {
// 					candies[i]++;
// 					amount++;
// 					adjusted = true;
// 				}
// 				else if (ratings[i] > ratings[i - 1] && candies[i] <= candies[i - 1]) {
// 					candies[i]++;
// 					amount++;
// 					adjusted = true;
// 				}
// 			}
// 			else if (i == size - 1 && i - 1 >= 0) {
// 				if (ratings[i] > ratings[i - 1] && candies[i] <= candies[i - 1]) {
// 					candies[i]++;
// 					amount++;
// 					adjusted = true;
// 				}
// 			}
// 		}
// 		if (adjusted == false)
// 			done = true;
// 	}

	// std::cout << "Candies: ";
	// for (int i = 0; i < size; i++)
	// 	std::cout << candies[i] << " ";
// 	std::cout << std::endl;
// 	std::cout << "Amount : " << amount << std::endl;
// 	}
