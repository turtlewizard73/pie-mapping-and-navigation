# Usefull stuff to remember

## Remove shadows from .world
Add these lines (shadows=0)
```
    <scene>
      <ambient>0.9 0.9 0.9 1</ambient>
      <shadows>false</shadows>
    </scene>
```

## Camera distortion

https://classic.gazebosim.org/tutorials?tut=camera_distortion&cat=sensors

## Camera compression
```
sudo apt install ros-noetic-compressed-image-transport
```

IMU:
sudo apt install ros-noetic-hector-gazebo-plugins
sudo apt install ros-noetic-rviz-imu-plugin