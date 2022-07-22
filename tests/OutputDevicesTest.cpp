#include <memory>
#include "gtest/gtest.h"

#include "common/Types.hpp"
#include "output-devices/CliOutput.hpp"
#include "output-devices/TouchScreenOutput.hpp"
#include "output-devices/VoiceOutput.hpp"

namespace embeddedIntentRecognizer_unit_test
{
    namespace
    {
        using namespace embeddedIntentRecognizer;

    } // anonymous namespace

    class OutputDevicesTest : public ::testing::Test
    {
    public:
        OutputDevicesTest() = default;
        ~OutputDevicesTest() override = default;

        void SetUp() override {}
        void TearDown() override {}

        std::unique_ptr<IOutputDevice> outputDevice;
    };

    TEST_F(OutputDevicesTest, Test_CliIOutputLanguageSupport)
    {
        outputDevice = std::make_unique<CliOutput>();
        EXPECT_TRUE(outputDevice->init(SupportedLanguages::ENGLISH));

        outputDevice = std::make_unique<CliOutput>();
        EXPECT_FALSE(outputDevice->init(SupportedLanguages::DEUTSCH));
    }

    TEST_F(OutputDevicesTest, Test_TouchScreenOutputLanguageSupport)
    {
        outputDevice = std::make_unique<TouchScreenOutput>();
        EXPECT_FALSE(outputDevice->init(SupportedLanguages::ENGLISH));

        outputDevice = std::make_unique<TouchScreenOutput>();
        EXPECT_FALSE(outputDevice->init(SupportedLanguages::DEUTSCH));
    }

    TEST_F(OutputDevicesTest, Test_VoiceOutputLanguageSupport)
    {
        outputDevice = std::make_unique<VoiceOutput>();
        EXPECT_FALSE(outputDevice->init(SupportedLanguages::ENGLISH));

        outputDevice = std::make_unique<VoiceOutput>();
        EXPECT_FALSE(outputDevice->init(SupportedLanguages::DEUTSCH));
    }

} // namespace embeddedIntentRecognizer_unit_test