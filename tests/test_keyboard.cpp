#include <catch2/catch_test_macros.hpp>

#include "../src/core/keyboard.h"

TEST_CASE("Keyboard test", "[keyboard]")
{

    // FIXME: 
    // isKeyPressed takes ref mouse pos. this is bad for simulation
	// final position is not decided yet, so mouse pos is hardcoded for now
 
    Vector2 virtual_mouse_Q{300.0f, 400.0f};    // 'Q' key position
    Vector2 virtual_mouse_S{400.0f, 470.0f};    // 'S' key position
    Vector2 virtual_mouse_X{430.0f, 530.0f};    // 'X' key position

    enigma::KeyBoard keyboard{};
    REQUIRE(keyboard.get_keys().size() == 26);

    keyboard.isKeyPressed(virtual_mouse_Q, true);
    REQUIRE(keyboard.get_pressed_key() != nullptr);
    REQUIRE(keyboard.get_pressed_key()->get_label() == 'Q');
    keyboard.isKeyReleased(true);
    REQUIRE(keyboard.get_pressed_key() == nullptr);

    keyboard.isKeyPressed(virtual_mouse_S, true);
    REQUIRE(keyboard.get_pressed_key() != nullptr);
    REQUIRE(keyboard.get_pressed_key()->get_label() == 'S');
    keyboard.isKeyReleased(true);
    REQUIRE(keyboard.get_pressed_key() == nullptr);

    keyboard.isKeyPressed(virtual_mouse_X, true);
    REQUIRE(keyboard.get_pressed_key() != nullptr);
    REQUIRE(keyboard.get_pressed_key()->get_label() == 'X');
    keyboard.isKeyReleased(true);
    REQUIRE(keyboard.get_pressed_key() == nullptr);
}