//!
//! \file       EnglishLanguageModel.hpp
//! \author     Ahmed Salah Alanani
//! \date       20-Jul-2022
//!
//! \brief      Implementation of the Class EnglishLanguageModel
//!

//---------------------------------------------------------------------------
#ifndef ENGLISH_LANGUAGE_MODEL_HPP
#define ENGLISH_LANGUAGE_MODEL_HPP
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// Includes
//---------------------------------------------------------------------------
#include <vector>
#include <string>

#include "interfaces/IIntentRecognitionModel.hpp"
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
    //! \class      EnglishLanguageModel
    //!
    //! \brief      Class implements the intent recognition model for English
    //!             Language. It first needs to load its dataSets so that it can
    //!             recognize the intent of the text received from TextProcessor.
    //!
    class EnglishLanguageModel : public IIntentRecognitionModel
    {
    private:
        //---------------------------------------------------------------------------
        //!
        //! \brief      The following vectors shall hold the English model's dataSets
        //!             which are loaded during runtime at startup
        //!
        //! \note       The dataSets are assumed to be unique for Intent Recognition
        //!             Model and taking in consideration other factors (like language
        //!             for example)
        //!
        std::vector<std::string> m_dataSet1;
        std::vector<std::string> m_dataSet2;
        std::vector<std::string> m_dataSet3;
        std::vector<std::string> m_dataSet4;
        std::vector<std::string> m_dataSet5;

        //! IIntentRecognitionModel inherited method
        bool loadDataSet();

        //! IIntentRecognitionModel inherited method
        void getIntent(const std::string &text, std::string &intent) const;

        //---------------------------------------------------------------------------
        //!
        //! \brief Search for the pattern inside the first dataSet, and signal
        //!        whether the pattern was found or not so that the Model can decide
        //!        which dataSet to move to next
        //!
        //! \param text [in]  - the pattern to be searched for
        //!
        //! \param oss  [out] - an output stringstream to be filled continuosly
        //!                     by a part of the recognized intent  when a new pattern
        //!                     is recognized in the searched text
        //!
        //! \return true  - in case a pattern in the first dataSet currently searched
        //!                 was found,
        //!         false - otherwise
        //!
        bool searchDataSet1(const std::string &text, std::ostringstream &oss) const;
        //---------------------------------------------------------------------------
        //!
        //! \brief Search for the pattern inside the second, and signal
        //!        whether the pattern was found or not so that the Model can decide
        //!        which dataSet to move to next
        //!
        //! \param text [in]  - the pattern to be searched for
        //!
        //! \param oss  [out] - an output stringstream to be filled continuosly
        //!                     by a part of the recognized intent  when a new pattern
        //!                     is recognized in the searched text
        //!
        //! \return true  - in case a pattern in the second dataSet currently searched
        //!                 was found,
        //!         false - otherwise
        //!
        bool searchDataSet2(const std::string &text, std::ostringstream &oss) const;
        //---------------------------------------------------------------------------
        //!
        //! \brief Search for the pattern inside the third, and signal
        //!        whether the pattern was found or not so that the Model can decide
        //!        which dataSet to move to next
        //!
        //! \param text [in]  - the pattern to be searched for
        //!
        //! \param oss  [out] - an output stringstream to be filled continuosly
        //!                     by a part of the recognized intent  when a new pattern
        //!                     is recognized in the searched text
        //!
        //! \return true  - in case a pattern in the third dataSet currently searched
        //!                 was found,
        //!         false - otherwise
        //!
        bool searchDataSet3(const std::string &text, std::ostringstream &oss) const;
        //---------------------------------------------------------------------------
        //!
        //! \brief Search for the pattern inside the fourth, and signal
        //!        whether the pattern was found or not so that the Model can decide
        //!        which dataSet to move to next
        //!
        //! \param text [in]  - the pattern to be searched for
        //!
        //! \param oss  [out] - an output stringstream to be filled continuosly
        //!                     by a part of the recognized intent  when a new pattern
        //!                     is recognized in the searched text
        //!
        //! \return true  - in case a pattern in the fourth dataSet currently searched
        //!                 was found,
        //!         false - otherwise
        //!
        bool searchDataSet4(const std::string &text, std::ostringstream &oss) const;
        //---------------------------------------------------------------------------
        //!
        //! \brief Search for the pattern inside the fifth, and signal
        //!        whether the pattern was found or not so that the Model can decide
        //!        which dataSet to move to next
        //!
        //! \param text [in]  - the pattern to be searched for
        //!
        //! \param oss  [out] - an output stringstream to be filled continuosly
        //!                     by a part of the recognized intent  when a new pattern
        //!                     is recognized in the searched text
        //!
        //! \return true  - in case a pattern in the fifth dataSet currently searched
        //!                 was found,
        //!         false - otherwise
        //!
        bool searchDataSet5(const std::string &text, std::ostringstream &oss) const;
        //---------------------------------------------------------------------------
        //!
        //! \brief this internal method is called several times by the inherited
        //!        method loadDataSet given the dataSet file path and the vector
        //!        to be filled so that it can be modified and stored at runTime.
        //!
        //! \param filePath [in]  - the path to the file storing the corresponding
        //!                          dataSet to be filled
        //!
        //! \param dataSet  [out] - the corresponding vector that shall be filled
        //!                         with the data in the dataSet file, so that it can
        //!                         be used when running the model
        //!
        //! \return true  - in case the dataSet vector was successfully filled with
        //!                 with the data stored in the file under the passed path
        //!         false - otherwise
        //!
        bool fillDataSet(const char filePath[], std::vector<std::string> &dataSet);
    };

} // namespace embeddedIntentRecognizer

#endif // ENGLISH_LANGUAGE_MODEL_HPP

//---------------------------------------------------------------------------
// End of File
//---------------------------------------------------------------------------