//!
//! \file       CliOutput.hpp
//! \author     Ahmed Salah Alanani
//! \date       20-Jul-2022
//!
//! \brief      Implementation of the Class CliOutput
//!

//---------------------------------------------------------------------------
#ifndef CLI_OUTPUT_HPP
#define CLI_OUTPUT_HPP
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// Includes
//---------------------------------------------------------------------------
#include <memory>

#include "interfaces/IOutputLanguageStrategy.hpp"
#include "interfaces/IOutputDevice.hpp"
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
    //! \class      CliOutput
    //!
    //! \brief      Class responsible to receive the output from TextProcessor
    //!             in textual format (which is the recognized intent), and convert
    //!             it into displayed text on the command line interface prompt
    //!
    class CliOutput : public IOutputDevice
    {
    private:
        //---------------------------------------------------------------------------
        //!
        //! \brief      It holds the output language strategy which is accordingly
        //!             display the output in the configured language. Where
        //!             the language is configured after ConfigManager has successfully
        //!             loaded the configuration, so that it can be passed during
        //!             the initialization sequence.
        //!
        //! \note       The language passed must be one of the currently supported
        //!             languages, otherwise initialization would fail and output
        //!             language strategy won't be set.
        //!
        std::unique_ptr<IOutputLanguageStrategy> m_outputLanguageStrategy;

        //! IOutputDevice inherited method
        bool init(SupportedLanguages language) override;

        //! IOutputDevice inherited method
        void onNewOutputReady(const std::string &textProcessorOutput) override;
    };

} // namespace embeddedIntentRecognizer

#endif // CLI_OUTPUT_HPP

//---------------------------------------------------------------------------
// End of File
//---------------------------------------------------------------------------