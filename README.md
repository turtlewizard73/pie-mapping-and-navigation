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

## El Plan
**I. milestone - Basic models**
Define physics
1. Robot model: turtlebot
    - wheel radius
    - wheel spearation
    - lidar link
    - ... anything needded for starting mapping
    - if easy and do not compromise simulation use full model
    - xacro -> urdf -> tf tree
2. World model:  
    - Closed  --> room without door
    - Walls whit doors
    - Obsticles
    - world launch file
3. Basic launch file to run simulation with robot model and world

**II. milestone - Mapping**  
1. lidar packages
    - actual robot -> lidar type
    - simulating lidar in gazeboo
    - config lidar parameters
2. mapping package
    - input: lidar
    - output: map (how to save map, map format)
3. odometry
    - ???
    - sensor fusion -> IMU (type) -> package
4. do mapping
    - launch file + mapping package
    - teleop the shit out of the robot
    - save the map

**III. milestone - Navigation**  
Automate robot to position
1. global planner
2. (global costmap)

**IV. milestone - Simulating moving obsticles**  
1. Obstacle model
2. Simulate movement
3. local costmap & local planner

**V. milestone - Finalizing**  
1. Models are ok
2. Navigation works
3. extra: aruco marker -> initial position
4. README
5. Hand in
6. Beer(s)


## Sources
Add sources, links, documentations, any useful information, that might be useful or needed.
1. Plan 3d scanning:
    - **Meshroom**
        - https://alicevision.org/#meshroom
        - https://www.youtube.com/watch?v=yKbyVDK2Ep8
        - Uses images
    - **RealityCapture**
        - https://www.capturingreality.com/
        - https://www.youtube.com/watch?v=i8AdX6OCvHg
        - Images and video
    - by using equipment provided by karman studio shoot video or take pictures from robot, then make a 3d model by using some software. Touch up the generated model and import it into gazeboo.

2. tutel bot stuff
https://emanual.robotis.com/docs/en/platform/turtlebot3/overview/#notices

3. packages:
magic imu arrow
http://wiki.ros.org/rviz_imu_plugin