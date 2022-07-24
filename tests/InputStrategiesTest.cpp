//!
//! \file       InputStrategiesTest.cpp
//! \author     Ahmed Salah Alanani
//! \date       20-Jul-2022
//!
//! \brief      Unit tests for InputStrategies
//!

//---------------------------------------------------------------------------
// Includes
//---------------------------------------------------------------------------
#include <memory>
#include "gtest/gtest.h"

#include "common/Types.hpp"
#include "InputStrategyContext.hpp"
#include "interfaces/IInputStrategy.hpp"
#include "concrete-input-strategies/CliInput.hpp"
#include "concrete-input-strategies/TouchScreenInput.hpp"
#include "concrete-input-strategies/VoiceInput.hpp"

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
    //! \class      InputStrategyContextTest
    //!
    //! \brief      InputStrategyContextTest tests.
    //!
    class InputStrategyContextTest : public ::testing::Test
    {
    public:
        InputStrategyContextTest() = default;
        ~InputStrategyContextTest() override = default;

        void SetUp() override {}
        void TearDown() override {}

        ApplicationConfig applicationConfig;

        InputStrategyContext inputStrategyContext;
    };
    //---------------------------------------------------------------------------
    // Functions
    //---------------------------------------------------------------------------
    TEST_F(InputStrategyContextTest, Test_CliInputEnglishSupport)
    {
        EXPECT_TRUE(inputStrategyContext.init({SupportedLanguages::ENGLISH,
                                               SupportedInputs::CLI_INPUT}));
    }
    //---------------------------------------------------------------------------
    TEST_F(InputStrategyContextTest, Test_CliInputDeutschSupport)
    {
        EXPECT_FALSE(inputStrategyContext.init({SupportedLanguages::DEUTSCH,
                                                SupportedInputs::CLI_INPUT}));
    }
    //---------------------------------------------------------------------------
    TEST_F(InputStrategyContextTest, Test_TouchScreenInputEnglishSupport)
    {
        EXPECT_FALSE(inputStrategyContext.init({SupportedLanguages::ENGLISH,
                                                SupportedInputs::TOUCH_SCREEN_INPUT}));
    }
    //---------------------------------------------------------------------------
    TEST_F(InputStrategyContextTest, Test_TouchScreenInputDeutschSupport)
    {
        EXPECT_FALSE(inputStrategyContext.init({SupportedLanguages::DEUTSCH,
                                                SupportedInputs::TOUCH_SCREEN_INPUT}));
    }
    //---------------------------------------------------------------------------
    TEST_F(InputStrategyContextTest, Test_VoiceInputEnglishSupport)
    {
        EXPECT_FALSE(inputStrategyContext.init({SupportedLanguages::ENGLISH,
                                                SupportedInputs::VOICE_INPUT}));
    }
    //---------------------------------------------------------------------------
    TEST_F(InputStrategyContextTest, Test_VoiceInputDeutschSupport)
    {
        EXPECT_FALSE(inputStrategyContext.init({SupportedLanguages::DEUTSCH,
                                                SupportedInputs::VOICE_INPUT}));
    }

    //---------------------------------------------------------------------------
    //!
    //! \class      InputStrategiesTest
    //!
    //! \brief      InputStrategiesTest tests.
    //!
    class InputStrategiesTest : public ::testing::Test
    {
    public:
        InputStrategiesTest() = default;
        ~InputStrategiesTest() override = default;

        void SetUp() override {}
        void TearDown() override {}

        std::unique_ptr<IInputStrategy> inputStrategy;
    };
    //---------------------------------------------------------------------------
    // Functions
    //---------------------------------------------------------------------------
    TEST_F(InputStrategiesTest, Test_CliInputLanguageSupport)
    {
        inputStrategy = std::make_unique<CliInput>();
        EXPECT_TRUE(inputStrategy->init(SupportedLanguages::ENGLISH));

        inputStrategy = std::make_unique<CliInput>();
        EXPECT_FALSE(inputStrategy->init(SupportedLanguages::DEUTSCH));
    }
    //---------------------------------------------------------------------------
    TEST_F(InputStrategiesTest, Test_TouchScreenInputLanguageSupport)
    {
        inputStrategy = std::make_unique<TouchScreenInput>();
        EXPECT_FALSE(inputStrategy->init(SupportedLanguages::ENGLISH));

        inputStrategy = std::make_unique<TouchScreenInput>();
        EXPECT_FALSE(inputStrategy->init(SupportedLanguages::DEUTSCH));
    }
    //---------------------------------------------------------------------------
    TEST_F(InputStrategiesTest, Test_VoiceInputLanguageSupport)
    {
        inputStrategy = std::make_unique<VoiceInput>();
        EXPECT_FALSE(inputStrategy->init(SupportedLanguages::ENGLISH));

        inputStrategy = std::make_unique<VoiceInput>();
        EXPECT_FALSE(inputStrategy->init(SupportedLanguages::DEUTSCH));
    }

} // namespace embeddedIntentRecognizer_unit_test

//---------------------------------------------------------------------------
// End of File
//---------------------------------------------------------------------------