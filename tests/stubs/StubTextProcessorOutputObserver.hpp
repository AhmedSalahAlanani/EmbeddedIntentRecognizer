#ifndef STUB_TEXT_PROCESSOR_OUTPUT_OBSERVER_HPP
#define STUB_TEXT_PROCESSOR_OUTPUT_OBSERVER_HPP

#include "interfaces/ITextProcessorOutputObserver.hpp"
#include <string>

#include <iostream>
namespace embeddedIntentRecognizer
{
    class StubTextProcessorOutputObserver : public ITextProcessorOutputObserver
    {
    public:
        void onNewOutputReady(const std::string &textProcessorOutput) override
        {
            std::cout << textProcessorOutput << std::endl;

            m_textProcessorOutput = textProcessorOutput;
        }

        const std::string &getLastTextProcessorOutput() const
        {
            return m_textProcessorOutput;
        }

    private:
        std::string m_textProcessorOutput;
    };

} // namespace embeddedIntentRecognizer

#endif // STUB_TEXT_PROCESSOR_OUTPUT_OBSERVER_HPP