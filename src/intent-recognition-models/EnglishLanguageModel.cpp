#include <iostream>
#include <fstream>
#include <sstream>
#include <regex>

#include "EnglishLanguageModel.hpp"

namespace
{
    // dataSets files' paths
    static constexpr char g_dataSet1FilePath[] = ENGLISH_DATA_SET1_FILE_PATH;
    static constexpr char g_dataSet2FilePath[] = ENGLISH_DATA_SET2_FILE_PATH;
    static constexpr char g_dataSet3FilePath[] = ENGLISH_DATA_SET3_FILE_PATH;
    static constexpr char g_dataSet4FilePath[] = ENGLISH_DATA_SET4_FILE_PATH;
    static constexpr char g_dataSet5FilePath[] = ENGLISH_DATA_SET5_FILE_PATH;

    // dataSets outputs in case of a match
    static constexpr char g_dataSet1MatchOutput[] = "Get";
    static constexpr char g_dataSet2MatchOutput[] = "Get";
    static constexpr char g_dataSet3MatchOutput[] = " Fact";
    static constexpr char g_dataSet4MatchOutput[] = " Weather";
    static constexpr char g_dataSet5MatchOutput[] = " City";

} // anonymous namespace

namespace embeddedIntentRecognizer
{
    bool EnglishLanguageModel::loadDataSet()
    {
        if (!fillDataSet(g_dataSet1FilePath, m_dataSet1))
        {
            std::cout << "[ERROR]: Failed to load dataSet: " << g_dataSet1FilePath << " !.\n";
            return false;
        }
        if (!fillDataSet(g_dataSet2FilePath, m_dataSet2))
        {
            std::cout << "[ERROR]: Failed to load dataSet: " << g_dataSet2FilePath << " !.\n";
            return false;
        }
        if (!fillDataSet(g_dataSet3FilePath, m_dataSet3))
        {
            std::cout << "[ERROR]: Failed to load dataSet: " << g_dataSet3FilePath << " !.\n";
            return false;
        }
        if (!fillDataSet(g_dataSet4FilePath, m_dataSet4))
        {
            std::cout << "[ERROR]: Failed to load dataSet: " << g_dataSet4FilePath << " !.\n";
            return false;
        }
        if (!fillDataSet(g_dataSet5FilePath, m_dataSet5))
        {
            std::cout << "[ERROR]: Failed to load dataSet: " << g_dataSet5FilePath << " !.\n";
            return false;
        }

        return true;
    }

    bool EnglishLanguageModel::fillDataSet(const char filePath[], std::vector<std::string> &dataSet)
    {
        std::ifstream file{filePath};
        if (file.is_open() == false)
        {
            std::cout << "[ERROR]: Failed to find: " << filePath << " !.\n";
            return false;
        }

        std::string line;
        while (getline(file, line))
        {
            dataSet.emplace_back(line);
        }

        return true;
    }

    void EnglishLanguageModel::getIntent(const std::string &text, std::string &intent) const
    {
        std::ostringstream oss;
        oss << "(Intent: ";

        if (!searchDataSet1(text, oss))
        {
            searchDataSet2(text, oss);
        }

        oss << ")";
        intent = oss.str();
    }

    bool EnglishLanguageModel::searchDataSet1(const std::string &text, std::ostringstream &oss) const
    {
        std::cout << "[DEBUG]: Checking DataSet 1..\n";

        bool checkDataSet4 = false;
        for (const auto &regexp : m_dataSet1)
        {
            if (std::regex_match(text, std::regex(regexp, std::regex_constants::icase)))
            {
                oss << g_dataSet1MatchOutput;
                checkDataSet4 = true;
                break;
            }
        }

        if (checkDataSet4)
        {
            searchDataSet4(text, oss);
            return true;
        }

        return false;
    }

    bool EnglishLanguageModel::searchDataSet2(const std::string &text, std::ostringstream &oss) const
    {
        std::cout << "[DEBUG]: Checking DataSet 2..\n";

        bool checkDataSet3 = false;
        for (const auto &regexp : m_dataSet2)
        {
            if (std::regex_match(text, std::regex(regexp, std::regex_constants::icase)))
            {
                oss << g_dataSet2MatchOutput;
                checkDataSet3 = true;
                break;
            }
        }

        if (checkDataSet3)
        {
            searchDataSet3(text, oss);
            return true;
        }

        return false;
    }

    bool EnglishLanguageModel::searchDataSet3(const std::string &text, std::ostringstream &oss) const
    {
        std::cout << "[DEBUG]: Checking DataSet 3..\n";

        for (const auto &regexp : m_dataSet3)
        {
            if (std::regex_match(text, std::regex(regexp, std::regex_constants::icase)))
            {
                oss << g_dataSet3MatchOutput;
                return true;
            }
        }

        return false;
    }

    bool EnglishLanguageModel::searchDataSet4(const std::string &text, std::ostringstream &oss) const
    {
        std::cout << "[DEBUG]: Checking DataSet 4..\n";

        bool checkDataSet5 = false;
        for (const auto &regexp : m_dataSet4)
        {
            if (std::regex_match(text, std::regex(regexp, std::regex_constants::icase)))
            {
                oss << g_dataSet4MatchOutput;
                checkDataSet5 = true;
                break;
            }
        }

        if (checkDataSet5)
        {
            searchDataSet5(text, oss);
            return true;
        }

        return false;
    }

    bool EnglishLanguageModel::searchDataSet5(const std::string &text, std::ostringstream &oss) const
    {
        std::cout << "[DEBUG]: Checking DataSet 5..\n";

        for (const auto &regexp : m_dataSet5)
        {
            if (std::regex_match(text, std::regex(regexp, std::regex_constants::icase)))
            {
                oss << g_dataSet5MatchOutput;
                return true;
            }
        }

        return false;
    }

} // namespace embeddedIntentRecognizer