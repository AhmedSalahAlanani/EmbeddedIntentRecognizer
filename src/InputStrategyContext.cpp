//!
//! \file       InputStrategyContext.cpp
//! \author     Ahmed Salah Alanani
//! \date       20-Jul-2022
//!
//! \brief      Implementation of the Class InputStrategyContext
//!

//---------------------------------------------------------------------------
// Includes
//---------------------------------------------------------------------------
#include <iostream>

#include "concrete-input-strategies/CliInput.hpp"
#include "concrete-input-strategies/TouchScreenInput.hpp"
#include "concrete-input-strategies/VoiceInput.hpp"
#include "InputStrategyContext.hpp"

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
    bool InputStrategyContext::init(const ApplicationConfig &configuration)
    {
        std::cout << "[INFO]: Initializing Input stratetgy..\n";

        switch (configuration.inputType)
        {
        case SupportedInputs::CLI_INPUT:
        {
            m_inputStrategy = std::make_unique<CliInput>();
            break;
        }
        case SupportedInputs::TOUCH_SCREEN_INPUT:
        {
            m_inputStrategy = std::make_unique<TouchScreenInput>();
            break;
        }
        case SupportedInputs::VOICE_INPUT:
        {
            m_inputStrategy = std::make_unique<VoiceInput>();
            break;
        }
        default:
        {
            std::cout << "[ERROR]: Received Unknown Input Strategy!.\n";
            return false;
        }
        }

        if (m_inputStrategy == nullptr)
        {
            std::cout << "[ERROR]: Failed to set the selected Input strategy.\n";
            return false;
        }

        const bool state = m_inputStrategy->init(configuration.language);
        if (!state)
        {
            std::cout << "[ERROR]: Failed to initialize the selected Input strategy.\n";
            return false;
        }

        std::cout << "[VERBOSE]: Input strategy was set successfully.\n";
        return true;
    }
    //---------------------------------------------------------------------------
    void InputStrategyContext::waitForInput(std::string &receivedInput) const
    {
        m_inputStrategy->waitForInput(receivedInput);
    }

} // namespace embeddedIntentRecognizer

//---------------------------------------------------------------------------
// End of File
//---------------------------------------------------------------------------