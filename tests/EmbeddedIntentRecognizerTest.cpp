#include "gtest/gtest.h"

#include "EmbeddedIntentRecognizer.hpp"

namespace embeddedIntentRecognizer_unit_test
{
    namespace
    {
        using namespace embeddedIntentRecognizer;

    } // anonymous namespace

    class EmbeddedIntentRecognizerTest : public ::testing::Test
    {
    public:
        EmbeddedIntentRecognizerTest()
        {
        }

        ~EmbeddedIntentRecognizerTest() override
        {
        }

        void SetUp() override
        {
        }

        void TearDown() override
        {
        }

        EmbeddedIntentRecognizer embeddedIntentRecognizer;
    };

    TEST_F(EmbeddedIntentRecognizerTest, TestCase_1)
    {
        ASSERT_TRUE(true);
    }

} // namespace embeddedIntentRecognizer_unit_test