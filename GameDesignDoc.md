# Game Design Document
----

## Things
1. Red Ship - Mothership
	* Will move left and right across the screen with relatively high velocity (hard to shoot)
	* Sometimes will try to move downwards towards the user ship in an attempt to "abduct" them, pausing when x-coordinates are lined up to fire the tractor beam (random event)
	* Fires large (wide) bullets infrequently
	* Looks like a red ship with flashing lights at the top 
	* _Insert Image Here_
2. Blue Ship - Shooting Ship
	* Will move left and right within approx 50-150 px in the screen, staying in formation
	* Blue-colored ship
	* Fires single bullet frequently
	* _Insert Image Here_
3. Green Ship - Double Shooting Ship
	* Will move left, right, up, and/or down within approx 50-150px in the screen, staying in formation
	* Green-colored ship
	* Fires two bullets in a row frequently
	* _Insert Image Here_
4. Purple Ship - Suicide Ship
	* Will move l/r/u/d within approx 50-150px in the screen, staying in formation
	* Purple-colored ship with X across the front
	* Does not fire bullets
	* When killed, will immediately drop down off the screen in an attempt to kill the user (user dies on collision)
5. Projectile
	* Travels straight, normal to the line of entry
	* Exists until it collides with another object
	* Depending on ship that fires it, different image
	* Hearts are "neutral" projectiles that are slower than other projectiles
	* _Insert Images Here w/ Ship reference_

Notes:
* All ships excluding mothership will be given the same (relatively slow) speed, but velocity is randomly generated.

## How to play the game
* Keyboard Gameplay
* Option to choose between WASD or Arrow Keys
* Either way, space to shoot
* Esc to bring up the menu, which is mouse-navigated

## How the score changes
* Score is calculated by the ship killed
	* Blue - 100pt
	* Green - 150pt
	* Purple - 300pt
	* Red - 1000pt
* Score will be cut in half if you lose all your lives and choose to continue
* Each game only has ONE continue. This is hidden to the user, but they will only be prompted ONCE to continue after death.

## How to keep track of lives
* Each user starts with 3 lives (that is, 2 hearts in the life counter)
* Purple and Red ships VERY INFREQUENTLY drop hearts, which can be picked up for a life
* Each user can have a maximum of 4 extra lives (lives after that will fully heal the user)
* When a user's HP drops to/below zero, they lose a life, and HP will be restored to 100%. 
* The game ends when the user runs out of lives.

Note: When the user has 1 heart, that means if they lose that heart, they will have 0 hearts remaining. They can play with 0 hearts, but the game ends after they run out of HP having no hearts. (Look at it like they are using their last life, with zero backup lives remaining.) 

## Layout of UI
* Menus
	* Start Menu
		* BUttons
	* Pause Menu
		* Buttons
	* End Menu
		* Buttons
* Actions
	* What does this mean ):
* Other UI Components

* What they do

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
![Pause](http://f.cl.ly/items/00313x3k1O1U2v2W111f/gamepause.png "Pause")

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
