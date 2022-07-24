cmake_minimum_required(VERSION 3.16)

# Require dot, treat the other components as optional
find_package(Doxygen
    REQUIRED dot
    OPTIONAL_COMPONENTS mscgen dia)

# project-specific Doxygen options
set(DOXYGEN_PROJECT_NAME "Embedded Intent Recognizer")
set(DOXYGEN_PROJECT_NUMBER ${Embedded_Intent_Recognizer_VERSION})
set(DOXYGEN_ALPHABETICAL_INDEX NO)
set(DOXYGEN_BUILTIN_STL_SUPPORT YES)
set(DOXYGEN_CASE_SENSE_NAMES NO)
set(DOXYGEN_CLASS_DIAGRAMS YES)
set(DOXYGEN_DISTRIBUTE_GROUP_DOC YES)
set(DOXYGEN_EXCLUDE "${Embedded_Intent_Recognizer_SOURCE_DIR}/src/rapidjson")
set(DOXYGEN_EXTRACT_ALL YES)
set(DOXYGEN_EXTRACT_LOCAL_CLASSES YES)
set(DOXYGEN_FILE_PATTERNS *.dox *.cpp *.hpp *.in)
set(DOXYGEN_GENERATE_TREEVIEW YES)
set(DOXYGEN_HIDE_FRIEND_COMPOUNDS NO)
set(DOXYGEN_HIDE_IN_BODY_DOCS YES)
set(DOXYGEN_HIDE_UNDOC_CLASSES YES)
set(DOXYGEN_HIDE_UNDOC_MEMBERS YES)
set(DOXYGEN_QUIET YES)
set(DOXYGEN_RECURSIVE YES)
set(DOXYGEN_REFERENCED_BY_RELATION YES)
set(DOXYGEN_REFERENCES_RELATION YES)
set(DOXYGEN_SORT_BY_SCOPE_NAME YES)
set(DOXYGEN_SORT_MEMBER_DOCS NO)
set(DOXYGEN_SOURCE_BROWSER YES)
set(DOXYGEN_STRIP_CODE_COMMENTS NO)

doxygen_add_docs(doc
    "${Embedded_Intent_Recognizer_SOURCE_DIR}/config"
    "${Embedded_Intent_Recognizer_SOURCE_DIR}/docs"
    "${Embedded_Intent_Recognizer_SOURCE_DIR}/src"
    "${Embedded_Intent_Recognizer_SOURCE_DIR}/tests"
    ALL
    COMMENT "Generate HTML documentation")