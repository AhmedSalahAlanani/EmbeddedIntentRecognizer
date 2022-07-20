#ifndef CLI_OUTPUT_HPP
#define CLI_OUTPUT_HPP

#include "interfaces/ITextProcessorOutputObserver.hpp"

namespace embeddedIntentRecognizer
{
    class CliOutput : public ITextProcessorOutputObserver
    {
    private:
        void onNewOutputReady(const std::string &textProcessorOutput) const override;
    };

} // namespace embeddedIntentRecognizer

#endif // CLI_OUTPUT_HPP