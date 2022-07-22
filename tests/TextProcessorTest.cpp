#include "gtest/gtest.h"

#include "TextProcessor.hpp"

namespace embeddedIntentRecognizer_unit_test
{
    namespace
    {
        using namespace embeddedIntentRecognizer;

    } // anonymous namespace

    class TextProcessorTest : public ::testing::Test
    {
    public:
        TextProcessorTest()
        {
        }

        ~TextProcessorTest() override
        {
        }

        void SetUp() override
        {
        }

        void TearDown() override
        {
        }

        TextProcessor textProcessor;
    };

    TEST_F(TextProcessorTest, TestCase_1)
    {
        ASSERT_TRUE(true);
    }

} // namespace embeddedIntentRecognizer_unit_test