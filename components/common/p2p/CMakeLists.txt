file(GLOB_RECURSE COMMON_SOURCES "*.c" "*.cpp")
idf_component_register(SRCS "p2p.cpp" "${COMMON_SOURCES}"
                    INCLUDE_DIRS "."
                                 "message_handling"
                                 "message_structure")

