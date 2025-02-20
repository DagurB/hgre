all:
	clang++ yosupo.cpp -o yosupo -Wall -Wextra -O3 -g -march=native -fomit-frame-pointer
	clang++ longestPalindrome.cpp -o longestPalindrome -Wall -Wextra -O3 -g -march=native -fomit-frame-pointer

dbg:
	clang++ yosupo.cpp -o yosupo -Wall -Wextra -O2 -g -march=native -fsanitize=address,undefined
	clang++ longestPalindrome.cpp -o longestPalindrome -Wall -Wextra -O2 -g -march=native -fsanitize=address,undefined
