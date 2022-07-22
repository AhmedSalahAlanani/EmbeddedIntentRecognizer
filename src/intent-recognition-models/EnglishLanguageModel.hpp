#ifndef ENGLISH_LANGUAGE_MODEL_HPP
#define ENGLISH_LANGUAGE_MODEL_HPP

#include <vector>
#include <string>

#include "interfaces/IIntentRecognitionModel.hpp"

namespace embeddedIntentRecognizer
{
    class EnglishLanguageModel : public IIntentRecognitionModel
    {
    private:
        std::vector<std::string> m_dataSet1;
        std::vector<std::string> m_dataSet2;
        std::vector<std::string> m_dataSet3;
        std::vector<std::string> m_dataSet4;
        std::vector<std::string> m_dataSet5;

        bool loadDataSet();
        bool fillDataSet(const char filePath[], std::vector<std::string> &dataSet);
        void getIntent(const std::string &text, std::string &intent) const;
        bool searchDataSet1(const std::string &text, std::ostringstream &oss) const;
        bool searchDataSet2(const std::string &text, std::ostringstream &oss) const;
        bool searchDataSet3(const std::string &text, std::ostringstream &oss) const;
        bool searchDataSet4(const std::string &text, std::ostringstream &oss) const;
        bool searchDataSet5(const std::string &text, std::ostringstream &oss) const;
    };

} // namespace embeddedIntentRecognizer

#endif // ENGLISH_LANGUAGE_MODEL_HPP