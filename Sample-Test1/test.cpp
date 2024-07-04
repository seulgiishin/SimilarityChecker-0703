#include "pch.h"
#include "../SimilarityChecker_KATA/SimilarityChecker.cpp"

using namespace std;

class CheckFixture :public testing::Test {
public:
	SimilarityChecker checker;

	void assertIllegalArgument(string a, string b) {
		try {
			checker.getScore(a,b);
			FAIL();
		}
		catch (exception e) {
			//pass
		}
	}
};

TEST_F(CheckFixture, GetScore) {
	int ret = checker.getScore("AA", "AA");
	EXPECT_EQ(100, ret);
}

TEST_F(CheckFixture, CheckLengthScore60) {
	int ret = checker.getLengthScore("AA", "BB");
	EXPECT_EQ(60, ret);
}

TEST_F(CheckFixture, CheckLengthScore0) {
	int ret = checker.getLengthScore("AA", "AAAAAA");
	EXPECT_EQ(0, ret);
}

TEST_F(CheckFixture, CheckLengthScoreGap1) {
	int ret = checker.getLengthScore("AAABB", "bbbb");
	EXPECT_EQ(45, ret);
}

TEST_F(CheckFixture, CheckLengthScoreGap2) {
	int ret = checker.getLengthScore("AAAB", "bAbbb");
	EXPECT_EQ(45, ret);
}

TEST_F(CheckFixture, CheckAlphaScore40) {
	int ret = checker.getAlphaScore("ASD", "DSA");
	EXPECT_EQ(40, ret);
}

TEST_F(CheckFixture, CheckAlphaScore0) {
	int ret = checker.getAlphaScore("FGH", "DSA");
	EXPECT_EQ(0, ret);
}

TEST_F(CheckFixture, CheckAlphaCapital) {
	assertIllegalArgument("asd", "DSA");
}

TEST_F(CheckFixture, CheckAlphScore20) {
	int ret = checker.getAlphaScore("AA", "AAE");
	EXPECT_EQ(20, ret);
}

TEST_F(CheckFixture, CheckTotalScoreL60A40) {
	int ret = checker.getScore("ASD", "DSA");
	EXPECT_EQ(100, ret);
}

TEST_F(CheckFixture, CheckTotalScoreL0A0) {
	int ret = checker.getScore("FFFFFFFF", "DSA");
	EXPECT_EQ(0, ret);
}

TEST_F(CheckFixture, CheckTotalScoreeL60A0) {
	int ret = checker.getScore("FFF", "DSA");
	EXPECT_EQ(60, ret);
}

TEST_F(CheckFixture, CheckTotalScoreeL60A20) {
	int ret = checker.getScore("AA", "AB");
	EXPECT_EQ(80, ret);
}
