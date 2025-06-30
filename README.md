# CCP6124 OBJECT-ORIENTED PROGRAMMING & DATA STRUCTURES - TRIMESTER 2510

## Submission Date

30th May 2025, Friday, 5:00 p.m., Week 10

## Individual Assignment

This is an assignment for a group of one to four students. **STRICTLY NO COPYING** from other sources except codes given in this course. If detected, all parties involved will get 0 marks. The codes must be your own.

## Assignment

In this assignment, you are required to implement a "Robot War" simulator using standard C++. The simulator simulates the warfare of robots in a given battlefield. The rules of war are as follow:

### Number 1

The battlefield of the war is a 2D m×n matrix[^1] to be displayed on a screen. You can choose any appropriate battlefield representation using characters and symbols to represent robots, battlefield locations and battlefield boundaries.

### Number 2

The simulation is turn-based. If you have 3 robots simulated, robot one performs its action plan first, followed by robot two and robot three before going back to robot one, robot two and so on.

### Number 3

The position of a robot is not revealed to other robots.[^2] Each robot can perform a 'look' action to see what are around.

### Number 4

A robot can take a 'move' action to one of its 8 neighbouring locations:
- Up
- Down
- Left
- Right
- Up Left
- Up Right
- Down Left
- Down Right

| **Up Left** | **Up** | **Up Right** |
| :-----: | :-----: | :-----: |
| **Left** | **ROBOT** | **Right** |
| **Down Left** | **Down** | **Down Right** |

### Number 5

The look(x, y) action will reveal a nine-square area to a robot, centred on (robotsPositionX + x, robotsPositionY + y). Thus a look(0, 0) will provide the robot with its immediate neighbourhood[^3]. The look action should reveal whether a location is in the battlefield or not, or whether a location contains an enemy robot. A location can only be occupied by one robot.

### Number 6

The robot can perform a fire(x, y) action[^4]. This action will have a 70% probability to hit and destroy any robot in the location[^5]. Make sure that the robot will not fire at (0, 0). A robot must not commit suicide.

### Number 7

Each robot has a type[^6] and a name. The simulator will be started with a number of robots in different positions and it will display the actions of robots until the simulation time is up or until one robot remains, whichever comes first.

### Number 8

All robots' objects should inherit from a base abstract class called Robot. This Robot class is to be inherited by 4 basic abstract subclasses, namely:
- MovingRobot
- ShootingRobot
- SeeingRobot
- ThinkingRobot

These 4 classes should not have any overlapping public member functions[^7] and data members. All robot types mentioned below must be inherited[^8] from these 4 classes depending on their capacity to move, shoot, see and think.

### Number 9

The initial robot type is GenericRobot. It has the following capabilities:

#### GenericRobot

In each turn, this robot can in any order:
- think to decide what to do.
- look(x, y) one time where (x, y) is any 8 neighbouring locations or the location of the robot itself.
- fire(x, y) one time where (x, y) is any 8 neighbouring locations. It has only 10 shells to fire in a match. If a robot uses up all its shells, it will self destruct.
- move to one of its 8 neighbouring locations or remain in place.

If it can destroy a robot, it can choose an upgrade.

There are three possible areas to upgrade. They are moving, shooting and seeing:
- **Moving:** HideBot or JumpBot
- **Shooting:** LongShotBot, SemiAutoBot or ThirtyShotBot
- **Seeing:** ScoutBot or TrackBot

In each area, a robot can choose only one upgrade. For the next upgrade, the robot must choose from the areas not chosen before. After three upgrades, a robot cannot be upgraded anymore.

The capabilities of the upgrades are as follow:

#### MOVING - HideBot

The robot can hide three times in a match. When the robot hides, it cannot be hit by other robots.

#### MOVING - JumpBot

The robot can jump to a new location anywhere in the map. It can jump three times in a match.

#### SHOOTING - LongShotBot

The robot can fire up to three unit distance away from its location. It means the robot can fire(x, y) where:

```
x + y <= 3
```

#### SHOOTING - SemiAutoBot

Each shell the robot fires is now considered as three consecutive shots into one location and each shot has a 70% probability to hit and destroy another robot.

#### SHOOTING - ThirtyShotBot

The robot now has a fresh load of 30 shells replacing its current load of shells.

#### SEEING - ScoutBot

Instead of look(x, y), the robot can see the entire battlefield for one turn. This ability can be used three times in a match.

#### SEEING - TrackBot

The robot can plant a tracker on another robot it can see. The location of the targeted robot will be known to the robot until the end of a match. The robot has three trackers.

### Number 10

The initial conditions of a simulation are specified in a text file which contains:
- The dimensions of the battlefield (M by N)
- The number of simulation steps (T)
- The number of robots (R)
- The type, name and initial position of each robot[^9]

An example text file looks like this:

```
M by N : 40 50
steps: 300
robots: 5
GenericRobot     Kidd      3          6
GenericRobot     Jet       12         1
GenericRobot     Alpha     35         20
GenericRobot     Beta      20         37
GenericRobot     Star      random     random
```

### Number 11

Each robot has three lives. When a robot is destroyed, it can go into a queue to re-enter into the battlefield three times. Only one robot can re-enter as a GenericRobot each turn to a random location in the battlefield.

### Number 12

The above requirements are the basic requirements of this assignment. Add three more new robot types to make the simulation even more exciting.

## Implementation

1. In each turn of a simulation, display the battlefield, the actions and the results of the actions of each robot in that turn. In addition, save the same information into a text file.

2. Classes and functions in the standard C++ libraries can be used. Refer to the **Reference** section in [www.cplusplus.com](www.cplusplus.com) to find a list of standard C++ libraries.

3. Your solution must employ the **Object-Oriented Programming** concepts you have learnt such as **INHERITANCE**, **POLYMORPHISM**, **OPERATOR OVERLOADING** and any number of C++ object-oriented features.

4. Your code should use vectors or dynamic arrays to store robots, so that it does not limit the number of robots.

## Deliverables

- Source code in one file

```
TC01.1171777777.Tony.Gaddis.cpp
```

- Design documents such as class diagrams, flowcharts and/or pseudocodes in PDF format to explain your work.
- Screenshots and explanation of your program running compiled into a document in PDF format.

## Additional Information On Deliverables

1. Source codes have to be properly formatted and documented with comments and operation contracts. Do not submit executable files.

2. For **ALL** your '.cpp' and '.h' files, insert the following information at the top of the file:

```
/**********|**********|**********|
Program: YOUR_FILENAME.cpp / YOUR_FILENAME.h
Course: Data Structures and Algorithms
Trimester: 2410
Name:Frank Carrano
ID: 1071001234
Lecture Section: TC101
Tutorial Section: TT1L
Email: abc123@yourmail.com
Phone: 018-123 4567
**********|**********|**********/
```

## Soft-Copy Submission Instruction

1. Create a folder in the following format:

```
TUTORIALSECTION_ASSIGNMENT_FULLNAME
```

For example, if your name is Frank Carrano, you come from TC201 tutorial section and you are submitting Assignment Milestone 1, then your folder name should be **"TC201_M1_FRANK_CARRANO"** without the double quotes.

```
TC201_M1_FRANK_CARRANO
```

2. Place all files for submission into the folder.

3. Zip your folder to create a zip archive. Remember that for Assignment Milestone 2, your zip archive file name should be:

```
TC201_M2_FRANK_CARRANO.zip
```

4. Submit your assignment through eBwise. 10% per day penalty for late submissions.

## Evaluation Criteria

| Criteria | Maximum Marks |
| :-----: | :-----: |
| Design decumentation[^10] | 5 |
| Initialization of a simulation | 3 |
| Display and logging of the status of the battlefield at each turn | 5 |
| Display and logging of the actions and the status of each robot at each turn | 3 |
| Implementation of the required robot classes with Object-Oriented Programming concepts | 10 |
| Algorithms used to optimize the actions of robots listed in the assignment document | 5 |
| Implementation of three new robot classes[^11] | 9 |
| **Total** | **40** |

Each feature will be evaluated based on fulfilment of requirements, correctness, compilation without warnings and errors, error free during runtime, basic error handling, quality of comments, user friendliness and good coding format and style.

## Footnotes

[^1]: **EXAMPLE:** An 80×50 battlefield matrix
[^2]: robotsPositionX and robotsPositionY are private members of every robot class
[^3]: an exhaustive list of places it can visit in its next turn
[^4]: keeping in mind that different robot have different fire patterns
[^5]: robotsPositionX + x, robotsPositionY + y
[^6]: which determines the robot's strategy
[^7]: also known as methods
[^8]: multiple inheritance
[^9]: if the initial position is random, the robot is placed in a random location
[^10]: must include a class diagram
[^11]: 3 marks for each robot
