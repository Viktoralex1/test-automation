/**
 * @brief Temperature sensor stub.
 */
#pragma once

#include <stdint.h>
#include "driver/tempsensor/interface.h"

namespace driver
{
namespace tempsensor
{
/**
 * @brief Temperature sensor stub.
 */
class Stub final : public Interface
{
public:

    /**
     * @brief Constructor
     */
    Stub() noexcept
        : myInitialized{true}
        , temperature{0}
    {}

    /**
     * @brief Destructor.
     */
    ~Stub() noexcept = default;

    /**
     * @brief Check if the temperature sensor is initialized.
     * 
     * @return True if the temperature sensor is initialized, false otherwise.
     */
    bool isInitialized() const noexcept override { return myInitialized; }

    /**
     * @brief Read the temperature sensor.
     *
     * @return The temperature in degrees Celsius.
     */
    int16_t read() const noexcept override {
        return temperature;
    }

    Stub(const Stub&)            = delete; // No copy constructor.
    Stub(Stub&&)                 = delete; // No move constructor.
    Stub& operator=(const Stub&) = delete; // No copy assignment.
    Stub& operator=(Stub&&)      = delete; // No move assignment.    


private:
    /* Initialization state (high = True) */
    bool myInitialized;
    /* Temperature */
    int16_t temperature;

};
} // namespace tempsensor
} // namespace driver
