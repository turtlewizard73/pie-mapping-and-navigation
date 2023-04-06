FROM ros:noetic-robot

# https://classic.gazebosim.org/tutorials?tut=ros_installing
RUN echo "source /opt/ros/noetic/setup.bash" >> ~/.bashrc
RUN apt update && \
    apt install -y ros-noetic-gazebo-ros-pkgs ros-noetic-gazebo-ros-control x11-apps

# RUN ["/bin/bash", "-c", "source /opt/ros/noetic/setup.bash"]
# https://robotics.stackexchange.com/questions/21959/docker-dockerfile-bin-bash-catkin-init-workspace-catkin-make-command-not
# https://answers.ros.org/question/312577/catkin_make-command-not-found-executing-by-a-dockerfile/?answer=312730#post-id-312730
RUN /bin/bash -c 'source /opt/ros/noetic/setup.bash && \
    mkdir -p ~/catkin_ws/src && \
    cd ~/catkin_ws/src && \
    catkin_init_workspace && \
    cd ~/catkin_ws && \
    catkin_make'
RUN echo "source ~/catkin_ws/devel/setup.bash" >> ~/.bashrc

# RUN apt update && \
#     apt install -y git libgazebo11-dev

# RUN cd ~/catkin_ws/src && \
#     git clone https://github.com/ros-simulation/gazebo_ros_pkgs.git -b noetic-devel

# RUN rosdep update && \
#     rosdep check --from-paths . --ignore-src --rosdistro noetic && \
#     rosdep install --from-paths . --ignore-src --rosdistro noetic -y

# RUN /bin/bash -c 'source /opt/ros/noetic/setup.bash && \
#     cd ~/catkin_ws/ && catkin_make'

CMD ["bash"]