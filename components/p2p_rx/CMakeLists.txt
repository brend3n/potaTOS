idf_component_register(
    SRCS "p2p_rx.cpp"
    INCLUDE_DIRS "."
    REQUIRES utilities freertos p2p board_config arduino
)
