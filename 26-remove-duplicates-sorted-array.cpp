#include <iostream>
#include <vector>

int main(void) {
	std::vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};

	for (int i = 0; i < (int)nums.size() && nums.size() > 1; i++) {
		if (nums.front() == nums.back()) {
			nums.pop_back();
			i--;
		}

		nums.push_back(nums.front());
		nums.erase(nums.begin());
	}

	std::cout << nums.size() << std::endl;
}
