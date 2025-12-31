#pragma once
#include "raylib.h"
#include <vector>
#include <string_view>

/**
 * @name Key constants
 * Key drawing constants
 */
///@{
static constexpr float KEY_PADDING{75.0f};		///< Distance between button centers
static constexpr float KEY_OUTER_RING{30.0f};	///< Outer ring radius
static constexpr float KEY_INNER_RING{25.0f};	///< Inner ring radius
///@}

/**
 * @brief Represents a key in the Enigma machine	
 */
class Key
{
private:
	/**
	 * @brief Character label of the v. Includes null terminate '\0'
	 */
	char character[2]{};
	/**
	 * @brief Position of the key center
	 */
	Vector2 position{};
	/**
	 * @brief Size multiplier for key scaling (e.g. when pressed)
	 */
	float size_multiplier{1.0f};
	/**
	 * @brief Constants for key drawing
	 */
	float outer_ring{KEY_OUTER_RING};
	/**
	 * @brief Constants for key drawing
	 */
	float inner_ring{KEY_INNER_RING};

public:
	/**
	 * @brief Constructor
	 * Uses curlybrace initialization -- supposedly modern C++ style
	 * @param char Character label of the key
	 * @param pos Position of the key center
	 */
	Key(char, Vector2 pos);
	~Key();

	/**
	 * @brief Returns the character label of the key
	 */
	char get_label() const;
	/**
	 * @brief Returns the character label as a C-string (for raylib DrawTextEx())
	 */
	const char *get_text();
	/**
	 * @brief Returns the position of the key center
	 */
	Vector2 get_position() const;
	/**
	 * @brief Returns the key size (outer ring radius)
	 */
	float get_key_size() const;
	/**
	 * @brief Sets the size multiplier for key scaling
	 */
	void set_size_multiplier(float);
	/**
	 * @brief Draws the key using the provided font and offset
	 */
	void draw_key(Font, Vector2);

	// STATIC METHODS
	/**
	 * @brief Creates all keys based on the provided starting position and keypad characters
	 * @param x Starting x position
	 * @param y Starting y position
	 * @param keypad_characters String of characters representing the keys to create
	 * @return Vector of created Key objects
	 */
	static std::vector<Key> create_all_keys(float, float, std::string_view);
};