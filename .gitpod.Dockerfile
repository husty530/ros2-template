FROM ubuntu:22.04
ENV DISTRO humble

USER gitpod

RUN sudo apt-get update && sudo apt-get install -y curl gnupg lsb-release
RUN sudo curl -sSL https://raw.githubusercontent.com/ros/rosdistro/master/ros.key -o /usr/share/keyrings/ros-archive-keyring.gpg
RUN echo "deb [arch=$(dpkg --print-architecture) signed-by=/usr/share/keyrings/ros-archive-keyring.gpg] http://packages.ros.org/ros2/ubuntu $(source /etc/os-release && echo $UBUNTU_CODENAME) main" | sudo tee /etc/apt/sources.list.d/ros2.list > /dev/null
RUN sudo apt-get update && sudo apt-get install -y ros-${DISTRO}-ros-base ros-dev-tools
RUN echo "source /opt/ros/${DISTRO}/setup.bash" >> ~/.bashrc
RUN echo "source /workspace/ros2-template/install/setup.bash" >> ~/.bashrc
RUN source ~/.bashrc
RUN sudo apt-get install -y python3-colcon-common-extensions
RUN colcon build