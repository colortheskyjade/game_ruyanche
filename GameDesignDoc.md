# Game Design Document
----

## Things
1. Red Ship - Mothership
	* Movement
		* Located above all other ships
		* Left and right across the screen 
		* **High** velocity
		* Will move downwards towards the player in an attempt to abduct them
	* Characteristics
		* **Special**: Abduction
			* Move downwards towards the player and "hover" there
			* Fires a tractor beam
			* If the player is hit by the beam, they will be "captured" and lose a life
			* Upon success, the mothership flies off screen and can be considered dead
			* Upon failure, the mothership flies back to the top and resumes normal flight pattern
		* Fires wide bullets **infrequently**
		* Only one mothership can be on screen at a time.
		* May drop heart on death
	* Apperance
		* Red ship
		* Flashing lights on top
		* Fires a rainbow colored beam
		* *[Insert Image Here]*
2. Blue Ship - Shooting Ship
	* Movement
		* Located in the general ship area
		* Moves only left and right
		* Normal velocity
	* Characteristics
		* Fires average-sized bullets once per cycle
		* Fires frequently
	* Appearance
		* Blue ship
		* *[Insert Image Here]*
3. Green Ship - Double Shooting Ship
	* Movement
		* Located in the general ship area
		* Moves in square patterns (cw and ccw randomly determined)
		* Normal velocity
	* Characteristics
		* Fires average-sized bullets twice per cycle (fires two in a row)
		* Fires frequently
	* Appearance
		* Green
		* *[Insert Image Here]*
4. Purple Ship - Kamikaze Ship
	* Movement
		* Located in the general ship area
		* Moves only left and right
		* Normal velocity
	* Characteristics
		* Does not fire bullet
		* When killed, will quickly move downwards until off screen
		* If player collides with the purple ship, they will lose a life
	* Appearance
		* Purple ship with black "X"
		* *[Insert Image Here]*
5. Projectile
	* Movement
		* Travels straight with predetermined speed
		* Only travels in the up-down direction
	* Characteristics
		* Exists until it collides with another object or goes off screen
	* Appearance
		* Player bullet
			* White bullet
			* Travels relatively quickly
			*	Thin
			* *[Insert Image Here]*
		* Blue/Green ship bullet
			* Blue/green bullets, depending on who fired them
			* Travels relatively quickly
			*	Thin
			* *[Insert Image Here]*
		* Red ship bullet
			* Red-orange bullet
			* Travels relatively quickly
			* Wide (about a ship's width)
			* *[Insert Image Here]*
		* Heart
			* Heart shaped, red-pink
			* Travels relatively slow
			* *[Insert Image Here]*
6. Beam
	* Movement
		* Initial (root) point does not move
		* Beam grows until it reaches the bottom of the screen or a ship
		* Beam moves slower than a bullet but faster than a heart (approx halfway between)
	* Characteristics
		* Only fired by the red ship
		* Will stop growing on contact with the player
	* Appearance
		* Rainbow colored arcs
		* *[Insert Image Here]*

Notes:
* All ships excluding mothership will be given the same (relatively slow) speed, but velocity is randomly generated.

## How to play the game
* Keyboard Gameplay
>! Option to choose between WASD or Arrow Keys
* Arrow keys to move and space to shoot
* Esc to open/close the pause menu
* All menus are mouse-navigated only

## How the score changes
* Score is calculated by the ship killed
	* Blue - 100pt
	* Green - 150pt
	* Purple - 300pt
	* Red - 1000pt

## How to keep track of lives
* Each user starts with 3 lives (that is, 2 hearts in the life counter)
* Red ships drop hearts upon death about 50% of the time, which can be picked up for a life
* Each user can have a maximum of 4 extra lives (lives after that will fully heal the user)
* When a user's HP drops to/below zero, they lose a life, and HP will be restored to 100%. 
* The game ends when the user runs out of lives.

Note: When the user has 1 heart, that means if they lose that heart, they will have 0 hearts remaining. They can play with 0 hearts, but the game ends after they run out of HP having no hearts. (Look at it like they are using their last life, with zero backup lives remaining.) 

## Layout of UI
* Menus
	* Start Menu
		* Start - Start game
>! Options - Go to options menu
		* Help - Go to help screen
		* Quit - Quit the game
>! Options
>! Keyboard - WASD or Arrow Keys
	* Pause Menu
		* Return to Game - Return to currently paused game
		* Restart - Restart game
		* Quit - Exit to menu
	* End Menu
		* Menu - Exit to menu
		* Restart - Restart game
	* Back button on help screen to return to main menu
* Actions
	* Arrow keys to move in gameplay
	* Spacebar to shoot in gameplay
	* Esc to toggle the pause menu in gameplay

## Pictures of what your interface would look like

### Start Screen
![Start Screen](http://cl.ly/image/2A421L0n1I3T/gamefront.png "Start Screen")

### Options Screen
![Options](http://f.cl.ly/items/1M2P2s2E3t0d3t150s3S/gameoptions.png "Options")

### Help Screen
![Help](http://f.cl.ly/items/2D1b0a3m03440R0n2u26/gamehelp.png "Help")

### Sample Game Screen (blocks for ships currently)
![Game](http://f.cl.ly/items/0K3J360g1U1I2v1l2R3a/gameplay.png "Game")

### Pause Menu
![Pause](http://i.imgur.com/MNnXbRD.png "Pause")

### Game End
![End](http://f.cl.ly/items/0g031H0y2C1j0b141x2E/gameend.png "End")

## CREATE THIS ISSUEEEEEE

```
Title: Milestone 5A Submission
Label: PA5
Milestone: 5A
Assigned to:
Lecture MW 12pm @sprarage
Lecture MW 3:30pm @nakulj
Lecture TTh 12:30pm @Michael-Borke
Write (issue body): you state:
Your milestone 5A is ready for grading
The document file name
The SHA Hash of the commit to be graded.
```
