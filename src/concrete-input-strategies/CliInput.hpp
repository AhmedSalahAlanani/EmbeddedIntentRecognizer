#ifndef CLI_INPUT_HPP
#define CLI_INPUT_HPP

#include "interfaces/IInputStrategy.hpp"

namespace embeddedIntentRecognizer
{
    class CliInput : public IInputStrategy
    {
    private:
        bool init() const override;
        void waitForInput(std::string &receivedInput) const override;
    };

} // namespace embeddedIntentRecognizer

#endif // CLI_INPUT_HPP