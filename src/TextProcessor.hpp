#ifndef TEXT_PROCESSOR_HPP
#define TEXT_PROCESSOR_HPP

#include <vector>
#include <memory>

#include "common/Types.hpp"
#include "interfaces/ITextProcessorOutputObserver.hpp"
#include "interfaces/IIntentRecognitionModel.hpp"

namespace embeddedIntentRecognizer
{
    class TextProcessor
    {
    public:
        bool init(SupportedLanguages language);
        void attach(ITextProcessorOutputObserver *observer);
        void detach(ITextProcessorOutputObserver *observer);
        void processText(const std::string &text, InputTextType &inputType);
        void notifyOutputObservers() const;

    private:
        std::unique_ptr<IIntentRecognitionModel> m_intentRecognitionModel;

        std::string m_lastProcessedOutput;
        std::vector<ITextProcessorOutputObserver *> m_observers;
    };

} // namespace embeddedIntentRecognizer

#endif // TEXT_PROCESSOR_HPP