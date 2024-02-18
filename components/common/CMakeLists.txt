file(GLOB_RECURSE COMMON_SOURCES "*.c" "*.cpp")
idf_component_register(SRCS "${COMMON_SOURCES}"
                    INCLUDE_DIRS "cli"
                                  "led_control"
                                  "nv_mem"
                                  "ota_updates"
                                  "p2p"
                                  "utilities")

