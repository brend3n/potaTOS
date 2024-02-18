file(GLOB_RECURSE COMMON_SOURCES "*.c" "*.cpp")
idf_component_register(SRCS "${COMMON_SOURCES}"
                    INCLUDE_DIRS
                                    "api"
                                    "common"
                                    "config"
                                    "tasks")