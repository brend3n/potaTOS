# potaTOS

potaTOS is an innovative ESP-IDF project designed for ESP32 boards, focusing on creating a robust peer-to-peer network with support for Over-The-Air (OTA) updates. This project integrates a command-line interface (CLI) for ease of use and incorporates non-volatile storage functionality, setting the stage for a versatile and efficient networking solution. Future updates aim to introduce a command server, further expanding its capabilities.

## Installation

To get started with potaTOS, follow these simple steps:

1. Ensure you have ESP-IDF installed on your system. For installation instructions, visit [ESP-IDF Programming Guide](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/get-started/).
2. Clone the potaTOS repository:

    ```bash
        git clone git@github.com:brend3n/potaTOS.git
    ```
3. Navigate to the cloned directory and follow the setup instructions specific to your ESP-IDF environment.

4. Run the init script to setup esp-idf and such 
    ```bash 
        ./init/sh
    ```
    ### Note: 
    The export.sh script needs to be run in each terminal session when building or running esp-idf

    I use an alias in my ~/.bashrc alias:

    ```bash
        alias start_idf='. ~/esp/esp-idf/export.sh'
    ```

    Everytime I open a new terminal I just run the alias as

    ```bash
        start_idf
    ```

## Usage

Currently, users can interact with potaTOS through a CLI. This interface allows for direct engagement with the peer-to-peer network and other features such as OTA updates and non-volatile storage management. Detailed usage instructions and commands will be provided in future documentation.

## Features

- **Peer-to-Peer Networking**: Enables devices to connect and communicate directly without the need for a central server.
- **OTA Updates**: Supports updating device firmware over-the-air, ensuring devices can be kept up-to-date with ease.
- **Command Console**: A user-friendly CLI for managing network settings, updates, and storage.
- **Non-Volatile Storage Functionality**: Allows for persistent storage of settings and data across reboots.

Future enhancements will introduce a command server, further enriching the project's functionality.

## Contributing

We welcome contributions to potaTOS! If you're looking to contribute, please follow these steps:

1. Fork the repository.
2. Create a new branch for your feature or fix.
3. Commit your changes with clear, descriptive messages.
4. Submit a pull request with a summary of your changes and any relevant information.

For bug reports, feature requests, or further discussion, feel free to open an issue on GitHub.

## License

potaTOS is licensed under the MIT License. See the [LICENSE](LICENSE) file for more details.

## Contact

If you have any questions, need support, or want to contribute further, please don't hesitate to contact Brendan at brendencecs@gmail.com.
