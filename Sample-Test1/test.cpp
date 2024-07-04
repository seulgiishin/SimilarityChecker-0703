#include "pch.h"
#include "../SimilarityChecker_KATA/SimilarityChecker.cpp"

using namespace std;

TEST(CheckerTest, GetScore) {
	SimilarityChecker checker;
	int ret = checker.getScore("AA", "AA");
	EXPECT_EQ(100, ret);
}

TEST(CheckerTest, CheckLengthScore60) {
	SimilarityChecker checker;
	int ret = checker.getScore("AA", "BB");
	EXPECT_EQ(60, ret);
}

TEST(CheckerTest, CheckLengthScore0) {
	SimilarityChecker checker;
	int ret = checker.getScore("AA", "AAAAAA");
	EXPECT_EQ(0, ret);
}

TEST(CheckerTest, CheckLengthScoreGap1) {
	SimilarityChecker checker;
	int ret = checker.getScore("AAABB", "bbbb");
	EXPECT_EQ(45, ret);
}

TEST(CheckerTest, CheckLengthScoreGap2) {
	SimilarityChecker checker;
	int ret = checker.getScore("AAAB", "bAbbb");
	EXPECT_EQ(45, ret);
}