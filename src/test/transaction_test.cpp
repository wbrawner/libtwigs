#include <gtest/gtest.h>
#include <cppunit/extensions/HelperMacros.h>
#include <iostream>
#include <time.h>
#include <twigs/transaction.h>
#include <twigs/utils.h>

TEST(TransactionTest, SerializeTest) {

	const std::string json =
		R"({"amount":2108,"budgetId":"Gbhqm79yC8NereIONtq7W2Mf9MD2y1AU","categoryId":"Q4R8QLhSksL2wi7XzmrqhL06qm2aZ2S4","createdBy":"1","date":"2021-01-08T13:06:00Z","description":"Books","expense":true,"id":"2snbSS8flrSH6OrvmSEmqyvaduOi2uc2","title":"Amazon"})";

	tm date;
	date.tm_year = 2021;
	date.tm_mon = 0;
	date.tm_mday = 8;
	date.tm_hour = 13;
	date.tm_min = 6;
	date.tm_sec = 0;
	Transaction t = Transaction("2snbSS8flrSH6OrvmSEmqyvaduOi2uc2", "Amazon", date, "1", 2108,
		"Books", true, "Q4R8QLhSksL2wi7XzmrqhL06qm2aZ2S4",
		"Gbhqm79yC8NereIONtq7W2Mf9MD2y1AU");
	EXPECT_EQ(t.serialize(), json) << "Transaction serialization failed";
}

TEST(TransactionTest, DerializeTest) {
	const std::string json =
		R"({"id":"2snbSS8flrSH6OrvmSEmqyvaduOi2uc2","title":"Amazon","description":"Books","date":"2021-01-08T13:06:00Z","amount":2108,"expense":true,"budgetId":"Gbhqm79yC8NereIONtq7W2Mf9MD2y1AU","categoryId":"Q4R8QLhSksL2wi7XzmrqhL06qm2aZ2S4","createdBy":"1"})";
	Transaction t = Transaction::deserialize(json);
	EXPECT_EQ(std::string("2snbSS8flrSH6OrvmSEmqyvaduOi2uc2"), t.getId()) << "Transaction id parsing failed";
	EXPECT_EQ(std::string("Amazon"), t.getName()) << "Transaction name parsing failed";
	EXPECT_EQ(std::string("Books"), t.getDescription()) << "Transaction description parsing failed";
	tm date = t.getDate();
	EXPECT_EQ(2021, date.tm_year) << "Transaction date year parsing failed";
	EXPECT_EQ(0, date.tm_mon) << "Transaction date month parsing failed";
	EXPECT_EQ(8, date.tm_mday) << "Transaction date day parsing failed";
	EXPECT_EQ(13, date.tm_hour) << "Transaction date hour parsing failed";
	EXPECT_EQ(6, date.tm_min) << "Transaction date min parsing failed";
	EXPECT_EQ(0, date.tm_sec) << "Transaction date sec parsing failed";
	EXPECT_EQ(2108U, t.getAmount()) << "Transaction amount parsing failed";
	EXPECT_TRUE(t.isExpense()) << "Transaction expense parsing failed";
	EXPECT_EQ(std::string("Gbhqm79yC8NereIONtq7W2Mf9MD2y1AU"), t.getBudgetId()) << "Transaction budgetId parsing failed";
	EXPECT_EQ(std::string("Q4R8QLhSksL2wi7XzmrqhL06qm2aZ2S4"), t.getCategoryId()) << "Transaction category parsing failed";
	EXPECT_EQ(std::string("1"), t.getCreatedBy()) << "Transaction createdBy parsing failed";
}

TEST(TransactionTest, DefaultIdsDifferentTest) {
	Transaction t1;
	Transaction t2;
	EXPECT_NE(t1.getId(), t2.getId());
}

TEST(TransactionTest, HashTransactionTest) {
	tm date;
	date.tm_year = 2021;
	date.tm_mon = 0;
	date.tm_mday = 8;
	date.tm_hour = 13;
	date.tm_min = 6;
	date.tm_sec = 0;
	Transaction t =
		Transaction("2snbSS8flrSH6OrvmSEmqyvaduOi2uc2", "Amazon", date, "1", 2108,
			"Books", true, "Q4R8QLhSksL2wi7XzmrqhL06qm2aZ2S4",
			"Gbhqm79yC8NereIONtq7W2Mf9MD2y1AU");
	EXPECT_EQ(std::string("94140eb2923e905360cef1e7aca3d321da39f0608ea17eb944475d81b89a64cb"), t.hash()) << "Transaction hash failed";
}

int result = RUN_ALL_TESTS();