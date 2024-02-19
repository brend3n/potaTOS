idf_component_register(
    SRCS "main.cpp"
    INCLUDE_DIRS "."
    REQUIRES freertos board_config tasks utilities arduino
)
