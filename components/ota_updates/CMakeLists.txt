idf_component_register(
    SRCS "ota_updates.cpp"
    INCLUDE_DIRS "."
    REQUIRES esp_http_client esp_https_ota log app_update
)
