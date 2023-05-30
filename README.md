# ros-rob-project-mapping
Repo for Robotrendszerek laboratórium project

## Project description
- Navigációs stack behangolása bonyolult szimulációs környezetben
- Egy bonyolult szoba / épület feltérképezése és autonóm navigáció a navigációs stack használatával
- Mozgó akadályok szimulációja (pl ember, állat)

## Github workflow
How to add new functionality to the stack:
After working main branch
1. Create feature/fix branch from **main**
2. Develop feature set
3. Test
4. If testing was successful --> create **PR**
5. **PR** has to be tested by other project member
6. If it was successful --> squash merge onto **main**

Branch types:
- **main**: main branch, "protected"
- **feature**: feature branch, for adding new features, or expanding existing features
    - example name: feature-lidar-xacro
- **fix**: fix branch
    - example name: fix-robot-color

## Setup and install
1. **Clone repository and update submodules**
    ```
    mkdir -p workspace/src
    cd workspace/src
    git clone https://github.com/turtlewizard73/pie-mapping-and-navigation.git
    ```

2. **Checkout on development and update submodules**
    ```
    cd src/pie-mapping-and-navigation
    git fetch
    git checkout development
    git pull
    git submodule update --init --recursive
    ```

3. **Build gazebo actors plugin**
    ```
    cd gazebo_actor_collisions_plugin
    mkdir build
    cd build
    cmake ..
    make
    export GAZEBO_PLUGIN_PATH=$GAZEBO_PLUGIN_PATH:$(pwd)
    ```

4. **Install dependencies and build the packages**
    ```
    cd workspace/src/pie-mapping-and-navigation
    sudo xargs -a apt-dependencies.txt apt install -y
    cd workspace
    catkin_make
    source devel/setup.bash
    ```

## How to use
1. **start the simulation** (gazebo & rviz)
    ```
    roslaunch pie_bringup bringup.launch
    ```

2. **moving the robot**
    ```
    rosun teleop_twist_keboard teleop_twist_keboard.py
    ```

3. **mapping**
    - start mapping
    ```
    roslaunch pie_bringup gmapping.launch
    ```
    - save map:
    ```
    rosrun map_server map_saver -f map
    ```

4. **navigation**
    ```
    roslaunch pie_bringup navigation.launch
    ```

**Frequencies**
    - base scan = 5.0
    - global costmap update frequency: 5.0
    - local costmap update frequency: 5.0
    - ...

## Stuff
1. Image transport and compression
    - wiki.ros.org/image_transport
    - wiki.ros.org/compressed_image_transport (pont jó)
    - wiki.ros.org/theora_image_transport (nagyon compressed)

## Inspiration
Add sources, links, documentations, any useful information, that might be useful or helpful.
1. Plan 3d scanning:
    - **Meshroom**
        - https://alicevision.org/#meshroom
        - https://www.youtube.com/watch?v=yKbyVDK2Ep8
        - Uses images
    - **RealityCapture**
        - https://www.capturingreality.com/
        - https://www.youtube.com/watch?v=i8AdX6OCvHg
        - Images and video

2. turtlebot docs
https://emanual.robotis.com/docs/en/platform/turtlebot3/overview/#notices

3. packages:
magic imu arrow
http://wiki.ros.org/rviz_imu_plugin