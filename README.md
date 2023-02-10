# Path Planning in C++

This is the eighth project in the Udacity Self-Driving Car Engineer Nanodegree: implementing a PID controller in C++ to drive around a highway circuit.

## Description

## Requirements

- cmake >= 3.5
- make >= 4.1
- gcc/g++ >= 5.4
- [uWebSockets](https://github.com/uWebSockets/uWebSockets) @ `e94b6e1`
- [nlohmann-json](https://github.com/nlohmann/json)

To install uWebSockets, follow these instructions:
```
git clone https://github.com/uWebSockets/uWebSockets
cd uWebSockets
git checkout e94b6e1
mkdir build
cd build
cmake ..
make
sudo make install
cd ../..
sudo ln -s /usr/lib64/libuWS.so /usr/lib/libuWS.so
sudo rm -r uWebSockets
```

To install nlohmann-json, you have serveral options. You can:

1. Install using a package manager (easiest)

For Ubuntu:

```bash
sudo apt install nlohmann-json3-dev # use nlohmann-json-dev for Ubuntu 18.04
```

For Fedora:

```bash
sudo dnf install json-devel
```

For MacOS:
```bash
brew install nlohmann-json
```

2. Download manually

```bash
wget https://github.com/nlohmann/json/releases/download/v3.11.2/json.tar.xz
tar -xvf json.tar.xz
sudo cp -r json/include/nlohmann /usr/include/
rm -rf json json.tar.xz
```

## Build instructions

1. Clone this repo
```console
git clone https://github.com/ibvandersluis/udacity-CarND-P08-pid-controller.git
cd udacity-CarND-P08-pid-controller
```
2. Build the project
```console
mkdir build && cd build
cmake ..
make
```

## Run

To run this project as intended, you will need the [Term 2 Udacity Simulator](https://github.com/udacity/self-driving-car-sim/releases/).

1. Run the PID controller
```console
./pid
```
You should get back:
```
Listening to port 4567
```
2. Run the simulator and select the path planning project

When you do this, the particle filter executable should report:
```
Connected!!!
```
3. The vehicle should start moving automatically.

![Path Planning Simulation](https://user-images.githubusercontent.com/14826664/217097418-4c27159a-2005-4fda-b83d-48755101d3be.png)
