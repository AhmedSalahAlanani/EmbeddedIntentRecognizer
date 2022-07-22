#ifndef I_INTENT_RECOGNITION_MODEL_HPP
#define I_INTENT_RECOGNITION_MODEL_HPP

#include <string>

namespace embeddedIntentRecognizer
{
    class IIntentRecognitionModel
    {
    public:
        virtual ~IIntentRecognitionModel() = default;
        virtual bool loadDataSet() = 0;
        virtual void getIntent(const std::string &text, std::string &intent) const = 0;
    };

} // namespace embeddedIntentRecognizer

#endif // I_INTENT_RECOGNITION_MODEL_HPP