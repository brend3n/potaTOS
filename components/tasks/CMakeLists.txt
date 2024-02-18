idf_component_register(
    SRCS "task_info.cpp"
    INCLUDE_DIRS "."
    REQUIRES cli p2p p2p_rx p2p_tx ota_updates utilities board_config freertos
)
