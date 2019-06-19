#include <gtest/gtest.h>
#include "MedianStruct.hpp"

TEST(MedianStructTest, MedianOfZeroNumbers)
{
    MeadianStruct<int> ms;
    ASSERT_THROW(ms.calculate_median(), std::logic_error);
}

TEST(MedianStructTest, MedianOfOneInt)
{
    MeadianStruct<int> ms;
    ms.add(5);
    ASSERT_DOUBLE_EQ(5.0, ms.calculate_median());
}

TEST(MedianStructTest, MedianOfTwoInts)
{
    MeadianStruct<int> ms;
    ms.add(5);
    ms.add(6);
    ASSERT_DOUBLE_EQ(5.5, ms.calculate_median());
}

TEST(MedianStructTest, MedianOfMultipleInts)
{
    MeadianStruct<int> ms;
    for (auto &num : {2, 4, 6, 8, 7, 3, 9})
        ms.add(num);
    ASSERT_DOUBLE_EQ(6.0, ms.calculate_median());
}

TEST(MedianStructTest, MedianOfMultipleDoubles)
{
    MeadianStruct<double> ms;
    ms.add(13.7);
    EXPECT_DOUBLE_EQ(13.7, ms.calculate_median());
    ms.add(11.5);
    EXPECT_DOUBLE_EQ(12.6, ms.calculate_median());
    ms.add(3.4);
    EXPECT_DOUBLE_EQ(11.5, ms.calculate_median());
    ms.add(4);
    EXPECT_DOUBLE_EQ(7.75, ms.calculate_median());
    ms.add(2);
    EXPECT_DOUBLE_EQ(4.0, ms.calculate_median());
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
