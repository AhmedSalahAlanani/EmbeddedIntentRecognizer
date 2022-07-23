//!
//! \file       IOutputDevice.hpp
//! \author     Ahmed Salah Alanani
//! \date       20-Jul-2022
//!
//! \brief      Implementation of the Interface IOutputDevice
//!

//---------------------------------------------------------------------------
#ifndef I_OUTPUT_DEVICE_HPP
#define I_OUTPUT_DEVICE_HPP
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// Includes
//---------------------------------------------------------------------------
#include "ITextProcessorOutputObserver.hpp"
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
    //! \class      IOutputDevice
    //!
    //! \brief      The interface shall be responsible for sending out the received
    //!             text coming from the TextProcessor. It shall be also able to
    //!             to set its output language during runtime according to
    //!             the configured output language
    //!
    //! \note       Output devices are expected to receive TextProcessor output
    //!             in textual format and be able to convert it to their corresponding
    //!             output format (example: voice, touch screen display, ... etc),
    //!             and also in the configured output language
    //!
    class IOutputDevice : public ITextProcessorOutputObserver
    {
    public:
        //---------------------------------------------------------------------------
        //!
        //! \brief Destructor
        //!
        virtual ~IOutputDevice() = default;
        //---------------------------------------------------------------------------
        //!
        //! \brief This method shall initialize the output device and also set its
        //!        output language according to the receieved configuration
        //!
        //! \param language [in] - the output language in which the output device
        //!                        is expected to output the received text in,
        //!
        virtual bool init(SupportedLanguages language) = 0;
    };

} // namespace embeddedIntentRecognizer

#endif // I_OUTPUT_DEVICE_HPP

//---------------------------------------------------------------------------
// End of File
//---------------------------------------------------------------------------