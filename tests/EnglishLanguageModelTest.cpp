#include <memory>
#include "gtest/gtest.h"

#include "intent-recognition-models/EnglishLanguageModel.hpp"

namespace embeddedIntentRecognizer_unit_test
{
    namespace
    {
        using namespace embeddedIntentRecognizer;

    } // anonymous namespace

    class EnglishLanguageModelTest : public ::testing::Test
    {
    public:
        EnglishLanguageModelTest() = default;
        ~EnglishLanguageModelTest() override = default;

        void SetUp() override {}
        void TearDown() override {}

        std::string intent;
        std::unique_ptr<IIntentRecognitionModel> intentRecognitionModel{std::make_unique<EnglishLanguageModel>()};
    };

    TEST_F(EnglishLanguageModelTest, Test_DataSetNotLoaded)
    {
        intentRecognitionModel->getIntent("What is the weather like today?", intent);
        EXPECT_STREQ("(Intent: )", intent.c_str());

        intentRecognitionModel->getIntent("What is the weather like in Paris today?", intent);
        EXPECT_STREQ("(Intent: )", intent.c_str());

        intentRecognitionModel->getIntent("Tell me an interesting fact.", intent);
        EXPECT_STREQ("(Intent: )", intent.c_str());
    }

    TEST_F(EnglishLanguageModelTest, Test_DataSetLoaded)
    {
        intentRecognitionModel->loadDataSet();

        intentRecognitionModel->getIntent("What is the weather like today?", intent);
        EXPECT_STREQ("(Intent: Get Weather)", intent.c_str());

        intentRecognitionModel->getIntent("What is the weather like in Paris today?", intent);
        EXPECT_STREQ("(Intent: Get Weather City)", intent.c_str());

        intentRecognitionModel->getIntent("Tell me an interesting fact.", intent);
        EXPECT_STREQ("(Intent: Get Fact)", intent.c_str());
    }

    TEST_F(EnglishLanguageModelTest, Test_CaseInsensitivity)
    {
        intentRecognitionModel->loadDataSet();

        intentRecognitionModel->getIntent("wHaT iS tHe wEaThEr lIkE tOdAy?", intent);
        EXPECT_STREQ("(Intent: Get Weather)", intent.c_str());

        intentRecognitionModel->getIntent("wHaT iS tHe wEaThEr lIkE iN pArIs tOdAy?", intent);
        EXPECT_STREQ("(Intent: Get Weather City)", intent.c_str());

        intentRecognitionModel->getIntent("teLL mE An InTeReStiNg FaCt.", intent);
        EXPECT_STREQ("(Intent: Get Fact)", intent.c_str());
    }

    TEST_F(EnglishLanguageModelTest, Test_ExtraSpaces)
    {
        intentRecognitionModel->loadDataSet();

        intentRecognitionModel->getIntent("What is the     weather     like    today    ?", intent);
        EXPECT_STREQ("(Intent: Get Weather)", intent.c_str());

        intentRecognitionModel->getIntent("What is the     weather     like      in     Paris    today   ?", intent);
        EXPECT_STREQ("(Intent: Get Weather City)", intent.c_str());

        intentRecognitionModel->getIntent("Tell me     an     interesting       fact    .", intent);
        EXPECT_STREQ("(Intent: Get Fact)", intent.c_str());
    }

    TEST_F(EnglishLanguageModelTest, Test_SynonymsForWeather)
    {
        intentRecognitionModel->loadDataSet();

        intentRecognitionModel->getIntent("Get me the weather for today", intent);
        EXPECT_STREQ("(Intent: Get Weather)", intent.c_str());

        intentRecognitionModel->getIntent("Show me the weather for today", intent);
        EXPECT_STREQ("(Intent: Get Weather)", intent.c_str());

        intentRecognitionModel->getIntent("Search for the weather for today", intent);
        EXPECT_STREQ("(Intent: Get Weather)", intent.c_str());

        intentRecognitionModel->getIntent("find if there is rain this afternoon", intent);
        EXPECT_STREQ("(Intent: Get Weather)", intent.c_str());

        intentRecognitionModel->getIntent("what is the temperature here?", intent);
        EXPECT_STREQ("(Intent: Get Weather)", intent.c_str());

        intentRecognitionModel->getIntent("what was the wind speed this morning?", intent);
        EXPECT_STREQ("(Intent: Get Weather)", intent.c_str());
    }

    TEST_F(EnglishLanguageModelTest, Test_SynonymsForCity)
    {
        intentRecognitionModel->loadDataSet();

        intentRecognitionModel->getIntent("Show me the city", intent);
        EXPECT_STREQ("(Intent: Get City)", intent.c_str());

        intentRecognitionModel->getIntent("Show me this city", intent);
        EXPECT_STREQ("(Intent: Get City)", intent.c_str());

        intentRecognitionModel->getIntent("Show me Berlin", intent);
        EXPECT_STREQ("(Intent: Get City)", intent.c_str());

        intentRecognitionModel->getIntent("Show me Sofia", intent);
        EXPECT_STREQ("(Intent: Get City)", intent.c_str());

        intentRecognitionModel->getIntent("Show me Paris", intent);
        EXPECT_STREQ("(Intent: Get City)", intent.c_str());
    }

    TEST_F(EnglishLanguageModelTest, Test_SynonymsForFact)
    {
        intentRecognitionModel->loadDataSet();

        intentRecognitionModel->getIntent("tell me a fun fact", intent);
        EXPECT_STREQ("(Intent: Get Fact)", intent.c_str());

        intentRecognitionModel->getIntent("tell me an interesting fact", intent);
        EXPECT_STREQ("(Intent: Get Fact)", intent.c_str());

        intentRecognitionModel->getIntent("show me something I know nothing about.", intent);
        EXPECT_STREQ("(Intent: Get Fact)", intent.c_str());

        intentRecognitionModel->getIntent("tell me a fact I didn't know.", intent);
        EXPECT_STREQ("(Intent: Get Fact)", intent.c_str());

        intentRecognitionModel->getIntent("tell me a fact that's new to me.", intent);
        EXPECT_STREQ("(Intent: Get Fact)", intent.c_str());
    }

} // namespace embeddedIntentRecognizer_unit_test