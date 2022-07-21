#ifndef TEXT_PROCESSOR_HPP
#define TEXT_PROCESSOR_HPP

#include <vector>

#include "interfaces/ITextProcessorOutputObserver.hpp"

namespace embeddedIntentRecognizer
{
    class TextProcessor
    {
    public:
        bool init() const;
        void attach(ITextProcessorOutputObserver *observer);
        void detach(ITextProcessorOutputObserver *observer);
        void processText(const std::string &text);
        void notifyOutputObservers() const;

    private:
        std::string m_lastProcessedOutput;
        std::vector<ITextProcessorOutputObserver *> m_observers;

        bool loadDataSet() const;
    };

} // namespace embeddedIntentRecognizer

#endif // TEXT_PROCESSOR_HPP