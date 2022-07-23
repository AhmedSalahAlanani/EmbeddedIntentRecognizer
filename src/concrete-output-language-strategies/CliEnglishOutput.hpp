//!
//! \file       CliEnglishOutput.hpp
//! \author     Ahmed Salah Alanani
//! \date       20-Jul-2022
//!
//! \brief      Implementation of the Class CliEnglishOutput
//!

//---------------------------------------------------------------------------
#ifndef CLI_ENGLISH_OUTPUT_HPP
#define CLI_ENGLISH_OUTPUT_HPP
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// Includes
//---------------------------------------------------------------------------
#include "interfaces/IOutputLanguageStrategy.hpp"
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
    //! \class      CliEnglishOutput
    //!
    //! \brief      Class implements the Output Language Strategy in case of CLI
    //!             for English Language. Its responsibility is converting text
    //!             into the expected output format (in this case :CLI output in
    //!             English Language)
    //!
    class CliEnglishOutput : public IOutputLanguageStrategy
    {
    private:
        //! IOutputLanguageStrategy inherited method
        void convertTextToOutput(const std::string &text) const override;
    };

} // namespace embeddedIntentRecognizer

#endif // CLI_ENGLISH_OUTPUT_HPP

//---------------------------------------------------------------------------
// End of File
//---------------------------------------------------------------------------