# Usefull stuff to remember

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

## Remove shadows from .world
Add these lines (shadows=0)
```
    <scene>
      <ambient>0.9 0.9 0.9 1</ambient>
      <shadows>false</shadows>
    </scene>
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