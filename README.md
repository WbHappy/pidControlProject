# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program

---

## Dependencies

* cmake >= 3.5
 * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1(mac, linux), 3.81(Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools]((https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* [uWebSockets](https://github.com/uWebSockets/uWebSockets)
  * Run either `./install-mac.sh` or `./install-ubuntu.sh`.
  * If you install from source, checkout to commit `e94b6e1`, i.e.
    ```
    git clone https://github.com/uWebSockets/uWebSockets 
    cd uWebSockets
    git checkout e94b6e1
    ```
    Some function signatures have changed in v0.14.x. See [this PR](https://github.com/udacity/CarND-MPC-Project/pull/3) for more details.
* Simulator. You can download these from the [project intro page](https://github.com/udacity/self-driving-car-sim/releases) in the classroom.

Fellow students have put together a guide to Windows set-up for the project [here](https://s3-us-west-1.amazonaws.com/udacity-selfdrivingcar/files/Kidnapped_Vehicle_Windows_Setup.pdf) if the environment you have set up for the Sensor Fusion projects does not work for this project. There's also an experimental patch for windows in this [PR](https://github.com/udacity/CarND-PID-Control-Project/pull/3).

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./pid`

Tips for setting up your environment can be found [here](https://classroom.udacity.com/nanodegrees/nd013/parts/40f38239-66b6-46ec-ae68-03afd8a601c8/modules/0949fca6-b379-42af-a919-ee50aa304e6a/lessons/f758c44c-5e40-4e01-93b5-1a82aa4e044f/concepts/23d376c7-0195-4276-bdf0-e02f1f3c665d)

## [Rubric points](https://review.udacity.com/#!/rubrics/1972/view)

### Compilation

#### Your code should compile

The code compiles without errors or warnings.

### Implementation

#### The PID procedure follows what was taught in the lessons

The PID class is implement in [src/PID.cpp](src/PID.cpp). The [UpdateError method](src/PID.cpp#L33) handles computation of the proportional, integral and derivative errors and the [TotalError method](./src/PID.cpp#L55) computes the total error using our defined coefficients.

### Reflection

#### Describe the effect each of the P, I, D components had in your implementation

The proportional coefficient gives the fastest result in the car following the center of the track. However, using only this coefficient is not enough as the car quickly overshooted and went out of track.

The integral coefficient is usefull to remove a static bias. In this simulator no static bias exists so this explain why only a 0.0 value is working.

The differential coefficient is helpful to counter the overshooting of the proportional coefficient. This means that thanks to this coefficient the car stays nearly always on the center of the track.

#### Describe how the final hyperparameters were chosen

In order to choose the coefficients I honestly did multiple tests and failed multiple times. I changed the proportional coefficient first and result was actually good. Eventually the car started to overshoot and car went out of track. I then started to modify the integral and differential coefficient. Any value to the integral coefficient got the car outside the tracks.
My final parameters are : P = 0.12 | I = 0.0 | D = 2.5.

### Simulation

#### The vehicle must successfully drive a lap around the track

The vehicle managed to drive a full lap around the track without any issue.
