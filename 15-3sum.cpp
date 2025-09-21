#include <algorithm>
#include <iostream>
#include <vector>


int main(void) {
	std::vector<int> nums = {0, 0, 0};
	std::vector<std::vector<int>> triplets;
	int size = nums.size();

	std::sort(nums.begin(), nums.end());

	for (int i = 0; i < size && nums[i] <= 0; i++) {
		if (i > 0 && nums[i] == nums[i - 1])
			continue;

		if (size - i - 1 >= 2) {
			int left = i + 1;
			int right = size - 1;

			while (left != right) {
				if (nums[i] + nums[left] + nums[right] == 0) {
					triplets.push_back({nums[i], nums[right--], nums[left]});
					while (nums[right] == nums[right + 1] && right > left)
						right--;
				}
				else if (nums[i] + nums[left] + nums[right] < 0) {
					left++;
				}
				else if (nums[i] + nums[left] + nums[right] > 0) {
					right--;
				}
			}
		}
	}

	std::cout << "Triplets: ";
	for (int i = 0; i < (int)triplets.size(); i++) {
		std::cout << "[ ";
		for (int j = 0; j < 3; j++) {
			std::cout << triplets[i][j] << " ";
		}
		std::cout << "] ";
	}
	std::cout << std::endl;
}
