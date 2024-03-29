//!
//! \file       TextProcessorTest.cpp
//! \author     Ahmed Salah Alanani
//! \date       20-Jul-2022
//!
//! \brief      Unit tests for TextProcessor
//!

//---------------------------------------------------------------------------
// Includes
//---------------------------------------------------------------------------
#include <memory>
#include "gtest/gtest.h"

#include "stubs/StubTextProcessorOutputObserver.hpp"
#include "TextProcessor.hpp"

namespace embeddedIntentRecognizer_unit_test
{
    //---------------------------------------------------------------------------
    // Defines and Macros
    //---------------------------------------------------------------------------

    //---------------------------------------------------------------------------
    // Typedefs
    //---------------------------------------------------------------------------

    //---------------------------------------------------------------------------
    // Constants
    //---------------------------------------------------------------------------
    namespace
    {
        using namespace embeddedIntentRecognizer;

    } // anonymous namespace

    //---------------------------------------------------------------------------
    // Local function prototypes
    //---------------------------------------------------------------------------

    //---------------------------------------------------------------------------
    // Data
    //---------------------------------------------------------------------------

    //---------------------------------------------------------------------------
    //!
    //! \class      TextProcessorInitializationTest
    //!
    //! \brief      TextProcessorInitializationTest tests.
    //!
    class TextProcessorInitializationTest : public ::testing::Test
    {
    public:
        TextProcessorInitializationTest() = default;
        ~TextProcessorInitializationTest() override = default;

        void SetUp() override {}
        void TearDown() override {}

        ApplicationConfig appConfig;

        TextProcessor textProcessor;
    };
    //---------------------------------------------------------------------------
    // Functions
    //---------------------------------------------------------------------------
    TEST_F(TextProcessorInitializationTest, Test_EnglishSupport)
    {
        appConfig.language = SupportedLanguages::ENGLISH;
        EXPECT_TRUE(textProcessor.init(appConfig));
    }
    //---------------------------------------------------------------------------
    TEST_F(TextProcessorInitializationTest, Test_DeutschSupport)
    {
        appConfig.language = SupportedLanguages::DEUTSCH;
        EXPECT_FALSE(textProcessor.init(appConfig));
    }
    //---------------------------------------------------------------------------
    TEST_F(TextProcessorInitializationTest, Test_UnknownLanguageSupport)
    {
        EXPECT_FALSE(textProcessor.init(appConfig));
    }

    //---------------------------------------------------------------------------
    //!
    //! \class      TextProcessorProcessTextTest
    //!
    //! \brief      TextProcessorProcessTextTest tests.
    //!
    class TextProcessorProcessTextTest : public ::testing::Test
    {
    public:
        TextProcessorProcessTextTest() = default;
        ~TextProcessorProcessTextTest() override = default;

        void SetUp() override
        {
            textProcessor.init({SupportedLanguages::ENGLISH});
        }

        void TearDown() override {}

        std::string inputText;
        std::string outputText;
        InputTextType inputTextType;

        TextProcessor textProcessor;
    };
    //---------------------------------------------------------------------------
    // Functions
    //---------------------------------------------------------------------------
    TEST_F(TextProcessorProcessTextTest, Test_ExitCommand)
    {
        inputText = "Exit";
        textProcessor.processText(inputText, inputTextType);
        EXPECT_EQ(InputTextType::EXIT_COMMAND, inputTextType);
    }
    //---------------------------------------------------------------------------
    TEST_F(TextProcessorProcessTextTest, Test_QuitCommand)
    {
        inputText = "Quit";
        textProcessor.processText(inputText, inputTextType);
        EXPECT_EQ(InputTextType::EXIT_COMMAND, inputTextType);
    }
    //---------------------------------------------------------------------------
    TEST_F(TextProcessorProcessTextTest, Test_NormalText)
    {
        inputText = "Normal Text";
        textProcessor.processText(inputText, inputTextType);
        EXPECT_EQ(InputTextType::NORMAL_TEXT, inputTextType);
    }

    //---------------------------------------------------------------------------
    //!
    //! \class      TextProcessorOutputTextTest
    //!
    //! \brief      TextProcessorOutputTextTest tests.
    //!
    class TextProcessorOutputTextTest : public ::testing::Test
    {
    public:
        TextProcessorOutputTextTest() = default;
        ~TextProcessorOutputTextTest() override = default;

        void SetUp() override
        {
            textProcessor.init({SupportedLanguages::ENGLISH});

            m_stubTextobserver = std::make_unique<StubTextProcessorOutputObserver>();
            textProcessor.attach(m_stubTextobserver.get());
        }

        void TearDown() override
        {
            textProcessor.detach(m_stubTextobserver.get());
        }

        std::string inputText;
        InputTextType inputTextType;
        std::unique_ptr<StubTextProcessorOutputObserver> m_stubTextobserver;

        TextProcessor textProcessor;
    };
    //---------------------------------------------------------------------------
    // Functions
    //---------------------------------------------------------------------------
    TEST_F(TextProcessorOutputTextTest, Test_FirstUseCase)
    {
        inputText = "What is the weather like today?";
        textProcessor.processText(inputText, inputTextType);
        EXPECT_EQ(InputTextType::NORMAL_TEXT, inputTextType);

        EXPECT_STREQ("(Intent: Get Weather)", m_stubTextobserver->getLastTextProcessorOutput().c_str());
    }
    //---------------------------------------------------------------------------
    TEST_F(TextProcessorOutputTextTest, Test_SecondUseCase)
    {
        inputText = "What is the weather like in Paris today?";
        textProcessor.processText(inputText, inputTextType);
        EXPECT_EQ(InputTextType::NORMAL_TEXT, inputTextType);

        EXPECT_STREQ("(Intent: Get Weather City)", m_stubTextobserver->getLastTextProcessorOutput().c_str());
    }
    //---------------------------------------------------------------------------
    TEST_F(TextProcessorOutputTextTest, Test_ThirdUseCase)
    {
        inputText = "Tell me an interesting fact.";
        textProcessor.processText(inputText, inputTextType);
        EXPECT_EQ(InputTextType::NORMAL_TEXT, inputTextType);

        EXPECT_STREQ("(Intent: Get Fact)", m_stubTextobserver->getLastTextProcessorOutput().c_str());
    }

} // namespace embeddedIntentRecognizer_unit_test

//---------------------------------------------------------------------------
// End of File
//---------------------------------------------------------------------------