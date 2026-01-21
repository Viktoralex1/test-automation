/**
 * @brief GPIO driver stub.
 */
#pragma once

#include <stdint.h>

#include "driver/gpio/interface.h"

namespace driver
{
namespace gpio
{
/**
 * @brief GPIO stub driver.
 */
class Stub final : public Interface
{
public:
    /** 
     * @brief Constructor.
     */
    Stub() noexcept
        : myEnabled{false}
        , myInitialized{true}
        , myInterruptEnabled{false}
    {}

    /** 
     * @brief Destructor.
     */
    ~Stub() noexcept override = default;

    /** 
     * @brief Check whether the GPIO is initialized.
     * 
     *        An uninitialized device indicates that the specified PIN was unavailable or invalid
     *        when the device was created.
     * 
     * @return True if the device is initialized, false otherwise.
     */
    bool isInitialized() const noexcept override { return myInitialized; }

    /**
     * @brief Get the data direction of the GPIO.
     * 
     * @return The data direction of the GPIO.
     */
    Direction direction() const noexcept override {return Direction::Input;} //Direction is irrelevant for this stub}

    /**
     * @brief Read input of the GPIO.
     * 
     * @return True if the input is high, false otherwise.
     */
     bool read() const noexcept override { return myEnabled; }

    /**
     * @brief Write output to the GPIO.
     * 
     * @param[in] output The output value to write (true = high, false = low).
     */
    void write(bool output) noexcept override 
    {
        if (myInitialized) { myEnabled = output; }
    };

    /**
     * @brief Toggle the output of the GPIO.
     */
    void toggle() noexcept override 
    {
        if(myInitialized) {myEnabled = !myEnabled;} 
    };

    /**
     * @brief Enable/disable pin change interrupt for the GPIO.
     * 
     * @param[in] enable True to enable pin change interrupt for the GPIO, false otherwise.
     */
    void enableInterrupt(bool enable) noexcept override
    {
        if(myInitialized){ myInterruptEnabled = enable; }
    }

    /**
     * @brief Enable pin change interrupt for I/O port associated with the GPIO.
     * 
     * @param[in] enable True to enable pin change interrupt for the I/O port, false otherwise.
     */
    void enableInterruptOnPort(bool enable) noexcept override
    {
        if (myInitialized) { myInterruptEnabled = enable; }
    }

        /**
     * @brief Set initialization state
     * 
     * @param[in] Initialized gpio initialization state (true = initialized)
     */
    void setInitialized(bool initialized) noexcept 
    { 
        myInitialized = initialized;
        
        if (!myInitialized)
        {
            myEnabled           = false;
            myInterruptEnabled  = false;
        }
    }
    /**
     * @brief Check wether interrupts are enabled for the GPIO
     * 
     * @return True if interrupt are enabled, false otherwise
     */
    bool isInterruptEnabled() const noexcept { return myInterruptEnabled; }

    Stub(const Stub&)            = delete; // No copy constructor.
    Stub(Stub&&)                 = delete; // No move constructor.
    Stub& operator=(const Stub&) = delete; // No copy assignment.
    Stub& operator=(Stub&&)      = delete; // No move assignment.

private:
    /* Gpio enablement (true = HIGH, false = LOW)*/
    bool myEnabled;
    /* Initialization state (true = initialized)*/
    bool myInitialized;
    /* GPIO interrupt enablement (true = interrupts are enabled)*/
    bool myInterruptEnabled;
};
} // namespace gpio
} // namespace driver

