#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

class SimilarityChecker {
public:
	int getScore(string a, string b) {
		if (a == b) return 100;

		return getLengthScore(a, b) + getAlphaScore(a, b);
	}

	int getLengthScore(string a, string b)
	{
		if (a.length() == b.length()) {
			return LENGTH_SCORE_MAX;
		}
		if (a.length() / b.length() >= 2 || b.length() / a.length() >= 2) {
			return LENGTH_SCORE_MIN;
		}
		if (a.length() > b.length()) {
			return (1 - (double((a.length() - b.length())) / b.length())) * LENGTH_SCORE_MAX;
		}
		if (b.length() > a.length()) {
			return (1 - (double((b.length() - a.length())) / a.length())) * LENGTH_SCORE_MAX;
		}
	}

	int getAlphaScore(string a, string b)
	{
		int sameAlphaCount = 0;
		int checkDupAlpha[26] = { 0, };
		int totalAlphaCount = 0;
		int checkTotalAlpha[26] = { 0, };

		if (isCapitalAlpha(a, b) == false) {
			throw invalid_argument("Capital Letters only");
		}

		for (int i = 0; i < a.length(); i++) {
			for (int j = 0; j < b.length(); j++) {
				if (checkTotalAlpha[a[i] - 'A'] == 0) {
					checkTotalAlpha[a[i] - 'A'] = 1;
					totalAlphaCount++;
				}

				if (checkTotalAlpha[b[j] - 'A'] == 0) {
					checkTotalAlpha[b[j] - 'A'] = 1;
					totalAlphaCount++;
				}

				if (a[i] == b[j] && checkDupAlpha[a[i] - 'A'] == 0) {
					sameAlphaCount++;
					checkDupAlpha[a[i] - 'A'] = 1;
				}
			}
		}
		return  ALPHA_SCORE_MAX * sameAlphaCount / totalAlphaCount;
	}

	bool isCapitalAlpha(string a, string b)
	{
		for (int i = 0; i < a.length(); i++) {
			if (a[i] >= 'a' && a[i] <= 'z') return false;
		}

		for (int j = 0; j < b.length(); j++) {

			if (b[j] >= 'a' && a[j] <= 'z') return false;
		}
		return true;
	}
private:
	const int LENGTH_SCORE_MAX = 60;
	const int LENGTH_SCORE_MIN = 0;
	const int ALPHA_SCORE_MAX = 40;
	const int ALPHA_SCORE_MIN = 0;
};