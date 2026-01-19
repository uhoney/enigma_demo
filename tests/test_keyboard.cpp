#include <catch2/catch_test_macros.hpp>

#include "../src/core/keyboard.h"

TEST_CASE("Keyboard test", "[keyboard]")
{

    // FIXME: 
    // isKeyPressed takes ref mouse pos. this is bad for simulation
	// final position is not decided yet, so mouse pos is hardcoded for tests
 
    Vector2 virtual_mouse_Q{140.0f, 575.0f};    // 'Q' key position
    Vector2 virtual_mouse_S{235.0f, 640.0f};    // 'S' key position
    Vector2 virtual_mouse_X{270.0f, 705.0f};    // 'X' key position

    enigma::Keyboard keyboard{};
    REQUIRE(keyboard.get_keys().size() == 26);

    keyboard.is_key_pressed(virtual_mouse_Q, true);
    REQUIRE(keyboard.get_pressed_key() != nullptr);
    REQUIRE(keyboard.get_pressed_key()->get_label() == 'Q');
    keyboard.is_key_released(true);
    REQUIRE(keyboard.get_pressed_key() == nullptr);

    keyboard.is_key_pressed(virtual_mouse_S, true);
    REQUIRE(keyboard.get_pressed_key() != nullptr);
    REQUIRE(keyboard.get_pressed_key()->get_label() == 'S');
    keyboard.is_key_released(true);
    REQUIRE(keyboard.get_pressed_key() == nullptr);

    keyboard.is_key_pressed(virtual_mouse_X, true);
    REQUIRE(keyboard.get_pressed_key() != nullptr);
    REQUIRE(keyboard.get_pressed_key()->get_label() == 'X');
    keyboard.is_key_released(true);
    REQUIRE(keyboard.get_pressed_key() == nullptr);
}