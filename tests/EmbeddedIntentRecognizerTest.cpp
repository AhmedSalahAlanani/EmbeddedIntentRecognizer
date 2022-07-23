//!
//! \file       EmbeddedIntentRecognizerTest.cpp
//! \author     Ahmed Salah Alanani
//! \date       20-Jul-2022
//!
//! \brief      Unit tests for EmbeddedIntentRecognizer
//!

//---------------------------------------------------------------------------
// Includes
//---------------------------------------------------------------------------
#include "gtest/gtest.h"

#include "EmbeddedIntentRecognizer.hpp"

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
    //! \class      EmbeddedIntentRecognizerTest
    //!
    //! \brief      EmbeddedIntentRecognizerTest tests.
    //!
    class EmbeddedIntentRecognizerTest : public ::testing::Test
    {
    public:
        EmbeddedIntentRecognizerTest() = default;
        ~EmbeddedIntentRecognizerTest() override = default;

        void SetUp() override {}
        void TearDown() override {}

        EmbeddedIntentRecognizer embeddedIntentRecognizer;
    };
    //---------------------------------------------------------------------------
    // Functions
    //---------------------------------------------------------------------------
    TEST_F(EmbeddedIntentRecognizerTest, Test_EmbeddedIntentRecognizerInitialization)
    {
        EXPECT_TRUE(embeddedIntentRecognizer.init());
    }

} // namespace embeddedIntentRecognizer_unit_test

//---------------------------------------------------------------------------
// End of File
//---------------------------------------------------------------------------