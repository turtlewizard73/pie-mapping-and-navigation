# Usefull stuff to remember

## Remove shadows from .world
Add these lines (shadows=0)
```
    <scene>
      <ambient>0.9 0.9 0.9 1</ambient>
      <shadows>false</shadows>
    </scene>
```

##  PYSDF converter package
[REPO](https://github.com/MOGI-ROS/pysdf)  
Export env variable for your workspace.
  - MESH_WORKSPACE_PATH = ws/src
```
rosrun pysdf sdf2urdf.py -h
```
Dependencies (pip):
```
pip3 install parse pysdf
```
  
## Removing submodule
[Stackoverflow](https://stackoverflow.com/questions/20929336/git-submodule-add-a-git-directory-is-found-locally-issue)

## Usefull commands:
Run remote control
```
rosrun teleop_twist_keyboard teleop_twist_keyboard.py
```

RQT TF tree:
```
rosrun rqt_tf_tree rqt_tf_tree
```