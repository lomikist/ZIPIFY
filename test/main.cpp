#include <boost/gil.hpp>
#include <boost/gil/extension/io/png.hpp>
#include <iostream>
#include <stdexcept>

int main() {
    namespace gil = boost::gil;

    try {
        // Load the image (RGBA format)
        gil::rgba8_image_t img;
        gil::read_image("input.png", img, gil::png_tag());

        // Iterate over the image pixels
        for (int y = 0; y < img.height(); ++y) {
            auto row = gil::view(img).row_begin(y);
            for (int x = 0; x < img.width(); ++x) {
                gil::rgba8_pixel_t& pixel = row[x];
                // Set RGB channels to 255 (white)
                gil::at_c<0>(pixel) = 255; // Red
                gil::at_c<1>(pixel) = 255; // Green
                gil::at_c<2>(pixel) = 255; // Blue
                // Set alpha channel to 255 (fully opaque)
                gil::at_c<3>(pixel) = 255; // Alpha
            }
        }

        // Save the modified image (optional)
        gil::write_view("output.png", gil::const_view(img), gil::png_tag());
        std::cout << "Image converted to white and saved as output.png" << std::endl;

    } catch (const std::ios_base::failure& e) {
        std::cerr << "I/O error: " << e.what() << std::endl;
        return 1;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    } catch (...) {
        std::cerr << "An unknown error occurred." << std::endl;
        return 1;
    }

    return 0;
}
