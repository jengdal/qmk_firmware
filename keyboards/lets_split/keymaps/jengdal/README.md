# Half Lets Split

This is a keymap that attempts to make it possible to let only one
half of a Lets Split assume the responsibilities of a full keyboard.
At the time of writing it has only been slightly tested on a left
half of a Lets Split. I haven't built the right side yet. :)
Inspired by the Half Keyboard by Matias.

Holding down SPACE will mirror the other side of the keyboard on
the BASE, LOWER and RAISE layers. Tapping SPACE will produce a 
space.

The keymap is based on the default Lets Split keymap with some
modifications:
- Since I'm on a Mac I've flipped Alt and GUI
- You tap (as opposed to hold) LOWER and RAISE to move to them
- I've removed Dvorak and Colemak support
- I've removed the audio support
- Maybe introduced some fun bugs
- Nightmare handcramps?

Example usage:

- Producing backspace with the left side
    - Hold SPACE and press ESC
- Producing enter with the left side
    - Hold SPACE and press SHIFT
- Producing !
    - Press LOWER
    - Press Q
    - Go back to BASE by pressing LOWER again
    - (This is just like on a regular Lets Split with the default
      layout, no mirroring here)
- Producing the character 9 with the left side
    - Move to RAISE by pressing the LOWER key while holding SPACE
    - Press W
    - Go back to BASE by pressing LOWER again
- Producing a COLON
    - Hold SHIFT
    - Hold SPACE
    - Press A
