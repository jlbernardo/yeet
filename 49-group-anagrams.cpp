#include <algorithm>
#include <iostream>
#include <vector>
#include <deque>
#include <string>


int main(void) {
	std::vector<std::string> strs = {"eat","tea","tan","ate","nat","bat"};
	std::vector<std::string> copy(strs);
	std::deque<std::pair<std::string, int>> ordered;
	int size = strs.size();

	for (int i = 0; i < size; i++) {
		std::sort(copy[i].begin(), copy[i].end());
		ordered.push_back({copy[i], i});
	}

	std::sort(ordered.begin(), ordered.end());

	std::vector<std::vector<std::string>> anagrams;
	std::vector<std::string> group;
	std::deque<int> indexes;

	while (ordered.size()) {
		std::string current = ordered.front().first;

		while (ordered.size() && ordered.front().first == current) {
			indexes.push_back(ordered.front().second);
			ordered.pop_front();
		}

		while(indexes.size()) {
			group.push_back(strs[indexes.front()]);
			indexes.pop_front();
		}

		anagrams.push_back(group);
		group.clear();
	}

	for (auto &same : anagrams) {
		std::cout << "[ ";
		for (auto &word : same)
			std::cout << word << " ";
		std::cout << "]" << std::endl;
	}
}
