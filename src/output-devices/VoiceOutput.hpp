//!
//! \file       VoiceOutput.hpp
//! \author     Ahmed Salah Alanani
//! \date       20-Jul-2022
//!
//! \brief      Implementation of the Class VoiceOutput
//!

//---------------------------------------------------------------------------
#ifndef VOICE_OUTPUT_HPP
#define VOICE_OUTPUT_HPP
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// Includes
//---------------------------------------------------------------------------
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
    //! \class      VoiceOutput
    //!
    //! \brief      Class responsible to receive the output from TextProcessor
    //!             in textual format (which is the recognized intent), and convert
    //!             it into voice output.
    //!
    //! \note       This class implementation is not done yet but it is currently
    //!             supported
    //!
    class VoiceOutput : public IOutputDevice
    {
    private:
        //! IOutputDevice inherited method
        bool init(SupportedLanguages language) override;

        //! IOutputDevice inherited method
        void onNewOutputReady(const std::string &textProcessorOutput) override;
    };

} // namespace embeddedIntentRecognizer

#endif // VOICE_OUTPUT_HPP

//---------------------------------------------------------------------------
// End of File
//---------------------------------------------------------------------------