idf_component_register(
    SRCS "main.c"
    INCLUDE_DIRS "."
    REQUIRES freertos board_config tasks utilities
)
