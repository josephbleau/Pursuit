Pursuit:

  Pursuit is a simple game written in C++ using SDL (Simple DirectMedia Library). The goal of this project is to demonstrate the least circuitous process for creating a game from an empty main() to a working prototype. The concept is simple: outline exact goals which are directly associated with a part of the game that needs to work, implement those things as simply as possible, and only refactor for generalized scenarios when something else in the game calls for it.

  "Engine Hell" is too common a phenomena, it is the one where a developer becomes too focused on implementing the best solutions for every system in his game, and solves problems that don't exist. It's when you start looking at the forrest, and not the tree, thinking about how you can satisfy every need, when you only have one. The goal of Pursuit is to directly circumvent "Engine Hell."

Concept:
  The goal of Pursuit is to survive as long as possible, there are only four types of objects: Player, Trap, TrapPickup, Enemy. In Pursuit you will be chased by your enemies, and the only method you have to avoid them are traps, these are objects you can pickup and place where you want which provide different effects. Effect ideas, while not set in stone, might include: snare, mine, or poison.

Controls:
  W,A,S,D: Movement
  Mouse click: (radius around player) 'tosses' the tap a short distance 

Implementation stepping stones:
  These are the specific and immediate implementation needs to fufill the most basic version of the game.

  1) Draw square.
  2) Allow input (keybrd) to move this square (square is representing the player.)
    2.a) Bounds checking against the walls of the level (player cannot leave the level.)
  4) Draw trap tossing cursor (mouse controlled)
  5) Draw another square, different color (enemy.)
  6) Give the enemy a simple 'follow player' logic.
  7) Determine if enemy and player overlap
  8) On collisions, damage player
    8.a) If we haven't player needs to be storing a health attribute