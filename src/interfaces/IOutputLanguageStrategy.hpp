//!
//! \file       IOutputLanguageStrategy.hpp
//! \author     Ahmed Salah Alanani
//! \date       20-Jul-2022
//!
//! \brief      Implementation of the Interface IOutputLanguageStrategy
//!

//---------------------------------------------------------------------------
#ifndef I_OUTPUT_LANGUAGE_STRATEGY_HPP
#define I_OUTPUT_LANGUAGE_STRATEGY_HPP
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// Includes
//---------------------------------------------------------------------------
#include <string>
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
    //! \class      IOutputLanguageStrategy
    //!
    //! \brief      The interface shall be responsible for handling the output language
    //!             strategy, where it is expected to be able to handle a text coming
    //!             from the TextProcessor. And convert it to its output format
    //!             according to the configured language
    //!
    class IOutputLanguageStrategy
    {
    public:
        //---------------------------------------------------------------------------
        //!
        //! \brief Destructor
        //!
        virtual ~IOutputLanguageStrategy() = default;
        //---------------------------------------------------------------------------
        //!
        //! \brief This method shall convert the receieved Text into its corresponding
        //!        output format according to the configured language
        //!
        //! \param text [in] - the received text from TextProcessor to be converted to
        //!                    its corresponding output format
        //!
        virtual void convertTextToOutput(const std::string &text) const = 0;
    };

} // namespace embeddedIntentRecognizer

#endif // I_INPUT_LANGUAGE_STRATEGY_HPP

//---------------------------------------------------------------------------
// End of File
//---------------------------------------------------------------------------