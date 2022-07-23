//!
//! \file       CliInput.hpp
//! \author     Ahmed Salah Alanani
//! \date       20-Jul-2022
//!
//! \brief      Implementation of the Class CliInput
//!

//---------------------------------------------------------------------------
#ifndef CLI_INPUT_HPP
#define CLI_INPUT_HPP
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// Includes
//---------------------------------------------------------------------------
#include <memory>

#include "interfaces/IInputStrategy.hpp"
#include "interfaces/IInputLanguageStrategy.hpp"
//---------------------------------------------------------------------------
// Forward Declarations
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//!
//! \namespace embeddedIntentRecognizer
//!
//! \brief Embedded Intent Recognizer namespace
//!
namespace embeddedIntentRecognizer
{
    //---------------------------------------------------------------------------
    //!
    //! \class      CliInput
    //!
    //! \brief      Class implements input Strategy in case of CLI. Its responsibility
    //!             is to poll for new input on CLI and forward it to the configured
    //!             input language strategy to set the received input, which is
    //!             then forwarded to the TextProcessor after that.
    //!
    class CliInput : public IInputStrategy
    {
    private:
        //---------------------------------------------------------------------------
        //!
        //! \brief This is the input language strategy that shall be set according to
        //!        the received configuration during initialization. Where all
        //         the client requests to the CLI input strategy shall delegate
        //!        to the selected language strategy to be able to handle it on its way.
        //!
        //! \note this separation of responsibilities was made as it might be needed
        //!       in some cases when the CLI input strategy has different roles for
        //!       each configuration. (For example, it might need to show a different
        //!       keyboard layout for each input language)
        //!
        std::unique_ptr<IInputLanguageStrategy> m_inputLanguageStrategy;

        //! IInputStrategy inherited method
        bool init(SupportedLanguages language) override;

        //! IInputStrategy inherited method
        void waitForInput(std::string &receivedInput) const override;
    };

} // namespace embeddedIntentRecognizer

#endif // CLI_INPUT_HPP

//---------------------------------------------------------------------------
// End of File
//---------------------------------------------------------------------------