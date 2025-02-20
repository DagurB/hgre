#include <cassert>
#include <iostream>
#include <string>
#include <cstring>

void longestPalindrome(const std::string str, char bogus) {
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

	for (size_t idx = 1; idx < sLen - 1; ++idx) {
		printf("%zu ", palRadii[idx]);
	}
	puts("");
	free(palRadii);
}

int main() {
	std::string s;
	std::cin >> s;
	longestPalindrome(s, '|');

	return 0;
}
