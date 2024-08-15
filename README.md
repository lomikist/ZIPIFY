# ZIPIFY


To properly work with this project, ensure you have the following installed on your device:

- Boost
- CMake

## Build Instructions

Follow these steps to build and run the project:

1. Create a build directory:
    ```bash
    mkdir build
    ```

2. Navigate to the build directory:
    ```bash
    cd build
    ```

3. Run CMake to configure the project:
    ```bash
    cmake ..
    ```

4. Compile the project using `make`:
    ```bash
    make
    ```

5. Run the executable with a specified file:
    ```bash
    ./MyExecutable <some.file>
    ```
6. To process a .zipo file and extract its contents, use the following command:
    ```bash
    ./MyExecutable <out.zipo>
    ```
Replace `<some.file>` with the actual file you want to process.

## Notes

- Make sure Boost libraries are correctly linked in your CMake configuration.
- Ensure that all required dependencies are installed and properly configured.

## Troubleshooting

If you encounter any issues during the build process, consider the following steps:

- Verify that Boost is installed and accessible.
- Check that CMake is installed and available in your system's PATH.
- Ensure all dependencies are up to date and compatible with your system.

For further assistance, refer to the project's documentation or seek help from the community.
