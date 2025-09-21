#include <string>
#include <iostream>

#define println(x) std::cout << x << std::endl;

int main(void) {
	std::string haystack = "mississippi";
	std::string needle = "issip";
	int i = 0;
	int j = 0;
	int index = -1;

	while (i < (int)haystack.length()) {
		if (j == (int)needle.length())
			break;
		println("Haystack: " << haystack[i] << " [" << i << "]");
		println("Needle:   " << needle[j] << " [" << j << "]" << std::endl);
		if (haystack[i] == needle[j]) {
			j++;
			if (index == -1)
				index = i;
		}
		else {
			if (index != -1)
				i = index;
			j = 0;
			index = -1;
		}
		i++;
	}

	if (i >= (int)haystack.length() && j < (int)needle.length())
		index = -1;

	std::cout << index << std::endl;
}
