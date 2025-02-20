#include <cassert>
#include <iostream>
#include <string>
#include <cstring>

std::string longestPalindrome(const std::string str, char bogus) {
	std::string s(2 * str.length() + 1, bogus);
	for (size_t idx = 1; idx < s.length(); idx += 2) {
		assert(idx < s.length());
		assert((idx >> 1) < str.length());
		s[idx] = str[idx >> 1];
	}
	const size_t sLen = s.length();

	size_t* palRadii = (size_t*)malloc(sLen * sizeof(size_t));
	memset(palRadii, '\0', sLen * sizeof(size_t));
	size_t currCenter = 0;
	size_t currRadius = 0;

	while (currCenter < sLen) {
		while (currCenter >= currRadius + 1 && currCenter + currRadius + 1 < sLen && s[currCenter - currRadius - 1] == s[currCenter + currRadius + 1]) {
			++currRadius;
		}
		palRadii[currCenter] = currRadius;
		size_t origCenter = currCenter;
		size_t origRadius = currRadius;
		++currCenter;
		currRadius = 0;


		while (currCenter <= origCenter + origRadius) {
			size_t mirroredCenter = origCenter - (currCenter - origCenter);
			size_t maxMirroredRadius = origCenter + origRadius - currCenter;
			if (palRadii[mirroredCenter] < maxMirroredRadius) {
				palRadii[currCenter] = palRadii[mirroredCenter];
				++currCenter;
			} else if (palRadii[mirroredCenter] > maxMirroredRadius) {
				palRadii[currCenter] = maxMirroredRadius;
				++currCenter;
			} else {
				currRadius = maxMirroredRadius;
				break;
			}
		}
	}

	size_t best = 0;
	size_t bestIdx = 0;
	for (size_t idx = 0; idx < sLen; ++idx) {
		if (palRadii[idx] > best) {
			best = palRadii[idx];
			bestIdx = idx;
		}
	}

	size_t bestCenter = bestIdx >> 1; // translate from "s" index to "str" index
	size_t bestLeft = bestCenter - (best >> 1);

	free(palRadii);
	return str.substr(bestLeft, best);
}

int main() {
	std::string s;
	std::cin >> s;
	std::cout << longestPalindrome(s, '|') << '\n';

	return 0;
}
