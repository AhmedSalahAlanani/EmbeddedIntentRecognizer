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

    TEST_F(TextProcessorTest, Test_EnglishSupport)
    {
        ApplicationConfig appConfig;
        appConfig.language = SupportedLanguages::ENGLISH;
        EXPECT_TRUE(textProcessor.init(appConfig.language));
    }

    TEST_F(TextProcessorTest, Test_DeutschSupport)
    {
        ApplicationConfig appConfig;
        appConfig.language = SupportedLanguages::DEUTSCH;
        EXPECT_FALSE(textProcessor.init(appConfig.language));
    }

    TEST_F(TextProcessorTest, Test_UnknownLanguageSupport)
    {
        ApplicationConfig appConfig;
        EXPECT_FALSE(textProcessor.init(appConfig.language));
    }

} // namespace embeddedIntentRecognizer_unit_test