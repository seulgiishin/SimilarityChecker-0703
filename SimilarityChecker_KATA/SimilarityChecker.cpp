#include <iostream>
#include <string>

using namespace std;

class SimilarityChecker {
public:
	int getScore(string a, string b) {
		if (a == b) return 100;
		if (a.length() == b.length()) {
			return LENGTH_SCORE_MAX;
		}
		if (a.length() / b.length() >= 2 || b.length() / a.length() >= 2) {
			return 0;
		}
		if (a.length() > b.length()) {
			return (1 - (double((a.length() - b.length())) / b.length())) * LENGTH_SCORE_MAX;
		}
		if (b.length() > a.length()) {
			return (1 - (double((b.length() - a.length())) / a.length())) * LENGTH_SCORE_MAX;
		}
	}
private:
	const int LENGTH_SCORE_MAX = 60;
};