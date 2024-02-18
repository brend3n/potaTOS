idf_component_register(
    SRCS "p2p_tx.cpp"
    INCLUDE_DIRS "."
    REQUIRES utilities freertos p2p board_config
)
