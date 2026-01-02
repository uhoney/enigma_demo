#pragma once

#include "constants.h"
#include <vector>
#include "raylib.h"

namespace enigma
{
    class Lamp
    {
    private:
        bool is_on{ false };					///< Lamp state
        Vector2 position{};					///< Lamp position on screen

    public:
        Lamp(const Vector2& pos, float r, const Color& col_on, const Color& col_off);

        /**
         * @brief Turns the lamp on
         */
        void turn_on();

        /**
         * @brief Turns the lamp off
         */
        void turn_off();

        /**
         * @brief Draws the lamp on screen
         */
        void draw() const;

        /**
         * @brief Returns whether the lamp is on
         */
        bool is_lit() const;
    };
}