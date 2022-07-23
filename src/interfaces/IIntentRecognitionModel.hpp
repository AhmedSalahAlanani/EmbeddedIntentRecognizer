//!
//! \file       IIntentRecognitionModel.hpp
//! \author     Ahmed Salah Alanani
//! \date       20-Jul-2022
//!
//! \brief      Implementation of the Interface IIntentRecognitionModel
//!

//---------------------------------------------------------------------------
#ifndef I_INTENT_RECOGNITION_MODEL_HPP
#define I_INTENT_RECOGNITION_MODEL_HPP
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
    //! \class      IIntentRecognitionModel
    //!
    //! \brief      The interface shall be responsible for the intent recognition
    //!             model, where it shall support loading its DataSet and use it
    //!             during runtime while running the model and support of course
    //!             the main functionality of the model which is recognizing
    //!             the intent of the received text.
    //!
    //! \note       Model for each language is assumed to be separate and has
    //!             its own dataSet
    //!
    class IIntentRecognitionModel
    {
    public:
        //---------------------------------------------------------------------------
        //!
        //! \brief Destructor
        //!
        virtual ~IIntentRecognitionModel() = default;
        //---------------------------------------------------------------------------
        //!
        //! \brief This method shall load the Model's DataSet to be used later on
        //!        during the application runtime to recognize the intent of the input text
        //!
        virtual bool loadDataSet() = 0;
        //---------------------------------------------------------------------------
        //!
        //! \brief This method shall run the model's main functionality to recognize
        //!        the intent of the input text. It's expected that the model shall
        //!        use its previously loaded dataSet
        //!
        //! \param text   [in]  - the input text to be processed to recognize its intent
        //!
        //! \param intent [out] - the output intent of the input text according to
        //!                     the model execution
        //!
        virtual void getIntent(const std::string &text, std::string &intent) const = 0;
    };

} // namespace embeddedIntentRecognizer

#endif // I_INTENT_RECOGNITION_MODEL_HPP

//---------------------------------------------------------------------------
// End of File
//---------------------------------------------------------------------------