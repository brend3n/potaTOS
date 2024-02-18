# idf_component_register(SRCS "main.c"
#                     INCLUDE_DIRS "."
#                     "../components/config"
#                     "../components/common"
#                     "../components/tasks")


idf_component_register(
    SRCS "main.c"
    INCLUDE_DIRS "."
    REQUIRES freertos board_config tasks utilities
)
