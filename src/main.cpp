//!
//! \file       src/main.cpp
//! \author     Ahmed Salah Alanani
//! \date       20-Jul-2022
//!
//! \brief      Entry point for Embedded Intent Recognizer
//!

//---------------------------------------------------------------------------
// Includes
//---------------------------------------------------------------------------
#include <iostream>

#include "EmbeddedIntentRecognizer.hpp"
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
    static constexpr auto SUCCESS = 0;
    static constexpr auto GENERAL_ERROR = -1;

} // anonymous namespace

//---------------------------------------------------------------------------
// Local function prototypes
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// Data
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// Functions
//---------------------------------------------------------------------------
int main()
{
    embeddedIntentRecognizer::EmbeddedIntentRecognizer embeddedIntentRecognizer;

    bool state = embeddedIntentRecognizer.init();
    if (!state)
    {
        std::cout << "Error: Failed to initialize the application.\n";
        std::cout << "Terminating.." << std::endl;
        return GENERAL_ERROR;
    }

    state = embeddedIntentRecognizer.run();
    if (!state)
    {
        std::cout << "Error: Application terminated with error(s)." << std::endl;
        return GENERAL_ERROR;
    }

    std::cout << "Application finished successfully." << std::endl;
    return SUCCESS;
}
//---------------------------------------------------------------------------
// End of File
//---------------------------------------------------------------------------