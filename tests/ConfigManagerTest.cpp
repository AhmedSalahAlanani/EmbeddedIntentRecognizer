#include "gtest/gtest.h"

#include "ConfigManager.hpp"

namespace embeddedIntentRecognizer_unit_test
{
    namespace
    {
        using namespace embeddedIntentRecognizer;

        // configuration files' paths used in test cases
        static constexpr char g_invalidFormat1FilePath[] = TEST_INVALID_FORMAT1_FILE_PATH;
        static constexpr char g_invalidFormat2FilePath[] = TEST_INVALID_FORMAT2_FILE_PATH;
        static constexpr char g_invalidFormat3FilePath[] = TEST_INVALID_FORMAT3_FILE_PATH;
        static constexpr char g_invalidFormat4FilePath[] = TEST_INVALID_FORMAT4_FILE_PATH;

        static constexpr char g_validFormat1FilePath[] = TEST_VALID_FORMAT1_FILE_PATH;
        static constexpr char g_validFormat2FilePath[] = TEST_VALID_FORMAT2_FILE_PATH;
        static constexpr char g_validFormat3FilePath[] = TEST_VALID_FORMAT3_FILE_PATH;
        static constexpr char g_validFormat4FilePath[] = TEST_VALID_FORMAT4_FILE_PATH;

    } // anonymous namespace

    class ConfigManagerTest : public ::testing::Test
    {
    public:
        ConfigManagerTest() = default;
        ~ConfigManagerTest() override = default;

        void SetUp() override {}
        void TearDown() override {}

        ApplicationConfig appConfig;

        ConfigManager configManager;
    };

    TEST_F(ConfigManagerTest, Test_invalidFormatConfigFile1)
    {
        EXPECT_FALSE(configManager.loadConfig(appConfig, g_invalidFormat1FilePath));
    }

    TEST_F(ConfigManagerTest, Test_invalidFormatConfigFile2)
    {
        EXPECT_FALSE(configManager.loadConfig(appConfig, g_invalidFormat2FilePath));
    }

    TEST_F(ConfigManagerTest, Test_invalidFormatConfigFil3)
    {
        EXPECT_FALSE(configManager.loadConfig(appConfig, g_invalidFormat3FilePath));
    }

    TEST_F(ConfigManagerTest, Test_invalidFormatConfigFil4)
    {
        EXPECT_FALSE(configManager.loadConfig(appConfig, g_invalidFormat4FilePath));
    }

    TEST_F(ConfigManagerTest, Test_validFormatConfigFile1)
    {
        EXPECT_TRUE(configManager.loadConfig(appConfig, g_validFormat1FilePath));

        EXPECT_EQ(appConfig.language, SupportedLanguages::ENGLISH);
        EXPECT_EQ(appConfig.inputType, SupportedInputs::CLI_INPUT);
        EXPECT_TRUE(appConfig.cliOutput);
        EXPECT_FALSE(appConfig.touchScreenOutput);
        EXPECT_FALSE(appConfig.voiceOutput);
    }

    TEST_F(ConfigManagerTest, Test_validFormatConfigFile2)
    {
        EXPECT_TRUE(configManager.loadConfig(appConfig, g_validFormat2FilePath));

        EXPECT_EQ(appConfig.language, SupportedLanguages::DEUTSCH);
        EXPECT_EQ(appConfig.inputType, SupportedInputs::TOUCH_SCREEN_INPUT);
        EXPECT_TRUE(appConfig.cliOutput);
        EXPECT_FALSE(appConfig.touchScreenOutput);
        EXPECT_FALSE(appConfig.voiceOutput);
    }

    TEST_F(ConfigManagerTest, Test_validFormatConfigFile3)
    {
        EXPECT_TRUE(configManager.loadConfig(appConfig, g_validFormat3FilePath));

        EXPECT_EQ(appConfig.language, SupportedLanguages::ENGLISH);
        EXPECT_EQ(appConfig.inputType, SupportedInputs::VOICE_INPUT);
        EXPECT_FALSE(appConfig.cliOutput);
        EXPECT_TRUE(appConfig.touchScreenOutput);
        EXPECT_FALSE(appConfig.voiceOutput);
    }

    TEST_F(ConfigManagerTest, Test_validFormatConfigFile4)
    {
        EXPECT_TRUE(configManager.loadConfig(appConfig, g_validFormat4FilePath));

        EXPECT_EQ(appConfig.language, SupportedLanguages::DEUTSCH);
        EXPECT_EQ(appConfig.inputType, SupportedInputs::CLI_INPUT);
        EXPECT_TRUE(appConfig.cliOutput);
        EXPECT_TRUE(appConfig.touchScreenOutput);
        EXPECT_TRUE(appConfig.voiceOutput);
    }

} // namespace embeddedIntentRecognizer_unit_test