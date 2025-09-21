#include <iostream>
#include <vector>

int main() {
	std::vector<int> nums = {0, 1, 2, 2, 3, 0, 4, 2};
	int val = 2;
	int j = 0;

	for (std::vector<int>::iterator i = nums.begin(); i < nums.end(); i++) {
		if (nums.at(j) == val){
			nums.erase(i);
			i--;
			j--;
		}
		j++;
	}

	for (unsigned long i = 0; i < nums.size(); i++)
		std::cout << nums[i] << " ";
	std::cout << std::endl;
}
