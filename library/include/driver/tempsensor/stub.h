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
class Stub
{
public:
    /**
     * @brief Destructor.
     */
    ~Stub() noexcept = default;

    /**
     * @brief Check if the temperature sensor is initialized.
     * 
     * @return True if the temperature sensor is initialized, false otherwise.
     */
    bool isInitialized() const noexcept = 0;

    /**
     * @brief Read the temperature sensor.
     *
     * @return The temperature in degrees Celsius.
     */
    int16_t read() const noexcept = 0;
private:
    bool myInitialized;
    

};
} // namespace tempsensor
} // namespace driver
