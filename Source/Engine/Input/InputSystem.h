#pragma once
#include <vector>
#include "Core/Vector2.h"
#include <array>

namespace JoeBidenWakeup
{
	class InputSystem
	{
	private:
		std::vector<uint8_t> keyboardState, previousKeyboardState;
		Vector2 mousePosition;
		std::array<uint8_t, 3> mouseButtonState, previousMouseButtonState;

	public:
		InputSystem() = default;
		~InputSystem() = default;

		bool initialize();
		void shutdown();

		void update();
		bool getKeyDown(uint32_t key) const 
		{ 
			return keyboardState[key]; 
		};
		bool getPreviousKeyDown(uint32_t key) const { return previousKeyboardState[key]; };
		const Vector2& getMousePosition() const { return mousePosition; }
		bool getMouseButtonDown(uint32_t button) { return mouseButtonState[button]; }
		bool getMousePreviousButtonDown(uint32_t button) { return previousMouseButtonState[button]; }
	};

	extern InputSystem gInputSystem;
}

