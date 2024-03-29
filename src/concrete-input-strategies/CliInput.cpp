//!
//! \file       CliInput.cpp
//! \author     Ahmed Salah Alanani
//! \date       20-Jul-2022
//!
//! \brief      Implementation of the Class CliInput
//!

//---------------------------------------------------------------------------
// Includes
//---------------------------------------------------------------------------
#include <iostream>

#include "concrete-input-language-strategies/CliEnglishInput.hpp"
#include "CliInput.hpp"

namespace embeddedIntentRecognizer
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

    //---------------------------------------------------------------------------
    // Local function prototypes
    //---------------------------------------------------------------------------

    //---------------------------------------------------------------------------
    // Data
    //---------------------------------------------------------------------------

    //---------------------------------------------------------------------------
    // Functions
    //---------------------------------------------------------------------------
    bool CliInput::init(SupportedLanguages language)
    {
        switch (language)
        {
        case SupportedLanguages::ENGLISH:
        {
            m_inputLanguageStrategy = std::make_unique<CliEnglishInput>();
            break;
        }
        case SupportedLanguages::DEUTSCH:
        {
            std::cout << "[ERROR]: Input Language Deutsch support is currently not implemented.\n";
            return false;
        }
        default:
        {
            std::cout << "[ERROR]: Received Unknown Input Language!.\n";
            return false;
        }
        }

        if (m_inputLanguageStrategy == nullptr)
        {
            std::cout << "[ERROR]: Failed to set Input Language!.\n";
            return false;
        }

        std::cout << "[VERBOSE]: Input Language was set successfully.\n";
        return true;
    }
    //---------------------------------------------------------------------------
    void CliInput::waitForInput(std::string &receivedInput) const
    {
        m_inputLanguageStrategy->waitForInput(receivedInput);
    }

} // namespace embeddedIntentRecognizer

//---------------------------------------------------------------------------
// End of File
//---------------------------------------------------------------------------