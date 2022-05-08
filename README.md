<h1 align="center">
	🎮 so_long
</h1>

<p align="center">
	<b><i>And thanks for all the fish!</i></b><br>
</p>

<p align="center">
	<img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/surfi89/so_long?color=lightblue" />
	<img alt="Number of lines of code" src="https://img.shields.io/tokei/lines/github/surfi89/so_long?color=critical" />
	<img alt="Code language count" src="https://img.shields.io/github/languages/count/surfi89/so_long?color=yellow" />
	<img alt="GitHub top language" src="https://img.shields.io/github/languages/top/surfi89/so_long?color=blue" />
	<img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/surfi89/so_long?color=green" />
</p>

<h3 align="center">
	<a href="#%EF%B8%8F-about">About</a>
	<span> · </span>
	<a href="#%EF%B8%8F-usage">Usage</a>
	<span> · </span>
	<a href="#-testing">Testing</a>
</h3>

---

## 💡 About the project

> _This project is a very small 2D game.
Its purpose is to make you work with textures, sprites, and some other very basic gameplay elements._

	It’s time for you to create a basic computer graphics project!
	so long will help you improve your skills in the following areas:
	window management, event handling, colors, textures, and so forth.
	You are going to use the school graphical library: the MiniLibX!
	This library was developed internally and includes basic necessary tools to open
	a window, create images and deal with keyboard and mouse events.
	The other goals are similar to every other goal for this first year:
	being rigorous, level up in C programming, use basic algorithms, do some
	information research, and so forth. 

For more detailed information, look at the [**subject of this project**](https://github.com/Surfi89/42cursus/tree/main/Subject%20PDFs).


## 🛠️ Usage

### Requirements

The function is written in C language and thus needs the **`gcc` compiler** and some standard **C libraries** to run.

### Instructions

**1. Compiling**

To compile, go to the project path and run:

```shell
$ make
```

or

```shell
$ make bonus
```

If you want the player sprite to be animated and have enemies in the map.

## 📋 How to play

To play the minigame just need to launch it with the following shell command:

```shell
$ ./so_long <map_name>.ber
```

or

```shell
$ ./so_long_bonus <map_name>.ber
```

I added some maps if you want to test the game.
- "map1.ber" is a very simple map.
- "map2.ber" is a bigger map with more collectibles.
- "map3.ber" has some enemies for playing with the bonus minigame.

**Controls**

You can use WASD to move UP, LEFT, DOWN or RIGHT respectively.
To quit the game press ESC or click on the red cross of window.
If you touch an enemy you loose the game.
To win its necessary to pick up all collectibles and get back to the exit.

**Maps**

You can use any map of your choice as long as you follow the next rules:

* The file extension must be `.ber`.
* Its must be rectangular, and the whole map limits must be a `1`.
* It can only have one exit, one player and at least one collectible.
* Characters allowed:

|  Character  |          Object          |
|:-----------:|:------------------------:|
|     *1*     | Obstacle                 |
|     *0*     | Empty                    |
|     *C*     | collectible              |
|     *E*     | exit                     |
|     *P*     | Player starting position |
|     *K*     | Enemy position           |


I added some maps if you want to test the game.
- "map1.ber" is a very simple map.
- "map2.ber" is a bigger map with more collectibles.
- "map3.ber" has some enemies for playing with the bonus minigame.


Example of map2.ber with an enemy:


![so_long_42](https://github.com/Surfi89/so_long/blob/main/so_long_42.png)

