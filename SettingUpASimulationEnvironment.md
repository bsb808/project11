
# Setting up a ROS environment to simulate Project 11's backseat driver system.

## Introduction

CCOM/JHC's ASVs are capable of operating with a backseat driver, which is a computer not supplied by the manufaturer capable of taking control of the vehicle by supplying throttle or speed and rudder or heading commands. The vehicle's manufacturer supplied computer accepts such commands via a [ROS](http://www.ros.org/) interface.

ROS is offically supported on Ubuntu Linux so the Project 11 system runs on Ubuntu. The actual system consists of two separate computers, each running Ubuntu, comunicating over an unreliable wireless connection. For simulation puposes, the system has been designed to also work on a single computer.

A common directory structure has been created that typically resides in the user's home directory. The same structure is used both on the vehicle and on the operator station.

    project11/
    ├── catkin_ws
    ├── config
    ├── documentation
    ├── executed_missions
    ├── log
    ├── ros
    └── scripts

ROS development is done in the catkin_ws directory while ROS uses the ros directory at runtime. The documentation directory is where this and other documents live. The scripts directory contains useful shell scripts that help during development and operation.

## Background knowledge

### Ubuntu Linux

The ROS tutorials recommend [this page](http://www.ee.surrey.ac.uk/Teaching/Unix/) for beginner Unix tutorials.

### ROS

Project 11 uses the Melodic version of ROS. It is recomended to go through the [ROS Tutorials](http://wiki.ros.org/ROS/Tutorials) in order to better understand how it works.

### Git

TODO: Add git tutorials. [git book](https://git-scm.com/book/en/v2).

### Programing

Knowledge of Python or C++ is necessary for development.

#### Python

TODO Pyhton tutorials. (Python's own tutorial has served me well)

#### C++

TODO C++ tutorials.

## Prerequisite

The Project 11 system is based on ROS Melodic so it is designed to run on an Ubuntu 18.04 system.

If an Ubuntu 18.04 machine is not readily available, a virtual machine may be setup for this purpose.

### Setting up an Ubuntu virtual machine

These instructions were developed using VirtualBox on Ubuntu. Similar steps should work with VMWare as well.

  * Obtain an Ubuntu iso install image from the [Bionic release page](http://releases.ubuntu.com/bionic/). We are looking for the [64-bit PC (AMD64) desktop image.](http://releases.ubuntu.com/xenial/ubuntu-18.04.1-desktop-amd64.iso)
  * Create a virtual machine for a 64-bit Ubuntu install with the following specs:
    * 4GB or more of memory. (TODO: do we need more? At 1GB, ran out of memory compiling QT5)
    * 50GB or more of hard drive space.
  * Insert the downloaded Ubuntu iso image in the virtual machine's optical drive and start the virtual machine.
  * Chose "Install Ubuntu" when presented the choice.
  * Select "Download updates while installing Ubuntu" and optonally select "Install third-party software" (TODO: do this last one make a difference?)
  * Continue with default "Erase disk and install Ubuntu".
  * Pick reasonable values for timezone and languages.
  * Create a user account for yourself (for a shared machine, you may create a field account instead).
  * Install guest additions or equivalent. (Caution, skipping this step with VMWare may have caused diplay errors on boot later on.)

Once Ubuntu is installed, you can make sure it's up to date by doing a apt-get update followed by an apt-get upgrade.

    sudo apt-get update
    sudo apt-get upgrade

## Installing ROS

Follow the instructions on the [Ubuntu install of ROS Melodic](http://wiki.ros.org/melodic/Installation/Ubuntu) page, picking the Desktop-Full installation.

If you are new to ROS, now is a good time to follow the ROS tutorials.

## Configuring git.

The version control client git should already be installed so it only needs to be configured. The git book's [First Time Git Setup page](https://git-scm.com/book/en/v2/Getting-Started-First-Time-Git-Setup) contains instructions on how to configure your name and email address so that commits get attributed to you.

## Creating the Project 11 directory structure.

Part of the direcotry structure is created by hand while others are cloned from git repositories.

    mkdir -p ~/project11/catkin_ws/src
    mkdir -p ~/project11/log/nodes
    mkdir -p ~/project11/executed_missions

To be able to contain all the relevant data inside the project11 directory, ROS' default working directory, ~/.ros, gets moved and replaced with a symlink.

    mv ~/.ros ~/project11/ros
    ln -s ~/project11/ros ~/.ros

If an error occurs complaining that ~/.ros does not exist. Create it instead of moving it: mkdir ~/project11/ros

Create a few simlinks so that ROS nodes can log to the log directory.

    ln -s ~/project11/log/nodes ~/project11/ros/nodes
    
Initialize the ROS Catkin workspace.

    cd ~/project11/catkin_ws
    catkin_make

Normally, the Project 11 Catkin workspace is the only one used, so we can make it the default workspace when logging in by sourcing the setup script from .bashrc.

    echo "source ~/project11/catkin_ws/devel/setup.bash" >> ~/.bashrc
    source ~/.bashrc

## Fetching Project11 ROS Packages (non-contributor version)
This step involves "cloning" the Project11 packages from github. These packages contain all the code and documentation for our vehicles. There are two-ways this can be done. This first "non-contributor" version is a bit quicker and allows one to pull the packages, make local modifications as you see fit, but does not easily faciltate contributing your changes back to the master Project11 repositories. If contributing your code back is important, see the contributor version below.

Fetch a few more directories from github.

    cd ~/project11
    git clone https://github.com/CCOMJHC/project11_documentation.git documentation
    git clone https://github.com/CCOMJHC/project11_scripts.git scripts
    git clone https://github.com/CCOMJHC/project11_configuration.git config

Clone ROS packages from github:

    cd ~/project11/catkin_ws/src
    git clone https://github.com/CCOMJHC/asv_sim.git
    git clone https://github.com/CCOMJHC/asv_helm.git
    git clone https://github.com/CCOMJHC/project11.git
    git clone https://github.com/CCOMJHC/project11_transformations.git
    git clone https://github.com/CCOMJHC/udp_bridge.git
    git clone https://github.com/CCOMJHC/marine_msgs.git
    git clone https://github.com/CCOMJHC/mbes_sim.git
    git clone https://github.com/CCOMJHC/command_bridge.git
    git clone https://github.com/CCOMJHC/mission_manager.git
    git clone https://github.com/CCOMJHC/dubins_curves.git
    git clone https://github.com/CCOMJHC/path_follower.git
    git clone https://github.com/CCOMJHC/kongsberg_em_control.git
    git clone https://github.com/CCOMJHC/geographic_visualization_msgs.git
    git clone https://github.com/CCOMJHC/joy_to_helm.git
    git clone https://github.com/CCOMJHC/hover.git
    git clone https://github.com/CCOMJHC/path_planner.git
    git clone https://github.com/CCOMJHC/mpc.git
    git clone https://github.com/CCOMJHC/course_made_good.git
    

    
Clone darknet package, but only build the messages:

    git clone https://github.com/leggedrobotics/darknet_ros.git
    touch darknet_ros/darknet_ros/CATKIN_IGNORE
    
Install additional ROS packages available for apt-get

    sudo apt install ros-melodic-geographic-msgs
    sudo apt install ros-melodic-geodesy
    sudo apt install ros-melodic-pid
    sudo apt install ros-melodic-joy

The python gdal package is used by mbes_sim, so make sure it's installed.

    sudo apt install python-gdal    
    
## Fetching Project11 ROS Packages (contributor version)
The standard way in "git" to contribute code and other changes back into a repository is to "fork" the repository first. This creates a copy of the repository in your own github account that you can modify as you wish. But you cannot modify the code in the forked version of the repository directly, because it is on the github server. Rather you make a "clone" of if on your local machine where you can make changes and "push" them back to your forked copy on github. Finally, if you want to contribute your changes back to the original offical CCOMJHC repository you navigate to that repo on github and create a "pull request". This is a request for the maintainer of the CCOMJHC repository to "pull" your changes back into the original repository. If he/she agrees with your suggested changes, your request will be granted and your code will become part of the official archive.

Thus instead of simply cloning the repositories as shown above, you may want to first fork them into your own github account and clone them from there. You can then set a "remote" upstream head which also allows you to pull changes from the CCOMJHC repository to keep your own version up to date. 

## Build the packages
Build in the catkin workspace.

    cd ~/project11/catkin_ws
    catkin_make

Re-sourcing .bashrc will make sure new packages created by the build can be found.
    
    source ~/.bashrc
    
Once catkin_make completes without error in ~/project11/catkin_ws/, we can try starting the simulation.

    roslaunch project11 sim_local.launch

You may encouter an error about a python script not being able to import a module. That may indicate that the catkin workspace's setup script needs to be resourced.

    source ~/project11/catkin_ws/devel/setup.bash

Once sim_local.launch is succesfully launch, we can verify that things are running:

    rostopic list
    rostopic echo /udp/position

## rviz

With the simulation running, rviz may be launched in a new terminal.

    rviz
    
A configuration file showing the map frame of reference as well as the simulated boat, named base_link, can be found at ~/project11/catkin_ws/src/project11/rviz/transforms.rviz. 

## Installing the CCOM AutonomousMissionPlanner (CAMP)

The CCOM AutonomouMissionPlanner (CAMP) is a QT5 based C++ application for mission planning and monitoring. It optionally be built with ROS capabilities, but it doesn't get built in the catkin workspace. Following are instructions for cloning and building in the src directory.

    mkdir -p ~/src
    cd ~/src
    git clone https://github.com/CCOMJHC/AutonomousMissionPlanner.git
    cd AutonomousMissionPlanner
    mkdir build
    cd build
    cmake-gui ../
    
The last command may fail due to cmake-gui not being installed. Follow the instructions to install it. Once installed and running, click the configure button to start configuring the mission planner. Accept the default Unix Makefile generator and native compilers.

Some QT5 development libraries may be missing. Install then with apt.

    sudo apt install qtpositioning5-dev libqt5svg5-dev
    
    
Now that we have the prerequisits, lets go back to CAMP's build directory where we can finish configuring and compiling it.

    cd ~/src/AutonomousMissionPlanner/build
    cmake-gui ../


Make sure "AMP_USE_ROS" bos is checked. Press the 'Configure' button and then (if there are no errors) press the 'Generate' button. 
Once configure and generate complete succesfuly, exit cmake and build CAMP (still in the /build directory).

    make

From the build direcotry, run the mission planner.

    ./AutonomouMissionPlanner

## Downloading NOAA raster navigation chart for CAMP

CAMP uses georeferenced raster images as background layers. The simulations defaults to Portsmouth Harbor in New Hampshire, so a raster nautical chart works fine as a background layer. In [NOAA Nautical Chart Catalog](https://www.charts.noaa.gov/ChartCatalog/Northeast.html), search for chart 13283. Download and unzip it.

In CAMP, File->Open Background or the BG button, and open 13283_2.KAP.
